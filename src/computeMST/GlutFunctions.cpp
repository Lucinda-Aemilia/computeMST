#ifdef FREEGLUT

#include "GlutFunctions.h"

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    cmst::Window::instance()->draw();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    cmst::Window::instance()->resetWidth(width);
    cmst::Window::instance()->resetHeight(height);
    // 这里要设置opengl在窗口的绘图区域，一般是整个窗口
    /*
    int actualHeight, actualWidth;
    if ( (double)height/width < MAX_Y/MAX_X)
    {
        actualHeight = height;
        actualWidth = std::floor(height*MAX_X/MAX_Y);
        glViewport( (width-actualWidth)/2, 0, actualWidth, height );
    }
    else
    {
        actualWidth = width;
        actualHeight = std::floor(width*MAX_Y/MAX_X);
        glViewport( 0, (height-actualHeight)/2, width, actualHeight );
    }
    */
    // std::cout << (double)height/width << ' ' << MAX_Y/MAX_X << std::endl;
    // std::cout << width << ' ' << height << ' ' <<actualWidth << ' ' << actualHeight << std::endl;

    //设置视窗口的位置大小,注意原点（0,0）在屏幕画面左下角
    // need to think here
    glViewport(0, 0, width, height);
    // glViewport( (width-side)/2, (height-side)/2, (width+side)/2, (height+side)/2 );

    // 一般只在窗口reshape时才重新设定下投影矩阵和模型矩阵
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // 镜头默认在坐标原点看向Z轴负方向，而glOrtho最后两个参数表示
    // 距离镜头zNear到zFar距离间的图形才可以看到
    // 而且默认坐标系Z轴正方向是指向屏幕朝外侧的，
    // 你设置成0, 40就只能看到Z坐标( -40, 0 )间的物体，
    // 所以zNear给个负数，就能看到Z坐标为正的物体了
    if ((double)height/width < MAX_Y/MAX_X)
        // glOrtho( 0, MAX_Y*width/height, 0, MAX_Y, -40, 40 );
        glOrtho( (MAX_X-MAX_Y*width/height)/2, (MAX_Y*width/height+MAX_X)/2, 0, MAX_Y, -40, 40 );
    else
        glOrtho( 0, MAX_X, (MAX_Y-MAX_X*height/width)/2, (MAX_Y+MAX_X*height/width)/2, -40, 40 );

    // 投影矩阵设好后再将当前矩阵设置为模型矩阵，
    // 方便后续的图形绘制和图形变换
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void createGLUTMenus()
{
	// create the menu and
	// tell glut that "processMenuEvents" will
	// handle the events
	int newMenu = glutCreateMenu(processNewMenu);
	glutAddMenuEntry("Generate (2-10)", cmst::Menu::NEW_4_10);
	glutAddMenuEntry("Generate (11-100)", cmst::Menu::NEW_11_100);
	glutAddMenuEntry("Generate (101-1000)", cmst::Menu::NEW_101_1000);
	glutAddMenuEntry("Generate (1001-5000)", cmst::Menu::NEW_1001_5000);

	int showMenu = glutCreateMenu(processShowMenu);
	// glutAddMenuEntry("Voronoi", cmst::Menu::SHOW_VORONOI);
	glutAddMenuEntry("Delaunay", cmst::Menu::SHOW_DELAUNAY);

	int mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("Generate", newMenu);
	glutAddSubMenu("Show", showMenu);
	glutAddMenuEntry("Quit", cmst::Menu::QUIT);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void processNewMenu(int option)
{
    switch (option)
    {
    case cmst::Menu::NEW_4_10 :
        std::cout << "Running..." << std::endl;
        cmst::Window::instance()->resetCurGraph(4, 10);
        cmst::Window::instance()->printCurInfo();
        break;
    case cmst::Menu::NEW_11_100 :
        std::cout << "Running..." << std::endl;
        cmst::Window::instance()->resetCurGraph(11, 100);
        cmst::Window::instance()->printCurInfo();
        break;
    case cmst::Menu::NEW_101_1000 :
        std::cout << "Running..." << std::endl;
        cmst::Window::instance()->resetCurGraph(101, 1000);
        cmst::Window::instance()->printCurInfo();
        break;
    case cmst::Menu::NEW_1001_5000 :
        std::cout << "Running..." << std::endl;
        cmst::Window::instance()->resetCurGraph(1001, 5000);
        cmst::Window::instance()->printCurInfo();
        break;
    }
}

void processShowMenu(int option)
{
    switch (option)
    {
    /*
    case cmst::Menu::SHOW_VORONOI :
        cmst::Window::instance()->resetShowVoronoi();
        break;
    */
    case cmst::Menu::SHOW_DELAUNAY :
        cmst::Window::instance()->resetShowDelaunay();
        break;
    }
}

void processMainMenu(int option)
{
	switch (option)
	{
    case cmst::Menu::QUIT :
        exit(0);
        break;
	}
}

#endif // FREEGLUT
