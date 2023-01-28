#pragma once
#include <string>
#include <fstream>

class Logger
{
public:
    static void log(char type, const std::string& msg);
    // template<typename T>
    // static void log(const T&);
private:
    static std::string currentDateTime();
};

#define LOG_DEBUG(msg) Logger::log('I',msg)
// Todo:
// #define LOG(msg) Logger::log(msg)
