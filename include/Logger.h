// #ifndef LOGGER_H
// #define LOGGER_H

// #include <string>

// enum class LogLevel {
//     INFO,
//     WARNING,
//     error_info
// };

// class Logger {
// public:
//     static void log(const std::string &message, LogLevel level);
// };

// #endif // LOGGER_H
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

class Logger
{
public:
    enum class LogLevel
    {
        INFO,
        WARNING,
        error_info
    };

    static void log(const std::string &message, LogLevel level);
};

#endif // LOGGER_H
