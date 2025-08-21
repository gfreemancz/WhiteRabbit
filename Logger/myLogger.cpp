
#include "myLogger.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace nsWhiteRabbit
{

  std::shared_ptr<spdlog::logger> cLogger::sClientLogger;

  void cLogger::Init(void)
  {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    sClientLogger = spdlog::stdout_color_mt("White Rabbit");
    sClientLogger->set_level(spdlog::level::trace);
  }

  void LoggerInit(void)
  {
    cLogger::Init();
  }
  
  template<typename... Args>
	void LogError(Args... args)
  {
		cLogger::GetClientLogger()->error((args)...);
	}
	
  template<typename... Args>
	void LogWarn(Args... args) 
  {
		cLogger::GetClientLogger()->warn((args)...);
	}
	
  template<typename... Args>
	void LogInfo(Args... args)
  {
		cLogger::GetClientLogger()->info((args)...);
	}
	
  template<typename... Args>
	void LogTrace(Args... args) 
  {
		cLogger::GetClientLogger()->trace((args)...);
	}

}



