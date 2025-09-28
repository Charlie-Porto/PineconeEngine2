#ifndef LOGGING_MACROS_H
#define LOGGING_MACROS_H

#include <iostream>
#include <unordered_map>
#include <string>

//!< To enable debug logging in an executable that uses pceLogger, add
//!< `add_definitions(-DDEBUG)` to the top-level CMake.


#define LOG_V(x) (std::cout << '\n' << #x"=" << x)

namespace pce {
enum class LogLevel : int
{
    Debug = 0,
    Info = 1,
    Warning = 2,
    Error = 3,
    Fatal = 4
};
} //!< namespace pce
const std::unordered_map<pce::LogLevel, std::string> LogLevelStrings = {
    { pce::LogLevel::Debug, "DEBUG" },
    { pce::LogLevel::Info, "INFO" },
    { pce::LogLevel::Warning, "WARN" },
    { pce::LogLevel::Error, "ERROR" },
    { pce::LogLevel::Fatal, "FATAL" }
};

class LOG_PCE;
extern LOG_PCE mLOG_PCE;
extern pce::LogLevel LOG_LEVEL;

class LOG_PCE
{
public:
    pce::LogLevel current_level = pce::LogLevel::Debug;

    ~LOG_PCE()
    {
        std::cout << '\n';
    }
    LOG_PCE& operator()(const pce::LogLevel level, const char* label)
    {
#ifdef DEBUG
        current_level = level;
        if (static_cast<int>(current_level) >= static_cast<int>(LOG_LEVEL))
            std::cout << '\n' << "[" << LogLevelStrings.at(level) << "]\t(" << label << ") ";
#endif //!< #ifdef DEBUG
        return *this;
    }
    LOG_PCE& operator()(const pce::LogLevel level, const std::string label)
    {
        return operator()(level, label.c_str());
    }

    template<typename T> LOG_PCE& operator<<(T x)
    {
#ifdef DEBUG
        if (static_cast<int>(current_level) >= static_cast<int>(LOG_LEVEL))
            std::cout << x;
#endif //!< #ifdef DEBUG
        return *this;
    }
};


#define MLOG_PCE(level, label) ( mLOG_PCE(level, label) )

#define LOG_DEBUG(label) (MLOG_PCE(pce::LogLevel::Debug, label))
#define LOG_INFO(label) (MLOG_PCE(pce::LogLevel::Info, label))
#define LOG_WARNING(label) (MLOG_PCE(pce::LogLevel::Warning, label))
#define LOG_ERROR(label) (MLOG_PCE(pce::LogLevel::Error, label))
#define LOG_FATAL(label) (MLOG_PCE(pce::LogLevel::Fatal, label))



#endif //!< #ifndef LOGGING_MACROS_H
