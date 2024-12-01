// #include "Logger.h"
// #include <iostream>

// void Logger::log(const std::string &message, LogLevel level)
// {
//     std::string levelStr;
//     switch (level)
//     {
//     case LogLevel::INFO:
//         levelStr = "INFO";
//         break;
//     case LogLevel::WARNING:
//         levelStr = "WARNING";
//         break;
//     case LogLevel::ERROR:
//         levelStr = "ERROR";
//         break;
//     }
//     std::cout << "[" << levelStr << "] " << message << std::endl;
// }
#include "Logger.h"
#include <iostream>

void Logger::log(const std::string &message, Logger::LogLevel level)
{
    switch (level)
    {
    case Logger::LogLevel::INFO:
        std::cout << "[INFO]: " << message << std::endl;
        break;
    case Logger::LogLevel::WARNING:
        std::cout << "[WARNING]: " << message << std::endl;
        break;
    case Logger::LogLevel::error_info:
        std::cerr << "[ERROR]: " << message << std::endl;
        break;
    default:
        std::cerr << "[UNKNOWN]: " << message << std::endl;
        break;
    }
}
