#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/3D_tools.h"
#include "../inc/draw_scene.h"
#include "../inc/structures.h"
#include "../inc/interactions.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../inc/stb_image.h"

/* Window properties */
static const unsigned int WINDOW_WIDTH = 1000;
static const unsigned int WINDOW_HEIGHT = 1000;
static const char WINDOW_TITLE[] = "Corridor";
static float aspectRatio = 1.0;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 60.;


/*Menu Handlers*/
static int running = 0;
static int rules = 0;
static int new_game = 1;
static int quit = 0;
static int menu = 1;

/* Error handling function */
void onError(int error, const char* description)
{
    fprintf(stderr, "GLFW Error: %s\n", description);
}

void onWindowResized(GLFWwindow* window, int width, int height)
{
    aspectRatio = width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspectRatio, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		switch(key) {
			case GLFW_KEY_A :
				glfwSetWindowShouldClose(window, GLFW_TRUE);
				break;
			case GLFW_KEY_ESCAPE :
				if((running==1|rules==1) && menu==0)
				{
					menu = 1;
					speed = 0;
					printf("Menu %i\n",menu);
				}
				else{
					if(running==1 && menu == 1)
					{
						menu = 0;
						speed = 0.3f;
						printf("Menu %i\n",menu);
					};
				};
				break;
			case GLFW_KEY_L :
				glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
				break;
			case GLFW_KEY_P :
				glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
				break;
			default: fprintf(stdout,"Touche non gérée (%d)\n",key);
		}
	}
}



void onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
	// Diviser par une constante pour ajuster l'échelle de la translation
    float normalizedX = (float)((xpos/(WINDOW_WIDTH/(8)) - 4));
    float normalizedY = (float)((ypos/(WINDOW_HEIGHT/(8)) - 4));
	if((normalizedX<3.5 && normalizedY<1.5) && (normalizedX>-3.5 && normalizedY>-1.5))
	{
		if(balle[7]!=0 && (balle[1]==-2.5f && (balle[0]<(translate_x)+0.5 && balle[0]>(translate_x)-0.5) && (balle[2]<(translate_y)+0.5 && balle[2]>(translate_y)-0.5))) 
		{//la balle est collante et est collée  : il faut qu'elle suive les mouvements de la raquette.
			balle[0] = - normalizedX;
			balle[2] =  - normalizedY;
			balle[1] = -2.5;
		}

		translate_x = -normalizedX;
		translate_y = -normalizedY;
		

	}
}

void erreur(unsigned char *image){
    if(image != NULL){
        printf("reussi \n");
    }else{
        printf("rate \n");

    }
}

GLuint loadTexture(const char* imageName){
    int x = 400;
    int y = 400;
    int n = 200;
    int c = 0;
    GLuint texture;
    glGenTextures(1, &texture);
    unsigned char* image = stbi_load(imageName, &x, &y, &n, c);
    erreur(image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    stbi_image_free(image);
    return texture;
}


void mouse_button_callback(GLFWwindow* window,int button, int action, int mods)
{
	double x,y;
	glfwGetCursorPos(window,&x,&y);
	//Clic gauche (envoyer la balle et menu)
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		
		//Actions pour le menu
		if(menu == 1 && x >= (WINDOW_WIDTH/2)-190 && x<= (WINDOW_WIDTH/2)+190)
		{
			if(y>=(WINDOW_HEIGHT/2)-(28.5+80+57) && y<=(WINDOW_HEIGHT/2) - (28.5+40+57))
			{
				//Nouvelle Partie
				menu = 0;
				new_game = 1;
				running = 1;
				speed = 0.3f;
				
			}
			/*if(y>=(WINDOW_HEIGHT/2)-(28.5+40) && y<=(WINDOW_HEIGHT/2)-(28.5))
			{
				//Règles
				menu = 0;
				rules = 1;
			}Pas le temps ...*/
			if(y>=(WINDOW_HEIGHT/2)+28.5 && y<=(WINDOW_HEIGHT/2)+(28.5+40) && running == 1)
			{
				//Resume
				menu = 0 ;
				running = 1;
				speed = 0.3f;
			}
			if(y>=(WINDOW_HEIGHT/2)+(28.5+40+57) && y<=(WINDOW_HEIGHT/2)+(28.5+80+57))
			{
				//Quitter
				menu = 0;
				quit = 1;
			}
		}
		//Action pour envoyer la balle
		if(running==1 && (menu==0 && rules==0) && balle[7]!=0 && (balle[1]==-2.5f && (balle[0]<(translate_x)+0.5 && balle[0]>(translate_x)-0.5) && (balle[2]<(translate_y)+0.5 && balle[2]>(translate_y)-0.5)))
		{
			
			balle[7] --; //on perd un sticky dose
			if(balle[8]<0)
			{
				balle[5] = -cool_ball_speed;
				balle[1] -= 0.001f;
				balle[8]++;
			};
			if(balle[8]>0)
			{
				balle[5] = -speedy_ball_speed;
				balle[1] -= 0.001f;				
				balle[8]++;
			};
			if(balle[8]==0)
			{
				balle[5] = -normal_ball_speed;
				balle[1] -= 0.001f;
			};


		};
		//Action pour la page de règle
		if(rules==1)
		{

		};
		/*Actions pour le game over*/
		if(running == 1 && lives==0 && (y<715 && y>675))
		{
			printf("x : %f\n",x);
			printf("y : %f\n",y);
			if(x<460 && x>80)
			{
				new_game = 1;
			}
			if(x<920 && x>540)
			{
				quit = 1;
			}
		}
	};
	//Clic droit = Action "avancer" la raquette
	if(button==GLFW_MOUSE_BUTTON_RIGHT && GLFW_PRESS)
	{
		float normX = (float)((x/(WINDOW_WIDTH/(8)) - 4));
    	float normY = (float)((y/(WINDOW_HEIGHT/(8)) - 4));
		if((normX<3.5 && normY<1.5) && (normX>-3.5 && normY>-1.5)&&(!(balle[7]!=0 && (balle[1]==-2.5))))
		{
			state_right = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
		}
		else
		{
			state_right = 0;
		}
	};
};

int main(int argc, char** argv)
{
    /* GLFW initialization */
	
    GLFWwindow* window;
    if (!glfwInit()) return -1;

    /* Callback for GLFW errors */
    glfwSetErrorCallback(onError);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, onMouseMove);

	glfwSetWindowSizeCallback(window,onWindowResized);
	glfwSetKeyCallback(window, onKey);
	glfwSetCursorPosCallback(window, onMouseMove);
	glfwSetMouseButtonCallback(window,mouse_button_callback);

    //########_CHARGER_IMAGES_###################
    GLuint64 texture[32];

    // Charger image menu
	texture[0] = loadTexture("doc/VIE.jpg");

    // Charger image fin réussite
    //texture[1] = loadTexture("doc/JEU_ECHEC.jpg");

    // Charger image fin réussite
    //texture[2] = loadTexture("doc/POKEBALL_TEXTURE.jpg");

    glfwSetWindowSizeCallback(window,onWindowResized);


    onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);

    glPointSize(5.0);
    glEnable(GL_DEPTH_TEST);
	
	
	
	
    while (!glfwWindowShouldClose(window)) {
        double startTime = glfwGetTime();

        glClearColor(0.2, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
		setCamera();
		

		/* Scene rendering */
		
		if(running == 1)
		{
			
			if(new_game == 1)
			{
				
				init_structures(line_speed,obstacle_list,balle,takeable_list);
				lives =  5;
				
				//si c'est une nouvelle parie on recharge dans la liste une nouvelle serie d'obstacle,
				//on remet le compteur de score à zéro, et on redonne toute ses vies au joueur.
				new_game = 0;
			}
		
		
			
			if(menu == 0 && lives!=0 && end==0);
			{
				glPushMatrix();
					glTranslatef(0.,-40.,0.);	
					glRotatef(90.,1.,0.,0.);
					glScalef(60.,60.,0.);			
					drawSquare(0.,0.,0.);
				glPopMatrix();

				drawCorridor();	
				drawLineSpeed();
				drawObstacles();
				drawTakeable();
				
				drawBallz();

				glPushMatrix();
					glTranslatef(0.,-40.,0.);	
					glRotatef(90.,1.,0.,0.);
					glScalef(60.,60.,0.);			
					drawSquare(0.,0.,0.);
				glPopMatrix();
				glPushMatrix();
				glColor3f(1,1,1);
            glBindTexture(GL_TEXTURE_2D, texture[1]);
					for(int i = 0 ; i < lives ; i++)
					{	score(texture[1]);
						glTranslatef(0.6, 0., 0.);
					}	
				glPopMatrix();	

			glEnd();
				//Pour gérer les parties : il va y avoir une liste d'obstacles (nombre fixe, générés aléatoirement ou non).
				//Une fois que tous les obstacles sont passés, la partie se termine. 
			
				drawRaquette(translate_x, translate_y);
				if(state_right==GLFW_PRESS)
				{
					avance_joueur(line_speed,obstacle_list,takeable_list);	
				};
				avance_balle(balle);
			};
			//ballz();
			//drawHUD();
		}

		if(end == 1)
		{
				glPushMatrix();
					glTranslatef(0.,-40.,0.);	
					glRotatef(90.,1.,0.,0.);
					glScalef(60.,60.,0.);			
					drawSquare(0.,0.,0.);
				glPopMatrix();

				drawCorridor();	
				drawLineSpeed();
				drawObstacles();
				glPushMatrix();
					glTranslatef(0.,-40.,0.);	
					glRotatef(90.,1.,0.,0.);
					glScalef(60.,60.,0.);			
					drawSquare(0.,0.,0.);
				glPopMatrix();
				glPushMatrix();
				glColor3f(1,1,1);
            glBindTexture(GL_TEXTURE_2D, texture[1]);
					glTranslatef(3.2, 2.1, 2.);
					/*Petit bouquet final*/
					for(int j =0 ; j<lives*2 ; j++)
					{	glPushMatrix();
						glTranslatef(.2*j,0.,.2*j);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(.2,0.,.2*j);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(.2*j,0.,.2);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-.2*j,0.,.2*j);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(.2*j,0.,-.2*j);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-.2*j,0.,-.2*j);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(.2,0.,-.2*j);
						score(texture[1]);
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-.2*j,0.,.2);
						score(texture[1]);
						glPopMatrix();
					}
						
						
				glPopMatrix();

		};

		if(lives==0)
		{
			gameOver();
		};


		if(menu==1)
		{
			drawMenu();
		};


		if(rules==1)
		{

		};


		if(quit==1)
		{
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			return 0;
		}
		rotation += 3;
		
		glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);

        glfwSwapBuffers(window);
        glfwPollEvents();
        double elapsedTime = glfwGetTime() - startTime;
        if (elapsedTime < FRAMERATE_IN_SECONDS) {
            glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS - elapsedTime);
        }
    }

    glfwTerminate();
    return 0;
}
