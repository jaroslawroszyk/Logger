#include "logger.hpp"
#include <iostream>
#include <ctime>
#include <ostream>
#include <fstream>
#include <type_traits>
#include <experimental/filesystem>

using namespace std::experimental::filesystem;

template <typename T>
    requires std::is_same_v<T, std::fstream> bool
checkFile(T &file)
{
    if (not file)
        throw std::runtime_error("Failed to open file");
    return file.is_open();
}

void Logger::log(char type, const std::string &msg)
{
    std::string fileName = "foo.log";
    static std::fstream file(fileName, std::ios::out);
    checkFile(file);

    switch (type)
    {
    case 'I':
        file << "INFO\t" << currentDateTime() << "\t\t" << msg << std::endl;
    }
    file.close();
}

// template <typename T>
// void Logger::log(const T &)
// {
//     static std::ifstream file("dupa.log", std::ios::out);
//     if (!file.is_open())
//     {
//         throw "foo";
//     }
// }

//todo improve
std::string Logger::currentDateTime()
{
    std::time_t now = time(nullptr);
    struct tm tstruct{};
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}