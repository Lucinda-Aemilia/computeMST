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
    // ����Ҫ����opengl�ڴ��ڵĻ�ͼ����һ������������
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

    //�����Ӵ��ڵ�λ�ô�С,ע��ԭ�㣨0,0������Ļ�������½�
    // need to think here
    glViewport(0, 0, width, height);
    // glViewport( (width-side)/2, (height-side)/2, (width+side)/2, (height+side)/2 );

    // һ��ֻ�ڴ���reshapeʱ�������趨��ͶӰ�����ģ�;���
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // ��ͷĬ��������ԭ�㿴��Z�Ḻ���򣬶�glOrtho�������������ʾ
    // ���뾵ͷzNear��zFar������ͼ�βſ��Կ���
    // ����Ĭ������ϵZ����������ָ����Ļ�����ģ�
    // �����ó�0, 40��ֻ�ܿ���Z����( -40, 0 )������壬
    // ����zNear�������������ܿ���Z����Ϊ����������
    if ((double)height/width < MAX_Y/MAX_X)
        // glOrtho( 0, MAX_Y*width/height, 0, MAX_Y, -40, 40 );
        glOrtho( (MAX_X-MAX_Y*width/height)/2, (MAX_Y*width/height+MAX_X)/2, 0, MAX_Y, -40, 40 );
    else
        glOrtho( 0, MAX_X, (MAX_Y-MAX_X*height/width)/2, (MAX_Y+MAX_X*height/width)/2, -40, 40 );

    // ͶӰ������ú��ٽ���ǰ��������Ϊģ�;���
    // ���������ͼ�λ��ƺ�ͼ�α任
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
