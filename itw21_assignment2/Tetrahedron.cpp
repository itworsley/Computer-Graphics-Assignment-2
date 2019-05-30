/*----------------------------------------------------------
* COSC363  Ray Tracer
*
*  The tetrahedron class
*  This is a subclass of SceneObject, and hence implements the
*  methods intersect() and normal().
-------------------------------------------------------------*/

#include "Tetrahedron.h"
#include <math.h>


/**
* Checks if a point pt is inside the current polygon
* Implement a point inclusion test using
* member variables a, b, c, d.
*/
bool Tetrahedron::isInside(glm::vec3 pt)
{
    glm::vec3 n = normal(pt);
    glm::vec3 uA = b-a;
    glm::vec3 uB = c-b;
    glm::vec3 uC = a-c;

    glm::vec3 vA = pt-a;
    glm::vec3 vB = pt-b;
    glm::vec3 vC = pt-c;

    return glm::dot(glm::cross(uA, vA), n) >= 0
            && glm::dot(glm::cross(uB, vB), n) >= 0
            && glm::dot(glm::cross(uC, vC), n) >= 0;
}

/**
* Tetrahedron's intersection method.  The input is a ray (pos, dir).
*/
float Tetrahedron::intersect(glm::vec3 posn, glm::vec3 dir)
{
    glm::vec3 n = normal(posn);
    glm::vec3 vdif = a - posn;
    float vdotn = glm::dot(dir, n);
    if(fabs(vdotn) < 1.e-4) return -1;
    float t = glm::dot(vdif, n)/vdotn;
    if(fabs(t) < 0.0001) return -1;
    glm::vec3 q = posn + dir*t;
    if(isInside(q)) return t;

    else return -1;
}

/**
* Returns the unit normal vector at a given point.
*/
glm::vec3 Tetrahedron::normal(glm::vec3 pos)
{
    glm::vec3 crossProduct = normalize(glm::cross((b-a), (c-a)));
    glm::vec3 n = glm::vec3(crossProduct);

    return n;
}
