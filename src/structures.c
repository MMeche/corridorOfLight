#include "../inc/structures.h"

int totalObs = 26;
int totalTake = 6;

struct Rect obstacle_list[26];
struct Rect line_speed[4];
struct takeMe takeable_list[6];
//struct Ball *balle;
float balle[9];

/*Coordonées de la raquette (y=-2.5) */
float translate_x =0.f;
float translate_y = 0.f;
float sizeOfRaq = 0.65f;

/*Tourner*/
float rotation = 0.f;

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
struct Rect o15;
struct Rect o16 ;
struct Rect o17;
struct Rect o18 ;
struct Rect o19;
struct Rect o20;
struct Rect o21 ;
struct Rect o22;
struct Rect o23 ;
struct Rect o24;
struct Rect o25;
struct Rect final;

struct takeMe b1;
struct takeMe b2;
struct takeMe b3;
struct takeMe b4;
struct takeMe b5;
struct takeMe m1;
struct takeMe m2;


void init_structures(struct Rect* line_speed,struct Rect* obstacle_list, float* balle/*struct Ball* balle*/, struct takeMe* takeable_list)
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

//

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

//

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

//

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

//

    o5.cid.x = 0;
    o5.cid.y = -30;
    o5.cid.z =  -2;

    o5.cig.x = 4;
    o5.cig.y = -30;
    o5.cig.z = -2;

    o5.csd.x = 0;
    o5.csd.y = -30;
    o5.csd.z = 2;

    o5.csg.x = 4;
    o5.csg.y = -30;
    o5.csg.z = 2;

//

    o6.cid.x = -4;
    o6.cid.y = -34;
    o6.cid.z =  -2;

    o6.cig.x = -2;
    o6.cig.y = -34;
    o6.cig.z = -2;

    o6.csd.x = -4;
    o6.csd.y = -34;
    o6.csd.z = 2;

    o6.csg.x = -2;
    o6.csg.y = -34;
    o6.csg.z = 2;

//
    o7.cid.x = -4;
    o7.cid.y = -38;
    o7.cid.z =  -2;

    o7.cig.x = 0;
    o7.cig.y = -38;
    o7.cig.z = -2;

    o7.csd.x = -4;
    o7.csd.y = -38;
    o7.csd.z = 2;

    o7.csg.x = 0;
    o7.csg.y = -38;
    o7.csg.z = 2;

//
    
    o8.cid.x = -4;
    o8.cid.y = -46;
    o8.cid.z =  -2;

    o8.cig.x = 4;
    o8.cig.y = -46;
    o8.cig.z = -2;

    o8.csd.x = -4;
    o8.csd.y = -46;
    o8.csd.z = -1;

    o8.csg.x = 4;
    o8.csg.y = -46;
    o8.csg.z = -1;

//

    o9.cid.x = -4;
    o9.cid.y = -46;
    o9.cid.z =  2;

    o9.cig.x = 4;
    o9.cig.y = -46;
    o9.cig.z = 2;

    o9.csd.x = -4;
    o9.csd.y = -46;
    o9.csd.z = 1;

    o9.csg.x = 4;
    o9.csg.y = -46;
    o9.csg.z = 1;

//

    o10.cid.x = - 4;
    o10.cid.y = -54;
    o10.cid.z =  -2;

    o10.cig.x = 4;
    o10.cig.y = -54;
    o10.cig.z = -2;

    o10.csd.x = -4;
    o10.csd.y = -54;
    o10.csd.z = 0;

    o10.csg.x = 4;
    o10.csg.y = -54;
    o10.csg.z = 0;

//

    o11.cid.x = - 4;
    o11.cid.y = -60;
    o11.cid.z =  1;

    o11.cig.x = 4;
    o11.cig.y = -60;
    o11.cig.z = 1;

    o11.csd.x = -4;
    o11.csd.y = -60;
    o11.csd.z = 2;

    o11.csg.x = 4;
    o11.csg.y = -60;
    o11.csg.z = 2;

//

    o12.cid.x = - 4;
    o12.cid.y = -68;
    o12.cid.z =  0;

    o12.cig.x = 4;
    o12.cig.y = -68;
    o12.cig.z = 0;

    o12.csd.x = -4;
    o12.csd.y = -68;
    o12.csd.z = 2;

    o12.csg.x = 4;
    o12.csg.y = -68;
    o12.csg.z = 2;

//

    o13.cid.x = - 4;
    o13.cid.y = - 80;
    o13.cid.z =  -2;

    o13.cig.x = 4;
    o13.cig.y = -80;
    o13.cig.z = -2;

    o13.csd.x = -4;
    o13.csd.y = -80;
    o13.csd.z =-1.5;

    o13.csg.x = 4;
    o13.csg.y = -80;
    o13.csg.z = -1.5;

//

    o14.cid.x = - 4;
    o14.cid.y = - 88;
    o14.cid.z =  -2;

    o14.cig.x = 4;
    o14.cig.y = -88;
    o14.cig.z = -2;

    o14.csd.x = -4;
    o14.csd.y = -88;
    o14.csd.z = -1;

    o14.csg.x = 4;
    o14.csg.y = -88;
    o14.csg.z = -1;

//

    o15.cid.x = - 4;
    o15.cid.y = - 92;
    o15.cid.z =  -2;

    o15.cig.x = 4;
    o15.cig.y = -92;
    o15.cig.z = -2;

    o15.csd.x = -4;
    o15.csd.y = -92;
    o15.csd.z = 0.5;

    o15.csg.x = 4;
    o15.csg.y = -92;
    o15.csg.z = 0.5;

//

    o16.cid.x = 3.5;
    o16.cid.y = - 100;
    o16.cid.z =  -2;

    o16.cig.x = 4;
    o16.cig.y = -100;
    o16.cig.z = -2;

    o16.csd.x = 3.5;
    o16.csd.y = -100;
    o16.csd.z = 2;

    o16.csg.x = 4;
    o16.csg.y = -100;
    o16.csg.z = 2;

//

    o17.cid.x = - 4;
    o17.cid.y = - 100;
    o17.cid.z =  -2;

    o17.cig.x = 0.5;
    o17.cig.y = -100;
    o17.cig.z = -2;

    o17.csd.x = -4;
    o17.csd.y = -100;
    o17.csd.z = 2;

    o17.csg.x = 0.5;
    o17.csg.y = -100;
    o17.csg.z = 2;

//

    o18.cid.x = 2.5;
    o18.cid.y = - 108;
    o18.cid.z =  -2;

    o18.cig.x = 4;
    o18.cig.y = -108;
    o18.cig.z = -2;

    o18.csd.x = 2.5;
    o18.csd.y = -108;
    o18.csd.z = 2;

    o18.csg.x = 4;
    o18.csg.y = -108;
    o18.csg.z = 2;

//

    o19.cid.x = - 4;
    o19.cid.y = - 108;
    o19.cid.z =  -2;

    o19.cig.x = -0.5;
    o19.cig.y = -108;
    o19.cig.z = -2;

    o19.csd.x = -4;
    o19.csd.y = -108;
    o19.csd.z = 2;

    o19.csg.x = -0.5;
    o19.csg.y = -108;
    o19.csg.z = 2;

//

    o20.cid.x = 1.5;
    o20.cid.y = - 116;
    o20.cid.z =  -2;

    o20.cig.x = 4;
    o20.cig.y = -116;
    o20.cig.z = -2;

    o20.csd.x = 1.5;
    o20.csd.y = -116;
    o20.csd.z = 2;

    o20.csg.x = 4;
    o20.csg.y = -116;
    o20.csg.z = 2;

//

    o21.cid.x = - 4;
    o21.cid.y = - 116;
    o21.cid.z =  -2;

    o21.cig.x = -1.5;
    o21.cig.y = -116;
    o21.cig.z = -2;

    o21.csd.x = -4;
    o21.csd.y = -116;
    o21.csd.z = 2;

    o21.csg.x = -1.5;
    o21.csg.y = -116;
    o21.csg.z = 2;

//

    o22.cid.x = 0.5;
    o22.cid.y = - 116;
    o22.cid.z =  -2;

    o22.cig.x = 4;
    o22.cig.y = -116;
    o22.cig.z = -2;

    o22.csd.x = 0.5;
    o22.csd.y = -116;
    o22.csd.z = 2;

    o22.csg.x = 4;
    o22.csg.y = -116;
    o22.csg.z = 2;

//

    o23.cid.x = - 4;
    o23.cid.y = - 116;
    o23.cid.z =  -2;

    o23.cig.x = -2.5;
    o23.cig.y = -116;
    o23.cig.z = -2;

    o23.csd.x = -4;
    o23.csd.y = -116;
    o23.csd.z = 2;

    o23.csg.x = -2.5;
    o23.csg.y = -116;
    o23.csg.z = 2;

//

    o24.cid.x = - 4;
    o24.cid.y = - 124;
    o24.cid.z =  -2;

    o24.cig.x = 4;
    o24.cig.y = -124;
    o24.cig.z = -2;

    o24.csd.x = -4;
    o24.csd.y = -124;
    o24.csd.z = 0;

    o24.csg.x = 4;
    o24.csg.y = -124;
    o24.csg.z = 0;

//

    o25.cid.x = - 4;
    o25.cid.y = - 132;
    o25.cid.z =  0;

    o25.cig.x = 4;
    o25.cig.y = -132;
    o25.cig.z = 0;

    o25.csd.x = -4;
    o25.csd.y = -132;
    o25.csd.z = 2;

    o25.csg.x = 4;
    o25.csg.y = -132;
    o25.csg.z = 2;

//

    final.cid.x = -4;
    final.cid.y = -178;
    final.cid.z = -2;

    final.cig.x = 4;
    final.cig.y = -178;
    final.cig.z = -2;

    final.csd.x = -4;
    final.csd.y = -178;
    final.csd.z = 2;

    final.csg.x = 4;
    final.csg.y = -178;
    final.csg.z = 2;
    
    obstacle_list[0] =  o1;
    obstacle_list[1] = o2;
    obstacle_list[2] = o3;
    obstacle_list[3] = o4;
    obstacle_list[4] = o5;
    obstacle_list[5] = o6;
    obstacle_list[6] = o7;
    obstacle_list[7] = o8;
    obstacle_list[8] = o9;
    obstacle_list[9] = o10;
    obstacle_list[10] = o11;
    obstacle_list[11] = o12;
    obstacle_list[12] = o13;
    obstacle_list[13] = o14;
    obstacle_list[14] = o15;
    obstacle_list[15] = o16;
    obstacle_list[16] = o17;
    obstacle_list[17] = o18;
    obstacle_list[18] = o19;
    obstacle_list[19] = o20;
    obstacle_list[20] = o21;
    obstacle_list[21] = o22;
    obstacle_list[22] = o23;
    obstacle_list[23] = o24;
    obstacle_list[24] = o25;
    obstacle_list[25] = final;   

    b1.type = 'c';
    b1.pos.x = 1;
    b1.pos.y = -10.;
    b1.pos.z = 0;

    b2.type = 'r';
    b2.pos.x = 1.5;
    b2.pos.y = -100;
    b2.pos.z = -0.5;

    b3.type = 'g';
    b3.pos.x = 2;
    b3.pos.y = -92;
    b3.pos.z = 1;

    b4.type = 'v';
    b4.pos.x = 1;
    b4.pos.y = -46;
    b4.pos.z = 0.5;

    b5.type = 'v';
    b5.pos.x = 1;
    b5.pos.y = -6.5;
    b5.pos.z = 1;

    m1.type = 'a';
    m1.pos.x = -2;
    m1.pos.y = -30;
    m1.pos.z = -1;

    m2.type = 'p';
    m2.pos.x = 2;
    m2.pos.y = -80;
    m2.pos.z = -1;


    takeable_list[0] = b1;
    takeable_list[1] = b4;
    takeable_list[2] = m2;
    takeable_list[3] = b3;
    takeable_list[4] = m1;
    takeable_list[5] = b2;

};



