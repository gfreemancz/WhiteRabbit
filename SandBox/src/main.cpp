
#include <iostream>
#include "myLogger_ifx.hpp"
#include "wrWindow.hpp"

#include <SDL2/SDL.h>

#ifndef _MY_LOG_TO_FILE
  #define _MY_LOG_TO_FILE 0
#endif

nsWhiteRabbit::cWindow_WR * G_Wokynko = nullptr;

int main(int argc, char** argv) 
{
  #if (_MY_LOG_TO_FILE == 1)
  WR_INIT_FILE_LOG("log.txt");
  #endif

  WR_LOG_INFO("hello white rabbit logging system");

  WR_LOG_ERROR("test of error logging: %d", 42);
  WR_LOG_WARN("test of warning logging: %d", 42);
  WR_LOG_TRACE("test of trace logging: %d", 42);

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		WR_LOG_ERROR("SDL could not initialize! SDL_Error: %s", SDL_GetError());
	}
  else
  {
    WR_LOG_INFO("SDL initialized succesfuly");
    G_Wokynko = new nsWhiteRabbit::cWindow_WR("Imaginarium V0.1.0", 100, 100, 800, 600);
  }

 

  return 0;
}
