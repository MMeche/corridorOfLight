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
extern struct Rect obstacle_list[1];

extern struct Rect o1;

void init_structures(struct Rect* line_speed, struct Rect* obstacle_list);

#endif
