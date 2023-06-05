#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../inc/3D_tools.h"
#include "../inc/structures.h"
#include "../inc/variables.h"


void drawFrame();

void drawCorridor();

void drawLineSpeed();

void drawObstacles();

void drawBallz();

void drawMenu(GLuint rejouer,GLuint règles,GLuint reprendre,GLuint quitter);

void gameOver();

void drawTakeable();