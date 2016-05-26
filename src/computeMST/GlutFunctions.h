#pragma once

#ifdef FREEGLUT

#include <vector>
#include <GL/glut.h>

#include "Settings.h"
#include "Graph2D.h"
#include "Window.h"

void display();

void reshape(int width, int height);

void createGLUTMenus();

void processMenuEvents(int option);

#endif // FREEGLUT
