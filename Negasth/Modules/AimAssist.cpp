#include "Modules.h"
#include "../Cache/Cache.h"
#include "../net/Minecraft/item/ItemSword.h"
void Negasth::Modules::AimAssist::run() {
	if (!(GetKeyState(VK_LBUTTON) & 0x8000)|| cache->theMinecraft.getCurrentScreen().isValid())
	{
		prev_selected_target.Clear();
		return;
	}

	static Negasth::CTimer timer = std::chrono::milliseconds(10);
	if (!timer.isElapsed())
		return;

	Maths::Vector3d thePlayer_position = cache->thePlayer.getPosition();
	thePlayer_position.y += cache->thePlayer.getEyeHeight();

	Maths::Vector2d thePlayer_rotation = cache->thePlayer.getRotation();
	double cropped_thePlayer_yaw = Negasth::Maths::cropAngle180(thePlayer_rotation.x);
	double cropped_thePlayer_pitch = thePlayer_rotation.y;

	EntityPlayer selected_target{};
	double selected_target_YawToAdd = 0.0;
	double selected_target_PitchToAdd = 0.0;

	for (EntityPlayer& target : Negasth::cache->playerEntities.toVector<EntityPlayer>())
	{

		if (!target.isValid() || Negasth::p_env->IsInstanceOf(cache->thePlayer.getHeldItem().getItem().getInstance(), ItemSword::ItemSwordClass.getJclass(Negasth::p_env)) != JNI_TRUE || target.isEqualto(cache->thePlayer) || !cache->thePlayer.canAttackPlayer(target) ) /*|| target.getTicksExisted() < 10*/
			continue;
		//std::cout << target.getName() << std::endl;
		ScorePlayerTeam playerTeam{ target.getTeam().getInstance() };
		ScorePlayerTeam myTeam{ cache->thePlayer.getTeam().getInstance()};
		if (playerTeam.isValid() && myTeam.isValid()) {
			if (strcmp(playerTeam.getColorPrefix(), myTeam.getColorPrefix()) == 0)
				continue;
		}


		AxisAlignedBB targetBB = target.getBoundingBox();
		Maths::Vector3d target_position
		(
			targetBB.getMinX() + (targetBB.getMaxX() - targetBB.getMinX()) / 2.0,
			targetBB.getMinY() + (targetBB.getMaxY() - targetBB.getMinY()) / 2.0,
			targetBB.getMinZ() + (targetBB.getMaxZ() - targetBB.getMinZ()) / 2.0
		);
		target_position = target_position + target.getMovementVector(cache->timer.getRenderPartialTicks());

		Maths::Vector2d target_required_rotation = Maths::getYawPitch(thePlayer_position, target_position);
		double yawToAdd = target_required_rotation.x - cropped_thePlayer_yaw;
		double pitchToAdd = target_required_rotation.y - cropped_thePlayer_pitch;
		yawToAdd = Negasth::Maths::cropAngle180(yawToAdd);
		double target_distance = (target_position - thePlayer_position).distance();
		if (target_distance <= max_distance && target_distance > 0.5 && std::abs(yawToAdd) <= max_angle)
		{
			if (prev_selected_target.isValid() && prev_selected_target.isEqualto(target))
			{
				selected_target = target;
				selected_target_YawToAdd = yawToAdd;
				selected_target_PitchToAdd = pitchToAdd;
				break;
			}
			if (!selected_target.isValid() || std::abs(yawToAdd) < std::abs(selected_target_YawToAdd))
			{
				selected_target = target;
				selected_target_YawToAdd = yawToAdd;
				selected_target_PitchToAdd = pitchToAdd;
			}
		}
		else if (prev_selected_target.isValid() && prev_selected_target.isEqualto(target))
		{
			prev_selected_target.Clear();
		}
	}

	if (selected_target.isValid())
	{
		prev_selected_target = selected_target;
		Negasth::Maths::Vector3d selected_target_mvmt_vec = selected_target.getMovementVector(cache->timer.getRenderPartialTicks());
		AxisAlignedBB selected_target_bb = selected_target.getBoundingBox();
		Negasth::Maths::Vector3d positionsToCheck[] =
		{
			Negasth::Maths::Vector3d(selected_target_bb.getMinX(), selected_target_bb.getMinY(), selected_target_bb.getMaxZ()) + selected_target_mvmt_vec,
			Negasth::Maths::Vector3d(selected_target_bb.getMaxX(), selected_target_bb.getMinY(), selected_target_bb.getMinZ()) + selected_target_mvmt_vec,
			Negasth::Maths::Vector3d(selected_target_bb.getMaxX(), selected_target_bb.getMinY(), selected_target_bb.getMaxZ()) + selected_target_mvmt_vec,
			Negasth::Maths::Vector3d(selected_target_bb.getMinX(), selected_target_bb.getMinY(), selected_target_bb.getMinZ()) + selected_target_mvmt_vec
		};
		double minYaw = 361.0, maxYaw = -1.0;
		double minPitch = 0.0, maxPitch = 0.0;
		for (const Negasth::Maths::Vector3d& position : positionsToCheck)
		{
			Negasth::Maths::Vector2d YawPitch = Maths::getYawPitch(thePlayer_position, position);
			double Yaw = YawPitch.x;
			if (Yaw < 0.0) Yaw += 360.0;
			if (Yaw < minYaw) minYaw = Yaw;
			if (Yaw > maxYaw) maxYaw = Yaw;
			maxPitch = YawPitch.y;
		}

		if (minYaw > 180.0) minYaw -= 360.0;
		if (maxYaw > 180.0) maxYaw -= 360.0;

		Negasth::Maths::Vector2d YawPitch = Maths::getYawPitch
		(
			thePlayer_position,
			Negasth::Maths::Vector3d(selected_target_bb.getMaxX(), selected_target_bb.getMaxY(), selected_target_bb.getMaxZ()) + selected_target_mvmt_vec
		);
		minPitch = YawPitch.y;

		//don't even ask, some random calculations that sometimes bypass anticheats
		double maxDelta = std::abs(Negasth::Maths::cropAngle180((maxYaw - minYaw))) / 2.0;
		double difference = std::abs(selected_target_YawToAdd) - maxDelta;
		if (std::abs(selected_target_YawToAdd) > maxDelta)
		{
			if (difference < 2.0)
			{
				thePlayer_rotation.x += difference * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
			}
			else if (difference >= 16.0)
			{
				std::uniform_int_distribution<> distr(int(400.0 * multiplier), int(800.0 * multiplier));
				thePlayer_rotation.x += (double(distr(gen)) / 100.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
			}
			else if (difference >= 8.0)
			{
				std::uniform_int_distribution<> distr(int(250.0 * multiplier), int(400.0 * multiplier));
				thePlayer_rotation.x += (double(distr(gen)) / 100.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
			}
			else if (difference >= 4.0)
			{
				std::uniform_int_distribution<> distr(int(100.0 * multiplier), int(200.0 * multiplier));
				thePlayer_rotation.x += (double(distr(gen)) / 100.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
			}
			else
			{
				std::uniform_int_distribution<> distr(int(25.0 * multiplier), int(100.0 * multiplier));
				thePlayer_rotation.x += (double(distr(gen)) / 100.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
			}
		}

		double maxPitchDelta = std::abs(maxPitch - minPitch) / 2.0;
		difference = std::abs(selected_target_PitchToAdd) - maxPitchDelta;
		if (std::abs(selected_target_PitchToAdd) > maxPitchDelta)
		{
			if (difference < 2.0)
			{
				thePlayer_rotation.y += difference * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
			}
			else if (difference >= 16.0)
			{
				std::uniform_int_distribution<> distr(int(400.0 * multiplierPitch), int(800.0 * multiplierPitch));
				thePlayer_rotation.y += (double(distr(gen)) / 100.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
			}
			else if (difference >= 8.0)
			{
				std::uniform_int_distribution<> distr(int(250.0 * multiplierPitch), int(400.0 * multiplierPitch));
				thePlayer_rotation.y += (double(distr(gen)) / 100.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
			}
			else if (difference >= 4.0)
			{
				std::uniform_int_distribution<> distr(int(100.0 * multiplierPitch), int(200.0 * multiplierPitch));
				thePlayer_rotation.y += (double(distr(gen)) / 100.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
			}
			else
			{
				std::uniform_int_distribution<> distr(int(25.0 * multiplierPitch), int(100.0 * multiplierPitch));
				thePlayer_rotation.y += (double(distr(gen)) / 100.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
			}
		}
		cache->thePlayer.setRotation(thePlayer_rotation);
	}
}