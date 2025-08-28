
#pragma once

#include <string>
#include <cstdarg>

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif


namespace nsWhiteRabbit
{
  MYLIBRARY_API void LogError(const std::string& message, ...);

  MYLIBRARY_API void LogWarn(const std::string& message, ...);

  MYLIBRARY_API void LogInfo(const std::string& message, ...);

  MYLIBRARY_API void LogTrace(const std::string& message, ...);


//  MYLIBRARY_API void LoggerInit(void);
}



#define  WR_LOG_ERROR(...)  ::nsWhiteRabbit::LogError(__VA_ARGS__)
#define  WR_LOG_TRACE(...)  ::nsWhiteRabbit::LogTrace(__VA_ARGS__)
#define  WR_LOG_WARN(...)   ::nsWhiteRabbit::LogWarn(__VA_ARGS__)
#define  WR_LOG_INFO(...)   ::nsWhiteRabbit::LogInfo(__VA_ARGS__)