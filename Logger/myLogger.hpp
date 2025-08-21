
#pragma once

#include "memory"
#include "spdlog/spdlog.h"


namespace nsWhiteRabbit
{
  class cLogger
  {
    public:
    static void Init(void);
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return sClientLogger;}

    private:
    static std::shared_ptr<spdlog::logger> sClientLogger;

  };
}


// #define  WR_LOG_ERROR(...)  ::nsWhiteRabbit::clogger::GetClientLogger()->error(__VA_ARGS__)
// #define  WR_LOG_TRACE(...)  ::nsWhiteRabbit::clogger::GetClientLogger()->trace(__VA_ARGS__)
// #define  WR_LOG_WARN(...)   ::nsWhiteRabbit::clogger::GetClientLogger()->warn(__VA_ARGS__)
// #define  WR_LOG_INFO(...)   ::nsWhiteRabbit::clogger::GetClientLogger()->info(__VA_ARGS__)