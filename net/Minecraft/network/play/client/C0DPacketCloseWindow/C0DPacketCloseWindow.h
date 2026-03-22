#pragma once
#include "../../../Packet/Packet.h"

class C0DPacketCloseWindow : public Packet
{
public:
	using Packet::Packet;
	static C0DPacketCloseWindow newObject(JNIEnv* env = Negasth::p_env); 
protected:
	inline static Negasth::JavaClass C0DPacketCloseWindowClass{ "net/minecraft/network/play/client/C0DPacketCloseWindow" };
};