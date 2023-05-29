#ifndef INTERACTIONS
#define INTERACTIONS
#include "../inc/structures.h"

extern float speed;
extern int state_right;
extern const float normal_ball_speed ;
extern const float speedy_ball_speed ;
extern const float cool_ball_speed ;

void avance_joueur(struct Rect* line_speed,struct Rect* obstacle_list);
void avance_balle(float* balle /*struct Ball* balle*/);

#endif