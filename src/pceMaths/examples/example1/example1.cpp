#include <pceLogger/pceLogger.hpp>
#include <pceMaths/quaternion_functions.hpp>
//#include <glm/vec3.hpp>


int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);
    using namespace std;

    string ln = "pceMaths_ex1";
    cout << "Running: pceMaths example1\n";

    const glm::dvec3 a{ 1, 0, 0 };
    //const glm::dquat q{ 1, 0, 0, 1 };
    const glm::dquat q{ 8, 0, 0, -1 };
    const glm::dvec3 v = pce::rotateVector3byQuaternion(a, q);
    cout << "input: " << a.x << ", " << a.y << ", " << a.z << '\n';
    cout << "input magnitude: " << glm::length(a) << '\n';
    cout << "quat: " << q.w << ", " << q.x << ", " << q.y << ", " << q.z << '\n';
    cout << "result: " << v.x << ", " << v.y << ", " << v.z << '\n';
    cout << "result magnitude: " << glm::length(v) << '\n';

    cout << "Done Running: example1\n";
    return 0;
}
