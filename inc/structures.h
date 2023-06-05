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

struct takeMe
{
    /*Plusieurs types possible : collant (c), accélère (a), ralenti (r), grandis (g), vie bonus (v) ,petit (p) */
    char type;
    struct Point pos; 
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





void init_structures(struct Rect* line_speed, struct Rect* obstacle_list, float* balle /*struct Ball* balle*/,struct takeMe* takeable_list);


#endif
