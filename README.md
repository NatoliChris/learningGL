# Learning GL 
*Huge shoutout to Scott Greenup! Inspirational person who has unparallelled ability at coding! Check out his [github](https://github.com/scottgreenup).

Chapters:
1. Setups and basic concepts
2. Shapes 
1. Triangle
2. Square

*Last Update: 14/05/2015*


## 1. Setups and basics
Setting up requires glfw package, makes things easier for starting. Language used is ``c++`` which means that the ``#include <GLFW/glfw3.h>`` is needed to perform. 

#### Basic Concepts: 
* Model View Projection
* Very important
* Handles how the objects are then displayed onto the screen
* Basic concepts:
```
Model << local -> camera
View << camera -> world
Projection << world -> screen 
```

* Ratio is important especially when working with perspective/orthogonal, ensures that everything is displayed correctly

## 2. Shapes
### Notes on working with shapes
* ***Very important: When you draw a shape, make sure the points you put are in a adjacent in order!!***
* Shapes points are determined from the centre of the shape.
* *Protip: draw out the shape and work the points on paper prior to constructing the code.*
### Triangles
```c++
#include <GLFW/glfw3.h>

glBegin(GL_TRIANGLES);
glColor3f(1.f, 0.f, 0.f); //colours (R,G,B) [1.0 = max]
glVertex3f(-0.6f, -0.4f, 0.f); //First point, (x,y,z) coordinate from center

glColor3f(0.f, 1.f, 0.f); 
glVertex3f(0.6f, -0.4f, 0.f);

glColor3f(0.f, 0.f, 1.f);
glVertex3f(0.f, 0.6f, 0.f);

glEnd();
```

### Squares
```c++
glBegin(GL_QUADS);
glColor3f(1.f, 1.f, 1.f); //colours in RGB
glVertex3f(0.2, 0.2, 0.f); //points in (x,y,z);

glColor3f(0.f, 1.f, 0.f);
glVertex3f(0.2, -0.2, 0.f);

glColor3f(1.f, 0.f, 0.f);
glVertex3f(-0.2, -0.2, 0.f);

glColor3f(0.f, 0.f, 1.f);
glVertex3f(-0.2, 0.2, 0.f);
glEnd();
```
