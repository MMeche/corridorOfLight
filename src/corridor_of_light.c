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
static const char WINDOW_TITLE[] = "TD04 Ex01";
static float aspectRatio = 1.0;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 30.;

/* IHM flag */
static int flag_animate_rot_scale = 0;
static int flag_animate_rot_arm = 0;

/* Variable */
double angle = 0; // en degré
double angle_scale = 0;


/*Menu Handlers*/
static int started = 1;
static int rules = 0;
static int quit = 0;
static int menu = 0;

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
            case GLFW_KEY_ESCAPE :
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
            case GLFW_KEY_L :
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                break;
            case GLFW_KEY_P :
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            case GLFW_KEY_R :
                flag_animate_rot_arm = 1 - flag_animate_rot_arm;
                break;
            case GLFW_KEY_T :
                flag_animate_rot_scale = 1 - flag_animate_rot_scale;
                break;
            case GLFW_KEY_UP :
                if (dist_zoom > 1.0f)
                    dist_zoom *= 0.9;
                printf("Zoom is %f\n", dist_zoom);
                break;
            case GLFW_KEY_DOWN :
                if (dist_zoom <= 88.0)
                    dist_zoom += 2;
                printf("Zoom is %f\n", dist_zoom);
                break;
            case GLFW_KEY_LEFT :
                theta -= 5;
                printf("Theta %f\n", theta);
                break;
            case GLFW_KEY_RIGHT :
                theta += 5;
                printf("Theta %f\n", theta);
                break;
            default:
                fprintf(stdout, "Touche non gérée (%d)\n", key);
        }
    }
}

float translate_x = 0.0f;
float translate_y = 0.0f;

void onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
    float normalizedX = (float)(xpos / WINDOW_WIDTH) * 2 - 1;
    float normalizedY = (float)((WINDOW_HEIGHT - ypos) / WINDOW_HEIGHT) * 2 - 1;

    translate_x = normalizedX; // Diviser par une constante pour ajuster l'échelle de la translation
    translate_y = normalizedY;
}


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

    glfwSetWindowSizeCallback(window, onWindowResized);
    glfwSetKeyCallback(window, onKey);
    glfwSetCursorPosCallback(window, onMouseMove);

    onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);

    glPointSize(5.0);
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        double startTime = glfwGetTime();

        glClearColor(0.2, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        /* Initial scenery setup */
        drawFrame();

        /* Scene rendering */
        if (started == 1) {
            drawCorridor();
            glPushMatrix();
            glRotatef(180., 0., 1., 0.);
            drawCorridor();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0., -2.5, -1.2);
            glScalef(0.5, 0.5, 0.5);
            drawCircle();
            glPopMatrix();

            glPushMatrix();
            glColor3f(1., 0.5, 0.);
            glRotatef(90., 1., 0., 0.);
            drawCarre(translate_x, translate_y);
            glPopMatrix();
        }

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
