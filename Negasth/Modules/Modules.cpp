#include "Modules.h"

Negasth::Modules::IModule::IModule(const char* name) {
	this->name = name;
}

void Negasth::Modules::IModule::run() {
	
}

void Negasth::Modules::runModules() {
	for (Category& category : categories) {
		for (IModule* module : category.modules) {
			module->run();
		}
	}
}