#include "../inc/interactions.h"

float speed = 0.3f;
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