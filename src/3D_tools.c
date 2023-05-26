#include "../inc/3D_tools.h"

/* Camera parameters and functions */
float theta = 90.0f; // Angle between x axis and viewpoint
float phy = 90.0f; // Angle between z axis and viewpoint
float dist_zoom = 5.0f; // Distance between origin and viewpoint

void setCamera() {
	gluLookAt(dist_zoom*cos(toRad(theta))*sin(toRad(phy)),
			  dist_zoom*sin(toRad(theta))*sin(toRad(phy)),
			  dist_zoom*cos(toRad(phy)),
			  0.0,0.0,0.0,
			  0.0,0.0,1.0);
}

/* Convert degree to radians */
float toRad(float deg) {
	return deg*M_PI/180.0f;
}

void drawSquare(float r,float g,float b) {
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(r,g,b);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,-0.5,0.0);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(-0.5,0.5,0.0);
	glEnd();
}


void drawRaquette(float x, float y) {
	glPushMatrix();
		glColor3f(1., 0.5, 0.);
		glTranslatef(x, -2.5, y);
		glRotatef(90., 1., 0., 0.);
		glBegin(GL_LINE_LOOP);
			glVertex3f(-0.5, -0.5, 0.0);
			glVertex3f(0.5, -0.5, 0.0);
			glVertex3f(0.5, 0.5, 0.0);
			glVertex3f(-0.5, 0.5, 0.0);
		glEnd();
	glPopMatrix();
	
}


void drawCircle() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f); // Rotation de 90 degrés autour de l'axe  x
	glBegin(GL_TRIANGLE_FAN);
		
		glVertex3f(0.0f, 0.0f, 0.0f);
		float step_rad = 2 * M_PI / (float)NB_SEG_CIRCLE;
		for (int i = 0; i <= NB_SEG_CIRCLE; i++) {
			glVertex3f(cos(i * step_rad), sin(i * step_rad), 0.0f);
		}
		
	glEnd();
	glPopMatrix();
}




void drawCone() {
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0,0.0,1.0);
		float step_rad = 2*M_PI/(float)NB_SEG_CIRCLE;
		for(int i=0;i<=NB_SEG_CIRCLE;i++) {
			glVertex3f(cos(i*step_rad),sin(i*step_rad),0.0f);
		}
	glEnd();
}

void drawSphere() {
	gluSphere(gluNewQuadric(),1.0,NB_SEG_CIRCLE,NB_SEG_CIRCLE);
}

