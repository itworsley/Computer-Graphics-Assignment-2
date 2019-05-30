/*
 * COSC 363 Ray Tracer
 *
 * Cylinder class
 */

#include "Cylinder.h"
#include <math.h>


float Cylinder::intersect(glm::vec3 posn, glm::vec3 dir) {

    // x,z coord minus base x,z coord
    float x = posn.x - base.x;
    float z = posn.z - base.z;

    // Calculate square products (x-xa)**2 + (z-za)**2
    float a = dir.x*dir.x + dir.z*dir.z;
    float b = dir.x*(x) + dir.z*(z);
    float c = x*x + z*z - radius*radius;

    // Quadratic formula
    float discriminant = b*b - 4*a*c;

    if (discriminant <= 0) {
        return -1.0f;
    }

    // Calculate the t values (real roots) using the quadratic formula.
    // Don't forget the brackets around 2*a! BEDMAS
    float t1 = (-b + sqrt(discriminant))/(2*a);
    float t2 = (-b - sqrt(discriminant))/(2*a);

    if (t1 > 0) {
        if (t1 < t2) {
            return t1;
        }
        else if (t2 > 0) {
            return t2;
        }
        else {
            return t1;
        }
    }
    else if (t2 > 0) {
        return t2;
    }
    else {
        return -1.0f;
    }

}

glm::vec3 Cylinder::normal(glm::vec3 p) {
//    // the lid of the cylinder
//    if (p.y - base.y - height <= 0.001) {
//        return glm::vec3(0, 1, 0);
//    }
//    // the base of the cylinder
//    else if (p.y - base.y <= 0.001) {
//        return glm::vec3(0, -1, 0);
//    }
//    // the side
//    else {
//        // the angle around the cylinder for this point
//        glm::vec3 n = p - base;
//        n.y = 0;
//        return glm::normalize(n);
//    }
    float x = p.x - base.x;
    float z = p.z - base.z;
    glm::vec3 n;
    n.x = x;
    n.y = 0;
    n.z = z;
    return n;

}
