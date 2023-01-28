#pragma once
#include <string>

class Logger
{
public:
    static auto log(char type, const std::string& msg) -> void;
    // template<typename T>
    // static void log(const T&);
private:
    static auto currentDateTime() -> std::string;
};

#define LOG_DEBUG(msg) Logger::log('I',msg)
// Todo:
// #define LOG(msg) Logger::log(msg)
