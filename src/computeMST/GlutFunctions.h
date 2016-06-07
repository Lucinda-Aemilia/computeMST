#pragma once

#ifdef FREEGLUT

#include <vector>
#include <GL/glut.h>

#include "Settings.h"
#include "Graph2D.h"
#include "Window.h"

/// The GLUT display function.
///
/// Draws the points, Delaunay edges, MST and so on.
void display();

/// The GLUT reshape function.
///
/// Sets the view port to the whole window and resets modelview matrix,
/// so that the graph is shown in the middle of the window.
void reshape(int width, int height);

/// The GLUT keyboard function.
///
/// - key 'Esc': exit the window
void processNormalKeys(unsigned char key, int x, int y);

/// The GLUT special keyboard function.
///
/// - Left arrow key: switch between test graphs
/// - Right arrow key: switch between test graphs
/// - Up arrow key: switch between spanning trees
/// - Down arrow key: switch between spanning trees
void processSpecialKeys(int key, int x, int y);

/// Initialize GLUT rendering.
///
/// - Smooth rendering for points and edges
/// Background color: light gray (0.9, 0.9, 0.9, 1)
void initRendering();

/// Create pop-up menus for the window
void createGLUTMenus();

/// Sub-menu 'New' process function
void processNewMenu(int option);

/// Sub-menu 'Show' process function
void processShowMenu(int option);

/// Sub-menu 'Test' process function
void processTestMenu(int option);

/// Main menu process function
void processMainMenu(int option);

#endif // FREEGLUT
