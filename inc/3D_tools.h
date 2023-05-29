#ifndef D_TOOLS
#define D_TOOLS

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../inc/structures.h"

#define NB_SEG_CIRCLE 64

/* Camera parameters and functions */
static const float Z_NEAR = 0.1f;
static const float Z_FAR = 100.f;
extern float theta;      // Angle between x axis and viewpoint
extern float phy  ;      // Angle between z axis and viewpoint
extern float dist_zoom ; // Distance between origin and viewpoint

void setCamera();

/* Draw cannonic objet functions */
void drawSquare(float r,float g,float b);

void drawCircle(double r);

void drawRaquette(float translate_x, float translate_y);

void drawCone();

void drawSphere();

void drawWall(struct Rect wall, float r, float g, float b);

/* Small tools */
float toRad(float deg);

#endif
