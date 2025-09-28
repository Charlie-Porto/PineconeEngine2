#include <pceLogger.hpp>

int main()
{
    LOG_DEBUG("TEST") << "Doing test of debug level.";
    LOG_INFO("TEST") << "Doing test of info level.";
    LOG_WARNING("TEST") << "Doing test of warning level.";
    LOG_ERROR("TEST") << "Doing test of error level.";


    std::cout << '\n';
    return 0;
}

