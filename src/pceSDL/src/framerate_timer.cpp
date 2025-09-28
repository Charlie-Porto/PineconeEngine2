#include "framerate_timer.hpp"
#include <pceLogger/pceLogger.hpp>

namespace pce {
namespace {
const std::string log_name = "framerate_timer";
}

void framerate_timer::update(int new_seconds_since_start)
{
    if (new_seconds_since_start < seconds_since_start_ + 1)
        ++loops_this_second_;
    else
    {
        seconds_since_start_ = new_seconds_since_start;
        LOG_INFO(log_name) << "Time: " << seconds_since_start_ << "s" << "\tFrame Rate: " << loops_this_second_;
        loops_this_second_ = 0;
    }
}

} /* namespace pce */
