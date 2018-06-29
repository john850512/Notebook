#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#pragma warning(disable:4996)
GLfloat size = 3.0;
GLsizei wh = 500,ww = 500;//寬度跟高度
void drawSquare(int x, int y)//在(x,y)畫出一個小點
{ 
    glColor3ub( (char)0, (char)255, (char)0);//綠色
    glBegin(GL_POLYGON);
		glVertex2f(x+size, y+size);
		glVertex2f(x-size, y+size);
		glVertex2f(x-size, y-size);
		glVertex2f(x+size, y-size);
    glEnd();
}
void myinit()
{
   glViewport(0, 0, ww, wh);
   glMatrixMode(GL_PROJECTION);    
   glLoadIdentity( );
   glOrtho(-ww, (GLdouble) ww , -wh, (GLdouble) wh ,-1.0, 1.0);
   glClearColor (0.8, 0.8, 0.8, 1.0);
   glClear(GL_COLOR_BUFFER_BIT); 
   glFlush();
}
void dis()
{
	/*
		你們要幹嘛呢～在這裡面寫個迴圈去讓他產生20000個點 (應該)就是阿貝要的作業了
		產生點的function已經幫你們寫好了
	*/
	drawSquare(0,0);//在(x,y)畫出一個小點

	glFlush();//刷新螢幕，不要動這行
}
int main(int argc , char** argv)
{
	glutInit(&argc,argv);//初始化glut
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(500,200);
	glutCreateWindow("hello world");
	myinit();
	glutDisplayFunc(dis);
	glutMainLoop();//glutMainLoop()會反覆執行是回呼函數的function

	return 0;
}