#include "../inc/draw_scene.h"
#include "../inc/3D_tools.h"

void drawCorridor(){
    glPushMatrix();
    glColor3f(1,0.,0.);
    glScalef(4.,35.,0.);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.9,0.8,0.2);
    glScalef(1.,35.,4.);
    glRotatef(90.0, 0., 1., 0.);
    glTranslatef(1., 0., 0.);
    
    drawSquare();
    glPopMatrix();
    
}

void drawBase() 
{
    glPushMatrix();
        glScalef(3.,3.,0.);
        drawCircle();
    glPopMatrix();
    glPushMatrix();
        glScalef(2.,2.,10.);
        drawCone();
    glPopMatrix();
    
}

void drawArm() 
{
    glColor3f(0.95,0.65,0.21);
    glPushMatrix();
        glScalef(1.6,1.6,1.6);
        drawSphere();
    glPopMatrix();

    
    glPushMatrix();
        glScalef(10.,1.,1.);
        glRotatef(90,0.,1.,0.);
        drawCone();
    glPopMatrix();
    glPushMatrix();
        glScalef(10.,1.,1.);
        glRotatef(-90,0.,1.,0.);
        drawCone();
    glPopMatrix();



}

void drawPan() 
{
    glColor3f(0.,1.,1.);
    glPushMatrix();
        glTranslatef(0.,0.,-5.);
        glScalef(3.,3.,3.);
        drawCircle();
    glPopMatrix();
    glColor3f(1.,0.,0.);
    glBegin(GL_LINES);
        glVertex3f(0.,0.,0.);
        glVertex3f(cos(0)*3.,sin(0)*3.,-5.0);
        
        glVertex3f(0.,0.,0.);
        glVertex3f(cos(toRad(120))*3.,sin(toRad(120))*3.,-5.0);

        glVertex3f(0.,0.,0.);
        glVertex3f(cos(toRad(240))*3.,sin(toRad(240))*3.,-5.0);
    glEnd();

    
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
