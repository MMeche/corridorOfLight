#ifndef VARIABLES
#define VARIABLES
#include "../inc/structures.h"

/*Les tableaux d'objets et leur cardinaux*/
extern struct Rect line_speed[4];
extern struct Rect obstacle_list[12];
extern int totalObs;
extern struct takeMe takeable_list[6];
extern int totalTake;

//extern struct Ball *balle;
extern float balle[9]; //je n'arrive pas à utiliser ma structure, ça me saoule donc je fais autrement.

/*Dimensions de la raquette*/
extern float translate_x ;
extern float translate_y ;
extern float sizeOfRaq ;

/*La liste de tous les obstacles*/
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
extern struct Rect o15;
extern struct Rect o16 ;
extern struct Rect o17;
extern struct Rect o18 ;
extern struct Rect o19;
extern struct Rect o20;
extern struct Rect o21 ;
extern struct Rect o22;
extern struct Rect o23 ;

extern struct Rect final;

/*La liste de tous les bonus/malus (on va en mettre un de chaque, donc 6)*/
extern struct takeMe b1;
extern struct takeMe b2;
extern struct takeMe b3;
extern struct takeMe b4;
extern struct takeMe m1;
extern struct takeMe m2;

/*L'angle pour faire tourner les trucs que l'on ramasse*/
extern float rotation ; 

/*Le nombre de vies*/
extern int lives;

#endif