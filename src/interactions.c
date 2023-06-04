#include "../inc/interactions.h"

float speed = 0.3f;


const float normal_ball_speed = 0.5f;
const float speedy_ball_speed = 0.7f;
const float cool_ball_speed = 0.3f;

/*Coordonées de la raquette (y=-2.5) */
float translate_x =0.f;
float translate_y = 0.f;

int state_right;

void avance_joueur(struct Rect* line_speed,struct Rect* obstacle_list)
{
    int raquetteIsBlocked = 0;
	for(int i=0;i<totalObs;i++)
	{
		/*On test si la raquette peut avancer*/
		if((obstacle_list[i].cid.y<-2.5 && obstacle_list[i].cid.y + speed > -2.5)
			&&((translate_x + 0.5 >= obstacle_list[i].cid.x)&&(translate_x + 0.5 <= obstacle_list[i].cig.x)||(translate_x - 0.5 >= obstacle_list[i].cid.x)&&(translate_x - 0.5 <= obstacle_list[i].cig.x))
			&&((translate_y + 0.5 >= obstacle_list[i].cid.z)&&(translate_y + 0.5 <= obstacle_list[i].csd.z)||(translate_y - 0.5 >= obstacle_list[i].cid.z)&&(translate_y - 0.5 <= obstacle_list[i].csd.z)))
		{
			raquetteIsBlocked = 1;
		}
	}
	if(raquetteIsBlocked == 0)
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
		
		for(int i=0;i<totalObs;i++)
		{
			obstacle_list[i].cid.y += speed;
			obstacle_list[i].csd.y += speed;
			obstacle_list[i].cig.y += speed;
			obstacle_list[i].csg.y += speed;
			
		}
	};
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
	if(balle[5]<0) 
	{
		/*Cas où la balle va vers le fond*/
		for(int i=0;i<totalObs;i++)
		{
			if(balle[1]>obstacle_list[i].cid.y)
			{
				if((balle[0]+balle[4]+balle[3] >= obstacle_list[i].cid.x)&&(balle[0]+balle[4]-balle[3] <= obstacle_list[i].cig.x) // la balle est comprise 
					&& (balle[2]+balle[6]+balle[3] >= obstacle_list[i].cid.z)&&(balle[2]+balle[6]-balle[3] <= obstacle_list[i].csd.z)
					&& (balle[1]+balle[5]-balle[3] <= obstacle_list[i].cid.y))
				{	
					printf("oui");
					balle[5] = -balle[5];
				}		
			}	
		}
	}else
		{	
			if(balle[5]>0) 
			{
				/*Cas où la balle va vers la raquette*/
				for(int i=0;i<totalObs;i++)
				/*Gestion des collisions avec les murs*/
				{
					if(balle[1]<obstacle_list[i].cid.y)
					{
						if((balle[0]+balle[4]+balle[3] >= obstacle_list[i].cid.x)&&(balle[0]+balle[4]-balle[3] <= obstacle_list[i].cig.x) // la balle est comprise 
							&& (balle[2]+balle[6]+balle[3] >= obstacle_list[i].cid.z)&&(balle[2]+balle[6]-balle[3] <= obstacle_list[i].csd.z)
							&& (balle[1]+balle[5]+balle[3] >= obstacle_list[i].cid.y))
						{
							
							balle[5] = -balle[5];
						};
					}
				};
				/*Gestion des collisions avec la raquette*/
				if(balle[1]+balle[5]+balle[3]>-2.5 && (balle[0] < (translate_x+0.5) && balle[0] > (translate_x-0.5)) && (balle[2] < (translate_y + 0.5) && balle[2] > (translate_y -0.5)))
				{
					/*C'est la fonction de renvoi de la balle par la raquette (pour le moment simple rebond selon y)*/
					balle[5] = -balle[5];
					float xDeviationRate = -(balle[0] - translate_x)/2;
					float zDeviationRate = -(balle[2] - translate_y)/2;
					
					balle[4] = balle[5]*xDeviationRate;
					balle[6] = balle[5]*zDeviationRate;			
				}
			};
		};
	/*Gestion des collisions avec les quatre murs d'enceinte*/
	if(balle[0]+balle[4]+balle[3] > 3.8 || balle[0] + balle[4]- balle[3] < -3.8)
	{
		balle[4] = -balle[4];
		balle[0] += balle[4];
	
	};
	if(balle[2]+balle[6]+balle[3] > 1.8 || balle[2] + balle[6]- balle[3] < -1.8)
	{
		balle[6] = -balle[6];
		balle[2] += balle[6];
	};

	if(balle[1]>-2.5)
	{
		balle[0] = 0.f; //x
    	balle[1] = -2.5f; //y
    	balle[2] = 0.f; //z
    
    	balle[4] = 0.f; //speedx
    	balle[5] = 0.f; //speedy
    	balle[6] = 0.f; //speedz

   		balle[3] = 0.25f; //r
    	balle[7] = 1; //sticky doses
	}
	
	
	
	
	
	
	//Update de la position. 
	for(int i=0;i<3;i++)
	{
		//printf("%f\n",balle[i]);
		//printf("%f\n",balle[i+4]);
		balle[i] += balle[i+4];
	};
		
};