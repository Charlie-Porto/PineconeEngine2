#include <pceLogger/pceLogger.hpp>
#include <pceMaths/quaternion_functions.hpp>
//#include <glm/vec3.hpp>


int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);
    std::string ln = "pceMaths_ex1";
    LOG_INFO(ln) << "Running: pceMaths example1";

    const glm::dvec3 a{ 1, 0, 0 };
    //const glm::dquat q{ 1, 0, 0, 1 };
    const glm::dquat q{ 8, 0, 0, -1 };
    const glm::dvec3 v = pce::rotateVector3byQuaternion(a, q);
    LOG_INFO(ln) << "input: " << a.x << ", " << a.y << ", " << a.z;
    LOG_INFO(ln) << "input magnitude: " << glm::length(a);
    LOG_INFO(ln) << "quat: " << q.w << ", " << q.x << ", " << q.y << ", " << q.z;
    LOG_INFO(ln) << "result: " << v.x << ", " << v.y << ", " << v.z;
    LOG_INFO(ln) << "result magnitude: " << glm::length(v);

    LOG_INFO(ln) << "Done Running: example1";
    return 0;
}
