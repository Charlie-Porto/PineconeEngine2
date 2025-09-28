#include <pceLogger/pceLogger.hpp>
#include <pceMaths/quaternion_functions.hpp>

#include <string>

bool vec3StrToVec3(const std::string& v3str, glm::dvec3& v3vec)
{
    size_t start_num_pos = 0;
    size_t end_num_pos = 0;

    end_num_pos=v3str.find(",");
    if (end_num_pos == std::string::npos)
        return false;
    std::string ss = v3str.substr(start_num_pos, end_num_pos);
    LOG_DEBUG("quat_test_2") << "x substring: " << ss;
    v3vec.x = std::stod(ss);

    start_num_pos = end_num_pos;
    end_num_pos=v3str.find(",", start_num_pos);
    if (end_num_pos == std::string::npos)
        return false;
    ss = v3str.substr(start_num_pos+1, end_num_pos);
    LOG_DEBUG("quat_test_2") << "y substring: " << ss;
    v3vec.y = std::stod(ss);

    start_num_pos = v3str.find(",", end_num_pos+1);
    end_num_pos = std::string::npos;
    ss = v3str.substr(start_num_pos+1, end_num_pos);
    LOG_DEBUG("quat_test_2") << "z substring: " << ss;
    v3vec.z = std::stod(ss);

    return true;
}

bool quatStrToQduat(const std::string& qstr, glm::dquat& qquat)
{
    size_t start_num_pos = 0;
    size_t end_num_pos = 0;
    size_t i = 0;

    LOG_DEBUG("quat_test_2") << "start_num_pos: " << start_num_pos;
    end_num_pos=qstr.find(",");
    LOG_DEBUG("quat_test_2") << "end_num_pos: " << end_num_pos;
    i = end_num_pos - start_num_pos;
    if (end_num_pos == std::string::npos)
        return false;
    std::string ss = qstr.substr(start_num_pos, i);
    LOG_DEBUG("quat_test_2") << "w substring: " << ss;
    qquat.w = std::stod(ss);

    start_num_pos = end_num_pos+1;
    LOG_DEBUG("quat_test_2") << "start_num_pos: " << start_num_pos;
    end_num_pos=qstr.find(",", start_num_pos);
    i = end_num_pos - start_num_pos;
    LOG_DEBUG("quat_test_2") << "end_num_pos: " << end_num_pos;
    if (end_num_pos == std::string::npos)
        return false;
    ss = qstr.substr(start_num_pos, i);
    LOG_DEBUG("quat_test_2") << "x substring: " << ss;
    qquat.x = std::stod(ss);

    start_num_pos = end_num_pos+1;
    LOG_DEBUG("quat_test_2") << "start_num_pos: " << start_num_pos;
    end_num_pos=qstr.find(",", start_num_pos);
    i = end_num_pos - start_num_pos;
    LOG_DEBUG("quat_test_2") << "end_num_pos: " << end_num_pos;
    if (end_num_pos == std::string::npos)
        return false;
    ss = qstr.substr(start_num_pos, i);
    LOG_DEBUG("quat_test_2") << "y substring: " << ss;
    qquat.y = std::stod(ss);

    start_num_pos = qstr.find(",", end_num_pos)+1;
    LOG_DEBUG("quat_test_2") << "start_num_pos: " << start_num_pos;
    end_num_pos = std::string::npos;
    LOG_DEBUG("quat_test_2") << "end_num_pos: " << end_num_pos;
    ss = qstr.substr(start_num_pos, end_num_pos);
    LOG_DEBUG("quat_test_2") << "z substring: " << ss;
    qquat.z = std::stod(ss);

    return true;
}

void printManual()
{
    std::cout << "usage: pceMath_example2_vec3_times_quat x1,y1,z1 w,x2,y2,z2\n";
}


int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);
    std::string ln = "pceMaths_ex2";
    std::cout << "Running: pceMaths example2\n";
    size_t first_arg = 1;

    if (argc < 3)
    {
        std::cout << "Incorrect number of args.\n";
        printManual();
        return EXIT_SUCCESS;
    }
    if (std::string(argv[1]) == std::string("-l"))
    {
        first_arg = 3;
        if (argc != 5)
        {
            std::cout << "Incorrect number of args.\n";
            printManual();
            return EXIT_SUCCESS;
        }
    }
    
    const std::string v3str = argv[first_arg];
    const std::string qstr = argv[first_arg+1];
    glm::dvec3 v1{ 1, 0, 0 };
    glm::dquat q{ 1, 0, 0, 0 };
    if (!vec3StrToVec3(v3str, v1))
    {
        std::cout << "could not convert first arg to vec3: " << v3str << '\n';
        return EXIT_FAILURE;
    }
    std::cout << "\ninput vec3: " << v1.x << ", " << v1.y << ", " << v1.z << '\n';
    if(!quatStrToQduat(qstr, q))
    {
        std::cout << "\ncould not convert second arg to quat: " << qstr << '\n';
        return EXIT_FAILURE;
    }
    std::cout << "input quat: " << q.w << ", " << q.x << ", " << q.y << ", " << q.z << '\n';
    const glm::dquat q2 = pce::convertVector3toQuaternion(v1);
    const glm::dquat q3 = q2 * q;

    //const glm::dvec3 v = pce::rotateVector3byQuaternion(v1, q);
    const glm::dvec3 v = pce::rotateVector3byQuaternion(v1, q3);
    std::cout << "rotated vec3: " << v.x << ", " << v.y << ", " << v.z << '\n';

    return EXIT_SUCCESS;
}
