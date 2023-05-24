#include "../inc/draw_scene.h"
#include "../inc/3D_tools.h"

void drawSection(float r1,float g1,float b1,float r2,float g2, float b2){ 
// Une section est un coin du couloir, le s paramètres déterminent la couleur des deux carrés composants le coin
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
