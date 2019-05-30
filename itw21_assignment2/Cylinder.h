/*----------------------------------------------------------
 * COSC363 Ray Tracer
 *
 *  The cylinder class
 *  This is a subclass of SceneObject, and hence implements the
 *  methods intersect() and normal().
 -------------------------------------------------------------*/

#ifndef H_CYLINDER
#define H_CYLINDER

#include <glm/glm.hpp>
#include "SceneObject.h"

/**
 * Defines a cyclinder using a specified radius.
 */
class Cylinder : public SceneObject {
private:
    glm::vec3 center;
    float radius;
    float height;
  
public:  
    Cylinder() : center(glm::vec3()), radius(1), height(1)  // Default constructor creates a unit cylinder
	{
        color = glm::vec3(0, 0, 0); // Black colour
	};
    
    Cylinder(glm::vec3 b, float r, float h, glm::vec3 c)
    : center(b), radius(r), height(h)
	{
	    color = c;
	};

    float intersect(glm::vec3 pos, glm::vec3 dir);
    
    glm::vec3 normal(glm::vec3 p);
    
};

#endif //!H_CYLINDER
