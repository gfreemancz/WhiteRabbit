
#pragma once


#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif


namespace nsWhiteRabbit
{
  template<typename... Args>
	MYLIBRARY_API void LogError(Args... args);
	
  template<typename... Args>
	MYLIBRARY_API void LogWarn(Args... args);
	
  template<typename... Args>
	MYLIBRARY_API void LogInfo(Args... args);
	
  template<typename... Args>
	MYLIBRARY_API void LogTrace(Args... args);


  MYLIBRARY_API void LoggerInit(void);
}



#define  WR_LOG_ERROR(...)  ::nsWhiteRabbit::LogError(__VA_ARGS__)
#define  WR_LOG_TRACE(...)  ::nsWhiteRabbit::LogTrace(__VA_ARGS__)
#define  WR_LOG_WARN(...)   ::nsWhiteRabbit::LogWarn(__VA_ARGS__)
#define  WR_LOG_INFO(...)   ::nsWhiteRabbit::LogInfo(__VA_ARGS__)