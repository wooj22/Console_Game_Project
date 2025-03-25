#include <stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace Menu {
    // Map
    const char* menuMap[] = {
    "                                                            ", 
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                         TOWER OF 7                         ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "############################################################",
    "#                       ^                                  #",
    "#                      / \\                                 #",
    "#                     /   \\                                #",
    "#                    /     \\                               #",
    "#                   /       \\                              #",
    "#                  /         \\                             #",
    "#                 /___________\\                            #",
    "#                  |         |                             #",
    "#                  |    7    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                  |         |                             #",
    "#                  |    6    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                  |         |                             #",
    "#                  |    5    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                  |         |                             #",
    "#                  |    4    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                  |         |                             #",
    "#                  |    3    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                  |         |                             #",
    "#                  |    2    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                  |         |                             #",
    "#                  |    1    |                             #",
    "#                  |         |                             #",
    "#                  |_________|                             #",
    "#                      |||                                 #",
    "#                      |||                                 #",
    "#                      |||                                 #",
    "#                      |||                                 #",
    "#                      |||                                 #",
    "############################################################",
    "############################################################",
    "############################################################",
    "############################################################",
    "############################################################",
    "############################################################",
    "############################################################",
    "############################################################"
    };
    const int mapHeight = sizeof(menuMap) / sizeof(menuMap[0]);

	// Start
	void Initalize() {

	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::PLAY_SCENE;
			Play::Initalize();
		}
	}

	// Render
	void Render() {
        for (int i = 0; i < mapHeight; i++)
        {
            ConsoleRenderer::ScreenDrawString(0, i, menuMap[i], FG_YELLOW);
        }
	}
}
