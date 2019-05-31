/*
 * COSC 363 Ray Tracer
 *
 * Cylinder class
 */

#include "Cylinder.h"
#include <math.h>

/**
* Cylinder's intersection method.  The input is a ray (posn, dir).
*/
float Cylinder::intersect(glm::vec3 posn, glm::vec3 dir) {

    // x, z coord minus base x,z coord
    float x = posn.x - center.x;
    float z = posn.z - center.z;

    // Calculate square products (x-xa)**2 + (z-za)**2
    float a = (dir.x*dir.x) + (dir.z*dir.z);
    float b = 2* (dir.x*(x) + dir.z*(z));
    float c = (x*x) + (z*z) - (radius*radius);

    // Quadratic formula
    float discriminant = (b*b) - (4*(a*c));

    if (discriminant <= 0.0f) {
        return -1.0f;
    }

    // Calculate the t values (real roots) using the quadratic formula.
    // Don't forget the brackets around 2*a! BEDMAS
    float t1 = (-b + sqrt(discriminant))/(2*a);
    float t2 = (-b - sqrt(discriminant))/(2*a);

    float ts;
    float tb;

    if (t1 < 0.01f) {
        t1 = -1.0f;
    }

    if (t2 < 0.01f) {
        t2 = -1.0f;
    }

    if (t2 > t1) {
        ts = t1;
        tb = t2;
    }
    else {
        ts = t2;
        tb = t1;
    }


    float y1 = posn.y + dir.y * ts;
    float y2 = posn.y + dir.y * tb;

    if((y1 >= center.y) && (y1 <= center.y + height)) {
        return ts;
    }
    else if ((y2 >= center.y) && (y2 <= center.y + height)) {
        return tb;
    }

    return -1.0f;

}

glm::vec3 Cylinder::normal(glm::vec3 p) {
    float x = p.x - center.x;
    float z = p.z - center.z;
    glm::vec3 n = glm::vec3(x, 0, z);
    return glm::normalize(n);

}
