<<<<<<< HEAD
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
=======
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
>>>>>>> 25b80edf9ffd5686f0a11402a7139f3c9973eb87
}