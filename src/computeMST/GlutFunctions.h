#pragma once

#ifdef FREEGLUT

#include <vector>
#include <GL/glut.h>

#include "Settings.h"
#include "Graph2D.h"

static void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glPointSize( 3.0f );   // ����ǰ�����µ�Ĵ�С����ɫ
    glColor3f( 1, 0, 0 );

    std::vector<Vec2f> points( myGraph->getPoints() );
    std::vector<IndexEdge> kruskalMSTEdges( myGraph->getKruskalMSTEdges() );

    glBegin( GL_POINTS );
    //glVertex3f( 56, 87, 0 );
    for (int i = 0; i < points.size(); i++)
        glVertex3f(points[i].x, points[i].y, 0);
    glEnd();

    glColor3f( 0, 0, 1 );
    glBegin(GL_LINES);
    for (int i = 0; i < kruskalMSTEdges.size(); i++)
    {
        glVertex3f(kruskalMSTEdges[i].start().x, kruskalMSTEdges[i].start().y, -10);
        glVertex3f(kruskalMSTEdges[i].end().x, kruskalMSTEdges[i].end().y, -10);
    }
    glEnd();

    // ֻflushû�õģ�ֱ��swap�ͺ���
    glutSwapBuffers();
}

static void reshape(int width, int height)
{
    // ����Ҫ����opengl�ڴ��ڵĻ�ͼ����һ������������
    // glViewport( 0, 0, width, height );

    int side = std::min(width, height);
    //�����Ӵ��ڵ�λ�ô�С,ע��ԭ�㣨0,0������Ļ�������½�
    // need to think here
    glViewport(0, 0, side, side);
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

#endif // FREEGLUT
