
#include "Tree.h"
#include <string>

SGlutContextStruct glutContext;
const int SHIFT = 10;
const int WIDTH = 700;
const int HEIGHT = 500;
vector<int> Value;

 void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

 void drawButtons()
 {
	int shift = glutContext.shift;
	int height = glutContext.window_height;
	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 40);
	glVertex2i(shift + 100, height - shift - 40);
	glVertex2i(shift + 100, height - shift);
	glVertex2i(shift, height - shift);
	glEnd();

	glColor3d(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 90);
	glVertex2i(shift + 100, height - shift - 90);
	glVertex2i(shift + 100, height - shift - 50);
	glVertex2i(shift, height - shift - 50);
	glEnd();
}

 void drawFillCircle(int x, int y, int R)
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = 0; i <= R; i++)
	{
		for (int t = 0; t <= 360; t++) 
		{
			x1 = i * sin(t) + x;
			y1 = i * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++)
	{
		for (int t = 0; t <= 360; t++)
		{
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

 void drawBlueCircle(int x, int y, int R) 
 {
	glColor3f(0.0, 0.0, 1.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++)
	{
		for (int t = 0; t <= 360; t++) 
		{
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

int getPoss(int index, int width, int curLevel, int maxLevel) 
{
	int x1 = 0;
	int x2 = pow(2, curLevel) - 1;
	int y1 = width / pow(2, curLevel + 1);
	int y2 = width - pow(2, maxLevel - curLevel);
	if (x1 == x2) return y1;
	double k = (y2 - y1) / (x2 - x1);
	double m = -x1 * k + y1;
	int y = (int)(k * index + m);
	return y;
}


