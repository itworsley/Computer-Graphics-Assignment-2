/*----------------------------------------------------------
 * COSC363 Ray Tracer
 *
 *  The cylinder class
 *  This is a subclass of SceneObject, and hence implements the
 *  methods intersect() and normal().
 -------------------------------------------------------------*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include "SceneObject.h"

/**
 * Defines a cyclinder using a specified radius.
 */
class Cylinder : public SceneObject {
private:
    glm::vec3 base;
    float radius;
    float height;
  
public:  
    Cylinder() : base(glm::vec3()), radius(1), height(1)  // Default constructor creates a unit cylinder
	{
	    color = glm::vec3(0,0,0); // White colour
	};
    
    Cylinder(glm::vec3 b, float r, float h, glm::vec3 c)
	: base(b), radius(r), height(h)
	{
	    color = c;
	};

    float intersect(glm::vec3 pos, glm::vec3 dir);
    
    glm::vec3 normal(glm::vec3 p);
    
};

#endif // CYLINDER_H
