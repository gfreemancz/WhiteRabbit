
#include "myLogger.hpp"
#include <cstdarg>
#include <iostream>
#include <memory>
#include <iomanip>

namespace nsWhiteRabbit
{

  const std::string cLogger::sColorReset =  "\033[0m";
  const std::string cLogger::sColorRed =    "\033[31m";
  const std::string cLogger::sColorGreen =  "\033[32m";
  const std::string cLogger::sColorYellow = "\033[33m";
  const std::string cLogger::sColorBlue =   "\033[34m";
  const std::string cLogger::sColorMagenta ="\033[35m";
  const std::string cLogger::sColorCyan =  "\033[36m";
  const std::string cLogger::sColorWhite = "\033[37m";

  std::shared_ptr<std::string> cLogger::ptr_UsedColor;

  std::vector<char> buffer(MY_LOGGER_BUFFER_SIZE);


  void cLogger::WriteLogMsg(const std::string& message, ...)
  {
    
    va_list args;
    va_start(args, message);
    int written = vsnprintf(buffer.data(), buffer.size(), message.c_str(), args);
    va_end(args);
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    if (written < 0 || static_cast<size_t>(written) >= buffer.size()) {
      std::cerr  << std::put_time(&tm, "%Y-%m-%d %H:%M:%S ") << sColorRed << "defined buffer is too small for this message" << sColorReset << std::endl;
    }
    else
    {
      std::string formattedMessage(buffer.data());
      std::cerr  << std::put_time(&tm, "%Y-%m-%d %H:%M:%S ") << *ptr_UsedColor << formattedMessage << sColorReset << std::endl;
    }
  }

	void LogError(const std::string& message, ...)
	{
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorRed);
    cLogger::WriteLogMsg(message, args);
    va_end(args);
	}
	

	void LogWarn(const std::string& message, ...)
  {
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorYellow);
    cLogger::WriteLogMsg(message, args);
    va_end(args);
	}

	void LogInfo(const std::string& message, ...)
  {
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorGreen);
    cLogger::WriteLogMsg(message, args);
    va_end(args);
	}

	void LogTrace(const std::string& message, ...)
  {
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorCyan);
    cLogger::WriteLogMsg(message, args);
    va_end(args);
	}

}



