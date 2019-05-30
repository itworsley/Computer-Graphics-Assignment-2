#include "ChequeredPlane.h"
#include <math.h>

//glm::vec3 ChequeredPlane::getColor(glm::vec3 pos)
//{
//    float x = (a - b).x / 113;
//    float z = (b - c).z / 113;

//    int posX = (pos.x - a.x) / x;
//    int posZ = (pos.z - b.z) / z;

//    if ((posX % 2 == 0 || posZ % 2 == 0) && posX % 2 != posZ % 2)
//    {
//        return colourA;
//    }
//    return colourB;
//}


/**
* Checks if a point pt is inside the current polygon
* Implement a point inclusion test using
* member variables a, b, c, d.
*/
bool ChequeredPlane::isInside(glm::vec3 pt)
{
    glm::vec3 n = normal(pt);
    glm::vec3 uA = b-a;
    glm::vec3 uB = c-b;
    glm::vec3 uC = d-c;
    glm::vec3 uD = a-d;

    glm::vec3 vA = pt-a;
    glm::vec3 vB = pt-b;
    glm::vec3 vC = pt-c;
    glm::vec3 vD = pt-d;

    return glm::dot(glm::cross(uA, vA), n) >= 0
            && glm::dot(glm::cross(uB, vB), n) >= 0
            && glm::dot(glm::cross(uC, vC), n) >= 0
            && glm::dot(glm::cross(uD, vD), n) >= 0;
}

glm::vec3 ChequeredPlane::normal(glm::vec3 p) {
    return glm::vec3(0, 1, 0);
}
