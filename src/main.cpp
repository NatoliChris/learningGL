#include <GLFW/glfw3.h>
#include <iostream>
#include <Math.h>

#define PI 3.141592653589793

void render(GLFWwindow* window){
    float ratio;
    int width, height;

    glfwGetFramebufferSize(window, &width, &height); //get the size of the buffer

    ratio = width / (float) height; //get screen ratio
    glViewport(0, 0, width, height); //set the viewport

    glClear(GL_COLOR_BUFFER_BIT); //clear the buffer

    //setting the matrix and the orthogonal, setting up the viewport
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
     glMatrixMode(GL_MODELVIEW);

     glLoadIdentity();
     //glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
     glBegin(GL_POLYGON);
     float r = 2*PI;
     for(float angle = 0; angle < r; angle += 0.01){
/* Colouring circle multiple colours
        if(angle > 0 && angle <= (1/3.0)*r){
            glColor3f(0.f, 1.f, 0.f);
         } else if(angle > (1/3.0)*r && angle <=(2/3.0)*r){
            glColor3f(1.f, 0.f, 0.f);
         } else {
            glColor3f(0.f, 0.f, 1.f);
         }
*/
         //making pacman
         if(angle > (1.5/3.0)*r && angle <= (1.8/3.0)*r){
            glColor3f(0.f, 0.f, 0.f);
         } else {
            glColor3f(1.f, 1.f, 0.f);
         }
         glVertex3f(0.2f*cos(angle), 0.2f*sin(angle), 0);
     }
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.f, 1.f, 1.f);
     glVertex3f(-0.4, 0.8, 0.f);

     glColor3f(0.f, 1.f, 0.f);
     glVertex3f(-0.4, 0.4, 0.f);

     glColor3f(1.f, 0.f, 0.f);
     glVertex3f(-0.8, 0.4, 0.f);


     glColor3f(0.f, 0.f, 1.f);
     glVertex3f(-0.8, 0.8, 0.f);
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3f(0.6f, 0.7f, 0.3f);
     glVertex3f(0.6f, 0.8f, 0.f);

     glColor3f(1.f, 0.f, 0.f);
     glVertex3f(0.8f, 0.4f, 0.f);

     glColor3f(0.f, 0.f, 1.f);
     glVertex3f(0.4f, 0.4f, 0.f);

     glEnd();

     glfwSwapBuffers(window);
}

bool update(){
    return true;
}

int main(void){
    if(!glfwInit()){
        fprintf(stdout, "Error, failed to initialise GLFW\n");
        exit(EXIT_FAILURE);
    }

    GLFWwindow* window;

    window = glfwCreateWindow(640, 480, "First GL", NULL, NULL);

    if(!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    if(!glfwWindowShouldClose(window)){

    }
    while(!glfwWindowShouldClose(window)){
        render(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
