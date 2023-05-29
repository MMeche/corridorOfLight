#ifndef STRUCTURES
#define STRUCTURES
#include <stdlib.h>
#include <stdio.h>
struct Point
{
    double x;
    double y;
    double z;
};

struct Rect
{
    struct Point csg;
    struct Point csd;
    struct Point cig;
    struct Point cid;
    
    struct Rect* next;
};

struct Ball
{
    struct Point centre;
    double r;
    float speed_x;
    float speed_y;
    float speed_z;
    int sticky; //si la balle colle à la raquette (au début et avec les bonus). Entier représentant le nombre de fois où elle l'est.

};

extern struct Rect line_speed[4];
extern struct Rect obstacle_list[1];
//extern struct Ball *balle;
extern float balle[9]; //je n'arrive pas à utiliser ma structure, ça me saoule donc je fais autrement.
extern float translate_x ;
extern float translate_y ;


extern struct Rect o1;

void init_structures(struct Rect* line_speed, struct Rect* obstacle_list, float* balle /*struct Ball* balle*/);

#endif
