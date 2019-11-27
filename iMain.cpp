#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"

int HEIGHT = 400, WIDTH = 600;

double GravitationalForce   = 100;
double EngineForce          = 30;
double Mass                 = 10;

double CenterOfGravity_d, CenterOfGravity_angle;
double CenterOfGravity_x    = 0.5;
double CenterOfGravity_y    = 0.4;

void iDraw()
{
    iClear();

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    /*if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }*/
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key==GLUT_KEY_RIGHT)
    {

    }
    if(key==GLUT_KEY_LEFT)
    {

    }
    if(key==GLUT_KEY_UP)
    {

    }
    if(key==GLUT_KEY_DOWN)
    {

    }
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    //freopen("map.txt","r",stdin);


    iInitialize(WIDTH, HEIGHT, "Gravity Defied");
    return 0;
}
