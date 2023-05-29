#include "../inc/draw_scene.h"
#include "../inc/3D_tools.h"
#include "../inc/structures.h"

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
    //Première moitié du couloir
    drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
    glPushMatrix();
			glRotatef(180.,0.,1.,0.);
			drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
	glPopMatrix();
    glPushMatrix();
        glTranslatef(0.,-4.,0.);
        drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
        glPushMatrix();
			glRotatef(180.,0.,1.,0.);
			drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
	    glPopMatrix();
        glTranslatef(0.,-4.,0.);
        drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
        glPushMatrix();
			glRotatef(180.,0.,1.,0.);
			drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
	    glPopMatrix();
        glTranslatef(0.,-4.,0.);
        drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
        glPushMatrix();
			glRotatef(180.,0.,1.,0.);
			drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
	    glPopMatrix();
    glPopMatrix();
    //Deuxième moitié du couloir
    glPushMatrix();
        drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
        glPushMatrix();
                glRotatef(180.,0.,1.,0.);
                drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,-4.,0.);
            drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
            glPushMatrix();
                glRotatef(180.,0.,1.,0.);
                drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
            glPopMatrix();
            glTranslatef(0.,-4.,0.);
            drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
            glPushMatrix();
                glRotatef(180.,0.,1.,0.);
                drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
            glPopMatrix();
            glTranslatef(0.,-4.,0.);
            drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
            glPushMatrix();
                glRotatef(180.,0.,1.,0.);
                drawSection(0.223,0.141,0.243,0.329,0.250,0.49);
            glPopMatrix();
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
    
   
    for(int i=0;i<((&obstacle_list)[1] - obstacle_list);i++)
    {
        if(obstacle_list[i].cid.y<-2.5)
        {
                glPushMatrix();
                    glColor3f(0.329,0.250,0.49);
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
            drawSquare(1.,1.,1.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,0.25,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(1.,1.,1.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,-0.25,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(1.,1.,1.);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.,-0.75,-0.5);
            glScalef(2.,0.2,0.);
            drawSquare(1.,1.,1.);
        glPopMatrix();
    glPopMatrix();
};

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
