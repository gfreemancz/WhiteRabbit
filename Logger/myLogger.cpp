
#include "myLogger.hpp"
#include <cstdarg>
#include <iostream>
#include <memory>
#include <iomanip>
#include <fstream>

namespace nsWhiteRabbit
// Logger implementation for WhiteRabbit project
{

  std::string cLogger::sColorReset =  "\033[0m";
  std::string cLogger::sColorRed =    "\033[31m";
  std::string cLogger::sColorGreen =  "\033[32m";
  std::string cLogger::sColorYellow = "\033[33m";
  std::string cLogger::sColorCyan =   "\033[36m";
 

  std::shared_ptr<std::string> cLogger::ptr_UsedColor;

  std::vector<char> buffer(MY_LOGGER_BUFFER_SIZE);

  //cLogger::m_outputStream = &std::cerr;
  std::unique_ptr<std::ostream> cLogger::m_outputStream = std::make_unique<std::ostream>(std::cerr.rdbuf());
  std::unique_ptr<std::ofstream> cLogger::m_logFile;

  void cLogger::InitFileLog(const std::string& arg_filePath)
  {
    m_logFile = std::make_unique<std::ofstream>(arg_filePath, std::ios::app);
    cLogger::m_outputStream = std::make_unique<std::ostream>(m_logFile->rdbuf());
    (*m_outputStream) << "           New Logging Session" << std::endl;
    sColorReset.clear();
    sColorRed.clear();
    sColorGreen.clear();
    sColorYellow.clear();
    sColorCyan.clear();
  }

  /**
   * @brief Formats and writes a log message to stderr with timestamp and color.
   * @param message Format string (like printf).
   * @param args va_list containing arguments for formatting.
   * @return void
   */

  void cLogger::WriteLogMsg(const std::string &message, va_list args, const char *arg_fileName, int arg_lineNumber)
  {
    int written = vsnprintf(buffer.data(), buffer.size(), message.c_str(), args);
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    if (written < 0 || static_cast<size_t>(written) >= buffer.size()) {
      (*m_outputStream) << std::put_time(&tm, "%Y-%m-%d %H:%M:%S ") << sColorRed << "defined buffer is too small for this message" << sColorReset << std::endl;
    }
    else
    {
      std::string formattedMessage(buffer.data());
      (*m_outputStream) << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S ") << "] "
                 << "[" << arg_fileName << " : " << arg_lineNumber << "] "
                  << *ptr_UsedColor << formattedMessage << sColorReset << std::endl;
    }
  }

  /**
   * @brief Logs an error message in red color.
   * @param message Format string (like printf).
   * @param ... Variable arguments for formatting.
   * @return void
   */
	void LogError(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...)
	{
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorRed);
    cLogger::WriteLogMsg(message, args, arg_fileName, arg_lineNumber);
    va_end(args);
	}
	

  /**
   * @brief Logs a warning message in yellow color.
   * @param message Format string (like printf).
   * @param ... Variable arguments for formatting.
   * @return void
   */
	void LogWarn(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...)
  {
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorYellow);
    cLogger::WriteLogMsg(message, args, arg_fileName, arg_lineNumber);
    va_end(args);
	}

  /**
   * @brief Logs an informational message in green color.
   * @param message Format string (like printf).
   * @param ... Variable arguments for formatting.
   * @return void
   */
	void LogInfo(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...)
  {
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorGreen);
    cLogger::WriteLogMsg(message, args, arg_fileName, arg_lineNumber);
    va_end(args);
	}

  /**
   * @brief Logs a trace/debug message in cyan color.
   * @param message Format string (like printf).
   * @param ... Variable arguments for formatting.
   * @return void
   */
	void LogTrace(const char* arg_fileName ,int arg_lineNumber,const std::string& message, ...)
  {
    va_list args;
    va_start(args, message);
    cLogger::ptr_UsedColor = std::make_shared<std::string>(cLogger::sColorCyan);
    cLogger::WriteLogMsg(message, args, arg_fileName, arg_lineNumber);
    va_end(args);
	}

  void InitFileLog(const std::string& arg_filePath)
  {
    cLogger::InitFileLog(arg_filePath);
  }

}



