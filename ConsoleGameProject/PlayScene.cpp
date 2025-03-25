#include <stdio.h>
#include "Game.h"
#include "Floor1Scene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace Floor1 {
	// Map
    const char* floor1Map[] = {
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                    Current Floor : 1                       ",
    "                  이 정도는 거뜬하겠지?                       ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "############################################################",
    "#                                                          #",
    "#                                                     G    #",
    "#                                              ============#",
    "#                                                          #",
    "#                                                          #",
    "#                                     ============         #",
    "#                                                          #",
    "#                                                          #",
    "#                           ============                   #",
    "#                                                          #",
    "#                                                          #",
    "#                 ============                             #",
    "#                                                          #",
    "#                                                          #",
    "#         ============                                     #",
    "#                                                          #",
    "#                                                          #",
    "#============                                              #",
    "#                                                          #",
    "#                                                          #",
    "#            ============                                  #",
    "#                                                          #",
    "#                                                          #",
    "#                       ============                       #",
    "#                                                          #",
    "#                                                          #",
    "#                                   ============           #",
    "#                                                          #",
    "#                                                          #",
    "#                                              ============#",
    "#                                                          #",
    "#                                                          #",
    "#                                     ============         #",
    "#                                                          #",
    "#                                                          #",
    "#                              ============                #",
    "#                                                          #",
    "#                                                          #",
    "#                      ============                        #",
    "#                                                          #",
    "#                                                          #",
    "#              ============                                #",
    "#                                                          #",
    "#                                                          #",
    "#        ============                                      #",
    "#  P                                                       #",
    "#==========================================================#",
    "############################################################"
    };
    const int mapHeight = sizeof(floor1Map) / sizeof(floor1Map[0]);

    // Player
	COORD g_Player = { 0,0 };
	//bool g_bQuit = false;

	// Start
	void Initalize() {

	}

	// Update
	void Update() {
		// input & play controll
		ProcessInput();
		PlayerMove();

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}
	}

	// Render
	void Render() {
		//ConsoleRenderer::ScreenDrawString(0, 0, "PLAY SCENE  [Spacebar]", FG_RED);
		//ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_WHITE);
        for (int i = 0; i < mapHeight; i++)
        {
            ConsoleRenderer::ScreenDrawString(0, i, floor1Map[i], FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        
	}

	void ProcessInput()
	{
		if (Input::IsKeyDown(VK_LEFT)) {
			g_Player.X--;
		}
		if (Input::IsKeyDown(VK_RIGHT)) {
			g_Player.X++;
		}
		if (Input::IsKeyDown(VK_UP)) {
			g_Player.Y--;
		}
		if (Input::IsKeyDown(VK_DOWN)) {
			g_Player.Y++;
		}
		/*if (Input::IsKeyDown(VK_ESCAPE)) {
			g_bQuit = true;
		}*/
	}

	void PlayerMove() {
		if (g_Player.X < 0) g_Player.X = 0;
		if (g_Player.X >= ConsoleRenderer::ScreenWidth()) g_Player.X = ConsoleRenderer::ScreenWidth() - 1;
		if (g_Player.Y < 0) g_Player.Y = 0;
		if (g_Player.Y >= ConsoleRenderer::ScreenHeight()) g_Player.Y = ConsoleRenderer::ScreenHeight() - 1;
	}
}
