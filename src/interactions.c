#include "../inc/interactions.h"

float speed = 0.3f;
int lives = 1;


const float normal_ball_speed = 0.35f;
const float speedy_ball_speed = 0.6f;
const float cool_ball_speed = 0.1f;



int state_right;

void avance_joueur(struct Rect* line_speed,struct Rect* obstacle_list,struct takeMe* takeable_list)
{
    int raquetteIsBlocked = 0;
	/*On test si la raquette peut avancer*/
	for(int i=0;i<totalObs;i++)
	{
		
		if((obstacle_list[i].cid.y<-2.5 && obstacle_list[i].cid.y + speed > -2.5)
			&&((translate_x + sizeOfRaq >= obstacle_list[i].cid.x)&&(translate_x + sizeOfRaq <= obstacle_list[i].cig.x)||(translate_x - sizeOfRaq >= obstacle_list[i].cid.x)&&(translate_x - sizeOfRaq <= obstacle_list[i].cig.x))
			&&((translate_y + sizeOfRaq >= obstacle_list[i].cid.z)&&(translate_y + sizeOfRaq <= obstacle_list[i].csd.z)||(translate_y - sizeOfRaq >= obstacle_list[i].cid.z)&&(translate_y - sizeOfRaq <= obstacle_list[i].csd.z)))
		{
			raquetteIsBlocked = 1;
		}
	}

	/*On test si la raquette rencontre un bonus/malus */
	for(int i = 0; i<totalTake ;i++)
	{
		if((takeable_list[i].pos.y<-2.5 && takeable_list[i].pos.y+speed > -2.5)
		&&((takeable_list[i].pos.x+0.25 >= translate_x-sizeOfRaq)&&(takeable_list[i].pos.x+0.25 <= translate_x+sizeOfRaq)||(takeable_list[i].pos.x-0.25 >= translate_x-sizeOfRaq)&&(takeable_list[i].pos.x-0.25 <= translate_x+sizeOfRaq))
		&&((takeable_list[i].pos.z+0.25 >= translate_y-sizeOfRaq)&&(takeable_list[i].pos.z+0.25 <= translate_y+sizeOfRaq)||(takeable_list[i].pos.z-0.25 >= translate_y-sizeOfRaq)&&(takeable_list[i].pos.z-0.25 <= translate_y+sizeOfRaq)))
		{
			/*La bonus collant rajoute 3 sticky doses*/
			if(takeable_list[i].type == 'c')
			{
				balle[7] += 3;
			};
			/*La vie bonus rajoute une vie*/
			if(takeable_list[i].type == 'v')
			{
				lives +=2;
			};
			/*Le bonus de ralenti, ralenti la balle*/
			if(takeable_list[i].type == 'r')
			{
				balle[4] = balle[4]/balle[5];
				balle[6] = balle[6]/balle[5];
				if(balle[5]<0)
				{
					balle[5] = -cool_ball_speed;
				}else{balle[5] = cool_ball_speed;}
				
				balle[4] = balle[4]*balle[5];
				balle[6] = balle[6]*balle[5];
				balle[8] -= 3;
			};
			/*Le malus accélère, accélère la balle*/
			if(takeable_list[i].type == 'a')
			{
				balle[4] = balle[4]/balle[5];
				balle[6] = balle[6]/balle[5];
				if(balle[5]<0)
				{
					balle[5] = -speedy_ball_speed;
				}else{balle[5] = speedy_ball_speed;}
				balle[4] = balle[4]*balle[5];
				balle[6] = balle[6]*balle[5];
				balle[8] += 3;
			};
			/*Le bonus grandi, agrandit la taille de la raquette*/
			if(takeable_list[i].type == 'g')
			{
				if(sizeOfRaq<0.75)
				{
					sizeOfRaq += 0.1f;
				}
			}
			/*Le malus petit, rapettisse la raquette*/
			if(takeable_list[i].type == 'p')
			{
				if(sizeOfRaq>0.35)
				{
					sizeOfRaq -= 0.30f;
				}
			}
		}
	}; 
	/*On gère l'avancée du joueur sur tous les éléments (mur,lignes,bonus/malus)*/
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
		
		for(int i=0;i<totalTake;i++)
		{
			takeable_list[i].pos.y += speed;
		};
	};
};	

void avance_balle(float* balle)
{
	if(balle[7]!=0 && (balle[1]+balle[5]+balle[3]>-2.5f && (balle[0]<(translate_x)+sizeOfRaq && balle[0]>(translate_x)-sizeOfRaq) && (balle[2]<(translate_y)+sizeOfRaq && balle[2]>(translate_y)-sizeOfRaq))) //la balle est collante et est collée  : il faut qu'elle suive les mouvements de la raquette.
	{
		//state_right = 0;
		balle[4] = 0.f;
		balle[5] = 0.f;
		balle[6] = 0.f;
		balle[0] = translate_x;
		balle[1] = -2.5;
		balle[2] = translate_y;
	}
	else
	{
		/*Gestion des collisions avec la raquette*/
		if(balle[1]+balle[5]+balle[3]>-2.5 && (balle[0] < (translate_x+sizeOfRaq) && balle[0] > (translate_x-sizeOfRaq)) && (balle[2] < (translate_y + sizeOfRaq) && balle[2] > (translate_y -sizeOfRaq)))
		{
		/*C'est la fonction de renvoi de la balle par la raquette*/
			if(balle[8]==0)
			{
				balle[5] = normal_ball_speed;
			}
			if(balle[8]<0)
			{
				balle[8]++;
			};
			if(balle[8]>0)
			{
				balle[8]--;
			}
			
			
			printf("non %f,%f\n",balle[8],balle[5]);
			balle[5] = -balle[5];
			float xDeviationRate = -(balle[0] - translate_x)/2;
			float zDeviationRate = -(balle[2] - translate_y)/2;		
			balle[4] = balle[5]*xDeviationRate;
			balle[6] = balle[5]*zDeviationRate;			
		}
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
					&& (balle[1]+balle[5]-balle[3] <= obstacle_list[i].cid.y+(state_right*speed)))
				{	
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

		lives--;
		printf("vies : %d\n",lives);
	}
	
	
	
	
	
	
	//Update de la position. 
	for(int i=0;i<3;i++)
	{
		//printf("%f\n",balle[i]);
		//printf("%f\n",balle[i+4]);
		balle[i] += balle[i+4];
	};
		
};