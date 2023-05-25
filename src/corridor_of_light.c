#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../inc/3D_tools.h"
#include "../inc/draw_scene.h"


/* Window properties */
static const unsigned int WINDOW_WIDTH = 1000;
static const unsigned int WINDOW_HEIGHT = 1000;
static const char WINDOW_TITLE[] = "Corridor";
static float aspectRatio = 1.0;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* IHM flag */
static int flag_animate_rot_scale = 0;
static int flag_animate_rot_arm = 0;

/* Variable */
float speed = 0.3f;
double angle = 0; // en degré
double angle_scale = 0;

/*Menu Handlers*/
static int running = 0;
static int rules = 0;
static int new_game = 0;
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
	gluPerspective(60.0,aspectRatio,Z_NEAR,Z_FAR);
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
				if(running==1 && menu==0)
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
			case GLFW_KEY_R :
				flag_animate_rot_arm = 1-flag_animate_rot_arm;
				break;
			case GLFW_KEY_T :
				flag_animate_rot_scale = 1-flag_animate_rot_scale;
				break;
				if(dist_zoom>1.0f) dist_zoom*=0.9;
				printf("Zoom is %f\n",dist_zoom);
				break;
			case GLFW_KEY_UP :
				if (phy>2) phy -= 2;
				printf("Phy %f\n",phy);
				break;
			case GLFW_KEY_DOWN :
				if (phy<=88.) phy += 2;
				printf("Phy %f\n",phy);
				break;
			case GLFW_KEY_LEFT :
				theta -= 5;
				printf("Theta %f\n",theta);
				break;
			case GLFW_KEY_RIGHT :
				theta += 5;
				printf("Theta %f\n",theta);
				break;
			default: fprintf(stdout,"Touche non gérée (%d)\n",key);
		}
	}
}

void mouse_button_callback(GLFWwindow* window,int button, int action, int mods)
{
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		double x,y;
		glfwGetCursorPos(window,&x,&y);
		if(menu == 1 && x >= 300 && x<= 720)
		{
			if(y>=330 && y<=370)
			{
				//Nouvelle Partie
				menu = 0;
				new_game = 1;
				running = 1;
			}
			if(y>=426 && y<=460)
			{
				//Règles
				menu = 0;
				rules = 1;
			}
			if(y>=520 && y<=560 && running == 1)
			{
				//Resume
				menu = 0 ;
				running = 1;
			}
			if(y>=615 && y<=655)
			{
				//Quitter
				menu = 0;
				quit = 1;
			}
		}

	}
	return;
};

int main(int argc, char** argv)
{
	drawFrame();
	/* GLFW initialisation */
	GLFWwindow* window;
	if (!glfwInit()) return -1;

	/* Callback to a function if an error is rised by GLFW */
	glfwSetErrorCallback(onError);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		// If no context created : exit !
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window,onWindowResized);
	glfwSetKeyCallback(window, onKey);
	glfwSetMouseButtonCallback(window,mouse_button_callback);

	onWindowResized(window,WINDOW_WIDTH,WINDOW_HEIGHT);

	glPointSize(5.0);
	glEnable(GL_DEPTH_TEST);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Get time (in second) at loop beginning */
		double startTime = glfwGetTime();

		/* Cleaning buffers and setting Matrix Mode */
		glClearColor(0.2,0.0,0.0,0.0);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		setCamera();
		

		/* Initial scenery  setup */
		
		drawFrame();

		/* Scene rendering */
		

		if(running == 1)
		{
			drawCorridor();
			glPushMatrix();
				glRotatef(180.,0.,1.,0.);
				drawCorridor();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.,-2.5,-1.2);
				glScalef(0.5, 0.5, 0.5);
				drawCircle();
			glPopMatrix();
			//Pour gérer les parties : il va y avoir une liste d'obstacles (nombre fixe, générés aléatoirement ou non).
			//Une fois que tous les obstacles sont passés, la partie se termine. 
			if(new_game == 1)
			{
				//si c'est une nouvelle parie on recharge dans la liste une nouvelle serie d'obstacle,
				//on remet le compteur de score à zéro, et on redonne toute ses vies au joueur.
				new_game = 0;
			}
			
			//ballz();
			//drawHUD();
		}
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


		
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
		angle += 20 ;
		angle_scale += 5;

		/* Elapsed time computation from loop begining */
		double elapsedTime = glfwGetTime() - startTime;
		/* If to few time is spend vs our wanted FPS, we wait */
		if(elapsedTime < FRAMERATE_IN_SECONDS)
		{
			glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS-elapsedTime);
		}

		/* Animate scenery */
	}

	glfwTerminate();
	return 0;
}
