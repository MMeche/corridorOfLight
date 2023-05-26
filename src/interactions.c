#include "../inc/interactions.h"

float speed = 0.3f;
int state_right;

void avance_joueur(struct Rect* line_speed)
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
	}
};