#pragma once
namespace Mappings
{
	constexpr static char mappings_major_1_8_9[] = R"(
{
	"net/minecraft/client/Minecraft": {
		"obfuscated": "net/minecraft/client/Minecraft",
		"fields": [
			{
				"name": "theMinecraft",
				"obfuscated": "field_71432_P",
				"signature": "Lnet/minecraft/client/Minecraft;",
				"static": true
			},
			{
				"name": "thePlayer",
				"obfuscated": "field_71439_g",
				"signature": "Lnet/minecraft/client/entity/EntityPlayerSP;",
				"static": false
			},
			{
				"name": "theWorld",
				"obfuscated": "field_71441_e",
				"signature": "Lnet/minecraft/client/multiplayer/WorldClient;",
				"static": false
			},
			{
				"name": "gameSettings",
				"obfuscated": "gameSettings",
				"signature": "Lnet/minecraft/client/settings/GameSettings;",
				"static": false
			},
			{
				"name": "objectMouseOver",
				"obfuscated": "field_71476_x",
				"signature": "Lnet/minecraft/util/MovingObjectPosition;",
				"static": false
			},
			{
				"name": "rightClickDelayTimer",
				"obfuscated": "field_71467_ac",
				"signature": "I",
				"static": false
			},
			{
				"name": "pointedEntity",
				"obfuscated": "pointedEntity",
				"signature": "Lnet/minecraft/entity/Entity;",
				"static": false
			},
			{
				"name": "timer",
				"obfuscated": "field_71428_T",
				"signature": "Lnet/minecraft/util/Timer;",
				"static": false
			},
			{
				"name": "playerController",
				"obfuscated": "field_71442_b",
				"signature": "Lnet/minecraft/client/multiplayer/PlayerControllerMP;",
				"static": false
			},
			{
				"name": "currentScreen",
				"obfuscated": "field_71462_r",
				"signature": "Lnet/minecraft/client/gui/GuiScreen;",
				"static": false
			},
			{
				"name": "renderViewEntity",
				"obfuscated": "renderViewEntity",
				"signature": "Lnet/minecraft/entity/Entity;",
				"static": false
			},
			{
				"name": "renderManager",
				"obfuscated": "field_175616_W",
				"signature": "Lnet/minecraft/client/renderer/entity/RenderManager;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "clickMouse",
				"obfuscated": "func_147116_af",
				"signature": "()V",
				"static": false
			},
			{
				"name": "getNetHandler",
				"obfuscated": "func_147114_u",
				"signature": "()Lnet/minecraft/client/network/NetHandlerPlayClient;",
				"static": false
			}
		]
	},
	"net/minecraft/client/entity/EntityPlayerSP": {
		"obfuscated": "net/minecraft/client/entity/EntityPlayerSP",
		"fields": [
			{
				"name": "sendQueue",
				"obfuscated": "sendQueue",
				"signature": "Lnet/minecraft/client/network/NetHandlerPlayClient;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "swingItem",
				"obfuscated": "func_71038_i",
				"signature": "()V",
				"static": false
			}
		]
	},
	"net/minecraft/client/entity/AbstractClientPlayer": {
		"obfuscated": "net/minecraft/client/entity/AbstractClientPlayer",
		"fields": [],
		"methods": []
	},
	"net/minecraft/inventory/Container":{
		"obfuscated": "net/minecraft/inventory/Container",
		"fields": [
			{
				"name": "windowId",
				"obfuscated": "field_75152_c",
				"signature": "I",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/entity/player/InventoryPlayer": {
		"obfuscated": "net/minecraft/entity/player/InventoryPlayer",
		"fields": [
			{
				"name": "currentItem",
				"obfuscated": "field_70461_c",
				"signature": "I",
				"static": false
			},
			{
				"name": "mainInventory",
				"obfuscated": "field_70462_a",
				"signature": "[Lnet/minecraft/item/ItemStack;",
				"static": false
			},
			{
				"name": "armorInventory",
				"obfuscated": "field_70460_b",
				"signature": "[Lnet/minecraft/item/ItemStack;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/entity/player/EntityPlayer": {
		"obfuscated": "net/minecraft/entity/player/EntityPlayer",
		"fields": [
			{
				"name": "inventory",
				"obfuscated": "field_71071_by",
				"signature": "Lnet/minecraft/entity/player/InventoryPlayer;",
				"static": false
			},
			{
				"name": "openContainer",
				"obfuscated": "field_71070_bA",
				"signature": "Lnet/minecraft/inventory/Container;",
				"static": false
			}
		],
		"methods": [
			{
				"name": "canAttackPlayer",
				"obfuscated": "func_96122_a",
				"signature": "(Lnet/minecraft/entity/player/EntityPlayer;)Z",
				"static": false
			},
			{
				"name": "getName",
				"obfuscated": "func_70005_c_",
				"signature": "()Ljava/lang/String;",
				"static": false
			},
			{
				"name": "attackTargetEntityWithCurrentItem",
				"obfuscated": "attackTargetEntityWithCurrentItem",
				"signature": "(Lnet/minecraft/entity/Entity;)V",
				"static": false
			},
			{
				"name": "getTeam",
				"obfuscated": "func_96124_cp",
				"signature": "()Lnet/minecraft/scoreboard/Team;",
				"static": false
			},
			{
				"name": "getHeldItem",
				"obfuscated": "func_70694_bm",
				"signature": "()Lnet/minecraft/item/ItemStack;",
				"static": false
			},
			{
				"name": "getItemInUseDuration",
				"obfuscated": "func_71057_bx",
				"signature": "()I",
				"static": false
			},
			{
				"name": "isBlocking",
				"obfuscated": "func_70632_aY",
				"signature": "()Z",
				"static": false
			}
		]
	},
	"net/minecraft/entity/EntityLivingBase": {
		"obfuscated": "net/minecraft/entity/EntityLivingBase",
		"fields": [
			{
				"name": "jumpTicks",
				"obfuscated": "field_70773_bE",
				"signature": "I",
				"static": false
			}
		],
		"methods": [
			{
				"name": "getHealth",
				"obfuscated": "func_110143_aJ",
				"signature": "()F",
				"static": false
			},
			{
				"name": "getMaxHealth",
				"obfuscated": "func_110138_aP",
				"signature": "()F",
				"static": false
			},
			{
				"name": "canEntityBeSeen",
				"obfuscated": "func_70685_l",
				"signature": "(Lnet/minecraft/entity/Entity;)Z",
				"static": false
			}
		]
	},
	"net/minecraft/entity/Entity": {
		"obfuscated": "net/minecraft/entity/Entity",
		"fields": [
			{
				"name": "posX",
				"obfuscated": "field_70165_t",
				"signature": "D",
				"static": false
			},
			{
				"name": "posY",
				"obfuscated": "field_70163_u",
				"signature": "D",
				"static": false
			},
			{
				"name": "posZ",
				"obfuscated": "field_70161_v",
				"signature": "D",
				"static": false
			},
			{
				"name": "rotationYaw",
				"obfuscated": "field_70177_z",
				"signature": "F",
				"static": false
			},
			{
				"name": "rotationPitch",
				"obfuscated": "field_70125_A",
				"signature": "F",
				"static": false
			},
			{
				"name": "motionX",
				"obfuscated": "motionX",
				"signature": "D",
				"static": false
			},
			{
				"name": "motionY",
				"obfuscated": "motionY",
				"signature": "D",
				"static": false
			},
			{
				"name": "motionZ",
				"obfuscated": "motionZ",
				"signature": "D",
				"static": false
			},
			{
				"name": "hurtResistantTime",
				"obfuscated": "hurtResistantTime",
				"signature": "I",
				"static": false
			},
			{
				"name": "ticksExisted",
				"obfuscated": "field_70173_aa",
				"signature": "I",
				"static": false
			},
			{
				"name": "boundingBox",
				"obfuscated": "field_70121_D",
				"signature": "Lnet/minecraft/util/AxisAlignedBB;",
				"static": false
			},
			{
				"name": "lastTickPosX",
				"obfuscated": "field_70142_S",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickPosY",
				"obfuscated": "field_70137_T",
				"signature": "D",
				"static": false
			},
			{
				"name": "lastTickPosZ",
				"obfuscated": "field_70136_U",
				"signature": "D",
				"static": false
			},
			{
				"name": "onGround",
				"obfuscated": "onGround",
				"signature": "Z",
				"static": false
			},
			{
				"name": "ridingEntity",
				"obfuscated": "ridingEntity",
				"signature": "Lnet/minecraft/entity/Entity;",
				"static": false
			},
			{
				"name": "prevRotationYaw",
				"obfuscated": "prevRotationYaw",
				"signature": "F",
				"static": false
			},
			{
				"name": "prevRotationPitch",
				"obfuscated": "prevRotationPitch",
				"signature": "F",
				"static": false
			},
			{
				"name": "entityId",
				"obfuscated": "entityId",
				"signature": "I",
				"static": false
			}
		],
		"methods": [
			{
				"name": "getEyeHeight",
				"obfuscated": "func_70047_e",
				"signature": "()F",
				"static": false
			},
			{
				"name": "isSprinting",
				"obfuscated": "isSprinting",
				"signature": "()Z",
				"static": false
			},
			{
				"name": "setSprinting",
				"obfuscated": "setSprinting",
				"signature": "(Z)V",
				"static": false
			},
			{
				"name": "setPositionAndUpdate",
				"obfuscated": "setPositionAndUpdate",
				"signature": "(DDD)V",
				"static": false
			},
			{
				"name": "setPosition",
				"obfuscated": "setPosition",
				"signature": "(DDD)V",
				"static": false
			}
		]
	},
	"net/minecraft/scoreboard/Scoreboard": {
		"obfuscated": "net/minecraft/scoreboard/Scoreboard",
		"fields": [],
		"methods": [
			{
				"name": "getTeamNames",
				"obfuscated": "func_96531_f",
				"signature": "()Ljava/util/Collection;",
				"static": false
			}
		]
	},
	"net/minecraft/scoreboard/ScorePlayerTeam": {
		"obfuscated": "net/minecraft/scoreboard/ScorePlayerTeam",
		"fields": [],
		"methods": [
			{
				"name": "getTeamName",
				"obfuscated": "func_96669_c",
				"signature": "()Ljava/lang/String;",
				"static": false
			},
			{
				"name": "getColorPrefix",
				"obfuscated": "func_96668_e",
				"signature": "()Ljava/lang/String;",
				"static": false
			}
		]
	},
	"net/minecraft/client/multiplayer/WorldClient": {
		"obfuscated": "net/minecraft/client/multiplayer/WorldClient",
		"fields": [],
		"methods": []
	},
	"net/minecraft/world/World": {
		"obfuscated": "net/minecraft/world/World",
		"fields": [
			{
				"name": "playerEntities",
				"obfuscated": "field_73010_i",
				"signature": "Ljava/util/List;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/network/Packet": {
		"obfuscated": "net/minecraft/network/Packet",
		"fields": [],
		"methods": []
	},
	"net/minecraft/util/MovingObjectPosition": {
		"obfuscated": "net/minecraft/util/MovingObjectPosition",
		"fields": [
			{
				"name": "typeOfHit",
				"obfuscated": "field_72313_a",
				"signature": "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;",
				"static": false
			},
			{
				"name": "entityHit",
				"obfuscated": "field_72308_g",
				"signature": "Lnet/minecraft/entity/Entity;",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/util/MovingObjectPosition$MovingObjectType": {
		"obfuscated": "net/minecraft/util/MovingObjectPosition$MovingObjectType",
		"fields": [
			{
				"name": "BLOCK",
				"obfuscated": "BLOCK",
				"signature": "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;",
				"static": true
			},
			{
				"name": "MISS",
				"obfuscated": "MISS",
				"signature": "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;",
				"static": true
			}
		],
		"methods": []
	},
	"net/minecraft/util/AxisAlignedBB": {
		"obfuscated": "net/minecraft/util/AxisAlignedBB",
		"fields": [
			{
				"name": "minX",
				"obfuscated": "field_72340_a",
				"signature": "D",
				"static": false
			},
			{
				"name": "minY",
				"obfuscated": "field_72338_b",
				"signature": "D",
				"static": false
			},
			{
				"name": "minZ",
				"obfuscated": "field_72339_c",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxX",
				"obfuscated": "field_72336_d",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxY",
				"obfuscated": "field_72337_e",
				"signature": "D",
				"static": false
			},
			{
				"name": "maxZ",
				"obfuscated": "field_72334_f",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/util/Timer": {
		"obfuscated": "net/minecraft/util/Timer",
		"fields": [
			{
				"name": "renderPartialTicks",
				"obfuscated": "field_74281_c",
				"signature": "F",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/client/multiplayer/PlayerControllerMP": {
		"obfuscated": "net/minecraft/client/multiplayer/PlayerControllerMP",
		"fields": [
			{
				"name": "curBlockDamageMP",
				"obfuscated": "field_78770_f",
				"signature": "F",
				"static": false
			}
		],
		"methods": [
			{
				"name": "attackEntity",
				"obfuscated": "func_78764_a",
				"signature": "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/entity/Entity;)V",
				"static": false
			},
			{
				"name": "windowClick",
				"obfuscated": "func_78753_a",
				"signature": "(IIIILnet/minecraft/entity/player/EntityPlayer;)Lnet/minecraft/item/ItemStack;",
				"static": false
			}
		]
	},
	"net/minecraft/client/network/NetHandlerPlayClient": {
		"obfuscated": "net/minecraft/client/network/NetHandlerPlayClient",
		"fields": [],
		"methods": [
			{
				"name": "addToSendQueue",
				"obfuscated": "func_147297_a",
				"signature": "(Lnet/minecraft/network/Packet;)V",
				"static": false
			}
		]
	},
	"net/minecraft/item/Item": {
		"obfuscated": "net/minecraft/item/Item",
		"fields": [],
		"methods": []
	},
	"net/minecraft/item/ItemStack": {
		"obfuscated": "net/minecraft/item/ItemStack",
		"fields": [],
		"methods": [
			{
				"name": "getItem",
				"obfuscated": "func_77973_b",
				"signature": "()Lnet/minecraft/item/Item;",
				"static": false
			}
		]
	},
	"net/minecraft/item/ItemArmor": {
		"obfuscated": "net/minecraft/item/ItemArmor",
		"fields": [
			{
				"name": "armorType",
				"obfuscated": "field_77881_a",
				"signature": "I",
				"static": false
			},
			{
				"name": "damageReduceAmount",
				"obfuscated": "field_77879_b",
				"signature": "I",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/network/play/client/C02PacketUseEntity": {
		"obfuscated": "net/minecraft/network/play/client/C02PacketUseEntity",
		"fields": [
			{
				"name": "ATTACK",
				"obfuscated": "ATTACK",
				"signature": "Lnet/minecraft/network/play/client/C02PacketUseEntity$Action;",
				"static": true
			}
		],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "Lnet/minecraft/entity/Entity;Lnet/minecraft/network/play/client/C02PacketUseEntity$Action;)V",
				"static": false
			}
		]
	},
	"net/minecraft/network/play/client/C0DPacketCloseWindow": {
		"obfuscated": "net/minecraft/network/play/client/C0DPacketCloseWindow",
		"fields": [],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "()V",
				"static": false
			}
		]
	},
	"net/minecraft/network/play/client/C03PacketPlayer": {
		"obfuscated": "net/minecraft/network/play/client/C03PacketPlayer",
		"fields": [
			{
				"name": "x",
				"obfuscated": "field_149479_a",
				"signature": "D",
				"static": false
			},
			{
				"name": "y",
				"obfuscated": "field_149477_b",
				"signature": "D",
				"static": false
			},
			{
				"name": "z",
				"obfuscated": "field_149478_c",
				"signature": "D",
				"static": false
			},
			{
				"name": "yaw",
				"obfuscated": "field_149476_e",
				"signature": "F",
				"static": false
			},
			{
				"name": "pitch",
				"obfuscated": "field_149473_f",
				"signature": "F",
				"static": false
			},
			{
				"name": "onGround",
				"obfuscated": "field_149474_g",
				"signature": "Z",
				"static": false
			},
			{
				"name": "moving",
				"obfuscated": "field_149480_h",
				"signature": "Z",
				"static": false
			},
			{
				"name": "rotating",
				"obfuscated": "field_149481_i",
				"signature": "Z",
				"static": false
			}
		],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "(Z)V",
				"static": false
			}
		]
	},
	"net/minecraft/network/play/client/C16PacketClientStatus": {
		"obfuscated": "net/minecraft/network/play/client/C16PacketClientStatus",
		"fields": [
			{
				"name": "OPEN_INVENTORY_ACHIEVEMENT",
				"obfuscated": "OPEN_INVENTORY_ACHIEVEMENT",
				"signature": "Lnet/minecraft/network/play/client/C16PacketClientStatus$EnumState;",
				"static": true
			}
		],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "(Lnet/minecraft/network/play/client/C16PacketClientStatus$EnumState;)V",
				"static": false
			}
		]
	},
	"net/minecraft/network/play/client/C03PacketPlayer$C04PacketPlayerPosition": {
		"obfuscated": "net/minecraft/network/play/client/C03PacketPlayer$C04PacketPlayerPosition",
		"fields": [],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "(DDDZ)V",
				"static": false
			}
		]
	},
)"
R"(
	"net/minecraft/network/play/client/C03PacketPlayer$C05PacketPlayerLook": {
		"obfuscated": "net/minecraft/network/play/client/C03PacketPlayer$C05PacketPlayerLook",
		"fields": [],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "(FFZ)V",
				"static": false
			}
		]
	},
	"net/minecraft/network/play/client/C03PacketPlayer$C06PacketPlayerPosLook": {
		"obfuscated": "net/minecraft/network/play/client/C03PacketPlayer$C06PacketPlayerPosLook",
		"fields": [],
		"methods": [
			{
				"name": "<init>",
				"obfuscated": "<init>",
				"signature": "(DDDFFZ)V",
				"static": false
			}
		]
	},
	"net/minecraft/client/gui/GuiScreen": {
		"obfuscated": "net/minecraft/client/gui/GuiScreen",
		"fields": [],
		"methods": []
	},
	"net/minecraft/client/renderer/entity/RenderManager": {
		"obfuscated": "net/minecraft/client/renderer/entity/RenderManager",
		"fields": [
			{
				"name": "playerRenderer",
				"obfuscated": "field_178637_m",
				"signature": "Lnet/minecraft/client/renderer/entity/RenderPlayer;",
				"static": false
			},
			{
				"name": "renderPosX",
				"obfuscated": "field_78725_b",
				"signature": "D",
				"static": false
			},
			{
				"name": "renderPosY",
				"obfuscated": "field_78726_c",
				"signature": "D",
				"static": false
			},
			{
				"name": "renderPosZ",
				"obfuscated": "field_78723_d",
				"signature": "D",
				"static": false
			}
		],
		"methods": []
	},
	"net/minecraft/client/renderer/ActiveRenderInfo": {
		"obfuscated": "net/minecraft/client/renderer/ActiveRenderInfo",
		"fields": [
			{
				"name": "MODELVIEW",
				"obfuscated": "field_178812_b",
				"signature": "Ljava/nio/FloatBuffer;",
				"static": true
			},
			{
				"name": "PROJECTION",
				"obfuscated": "field_178813_c",
				"signature": "Ljava/nio/FloatBuffer;",
				"static": true
			}
		],
		"methods": []
	}
}
)";
}