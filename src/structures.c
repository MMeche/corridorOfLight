#include "../inc/structures.h"

int totalObs = 5;

struct Rect obstacle_list[5];
struct Rect line_speed[4];
//struct Ball *balle;
float balle[9];



struct Rect o1;
struct Rect o2;
struct Rect o3 ;
struct Rect o4;
struct Rect o5 ;
struct Rect o6;
struct Rect o7 ;
struct Rect o8;
struct Rect o9 ;
struct Rect o10;
struct Rect o11 ;
struct Rect o12;
struct Rect o13 ;
struct Rect o14;

struct Rect final;

void init_structures(struct Rect* line_speed,struct Rect* obstacle_list, float* balle/*struct Ball* balle*/)
{
    
    balle[0] = 0.f; //x
    balle[1] = -2.5f; //y
    balle[2] = 0.f; //z
    
    balle[4] = 0.f; //speedx
    balle[5] = 0.f; //speedy
    balle[6] = 0.f; //speedz

    balle[3] = 0.25f; //r
    balle[7] = 1; //sticky doses
    balle[8] =  0; //valeurs négatives pour une vitesse ralentie, positive pour accélérée et nulle pour normale.
    
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
    /*On entre la liste des obstacles du niveau. Il faut tous les entrer à la main donc c'est long.
    Possiblement à transformer en aléatoire pour plus tard*/
    
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

  
    o2.cid.x = -4;
    o2.cid.y = -22;
    o2.cid.z =  1;

    o2.cig.x = 4;
    o2.cig.y = -22;
    o2.cig.z = 1;

    o2.csd.x = -4;
    o2.csd.y = -22;
    o2.csd.z = 2;

    o2.csg.x = 4;
    o2.csg.y = -22;
    o2.csg.z = 2;


    o3.cid.x = -4;
    o3.cid.y = -22;
    o3.cid.z =  -2;

    o3.cig.x = 4;
    o3.cig.y = -22;
    o3.cig.z = -2;

    o3.csd.x = -4;
    o3.csd.y = -22;
    o3.csd.z = -1;

    o3.csg.x = 4;
    o3.csg.y = -22;
    o3.csg.z = -1;


    o4.cid.x = 2;
    o4.cid.y = -26;
    o4.cid.z =  -2;

    o4.cig.x = 4;
    o4.cig.y = -26;
    o4.cig.z = -2;

    o4.csd.x = 2;
    o4.csd.y = -26;
    o4.csd.z = 2;

    o4.csg.x = 4;
    o4.csg.y = -26;
    o4.csg.z = 2;


    o5.cid.x = 2;
    o5.cid.y = -26;
    o5.cid.z =  -2;

    o5.cig.x = 4;
    o5.cig.y = -26;
    o5.cig.z = -2;

    o5.csd.x = 2;
    o5.csd.y = -26;
    o5.csd.z = 2;

    o5.csg.x = 4;
    o5.csg.y = -26;
    o5.csg.z = 2;


    final.cid.x = -4;
    final.cid.y = -138;
    final.cid.z = -2;

    final.cig.x = 4;
    final.cig.y = -138;
    final.cig.z = -2;

    final.csd.x = -4;
    final.csd.y = -138;
    final.csd.z = 2;

    final.csg.x = 4;
    final.csg.y = -138;
    final.csg.z = 2;
    
    obstacle_list[0] =  o1;
    obstacle_list[1] = o2;
    obstacle_list[2] = o3;
    obstacle_list[3] = o4;

    obstacle_list[4] = final;   

};



