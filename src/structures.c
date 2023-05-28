#include "../inc/structures.h"

struct Rect obstacle_list[1];
struct Rect line_speed[4];

struct Rect o1;

void init_structures(struct Rect* line_speed,struct Rect* obstacle_list)
{
    
    //On charge les lignes affichées pour simuler la vitesse (4*4 points)    
    for(int i = 0 ; i<5;i++)
    {
        struct Rect lnew; // Allocation mémoire pour le nouvel objet;
        lnew.cid.x = -3.99; //on décrémente légèrement pour pas que les lignes se confondent au murs
        lnew.cid.y = -18+(i*4);
        lnew.cid.z = -1.99;

        lnew.cig.x =  3.99;
        lnew.cig.y = -18+(i*4);
        lnew.cig.z = -1.9;

        lnew.csd.x = -3.99;
        lnew.csd.y = -18+(i*4);
        lnew.csd.z = 1.99;

        lnew.csg.x =  3.99;
        lnew.csg.y = -18+(i*4);
        lnew.csg.z = 1.99;

        line_speed[i]= lnew;
        
    }
    //On entre la liste des obstacles du niveau. Il faut tous les entrer à la main donc c'est long.
    
    o1.cid.x = -4;
    o1.cid.y = -18;
    o1.cid.z =  -2;

    o1.cig.x = 0;
    o1.cig.y = -18;
    o1.cig.z = -2;

    o1.csd.x = -4;
    o1.csd.y = -18;
    o1.csd.z = 2;

    o1.csg.x = 0;
    o1.csg.y = -18;
    o1.csg.z = 2; 
    
    obstacle_list[0] =  o1;   

}
