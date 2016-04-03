#ifndef CONFIG_H
#define CONFIG_H

#pragma once

#include <string>

static const size_t WIDTH_WINDOW = 960;
static const size_t HEIGHT_WINDOW = 640;

namespace Buttons
{
	static const std::string PATH_TEXTURE = "Buttons/";

	static const std::string RETRY_BUTTON = PATH_TEXTURE + "Retry_Button.png";
	static const std::string RETRY_BUTTON_CLICK = PATH_TEXTURE + "Retry_Button_Click.png";

	static const std::string MENU_BUTTON = PATH_TEXTURE + "Menu_Button.png";
	static const std::string MENU_BUTTON_CLICK = PATH_TEXTURE + "Menu_Button_Click.png";

	static const std::string RESUME_BUTTON = PATH_TEXTURE + "Resume_Button.png";
	static const std::string RESUME_BUTTON_CLICK = PATH_TEXTURE + "Resume_Button_Click.png";

	static const std::string PAUSE_BUTTON = PATH_TEXTURE + "Pause_Button.png";
	static const std::string PAUSE_BUTTON_CLICK = PATH_TEXTURE + "Pause_Button_Click.png";

	static const std::string PLAY_BUTTON = PATH_TEXTURE + "Play_Button.png";
	static const std::string PLAY_BUTTON_CLICK = PATH_TEXTURE + "Play_Button_Click.png";

	static const std::string EXIT_BUTTON = PATH_TEXTURE + "Exit_Button.png";
	static const std::string EXIT_BUTTON_CLICK = PATH_TEXTURE + "Exit_Button_Click.png";

}

namespace GameoverTexture
{
	static const std::string PATH_TEXTURE = "GameOverScreen/";

	static const std::string MENU_TITLE = PATH_TEXTURE + "Game_Over.png";
	static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";
}

namespace MainMenuTexture
{
	static const std::string PATH_TEXTURE = "MainMenuScreen/";

static const std::string GAME_TITLE = PATH_TEXTURE + "Game_Title.png";
static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";
}

namespace PauseSceneTexture
{
	static const std::string PATH_TEXTURE = "PauseScreen/";

	static const std::string BACKGROUND = PATH_TEXTURE + "Background.png";
}

#endif