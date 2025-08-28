
#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#define MY_LOGGER_BUFFER_SIZE 1024


namespace nsWhiteRabbit
{


  class cLogger
  {
    public:

    static void WriteLogMsg(const std::string& message, ...);
    static std::shared_ptr<std::string> ptr_UsedColor;
    static const std::string sColorReset;
    static const std::string sColorRed;
    static const std::string sColorGreen;
    static const std::string sColorYellow;
    static const std::string sColorBlue;
    static const std::string sColorMagenta;
    static const std::string sColorCyan;
    static const std::string sColorWhite;
    
    

  };
}


// #define  WR_LOG_ERROR(...)  ::nsWhiteRabbit::clogger::GetClientLogger()->error(__VA_ARGS__)
// #define  WR_LOG_TRACE(...)  ::nsWhiteRabbit::clogger::GetClientLogger()->trace(__VA_ARGS__)
// #define  WR_LOG_WARN(...)   ::nsWhiteRabbit::clogger::GetClientLogger()->warn(__VA_ARGS__)
// #define  WR_LOG_INFO(...)   ::nsWhiteRabbit::clogger::GetClientLogger()->info(__VA_ARGS__)