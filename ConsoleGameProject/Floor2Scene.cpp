﻿#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor2Scene.h"
#include "Floor3Scene.h"


namespace Floor2 {
	// Map Data
	const wchar_t* floor2StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	};
	const int mapHeight = sizeof(floor2StaticMap) / sizeof(floor2StaticMap[0]);


	// Start
	void Initalize() {

	}

	// Update
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR3_SCENE;
			Floor3::Initalize();
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor2StaticMap[i], FG_GRAY | FOREGROUND_INTENSITY);
		}
	}
}
