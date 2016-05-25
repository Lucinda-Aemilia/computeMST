#pragma once

#ifdef FREEGLUT

#include <vector>
#include <GL/glut.h>

#include "Settings.h"
#include "Graph2D.h"

static void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glPointSize( 3.0f );   // 绘制前设置下点的大小和颜色
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

    // 只flush没用的，直接swap就好了
    glutSwapBuffers();
}

static void reshape(int width, int height)
{
    // 这里要设置opengl在窗口的绘图区域，一般是整个窗口
    // glViewport( 0, 0, width, height );

    int side = std::min(width, height);
    //设置视窗口的位置大小,注意原点（0,0）在屏幕画面左下角
    // need to think here
    glViewport(0, 0, side, side);
    // glViewport( (width-side)/2, (height-side)/2, (width+side)/2, (height+side)/2 );

    // 一般只在窗口reshape时才重新设定下投影矩阵和模型矩阵
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // 镜头默认在坐标原点看向Z轴负方向，而glOrtho最后两个参数表示
    // 距离镜头zNear到zFar距离间的图形才可以看到
    // 而且默认坐标系Z轴正方向是指向屏幕朝外侧的，
    // 你设置成0, 40就只能看到Z坐标( -40, 0 )间的物体，
    // 所以zNear给个负数，就能看到Z坐标为正的物体了
    glOrtho( 0, MAX_X, 0, MAX_Y, -40, 40 );

    // 投影矩阵设好后再将当前矩阵设置为模型矩阵，
    // 方便后续的图形绘制和图形变换
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

#endif // FREEGLUT
