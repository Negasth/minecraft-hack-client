#pragma once
#include "MinHook/MinHook.h"
#include "iostream"
#include "gl/GL.h"  
#include "../net/Minecraft/Client/Renderer/ActiveRenderInfo.h"


namespace Negasth::glHOOK {

	typedef BOOL(__stdcall* twglSwapBuffers)(HDC hdc);
	twglSwapBuffers owglSwapBuffers;

	JNIEnv* renderEnv = NULL;
	void* swapbuffer;
	inline GLfloat* PROJECTION;
	inline GLfloat* MODELVIEW;

	void DrawHealth(float curHealth,float maxHealth, double minX, double minY, double minZ, double maxX, double maxY, double maxZ, float r, float g, float b) {
		minX -= cache->theRenderManager.getRenderPosX(renderEnv);
		minY -= cache->theRenderManager.getRenderPosY(renderEnv);
		minZ -= cache->theRenderManager.getRenderPosZ(renderEnv);
		maxX -= cache->theRenderManager.getRenderPosX(renderEnv);
		maxY -= cache->theRenderManager.getRenderPosY(renderEnv);
		maxZ -= cache->theRenderManager.getRenderPosZ(renderEnv);

		//maxY /= 2;
		float per = curHealth / maxHealth;
		double suby = maxY - minY;
		maxY = minY + suby * per;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(r, g, b, 0.3f);

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, minZ);
		glVertex3d(maxX, minY, minZ);
		glVertex3d(maxX, maxY, minZ);
		glVertex3d(minX, maxY, minZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, minZ);
		glVertex3d(minX, minY, maxZ);
		glVertex3d(minX, maxY, maxZ);
		glVertex3d(minX, maxY, minZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, minZ);
		glVertex3d(maxX, minY, minZ);
		glVertex3d(maxX, minY, maxZ);
		glVertex3d(minX, minY, maxZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(maxX, minY, minZ);
		glVertex3d(maxX, maxY, minZ);
		glVertex3d(maxX, maxY, maxZ);
		glVertex3d(maxX, minY, maxZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, maxY, minZ);
		glVertex3d(maxX, maxY, minZ);
		glVertex3d(maxX, maxY, maxZ);
		glVertex3d(minX, maxY, maxZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, maxZ);
		glVertex3d(maxX, minY, maxZ);
		glVertex3d(maxX, maxY, maxZ);
		glVertex3d(minX, maxY, maxZ);
		glEnd();
	}

	void DrawBox(double minX,double minY,double minZ,double maxX,double maxY,double maxZ,float r,float g,float b) {
		minX -= cache->theRenderManager.getRenderPosX(renderEnv);
		minY -= cache->theRenderManager.getRenderPosY(renderEnv);
		minZ -= cache->theRenderManager.getRenderPosZ(renderEnv);
		maxX -= cache->theRenderManager.getRenderPosX(renderEnv);
		maxY -= cache->theRenderManager.getRenderPosY(renderEnv);
		maxZ -= cache->theRenderManager.getRenderPosZ(renderEnv);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(r, g, b, 0.2f);

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, minZ);
		glVertex3d(maxX, minY, minZ);
		glVertex3d(maxX, maxY, minZ);
		glVertex3d(minX, maxY, minZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, minZ);
		glVertex3d(minX, minY, maxZ);
		glVertex3d(minX, maxY, maxZ);
		glVertex3d(minX, maxY, minZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, minZ);
		glVertex3d(maxX, minY, minZ);
		glVertex3d(maxX, minY, maxZ);
		glVertex3d(minX, minY, maxZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(maxX, minY, minZ);
		glVertex3d(maxX, maxY, minZ);
		glVertex3d(maxX, maxY, maxZ);
		glVertex3d(maxX, minY, maxZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, maxY, minZ);
		glVertex3d(maxX, maxY, minZ);
		glVertex3d(maxX, maxY, maxZ);
		glVertex3d(minX, maxY, maxZ);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3d(minX, minY, maxZ);
		glVertex3d(maxX, minY, maxZ);
		glVertex3d(maxX, maxY, maxZ);
		glVertex3d(minX, maxY, maxZ);
		glEnd();

	}

	void DrawBoxOutline(double minX, double minY, double minZ, double maxX, double maxY, double maxZ, float r, float g, float b) {
		minX -= cache->theRenderManager.getRenderPosX(renderEnv);
		minY -= cache->theRenderManager.getRenderPosY(renderEnv);
		minZ -= cache->theRenderManager.getRenderPosZ(renderEnv);
		maxX -= cache->theRenderManager.getRenderPosX(renderEnv);
		maxY -= cache->theRenderManager.getRenderPosY(renderEnv);
		maxZ -= cache->theRenderManager.getRenderPosZ(renderEnv);

		glLineWidth(3.0f);
		glColor4f(r, g, b, 1.0f);

		glBegin(GL_LINES);
		double vertices[8][3] = {
		{minX, minY, minZ},
		{maxX, minY, minZ},
		{maxX, maxY, minZ},
		{minX, maxY, minZ},
		{minX, minY, maxZ},
		{maxX, minY, maxZ},
		{maxX, maxY, maxZ},
		{minX, maxY, maxZ}
		};

		// 定义边连接  
		int edges[12][2] = {
			{0, 1}, {1, 2}, {2, 3}, {3, 0}, // 后面  
			{4, 5}, {5, 6}, {6, 7}, {7, 4}, // 前面  
			{0, 4}, {1, 5}, {2, 6}, {3, 7}  // 连接前后  
		};

		// 绘制边  
		for (int i = 0; i < 12; ++i) {
			glVertex3dv(vertices[edges[i][0]]);
			glVertex3dv(vertices[edges[i][1]]);
		}
		glEnd();

	}

	void Test(long w,long h){
		if (renderEnv == NULL) {
			if (Negasth::p_jvm->AttachCurrentThreadAsDaemon(reinterpret_cast<void**>(&renderEnv), nullptr) != JNI_OK) {
				return;
			}
		}

		PROJECTION = ActiveRenderInfo::Get_PROJECTION(renderEnv);
		MODELVIEW = ActiveRenderInfo::Get_MODELVIEW(renderEnv);

		glViewport(0, 0, w, h);
		glPushMatrix();

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(MODELVIEW);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(PROJECTION);
		glDisable(GL_DEPTH_TEST);

		if (Negasth::cache->playerEntities.isValid()) {
			for (EntityPlayer& target : Negasth::cache->playerEntities.toVector<EntityPlayer>(renderEnv))
			{
				if (!target.isValid() || target.isEqualto(cache->thePlayer) /*|| target.getTicksExisted() < 10*/)
					continue;



				//render esp
				AxisAlignedBB targetBB = target.getBoundingBox(renderEnv);
				double minx = targetBB.getMinX(renderEnv);
				double miny = targetBB.getMinY(renderEnv);
				double minz = targetBB.getMinZ(renderEnv);
				double maxx = targetBB.getMaxX(renderEnv);
				double maxy = targetBB.getMaxY(renderEnv);
				double maxz = targetBB.getMaxZ(renderEnv);
				float curHealth = target.getHealth(renderEnv);
				float maxHealth = target.getMaxHealth(renderEnv);

				DrawBox(minx, miny, minz, maxx, maxy, maxz, 0, 0, 0);
				DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 0, 0, 0);//外边框

				ScorePlayerTeam playerTeam{ target.getTeam(renderEnv).getInstance() };
				if (playerTeam.isValid()) {
					const char* teamName = playerTeam.getTeamName(renderEnv);
					if (strstr(teamName, "RED")) {
						DrawHealth(curHealth, maxHealth, minx, miny, minz, maxx, maxy, maxz, 1.0f, 0, 0);
						DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 1.0f, 0, 0);
					}
					else if (strstr(teamName, "YEL")) {
						DrawHealth(curHealth, maxHealth, minx, miny, minz, maxx, maxy, maxz, 1.0f, 1.0f, 0);
						DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 1.0f, 1.0f, 0);
					}
					else if (strstr(teamName, "BLU")) {
						DrawHealth(curHealth, maxHealth, minx, miny, minz, maxx, maxy, maxz, 0, 0, 1.0f);
						DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 0, 0, 1.0f);
					}
					else if (strstr(teamName, "GRE")) {
						DrawHealth(curHealth, maxHealth, minx, miny, minz, maxx, maxy, maxz, 0, 1.0f, 0);
						DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 0, 1.0f, 0);
					}
					else {
						DrawHealth(curHealth, maxHealth, minx, miny, minz, maxx, maxy, maxz, 0, 0, 0);
						DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 0, 0, 0);
					}
				}
				else {
					DrawHealth(curHealth, maxHealth, minx, miny, minz, maxx, maxy, maxz, 0, 0, 0);
					DrawBoxOutline(minx, miny, minz, maxx, maxy, maxz, 0, 0, 0);
				};

			}
		}


		glPopMatrix();
	}


	BOOL __stdcall wglSwapBuffers(HDC hdc) {
		static HGLRC oContent = wglGetCurrentContext();
		static HGLRC newContent = wglCreateContext(hdc);
		wglMakeCurrent(hdc, newContent);

		RECT rcClient;
		GetClientRect(WindowFromDC(hdc), &rcClient);
		long nWidth = rcClient.right - rcClient.left;
		long nHeight = rcClient.bottom - rcClient.top;
		Test(nWidth, nHeight);

		wglMakeCurrent(hdc, oContent);
		return owglSwapBuffers(hdc);
	}


	BOOL SetupHook() {
		MH_Initialize();

		HMODULE op32dll = GetModuleHandleA("opengl32.dll");
		if (op32dll == NULL) {
			std::cout << "GetModuleHandleA ErrorCode:" << GetLastError() << std::endl;
			return FALSE;
		}
		swapbuffer = (void*)GetProcAddress(op32dll, "wglSwapBuffers");
		if (swapbuffer == NULL) {
			std::cout << "GetProcAddress ErrorCode:" << GetLastError() << std::endl;
			return FALSE;
		}

		MH_CreateHook(swapbuffer, (LPVOID*)wglSwapBuffers, (LPVOID*) & owglSwapBuffers);
		MH_EnableHook(swapbuffer);
	}

	void removeHook() {
		MH_RemoveHook(swapbuffer);
	}
}