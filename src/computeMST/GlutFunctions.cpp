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
    // ����Ҫ����opengl�ڴ��ڵĻ�ͼ����һ������������
    glViewport( 0, 0, width, height );

    int side = std::min(width, height);
    //�����Ӵ��ڵ�λ�ô�С,ע��ԭ�㣨0,0������Ļ�������½�
    // need to think here
    // glViewport(0, 0, side, side);
    // glViewport( (width-side)/2, (height-side)/2, (width+side)/2, (height+side)/2 );

    // һ��ֻ�ڴ���reshapeʱ�������趨��ͶӰ�����ģ�;���
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // ��ͷĬ��������ԭ�㿴��Z�Ḻ���򣬶�glOrtho�������������ʾ
    // ���뾵ͷzNear��zFar������ͼ�βſ��Կ���
    // ����Ĭ������ϵZ����������ָ����Ļ�����ģ�
    // �����ó�0, 40��ֻ�ܿ���Z����( -40, 0 )������壬
    // ����zNear�������������ܿ���Z����Ϊ����������
    glOrtho( 0, MAX_X, 0, MAX_Y, -40, 40 );

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
	int menu = glutCreateMenu(processMenuEvents);

	//add entries to our menu
	glutAddMenuEntry("Refresh", cmst::Menu::Refresh);
	glutAddMenuEntry("Quit", cmst::Menu::Quit);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void processMenuEvents(int option)
{
	switch (option)
	{
    case cmst::Menu::Refresh :
        cmst::Window::instance()->resetCurGraph();
        break;
    case cmst::Menu::Quit :
        exit(0);
        break;
	}
}

#endif // FREEGLUT
