#ifndef CameraOperatorSystem_hpp
#define CameraOperatorSystem_hpp

#include <pceCamera/camera.hpp>
#include <pceUtils/virtual_keyboard.hpp>


namespace pce {

class CameraOperatorSystem
{
public:
    void update(Camera&, VirtualKeyboard);
};


} /* namespace pce */
#endif /* CameraOperatorSystem_hpp */
