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
extern struct Rect line_speed[4];

void init_structures(struct Rect* line_speed);

#endif
