#include "Modules.h"
#include "../Cache/Cache.h"
#include "../Negasth.h"

void Negasth::Modules::CheckPackets::run() {

	if (!packetsList.empty()) {
		std::chrono::seconds timeNow = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch());

		for (auto it = packetsList.rbegin(); it != packetsList.rend();) {
			if (timeNow - (std::chrono::seconds)(*it) >= coolDownSecond) {
				it = std::list<std::chrono::seconds>::reverse_iterator(packetsList.erase(std::next(it).base()));
			}
			else {
				break;
			}
		}
	}
}