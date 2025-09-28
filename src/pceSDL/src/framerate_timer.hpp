#ifndef framerate_timer_hpp
#define framerate_timer_hpp
/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
purpose: a simple timer for observing frame rate.
-----------------------------------------------------------------*/

namespace pce {

class framerate_timer
{
    int seconds_since_start_ = 0;
    int loops_this_second_ = 0;
public:
    void update(int new_seconds_since_start);
};

} /* namespace pce */

#endif /* framerate_timer_hpp */
