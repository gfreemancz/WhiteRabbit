
#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#define MY_LOGGER_BUFFER_SIZE 1024


namespace nsWhiteRabbit
{


  class cLogger
  {
    public:
    static void InitFileLog(const std::string& arg_filePath);
    static void WriteLogMsg(const std::string& message, va_list args,const char* arg_fileName ,int arg_lineNumber);
    static std::shared_ptr<std::string> ptr_UsedColor;
    static std::unique_ptr<std::ostream> m_outputStream;
    static std::unique_ptr<std::ofstream> m_logFile;

    static  std::string sColorReset;
    static  std::string sColorRed;
    static  std::string sColorGreen;
    static  std::string sColorYellow;
    static  std::string sColorCyan;
  };
}
