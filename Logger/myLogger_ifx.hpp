
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
  MYLIBRARY_API void LogError(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...);

  MYLIBRARY_API void LogTrace(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...);

  MYLIBRARY_API void LogWarn(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...);

  MYLIBRARY_API void LogInfo(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...);

  MYLIBRARY_API void InitFileLog(const std::string& arg_filePath);
}

#define  WR_LOG_ERROR(...)  ::nsWhiteRabbit::LogError(__FILE__,__LINE__,__VA_ARGS__)
#define  WR_LOG_TRACE(...)  ::nsWhiteRabbit::LogTrace(__FILE__,__LINE__,__VA_ARGS__)
#define  WR_LOG_WARN(...)   ::nsWhiteRabbit::LogWarn(__FILE__,__LINE__,__VA_ARGS__)
#define  WR_LOG_INFO(...)   ::nsWhiteRabbit::LogInfo(__FILE__,__LINE__,__VA_ARGS__)
#define  WR_INIT_FILE_LOG(...)   ::nsWhiteRabbit::InitFileLog(__VA_ARGS__)