#include "../inc/draw_scene.h"


void drawSection(float r1,float g1,float b1,float r2,float g2, float b2){ 
// Une section est un coin du couloir, les paramètres déterminent la couleur des deux carrés composants le coin
    glPushMatrix();
    
    glTranslatef(0.,-4.5,2.);
    glScalef(8.,4.,0.);
    
    drawSquare(r1,g1,b1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4., -4.5, 0.);
    glScalef(1.,4.,4.);
    glRotatef(90.0, 0., 1., 0.);
    
    
    drawSquare(r2,g2,b2);
    glPopMatrix();
    
}

void drawCorridor()
{
    drawSection(0.259,0.086,0.125,0.518,0.220,0.035);
    glPushMatrix();
            glRotatef(180.,0.,1.,0.);
            drawSection(0.259,0.086,0.125,0.518,0.220,0.035);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.,-4.,0.);
        drawSection(0.16,0.020,0.004,0.404,0.160,0.071);
        glPushMatrix();
            glRotatef(180.,0.,1.,0.);
            drawSection(0.16,0.020,0.004,0.404,0.160,0.071);
        glPopMatrix();
        glTranslatef(0.,-4.,0.);
        drawSection(0.060,0.011,0.004,0.254,0.117,0.078);
        glPushMatrix();
            glRotatef(180.,0.,1.,0.);
            drawSection(0.060,0.011,0.004,0.254,0.117,0.078);
        glPopMatrix();
        glTranslatef(0.,-4.,0.);
        drawSection(0.,0.,0.,0.16,0.020,0.004);
        glPushMatrix();
            glRotatef(180.,0.,1.,0.);
            drawSection(0.,0.,0.,0.16,0.020,0.004);
        glPopMatrix();
    glPopMatrix();
};

void drawLineSpeed()
{
    for(int i = 0; i<4 ; i++ )
    {
    glBegin(GL_LINES);
        glPushMatrix();
            glColor3f(1.,1.,1.);
        
            glVertex3f(line_speed[i].cid.x,line_speed[i].cid.y,line_speed[i].cid.z);
            glVertex3f(line_speed[i].cig.x,line_speed[i].cig.y,line_speed[i].cig.z);
            glVertex3f(line_speed[i].cig.x,line_speed[i].cig.y,line_speed[i].cig.z);
            glVertex3f(line_speed[i].csg.x,line_speed[i].csg.y,line_speed[i].csg.z);
            glVertex3f(line_speed[i].csg.x,line_speed[i].csg.y,line_speed[i].csg.z);
            glVertex3f(line_speed[i].csd.x,line_speed[i].csd.y,line_speed[i].csd.z);
            glVertex3f(line_speed[i].csd.x,line_speed[i].csd.y,line_speed[i].csd.z);
            glVertex3f(line_speed[i].cid.x,line_speed[i].cid.y,line_speed[i].cid.z);     

        glPopMatrix();
    glEnd();
    }
}

void drawObstacles()
{
    
    for(int i=0;i<totalObs;i++)
    {
        if(obstacle_list[i].cid.y<-2.5 && obstacle_list[i].cid.y>-18.5)
        {
                glPushMatrix();
                    glColor3f(0.518,0.220,0.035);
                        glBegin(GL_TRIANGLE_FAN);
                        glVertex3f(obstacle_list[i].cid.x,obstacle_list[i].cid.y,obstacle_list[i].cid.z);
                        glVertex3f(obstacle_list[i].cig.x,obstacle_list[i].cid.y,obstacle_list[i].cig.z);
                        glVertex3f(obstacle_list[i].csg.x,obstacle_list[i].csg.y,obstacle_list[i].csg.z);
                        glVertex3f(obstacle_list[i].csd.x,obstacle_list[i].csd.y,obstacle_list[i].csd.z);
		                glEnd();
                glPopMatrix();  
        };
    };
    


};

void drawBallz()
{
    glPushMatrix();
        //glTranslatef(balle->centre.x,balle->centre.y,balle->centre.z);
        //drawCircle(balle->r);
        glColor3f(1.,0.,0.);
        glTranslatef(balle[0],balle[1],balle[2]);
        drawCircle(balle[3]);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.,0.,0.);
        glTranslatef(balle[0],balle[1],-2);
        glRotatef(90.,1.,0.,0.);
        drawCircle(balle[3]);
    glPopMatrix();
};

void drawMenu()
{
	glPushMatrix();
        glRotatef(90.,1.,0.,0.);
        glScalef(5.33f,2.75f,0.);
        drawSquare(0.,0.,0.);
    glPopMatrix();
    glPushMatrix();
        glRotatef(90.f,1.f,0.,0.);
        glPushMatrix();
            glTranslatef(0.,0.75,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(0.,0.,1.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,0.25,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(0.,1.,0.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,-0.25,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(1.,1.,1.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,-0.75,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(1.,0.,0.);
        glPopMatrix();
    glPopMatrix();
};

void gameOver()
{
    glPushMatrix();
        glRotatef(90.,1.,0.,0.);
        glScalef(5.33f,2.75f,0.);
        drawSquare(0.,0.,0.);
    glPopMatrix();
    glPushMatrix();
        glRotatef(90.f,1.f,0.,0.);
        glPushMatrix();
            glTranslatef(-1.2,-1.,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(1.,0.,0.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1.2,-1.,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(0.,0.,1.);
        glPopMatrix();



    glPopMatrix();

}

void drawFrame() {
    glBegin(GL_LINES);
        glColor3f(1.,0.,0.);
        glVertex3f(1.,0.,0.);
        glVertex3f(0.,0.,0.);
        glColor3f(0.,1.,0.);
        glVertex3f(0.,1.,0.);
        glVertex3f(0.,0.,0.);
        glColor3f(0.,0.,1.);
        glVertex3f(0.,0.,1.);
        glVertex3f(0.,0.,0.);
    glEnd();
}

void drawTakeable()
{
    for(int i = 0 ; i<totalTake ;i++)
    {
        if(takeable_list[i].pos.y<-2.5 && takeable_list[i].pos.y>-18.5)
        {
            glPushMatrix();
                if(takeable_list[i].type == 'v' || takeable_list[i].type == 'g' || takeable_list[i].type == 'r' || takeable_list[i].type == 'c')
                {
                    glColor3f(0.,1.,0.);
                }else{glColor3f(1.,0.,0.);}
                glBegin(GL_LINES);
                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z-0.25);
                glVertex3f(takeable_list[i].pos.x-(0.25*cos(toRad(rotation))),takeable_list[i].pos.y-(0.25*sin(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z-0.25);
                glVertex3f(takeable_list[i].pos.x+(0.25*cos(toRad(rotation))),takeable_list[i].pos.y+(0.25*sin(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z-0.25);
                glVertex3f(takeable_list[i].pos.x-(0.25*sin(toRad(rotation))),takeable_list[i].pos.y-(0.25*cos(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z-0.25);
                glVertex3f(takeable_list[i].pos.x+(0.25*sin(toRad(rotation))),takeable_list[i].pos.y+(0.25*cos(toRad(rotation))),takeable_list[i].pos.z);   

                
                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z+0.25);
                glVertex3f(takeable_list[i].pos.x-(0.25*cos(toRad(rotation))),takeable_list[i].pos.y-(0.25*sin(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z+0.25);
                glVertex3f(takeable_list[i].pos.x+(0.25*cos(toRad(rotation))),takeable_list[i].pos.y+(0.25*sin(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z+0.25);
                glVertex3f(takeable_list[i].pos.x-(0.25*sin(toRad(rotation))),takeable_list[i].pos.y-(0.25*cos(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x,takeable_list[i].pos.y,takeable_list[i].pos.z+0.25);
                glVertex3f(takeable_list[i].pos.x+(0.25*sin(toRad(rotation))),takeable_list[i].pos.y+(0.25*cos(toRad(rotation))),takeable_list[i].pos.z);

                glVertex3f(takeable_list[i].pos.x-(0.25*cos(toRad(rotation))),takeable_list[i].pos.y-(0.25*sin(toRad(rotation))),takeable_list[i].pos.z);
                glVertex3f(takeable_list[i].pos.x+(0.25*cos(toRad(rotation))),takeable_list[i].pos.y+(0.25*sin(toRad(rotation))),takeable_list[i].pos.z);
                glVertex3f(takeable_list[i].pos.x-(0.25*sin(toRad(rotation))),takeable_list[i].pos.y-(0.25*cos(toRad(rotation))),takeable_list[i].pos.z);
                glVertex3f(takeable_list[i].pos.x+(0.25*sin(toRad(rotation))),takeable_list[i].pos.y+(0.25*cos(toRad(rotation))),takeable_list[i].pos.z);   
                
                glEnd();
            glPopMatrix();
        }
    }
}