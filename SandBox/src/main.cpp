
#include <iostream>
#include "myLogger_ifx.hpp"
#include "wrWindow.hpp"

#include <SDL2/SDL.h>

nsWhiteRabbit::cWindow_WR * G_Wokynko = nullptr;

int main(int argc, char** argv) 
{
  nsWhiteRabbit::LoggerInit();
  WR_LOG_INFO("hello white rabbit logging system");

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		WR_LOG_ERROR("SDL could not initialize! SDL_Error:",SDL_GetError() );
	}
  else
  {
   // WR_LOG_INFO("SDL initialized succesfuly");
    G_Wokynko = new nsWhiteRabbit::cWindow_WR("Imaginarium V0.1.0", 100, 100, 800, 600);
  }

 

  return 0;
}
