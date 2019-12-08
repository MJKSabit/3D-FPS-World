#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"

double PI = acos(-1.0);
int HEIGHT = 500, WIDTH = 450;

double ANGLE_CHANGE_PER_CLICK = 0.05;
double MOVEMENT_CHANGE_PER_CLICK = 0.1;

double RAY_MOVEMENT_CHANGE = 0.01;

int m, n;
char **map/*[10][21] =
{
    "####################",
    "#..................#",
    "#..................#",
    "#............##....#",
    "#.............#....#",
    "#..................#",
    "#..................#",
    "#..................#",
    "#..................#",
    "####################"
}*/;

double fieldOfView = PI/4.0; // 45 degree
#define numOfRays 100
double FOV_increament = fieldOfView/(numOfRays-1);

double rayIncreament = 1;

double lineHeight[numOfRays];
double maxLineHeight = HEIGHT/2;

double playerX=10.0, playerY=5.0;
double playerAngle=0.0;

void findLineHeight()
{
    int i, j;
    double angle = playerAngle;

    for(i=0; i<numOfRays; i++)
    {
        angle = playerAngle + FOV_increament*i;

        double angleSIN = RAY_MOVEMENT_CHANGE*sin(angle);
        double angleCOS = RAY_MOVEMENT_CHANGE*cos(angle);

        double rayX = playerX, rayY = playerY;

        for(j=0; ; j++){

            if(map[int(rayY)][int(rayX)]!='.'){
                break;
            }

            rayX += angleCOS;
            rayY += angleSIN;
        }

        lineHeight[i] = maxLineHeight/(j*RAY_MOVEMENT_CHANGE);
    }
}

void drawRays()
{
    int i;
    for(i=0; i<numOfRays; i++){
        /// Intense Coloring
        int temp = 1000*lineHeight[i]/maxLineHeight;
        int col = 32 + (temp < 220 ? temp : 220);
        iSetColor(col, col, col);

        /// Height Drawing
        iLine(i*WIDTH/(numOfRays-1), HEIGHT/2, i*WIDTH/(numOfRays-1), HEIGHT/2+lineHeight[i]);
        iLine(i*WIDTH/(numOfRays-1), HEIGHT/2, i*WIDTH/(numOfRays-1), HEIGHT/2-lineHeight[i]);
    }
}

void drawMap()
{
    iSetColor(10, 250, 10);
    iFilledRectangle(1, 1, n*10, m*10);

    iSetColor(250, 0, 0);
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(map[i][j]=='#') iPoint(j*10, i*10, 2);
        }
    }

    iSetColor(250, 250, 0);
    iPoint(playerX*10, playerY*10, 2);
}

void iDraw()
{
    iClear();
    iSetColor(255, 255, 255);
    //iLine(0, HEIGHT/2, WIDTH, HEIGHT/2);

    findLineHeight();
    drawRays();
    drawMap();

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
        playerAngle+=ANGLE_CHANGE_PER_CLICK;
    }
    if(key==GLUT_KEY_LEFT)
    {
        playerAngle-=ANGLE_CHANGE_PER_CLICK;
    }
    if(key==GLUT_KEY_UP)
    {
        playerX += MOVEMENT_CHANGE_PER_CLICK*cos(playerAngle+fieldOfView/2);
        playerY += MOVEMENT_CHANGE_PER_CLICK*sin(playerAngle+fieldOfView/2);

        if(map[int(playerY)][(int)playerX]!='.'){
            playerX -= MOVEMENT_CHANGE_PER_CLICK*cos(playerAngle+fieldOfView/2);
            playerY -= MOVEMENT_CHANGE_PER_CLICK*sin(playerAngle+fieldOfView/2);
        }
    }
    if(key==GLUT_KEY_DOWN)
    {
        playerX -= MOVEMENT_CHANGE_PER_CLICK*cos(playerAngle+fieldOfView/2);
        playerY -= MOVEMENT_CHANGE_PER_CLICK*sin(playerAngle+fieldOfView/2);

        if(map[int(playerY)][(int)playerX]!='.'){
            playerX += MOVEMENT_CHANGE_PER_CLICK*cos(playerAngle+fieldOfView/2);
            playerY += MOVEMENT_CHANGE_PER_CLICK*sin(playerAngle+fieldOfView/2);
        }
    }
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    freopen("map.txt","r",stdin);

    int i;
    scanf("%d %d", &m, &n);

    map = (char **) malloc(m*sizeof(char *));
    for(i=0; i<m; i++){
        map[i] = (char*) malloc(n+2);
        scanf("%s", map[i]);
    }

    //printf("Player position: ");
    scanf("%lf %lf", &playerX, &playerY);

    //playerX = n - playerX;
    //playerY = m - playerY;

    iInitialize(WIDTH, HEIGHT, "3D FPS World by Sabit");
    return 0;
}
