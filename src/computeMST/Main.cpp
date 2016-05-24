#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <array>
#include <ctime>

#include "delaunay-triangulation/delaunay.h"
#include "Graph2D.h"
#include "TestcaseGenerator.h"
#include "Settings.h"

#ifdef FREEGLUT
#include <GL/glut.h>
#include "GlutFunctions.h"
// #include <windows.h>
#endif // FREEGLUT

std::stringstream debugout;
Graph2D* myGraph = NULL;

void Initialize()
{

}

void CleanUp()
{
    #ifdef DEBUG
    // Write to log
    std::ofstream logout("log.txt");
    logout << debugout.str();
    logout.close();
    #endif // DEBUG

    delete myGraph;
}

int main(int argc, char** argv)
{
    Initialize();

	std::vector<Vec2f> points(TestcaseGenerator());

    myGraph = new Graph2D(points);
    double mstLength = myGraph->Kruskal();
    std::cout << "The length of the minimal spanning tree: " << mstLength << std::endl;

    #ifdef FREEGLUT

    glutInit( &argc, argv );
    glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize ( 800, 600 );
    glutInitWindowPosition ( 0, 0 );
    glutCreateWindow ( "Compute MST" );

    // These should be put in initRendering()
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // Make round points, not square points
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);  // Antialias the lines
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor( 0.9, 0.9, 0.9, 1 );

    glutDisplayFunc( display );
    glutReshapeFunc( reshape );   // ���������
    glutMainLoop();

    #endif // FREEGLUT

    CleanUp();

	return 0;
}
