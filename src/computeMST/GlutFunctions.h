#pragma once

#ifdef FREEGLUT

#include <vector>
#include <GL/glut.h>

#include "Settings.h"
#include "Graph2D.h"
#include "Window.h"

void display();

void reshape(int width, int height);

void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

void createGLUTMenus();

void processNewMenu(int option);

void processShowMenu(int option);

void processTestMenu(int option);

void processMainMenu(int option);

#endif // FREEGLUT
