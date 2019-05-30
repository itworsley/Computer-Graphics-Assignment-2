/*========================================================================
* COSC 363  Computer Graphics Assignment 2 - Ray Tracing
* Isaac Worsley itw21 55137767
*=========================================================================
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include "Sphere.h"
#include "Cylinder.h"
#include "SceneObject.h"
#include "Ray.h"
#include <GL/glut.h>
#include "Plane.h"
#include "TextureBMP.h"
#include "Tetrahedron.h"

using namespace std;

const float WIDTH = 20.0;  
const float HEIGHT = 20.0;
const float EDIST = 40.0;
const int NUMDIV = 500;
const int MAX_STEPS = 15;
const float XMIN = -WIDTH * 0.5;
const float XMAX =  WIDTH * 0.5;
const float YMIN = -HEIGHT * 0.5;
const float YMAX =  HEIGHT * 0.5;

float EYE_X = 0.;
float EYE_Y = 0.;
float EYE_Z = 0.;



const float ETA = 1.004;

TextureBMP textureSphere;
TextureBMP textureFloor;

vector<SceneObject*> sceneObjects;  //A global list containing pointers to objects in the scene

//---The most important function in a ray tracer! ---------------------------------- 
//   Computes the colour value obtained by tracing a ray and finding its 
//     closest point of intersection with objects in the scene.
//----------------------------------------------------------------------------------
glm::vec3 trace(Ray ray, int step)
{
	glm::vec3 backgroundCol(0);
    glm::vec3 light1(10, 40, -3);  // Light source 1
    glm::vec3 light2(-10, 40, -3); // Light soure 2
    glm::vec3 ambientCol(0.2);   // Ambient color of light

    float light1Intensity = 0.2;

    ray.closestPt(sceneObjects);		// Compute the closest point of intersetion of objects with the ray

    if(ray.xindex == -1) return backgroundCol;      // If there is no intersection return background colour

    glm::vec3 materialCol = sceneObjects[ray.xindex]->getColor(); // Else return object's colour

    float transparency = 0.4f; // Transparency value

    glm::vec3 normalVector = sceneObjects[ray.xindex]->normal(ray.xpt);

    glm::vec3 lightVector1 = normalize(light1 - ray.xpt);
    glm::vec3 lightVector2 = normalize(light2 - ray.xpt);

    float lDotn = glm::dot(normalVector, lightVector1);
    float lDotn2 = glm::dot(normalVector, lightVector2);

    //-- Initialize reflections
    glm::vec3 reflVector = glm::reflect(-lightVector1, normalVector);
    glm::vec3 reflVector2 = glm::reflect(-lightVector2, normalVector);
    glm::vec3 colorSum;

    float rDotv = glm::dot(reflVector, lightVector1);
    float rDotv2 = glm::dot(reflVector2, lightVector2);

    //-- Chequered Plane
    if(ray.xindex == 0) {
        int moduloX = (int)((ray.xpt.x + 40) / 4) % 2;
        int moduloZ = (int)((ray.xpt.z + 200) / 4) % 2;

        if ((moduloX && moduloZ) || (!moduloX && !moduloZ)) {
            materialCol = glm::vec3(0, 0, 0);
        } else {
            materialCol = glm::vec3(1, 1, 1);
        }
    }

    //-- Patterned Sphere
    if(ray.xindex == 9) {
        if (int((ray.xpt.x) * sqrt(10.0)) % 2) {
            materialCol = glm::vec3(sqrt(1), glm::dot(float(atan(ray.xpt.x * 1.5 * M_PI)), float(asin(ray.xpt.x * 0.5 * M_PI))), 0.5);
        } else if(int(ray.xpt.y) % 2) {
            materialCol = glm::vec3(1, float(asin(ray.xpt.x * 1.5 * M_PI)), 1);
        } else {
            materialCol = glm::vec3(1, 0, float(asin(ray.xpt.x * 1.5 * M_PI)));
        }
    }

    //-- Earth sphere
    if(ray.xindex == 8) {
        glm::vec3 center(5.0, -10.0, -70.0);
        glm::vec3 d = glm::normalize(ray.xpt - center);
        float u = (0.5 - atan2(d.z, d.x) + M_PI) / (2 * M_PI);
        float v = 0.5 + asin(d.y) / M_PI;

        materialCol = textureSphere.getColorAt(u, v);
    }

    //--------------- Shadows ---------------
    Ray shadow1(ray.xpt, lightVector1);
    shadow1.closestPt(sceneObjects);

    Ray shadow2(ray.xpt,lightVector2);
    shadow2.closestPt(sceneObjects);

    float specularCol;
    float specularCol2;

    //-- Shadow of light 1
    if (rDotv <= 0) {
        specularCol = 0;
    } else {
        specularCol = pow(rDotv, 10);
    }
    if (lDotn < 0 || (shadow1.xindex > -1 && (shadow1.xdist < distance(ray.xpt, light1)))) {
        colorSum = ambientCol*materialCol;
        if(shadow1.xindex == 10) {
            colorSum += (lDotn*materialCol + specularCol)*glm::vec3(0.4) + sceneObjects[10]->getColor()*glm::vec3(0.03);
        }
    } else {
        colorSum = (ambientCol+ specularCol) * materialCol + lDotn*(materialCol + specularCol)*light1Intensity;
    }

    //-- Shadow of light 2
    if (rDotv2 <= 0) {
        specularCol2 = 0;
    } else {
        specularCol2 = pow(rDotv2, 10);
    }
    if (lDotn2 <= 0 || (shadow2.xindex > -1 && (shadow2.xdist < distance(ray.xpt, light2)))) {
        colorSum += ambientCol*materialCol;
        if(shadow2.xindex == 10) {
            colorSum += (lDotn2*materialCol + specularCol2)*glm::vec3(0.4) + sceneObjects[10]->getColor()*glm::vec3(0.02);
        }
    } else {
        colorSum += (ambientCol+ specularCol) * materialCol + lDotn2*(materialCol + specularCol)*(1-light1Intensity);
    }

    //-- Reflective sphere
    if(ray.xindex == 7 && step < MAX_STEPS) {
        glm::vec3 reflectedDir = glm::reflect(ray.dir, normalVector);
        Ray reflectedRay(ray.xpt, reflectedDir);
        glm::vec3 reflectedCol = trace(reflectedRay, step+1); //Recursion!
        colorSum = colorSum + (0.8f*reflectedCol);
    }

    //-- Transparent and refractive sphere
    if(ray.xindex == 10 && step < MAX_STEPS) {
        glm::vec3 refracDir1 = glm::refract(ray.dir, normalVector, 1.0f/ETA);
        Ray incidentRay(ray.xpt, ray.dir);
        incidentRay.closestPt(sceneObjects);

        if (incidentRay.xindex == -1) {
            return backgroundCol;
        }

        if(ray.xindex != incidentRay.xindex) {
            colorSum = trace(incidentRay, step+1);
        }

        glm::vec3 normalV1 = sceneObjects[incidentRay.xindex] -> normal(incidentRay.xpt);
        glm::vec3 refracDir2 = glm::refract(refracDir1, -normalV1, ETA);
        Ray outRay(incidentRay.xpt, refracDir2);
        outRay.closestPt(sceneObjects);
        glm::vec3 transparentCol = trace(outRay, step+1);

        colorSum = (colorSum * transparency) + (transparentCol * (transparency));
    }

    return colorSum;
}

//---The main display module -----------------------------------------------------------
// In a ray tracing application, it just displays the ray traced image by drawing
// each cell as a quad.
//---------------------------------------------------------------------------------------
void display()
{
	float xp, yp;  //grid point
	float cellX = (XMAX-XMIN)/NUMDIV;  //cell width
	float cellY = (YMAX-YMIN)/NUMDIV;  //cell height

    glm::vec3 eye(EYE_X, EYE_Y, EYE_Z);  //The eye position (source of primary rays) is the origin

	glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glBegin(GL_QUADS);  //Each cell is a quad.

	for(int i = 0; i < NUMDIV; i++)  	//For each grid point xp, yp
	{
		xp = XMIN + i*cellX;
		for(int j = 0; j < NUMDIV; j++)
		{
			yp = YMIN + j*cellY;

		    glm::vec3 dir(xp+0.5*cellX, yp+0.5*cellY, -EDIST);	//direction of the primary ray

		    Ray ray = Ray(eye, dir);		//Create a ray originating from the camera in the direction 'dir'
            ray.normalize();				//Normalize the direction of the ray to a unit vector
            glm::vec3 col = trace (ray, 1); //Trace the primary ray and get the colour value

			glColor3f(col.r, col.g, col.b);
			glVertex2f(xp, yp);				//Draw each cell with its color value
			glVertex2f(xp+cellX, yp);
			glVertex2f(xp+cellX, yp+cellY);
			glVertex2f(xp, yp+cellY);
        }
    }

    glEnd();
    glFlush();
}


//--- Draw a cube with 6 sides -----------------------------
void drawCube()
{

    Plane *front = new Plane(glm::vec3(10., -15, -100),  //A
                             glm::vec3(20., -15, -100),   //B
                             glm::vec3(20., -5, -100),  //C
                             glm::vec3(10., -5, -100), //D
                             glm::vec3(0.3, 0.7, 0.7));    //Colour

    Plane *back = new Plane(glm::vec3(10., -15, -110),  //A
                             glm::vec3(20., -15, -110),   //B
                             glm::vec3(20., -5, -110),  //C
                             glm::vec3(10., -5, -110), //D
                             glm::vec3(0.3, 0.7, 0.7));    //Colour
    Plane *right = new Plane(glm::vec3(20., -15, -100),  //A
                             glm::vec3(20., -15, -110),   //B
                             glm::vec3(20., -5, -110),  //C
                             glm::vec3(20., -5, -100), //D
                             glm::vec3(0.3, 0.7, 0.7));    //Colour

    Plane *left = new Plane(glm::vec3(10., -15, -100),  //A
                             glm::vec3(10., -15, -110),   //B
                             glm::vec3(10., -5, -110),  //C
                             glm::vec3(10., -5, -100), //D
                             glm::vec3(0.3, 0.7, 0.7));    //Colour

    Plane *top = new Plane(glm::vec3(10., -5, -100),  //A
                             glm::vec3(20., -5, -100),   //B
                             glm::vec3(20., -5, -110),  //C
                             glm::vec3(10., -5, -110), //D
                             glm::vec3(0.3, 0.7, 0.7));    //Colour

    Plane *bottom = new Plane(glm::vec3(10., -15, -100),  //A
                             glm::vec3(20., -15, -100),   //B
                             glm::vec3(20., -15, -110),  //C
                             glm::vec3(10., -15, -110), //D
                             glm::vec3(0.3, 0.7, 0.7));    //Colour

    sceneObjects.push_back(front);
    sceneObjects.push_back(back);
    sceneObjects.push_back(right);
    sceneObjects.push_back(left);
    sceneObjects.push_back(top);
    sceneObjects.push_back(bottom);
}

//--- Draws a tetrahedron and adds it to the scene objects ------------------------
void drawTetrahedron() {
    Tetrahedron *tFront = new Tetrahedron(glm::vec3(-20., -15, -90), glm::vec3(-10., -15, -90), glm::vec3(-15., -10, -95), glm::vec3(0.6, 0, 0.6));
    Tetrahedron *tRight = new Tetrahedron(glm::vec3(-10., -15, -90), glm::vec3(-12.5, -15, -100), glm::vec3(-15, -10, -95), glm::vec3(0.6, 0, 0.6));
    Tetrahedron *tBack = new Tetrahedron(glm::vec3(-12.5, -15, -100), glm::vec3(-20., -15, -90), glm::vec3(-15., -10, -95), glm::vec3(0.6, 0, 0.6));
    Tetrahedron *tBottom = new Tetrahedron(glm::vec3(-20., -15, -90), glm::vec3(-10., -15, -90), glm::vec3(-12.5, -15, -100), glm::vec3(0.6, 0, 0.6));

    sceneObjects.push_back(tFront);
    sceneObjects.push_back(tRight);
    sceneObjects.push_back(tBack);
    sceneObjects.push_back(tBottom);
}


//--- This function initializes the scene ------------------------------------------
//   Specifically, it creates scene objects (spheres, planes, cones, cylinders etc)
//     and add them to the list of scene objects.
//   It also initializes the OpenGL orthographc projection matrix for drawing the
//     the ray traced image.
//----------------------------------------------------------------------------------
void initialize()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
    glClearColor(0, 0, 0, 1);

	//-- Create a pointer to a sphere object
    Sphere *sphere1 = new Sphere(glm::vec3(-1.0, -5.0, -90.0), 7.0, glm::vec3(0, 0, 1)); // Blue
    Sphere *sphere2 = new Sphere(glm::vec3(5.0, -10.0, -70.0), 3.0, glm::vec3(0, 1, 0));  // Green
    Sphere *sphere3 = new Sphere(glm::vec3(5.0, 6.0, -70.0), 5.0, glm::vec3(1, 0, 0));    // Red
    Sphere *sphere4 = new Sphere(glm::vec3(10., -5., -70.0), 3.0, glm::vec3(1, 0.75, 0.0));    // Yellow

    Cylinder *cylinder = new Cylinder(glm::vec3(-10, -20, -100), 2.0f, 20.0f, glm::vec3(0, 1, 1)); // Red
    Plane *plane = new Plane(glm::vec3(-40., -20, -40),  //A
                             glm::vec3(40., -20, -40),   //B
                             glm::vec3(40., -20, -200),  //C
                             glm::vec3(-40., -20, -200), //D
                             glm::vec3(0.5, 0.5, 0));   //Colour

    textureSphere = TextureBMP((char*)"texture_sphere.bmp");
    textureFloor = TextureBMP((char*)"texture_floor.bmp");



    //--Add the above to the list of scene objects.

    sceneObjects.push_back(plane); //0

    drawCube(); //1-6

    //--Spheres
    sceneObjects.push_back(sphere1);  // Reflective 7
    sceneObjects.push_back(sphere2);  // Textured 8
    sceneObjects.push_back(sphere3);  // Procedural Pattern 9
    sceneObjects.push_back(sphere4);  // Refracted 10

    drawTetrahedron(); // 11-14
    sceneObjects.push_back(cylinder); // 15
}

void rotateCamera() {

}

//--- Event handler for special key events, moving camera through the scene -----
void moveCamera(int key, int x, int y)
{
    if(key==GLUT_KEY_LEFT) {
        EYE_X -= 1;     // Move left
    }
    else if(key==GLUT_KEY_RIGHT) {
        EYE_X += 1;     // Move right
    }
    else if(key==GLUT_KEY_UP) {
        EYE_Z -= 1;     //Move forward
    }
    else if(key==GLUT_KEY_DOWN) {
        EYE_Z += 1;     //Move backward
    }

    glutPostRedisplay();
}

//--- Event handler for normal key events, moving camera angle up and down -------
void panCamera(unsigned char key, int x, int y) {
    if(key=='w') {
        EYE_Y += 1;
    }
    else if(key=='s') {
        EYE_Y -= 1;
    }

    glutPostRedisplay();
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("Raytracer");

    glutDisplayFunc(display);
    initialize();

    glutKeyboardFunc(panCamera);
    glutSpecialFunc(moveCamera);

    glutMainLoop();
    return 0;
}
