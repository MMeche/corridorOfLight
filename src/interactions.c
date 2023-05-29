#include "../inc/interactions.h"

float speed = 0.3f;


const float normal_ball_speed = 0.5f;
const float speedy_ball_speed = 0.7f;
const float cool_ball_speed = 0.3f;

int state_right;

void avance_joueur(struct Rect* line_speed,struct Rect* obstacle_list)
{
    for(int i=0;i<4;i++)
	{
		line_speed[i].cid.y += speed;
		if(line_speed[i].cid.y >-2)
		{
			line_speed[i].cid.y-=16;
		}
    	line_speed[i].cig.y += speed;
		if(line_speed[i].cig.y >-2)
		{
			line_speed[i].cig.y-=16;
		}
		line_speed[i].csd.y += speed;
		if(line_speed[i].csd.y >-2)
		{
			line_speed[i].csd.y-=16;
		}
		line_speed[i].csg.y += speed;
		if(line_speed[i].csg.y >-2)
		{
			line_speed[i].csg.y-=16;
		}
	};
	
	for(int i=0;i<1;i++)
	{
		obstacle_list[i].cid.y += speed;
		obstacle_list[i].csd.y += speed;
		obstacle_list[i].cig.y += speed;
		obstacle_list[i].csg.y += speed;
	}
};	

void avance_balle(float* balle)
{
	if(balle[7]!=0 && (balle[1]==-2.5f && (balle[0]<(translate_x)+0.5 && balle[0]>(translate_x)-0.5) && (balle[1]<(translate_y)+0.5 && balle[1]>(translate_y)-0.5))) //la balle est collante et est collée  : il faut qu'elle suive les mouvements de la raquettes.
	{
		balle[4] = 0.f;
		balle[5] = 0.f;
		balle[6] = 0.f;
	}
	//Gestion des collisions
	
	
	
	
	
	//Update de la position. 
	for(int i=0;i<3;i++)
	{
		//printf("%f\n",balle[i]);
		//printf("%f\n",balle[i+4]);
		balle[i] += balle[i+4];
	};
		
};