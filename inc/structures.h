#ifndef STRUCTURES
#define STRUCTURES
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
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
extern struct Rect obstacle_list[5];
extern int restantObs;
extern int totalObs;
//extern struct Ball *balle;
extern float balle[9]; //je n'arrive pas à utiliser ma structure, ça me saoule donc je fais autrement.
extern float translate_x ;
extern float translate_y ;


extern struct Rect o1 ;
extern struct Rect o2 ;
extern struct Rect o3 ;
extern struct Rect o4 ;
extern struct Rect o5 ;
extern struct Rect o6 ;
extern struct Rect o7 ;
extern struct Rect o8 ;
extern struct Rect o9 ;
extern struct Rect o10 ;
extern struct Rect o11 ;
extern struct Rect o12 ;
extern struct Rect o13 ;
extern struct Rect o14 ;

extern struct Rect final;


void init_structures(struct Rect* line_speed, struct Rect* obstacle_list, float* balle /*struct Ball* balle*/);


#endif
