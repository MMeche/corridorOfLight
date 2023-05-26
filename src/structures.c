#include "../inc/structures.h"


struct Rect line_speed[4];

void init_structures(struct Rect* line_speed)
{
    
    //On charge les lignes affichées pour simuler la vitesse (4*4 points)    
    for(int i = 0 ; i<5;i++)
    {
        printf("egehege");
        struct Rect lnew; // Allocation mémoire pour le nouvel objet;
        lnew.cid.x = -3.9; //on décrémente légèrement pour par que les lignes se confondent au murs
        lnew.cid.y = -18+(i*4);
        lnew.cid.z = -1.9;

        lnew.cig.x =  3.9;
        lnew.cig.y = -18+(i*4);
        lnew.cig.z = -1.9;

        lnew.csd.x = -3.9;
        lnew.csd.y = -18+(i*4);
        lnew.csd.z = 1.9;

        lnew.csg.x =  3.9;
        lnew.csg.y = -18+(i*4);
        lnew.csg.z = 1.9;

        line_speed[i]= lnew;
        
    }
}
