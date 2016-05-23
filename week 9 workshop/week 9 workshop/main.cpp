// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// OpenGL without using GLUT - 2013 by Neil Dansey, Tim Dykes and Ian Cant, and using excerpts from here:
// http://bobobobo.wordpress.com/2008/02/11/opengl-in-a-proper-windows-app-no-glut/
// Feel free to adapt this for what you need, but please leave these comments in.

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#pragma once

#include <windows.h>	// need this file if you want to create windows etc
#include <gl/gl.h>		// need this file to do graphics with opengl
#include <gl/glu.h>		// need this file to set up a perspective projection easily
#include <math.h> //sqrt() and pow()
#include "Game.h"
#include <time.h>
#include <random>


// include the opengl and glu libraries
#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glu32.lib")





// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//arrays and matrices
float tankVertices[18] = {

	-0.1f, -0.1f, 0.0f,

	0.13f, -0.1f, 0.0f,

	0.13f, 0.1f, 0.0f,

	-0.1f, -0.1f, 0.0f,

	-0.1f, 0.1f, 0.0f,

	-0.1f, 0.1f, 0.0f
};

float tankVertexColorsPOne[24] = {

	0.1f, 1.0f, 0.1f, 1.0f,

	0.1f, 1.0f, 0.1f, 1.0f,

	0.1f, 1.0f, 0.1f, 1.0f,

	0.1f, 1.0f, 0.1f, 1.0f,

	0.1f, 1.0f, 0.1f, 1.0f,

	0.1f, 1.0f, 0.1f, 1.0f

};
float tankVertexColorsPTwo[24] = {

	0.1f, 0.1f, 0.9f, 1.0f,

	0.1f, 0.1f, 0.9f, 1.0f,

	0.1f, 0.1f, 0.9f, 1.0f,

	0.1f, 0.1f, 0.9f, 1.0f,

	0.1f, 0.1f, 0.9f, 1.0f,

	0.1f, 0.1f, 0.9f, 1.0f

};
float bullet[18] = {

	
	-0.05f, -0.05f, 0.0f,

	0.05f, -0.05f, 0.0f,

	0.05f, 0.05f, 0.0f,

	-0.05f, -0.05f, 0.0f,

	0.05f, 0.05f, 0.0f,

	-0.05f, 0.05f, 0.0f
};

float turret[18] = {

	-0.05f, 0.05f, 0.0f,

	0.15f, -0.05f, 0.0f,

	0.15f, 0.05f, 0.0f,

	-0.05f, -0.05f, 0.0f,

	-0.05f, 0.05f, 0.0f,

	-0.05f, 0.05f, 0.0f
};

float bulletColor[24] = {

	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f,

	0.5f, 0.5f, 0.5f, 1.0f

};
float turretColor[24] = {

	0.5f, 0.7f, 0.5f, 1.0f,

	0.5f, 0.7f, 0.5f, 1.0f,

	0.5f, 0.7f, 0.5f, 1.0f,

	0.5f, 0.7f, 0.5f, 1.0f,

	0.5f, 0.7f, 0.5f, 1.0f,

	0.5f, 0.7f, 0.5f, 1.0f

};
float turretColor2[24] = {

	0.7f, 0.5f, 0.5f, 1.0f,

	0.7f, 0.5f, 0.5f, 1.0f,

	0.7f, 0.5f, 0.5f, 1.0f,

	0.7f, 0.5f, 0.5f, 1.0f,

	0.7f, 0.5f, 0.5f, 1.0f,

	0.7f, 0.5f, 0.5f, 1.0f

};
float powerUpVertices[18] = {

	-0.1f, -0.1f, 0.0f,

	0.13f, -0.1f, 0.0f,

	0.13f, 0.1f, 0.0f,

	-0.1f, -0.1f, 0.0f,

	-0.1f, 0.1f, 0.0f,

	-0.1f, 0.1f, 0.0f
};
float PowerUpsColorOne[24] = {

	0.1f, 0.6f, 0.9f, 1.0f,

	0.1f, 0.6f, 0.9f, 1.0f,

	0.1f, 0.6f, 0.9f, 1.0f,

	0.1f, 0.6f, 0.9f, 1.0f,

	0.1f, 0.6f, 0.9f, 1.0f,

	0.1f, 0.6f, 0.9f, 1.0f

};
float PowerUpsColorTwo[24] = {

	0.6f, 0.1f, 0.9f, 1.0f,

	0.6f, 0.1f, 0.9f, 1.0f,

	0.6f, 0.1f, 0.9f, 1.0f,

	0.6f, 0.1f, 0.9f, 1.0f,

	0.6f, 0.1f, 0.9f, 1.0f,

	0.6f, 0.1f, 0.9f, 1.0f

};
//passing by value
int color(int i)
{
	if(i==0)
	{
		glColorPointer(4, GL_FLOAT, 0, tankVertexColorsPOne);
	}
	else 
	{
		glColorPointer(4, GL_FLOAT, 0, tankVertexColorsPTwo);
	}
	return i;
}
//passing by value
int PowerUpColor(int i)
{
	if(i==0)
	{
		glColorPointer(4, GL_FLOAT, 0, PowerUpsColorOne);
	}
	else 
	{
		glColorPointer(4, GL_FLOAT, 0, PowerUpsColorTwo);
	}
	return i;
}








// function prototypes:
LRESULT CALLBACK WndProc(   HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam );	
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow );
bool detectCollision(   float objectOne_x,float objectOne_y, float objectTwo_x,	float objectTwo_y,	float collisionDistance);
//TankGame is a varieble of type Game that points to Game class
void draw(Game* TankGame);
void update(Game* TankGame);


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@






// In a C++ Windows app, the starting point is WinMain() rather than _tmain() or main().
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow )
{

	// some basic numbers to hold the position and size of the window
	int windowWidth = 800;
	int windowHeight = 600;
	int windowTopLeftX = 50;
	int windowTopLeftY = 50;
		
	// some other variables we need for our game...
    MSG msg;								// this will be used to store messages from the operating system
	bool keepPlaying = true;				// whether or not we want to keep playing



	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// this section contains all the window initialisation code, 
	// and should probably be collapsed for the time being to avoid confusion	
#pragma region  <-- click the plus/minus sign to collapse/expand!

	// this bit creates a window class, basically a template for the window we will make later, so we can do more windows the same.
    WNDCLASS myWindowClass;
    myWindowClass.cbClsExtra = 0;											// no idea
    myWindowClass.cbWndExtra = 0;											// no idea
    myWindowClass.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH );	// background fill black
    myWindowClass.hCursor = LoadCursor( NULL, IDC_ARROW );					// arrow cursor       
    myWindowClass.hIcon = LoadIcon( NULL, IDI_APPLICATION );				// type of icon to use (default app icon)
    myWindowClass.hInstance = hInstance;									// window instance name (given by the OS when the window is created)   
    myWindowClass.lpfnWndProc = WndProc;									// window callback function - this is our function below that is called whenever something happens
    myWindowClass.lpszClassName = TEXT("my window class name");				// our new window class name
    myWindowClass.lpszMenuName = 0;											// window menu name (0 = default menu?) 
    myWindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;				// redraw if the window is resized horizontally or vertically, allow different context for each window instance

    // Register that class with the Windows OS..
	RegisterClass(&myWindowClass);
    
   	// create a rect structure to hold the dimensions of our window
    RECT rect;
    SetRect( &rect, windowTopLeftX,				// the top-left corner x-coordinate
                    windowTopLeftY,				// the top-left corner y-coordinate
                    windowTopLeftX + windowWidth,		// far right
                    windowTopLeftY + windowHeight );	// far left
    
	// adjust the window, no idea why.
    AdjustWindowRect( &rect, WS_OVERLAPPEDWINDOW, false );

    // call CreateWindow to create the window
   HWND myWindow = CreateWindow(TEXT("my window class name"),		// window class to use - in this case the one we created a minute ago
                          TEXT("Przemyslaw Hendel CT4TOGA coursework"),		// window title
                          WS_OVERLAPPEDWINDOW,						// ??
                          windowTopLeftX, windowTopLeftY,			// x, y
                          windowWidth, windowHeight,							// width and height
                          NULL, NULL,								// ??
                          hInstance, NULL);							// ??

    
   // check to see that the window created okay
    if( myWindow == NULL )
    {
        FatalAppExit( NULL, TEXT("CreateWindow() failed!") );
    }

    // if so, show it
    ShowWindow( myWindow, iCmdShow );
   

    // get a device context from the window
    HDC myDeviceContext = GetDC( myWindow );


	// we create a pixel format descriptor, to describe our desired pixel format. 
	// we set all of the fields to 0 before we do anything else
	// this is because PIXELFORMATDESCRIPTOR has loads of fields that we won't use
    PIXELFORMATDESCRIPTOR myPfd = { 0 };
 

    // now set only the fields of the pfd we care about:
    myPfd.nSize = sizeof( PIXELFORMATDESCRIPTOR );		// size of the pfd in memory
    myPfd.nVersion = 1;									// always 1

    myPfd.dwFlags = PFD_SUPPORT_OPENGL |				// OpenGL support - not DirectDraw
					PFD_DOUBLEBUFFER   |				// double buffering support
					PFD_DRAW_TO_WINDOW;					// draw to the app window, not to a bitmap image

    myPfd.iPixelType = PFD_TYPE_RGBA ;					// red, green, blue, alpha for each pixel
    myPfd.cColorBits = 24;								// 24 bit == 8 bits for red, 8 for green, 8 for blue.
														// This count of color bits EXCLUDES alpha.

    myPfd.cDepthBits = 32;								// 32 bits to measure pixel depth.


	// now we need to choose the closest pixel format to the one we wanted...	
    int chosenPixelFormat = ChoosePixelFormat( myDeviceContext, &myPfd );
 
	// if windows didnt have a suitable format, 0 would have been returned...
    if( chosenPixelFormat == 0 )
    {
        FatalAppExit( NULL, TEXT("ChoosePixelFormat() failed!") );
    }

	// if we get this far it means we've got a valid pixel format
	// so now we need to set the device context up with that format...
    int result = SetPixelFormat( myDeviceContext, chosenPixelFormat, &myPfd );

	// if it failed...
    if (result == NULL)
    {
        FatalAppExit( NULL, TEXT("SetPixelFormat() failed!") );
    }

    // we now need to set up a render context (for opengl) that is compatible with the device context (from windows)...
    HGLRC myRenderContext = wglCreateContext( myDeviceContext );

	// then we connect the two together
    wglMakeCurrent( myDeviceContext, myRenderContext );



	// opengl display setup
	glMatrixMode(GL_PROJECTION);	// select the projection matrix, i.e. the one that controls the "camera"
    glLoadIdentity();				// reset it
    gluPerspective(45.0,(float)windowWidth/(float)windowHeight, 1, 1000);	// set up fov, and near / far clipping planes
	glViewport(0, 0, windowWidth, windowHeight);							// make the viewport cover the whole window
	glClearColor( 0.5, 0, 0, 3.0 );											// set the colour used for clearing the screen

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#pragma endregion
	

	// main game loop starts here!
	//dynamically allocated variable
	Game * theGame = new Game; 
	
	// keep doing this as long as the player hasnt exited the app: 
    while( keepPlaying == true )
    {



		// we need to listen out for OS messages.
		// if there is a windows message to process...
        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
			// and if the message is a "quit" message...
			if( msg.message == WM_QUIT )
			{
				keepPlaying = false;	// we want to quit asap
			}
			//below block of code makes the tank move when the defined keys are pressed
			else if( msg.message == WM_KEYDOWN)
			{
				//conditional statements and Event handling
				if(msg.wParam == VK_ESCAPE)
				{
					keepPlaying = false;
				}
				//Tank1
				if(msg.wParam == VK_UP)
				{ // arrow up
					theGame->Tank[0].setUp( true);
				}
				if(msg.wParam == VK_DOWN)
				{	// arrow down
					theGame->Tank[0].setDown(true);
				}
				if(msg.wParam == VK_LEFT)
				{	// Arrow left
					theGame->Tank[0].setLeft(true);
				}
				if(msg.wParam == VK_RIGHT)
				{	// arrow right
					theGame->Tank[0].setRight(true);
				}
				if(msg.wParam == 'P')
				{// fire
					theGame->Tank[0].setFire(true);
				}
				if(msg.wParam == 'I')
				{// turret left rotation
					theGame->Tank[0].setTurLeft(true);
				}
				if(msg.wParam == 'O')
				{// turret right rotation
					theGame->Tank[0].setTurRight(true);
				}
				//Tank2
				if(msg.wParam == 'W')
				{		//  up
					theGame->Tank[1].setUp( true);
				}
				if(msg.wParam == 'S')
				{	//  down
					theGame->Tank[1].setDown(true);
				}
				if(msg.wParam == 'A')
				{	// left
					theGame->Tank[1].setLeft(true);
				}
				if(msg.wParam == 'D')
				{	// right
					theGame->Tank[1].setRight(true);
				}
				if(msg.wParam == 'F')
				{// fire
					theGame->Tank[1].setFire(true);
				}
				if(msg.wParam == 'Q')
				{// turret left rotation
					theGame->Tank[1].setTurLeft(true);
				}
				if(msg.wParam == 'E')
				{// turret right rotation
					theGame->Tank[1].setTurRight(true);
				}
			}
			// below block of code makes the tank stop when the movement defining keys are not pressed
			else if( msg.message == WM_KEYUP)
			{
				//Tank1
				if(msg.wParam == VK_UP)
				{		// arrow up
					theGame->Tank[0].setUp( false);
				}
				if(msg.wParam == VK_DOWN)
				{	// arrow down
					theGame->Tank[0].setDown(false);
				}
				if(msg.wParam == VK_LEFT)
				{	// Arrow left
					theGame->Tank[0].setLeft(false);
				}
				if(msg.wParam == VK_RIGHT)
				{	// arrow right
					theGame->Tank[0].setRight(false);
				}
				if(msg.wParam == 'P')
				{// fire
					theGame->Tank[0].setFire(false);
				}
				if(msg.wParam == 'I')
				{// turret left rotation
					theGame->Tank[0].setTurLeft(false);
				}
				if(msg.wParam == 'O')
				{// turret right rotation
					theGame->Tank[0].setTurRight(false);
				}
				//Tank2
				if(msg.wParam == 'W')
				{		// arrow up
					theGame->Tank[1].setUp( false);
				}
				if(msg.wParam == 'S')
				{	// arrow down
					theGame->Tank[1].setDown(false);
				}
				if(msg.wParam == 'A')
				{	// Arrow left
					theGame->Tank[1].setLeft(false);
				}
				if(msg.wParam == 'D')
				{	// arrow right
					theGame->Tank[1].setRight(false);
				}
				if(msg.wParam == 'F')
				{// fire
					theGame->Tank[1].setFire(false);
				}
				if(msg.wParam == 'Q')
				{// turret left rotation
					theGame->Tank[1].setTurLeft(false);
				}
				if(msg.wParam == 'E')
				{// turret right rotation
					theGame->Tank[1].setTurRight(false);
				}

			}
			// or if it was any other type of message (i.e. one we don't care about), process it as normal...
            else 
            {
				TranslateMessage( &msg );
				DispatchMessage( &msg );  
            }
        }
		
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear scree
		update(theGame);
		draw(theGame);
		SwapBuffers(myDeviceContext);							// update graphics

    }

	
	
	//cleaning up or dynamically allocaed memory
	delete theGame;
	theGame = NULL;

    // the next bit will therefore happen when the player quits the app,
	// because they are trapped in the previous section as long as (keepPlaying == true).

    // UNmake our rendering context (make it 'uncurrent')
    wglMakeCurrent( NULL, NULL );

    // delete the rendering context, we no longer need it.
    wglDeleteContext( myRenderContext );

    // release our window's DC from the window
    ReleaseDC( myWindow, myDeviceContext );
  
	// end the program
    return msg.wParam;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// this part contains some code that should be collapsed for now too...
#pragma region keep_this_bit_collapsed_too!

// this function is called when any events happen to our window
LRESULT CALLBACK WndProc(   HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam ) 
{

    switch( message )
    {
		// if they exited the window...	
		case WM_DESTROY:
			// post a message "quit" message to the main windows loop
			PostQuitMessage( 0 ) ;
			return 0;
			break;
    }
 
	// must do this as a default case (i.e. if no other event was handled)...
    return DefWindowProc( hwnd, message, wparam, lparam );

}

#pragma endregion

bool detectCollision(float objectOne_x,float objectOne_y, float objectTwo_x,float objectTwo_y,	float collisionDistance)	
{
	float current_distance = sqrt(pow(objectOne_x - objectTwo_x, 2) + pow(objectOne_y - objectTwo_y, 2));
    
	if (current_distance <= collisionDistance)
	{
		return true;
	}
	
	else
	{
		return false;
	}

	
}
void draw(Game* TankGame)
{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		glFrontFace(GL_CCW);


		// draw players
		//for Loop
		for(int i = 0; i<2;i++)
		{
			//Drawing tanks
			glVertexPointer(3, GL_FLOAT, 0, tankVertices);
			color(i);
			glLoadIdentity();
			glTranslatef(TankGame->Tank[i].getPos_x(),TankGame->Tank[i].getPos_y(),-5.0);
			glRotatef(TankGame->Tank[i].getRotation(),0.0, 0.0, 1.0);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
			//drawing bullets
			glVertexPointer(3, GL_FLOAT, 0, bullet);
			glColorPointer(4, GL_FLOAT, 0, bulletColor);
			glLoadIdentity();
			glTranslatef(TankGame->Tank[i].Bullet[i].bGetPosx(), TankGame->Tank[i].Bullet[i].bGetPosy(), -5.0);
			glRotatef(TankGame->Tank[i].Bullet[i].bGetRot(),0.0,0.0,1.0);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
			//drawing turret
			glVertexPointer(3, GL_FLOAT, 0, turret);
			if(TankGame->Tank[i].getReloaded() == true)
			{
				glColorPointer(4, GL_FLOAT, 0, turretColor);
			}
			else
			{
				glColorPointer(4, GL_FLOAT, 0, turretColor2);
			}
			glLoadIdentity();
			glTranslatef(TankGame->Tank[i].Turret[i].tGetPosx(), TankGame->Tank[i].Turret[i].tGetPosy(), -5.0);
			glRotatef(TankGame->Tank[i].Turret[i].tGetRot(),0.0,0.0,1.0);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);

			//drawing powerups
			glVertexPointer(3, GL_FLOAT, 0, powerUpVertices);
			PowerUpColor(i);
			glLoadIdentity();
			glTranslatef(TankGame->powerUp[i].getPos_x(), TankGame->powerUp[i].getPos_y(), -5.0);
			glRotatef(TankGame->powerUp[i].getRotation(),0.0,0.0,1.0);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
		}
}

void update(Game* TankGame)
{
	
		
		bool answer = detectCollision(TankGame->Tank[1].Bullet[1].bGetPosx(), TankGame->Tank[1].Bullet[1].bGetPosy(), TankGame->Tank[0].getPos_x(), TankGame->Tank[0].getPos_y(), 0.20f);
		bool answer2 = detectCollision(TankGame->Tank[0].Bullet[0].bGetPosx(), TankGame->Tank[0].Bullet[0].bGetPosy(), TankGame->Tank[1].getPos_x(), TankGame->Tank[1].getPos_y(), 0.20f);
		
		bool answer3 = detectCollision(TankGame->powerUp[1].getPos_x(), TankGame->powerUp[1].getPos_y(), TankGame->Tank[1].getPos_x(), TankGame->Tank[1].getPos_y(), 0.20f);
		bool answer4 = detectCollision(TankGame->powerUp[1].getPos_x(), TankGame->powerUp[1].getPos_y(), TankGame->Tank[0].getPos_x(), TankGame->Tank[0].getPos_y(), 0.20f);

		bool answer5 = detectCollision(TankGame->powerUp[0].getPos_x(), TankGame->powerUp[0].getPos_y(), TankGame->Tank[1].getPos_x(), TankGame->Tank[1].getPos_y(), 0.20f);
		bool answer6 = detectCollision(TankGame->powerUp[0].getPos_x(), TankGame->powerUp[0].getPos_y(), TankGame->Tank[0].getPos_x(), TankGame->Tank[0].getPos_y(), 0.20f);

		
		if(answer == true || answer2 == true)
		{
			glClearColor(1.0, 1.0, 1.0, 1.0);
			if(TankGame->Tank[0].getInvincible() == false && TankGame->Tank[1].getInvincible() ==false)
			{
				TankGame->Tank[0].setPos_x(1.0f);
				TankGame->Tank[0].setPos_y(0.0f);
				TankGame->Tank[0].setRotation(-180.0f);
				TankGame->Tank[0].setAcceleration(0.001f);
				TankGame->Tank[0].Turret[0].tSetRot(-180.0f);
								
				TankGame->Tank[1].setPos_x(-1.0f);
				TankGame->Tank[1].setPos_y(0.0f);
				TankGame->Tank[1].setRotation(180.0f);
				TankGame->Tank[1].setAcceleration(0.001f);
				TankGame->Tank[1].Turret[1].tSetRot(-180.0f);
			}
			else
			{
				TankGame->Tank[0].setInvincible(false);
				TankGame->Tank[1].setInvincible(false);
			}

			TankGame->Tank[0].Bullet[0].bSetPosx(100.0f);
			TankGame->Tank[0].Bullet[0].bSetPosy(100.0f);
			TankGame->Tank[1].Bullet[1].bSetPosx(100.0f);
			TankGame->Tank[1].Bullet[1].bSetPosy(100.0f);
		}
		else
		{
			glClearColor( 0.5, 0, 0, 3.0 );
		}
		
		// making the powerup[1] give an acceleration boost if conditions are met
		if(answer3 == true)
		{
			TankGame->Tank[1].setAcceleration(50.0f);
		}
		if(answer4 == true)
		{
			TankGame->Tank[0].setAcceleration(50.0f);
		}
		// Making the powerup[0] give invincibility if conditions are met
		
		if(answer5 == true)
		{
			TankGame->Tank[1].setInvincible(true);

		}
		if(answer6 == true)
		{
			TankGame->Tank[0].setInvincible(true);
		}


			//Power Ups

			//http://en.cppreference.com/w/cpp/numeric/random

			std::random_device rd;
			std::default_random_engine e1(rd());
			std::uniform_real_distribution<float> uniform_dist(-2,2 );
			float x1 = uniform_dist(e1);
			float y1 = uniform_dist(e1);
			float x2 = uniform_dist(e1);
			float y2 = uniform_dist(e1);

			// in game class
			//time_t oldTime = 0;
			//time_t currentTime;
			
			
			// in update function
			TankGame->setCurrentTime(time(NULL));

			if ((TankGame->getCurrent() - TankGame->getOldTime()) >= 1)
			{
				TankGame->setOldTime ( TankGame->getCurrent());
				// move powerups
				
				TankGame->powerUp[0].setPos_x(x1);
				TankGame->powerUp[0].setPos_y(y1);
				TankGame->powerUp[1].setPos_x(x2);
				TankGame->powerUp[1].setPos_y(y2);
			}

			TankGame->powerUp[0].setRotation(TankGame->powerUp[0].getRotation() + 2.0f);
			TankGame->powerUp[1].setRotation(TankGame->powerUp[1].getRotation() - 2.0f);



			/****************/
			//TANK 1
			if(TankGame->Tank[0].getUp() == true)
			{				
				TankGame->Tank[0].setSpeed ((TankGame->Tank[0].getSpeed() +  TankGame->Tank[0].getAcceleration()));
					if(TankGame->Tank[0].getSpeed() > TankGame->Tank[0].getMaxSpeed())
						{
						TankGame->Tank[0].setSpeed( TankGame->Tank[0].getMaxSpeed());
						}
			}
			else if(TankGame->Tank[0].getDown() == true)
			{	
				TankGame->Tank[0].setSpeed((TankGame->Tank[0].getSpeed() - TankGame->Tank[0].getAcceleration()));
					if(TankGame->Tank[0].getSpeed() < TankGame->Tank[0].getMinSpeed())
						{
									TankGame->Tank[0].setSpeed(TankGame->Tank[0].getMinSpeed());
						}
			}
			else
			{
				TankGame->Tank[0].setSpeed(TankGame->Tank[0].getSpeed() * 0.98f);
				//	if it is in the range -0.01 to 0.01, make it 0
						if(TankGame->Tank[0].getSpeed() >= -0.01f && TankGame->Tank[0].getSpeed() <=0.01f)
						{
							TankGame->Tank[0].setSpeed(0.0f);
						}
			}
		//tank 1 rotation on keypress
		if(TankGame->Tank[0].getRight() == true)// determines the tank rotate speed - RIGHT
			{ 
				TankGame->Tank[0].setRotation ((TankGame->Tank[0].getRotation() - 2.0f));
			}
		if(TankGame->Tank[0].getLeft() == true)// determines the tank rotate speed - LEFT
			{  
				TankGame->Tank[0].setRotation ((TankGame->Tank[0].getRotation() + 2.0f));
			}


		// TANK 2
		if(TankGame->Tank[1].getUp() == true)
			{				
				TankGame->Tank[1].setSpeed ((TankGame->Tank[1].getSpeed() +  TankGame->Tank[1].getAcceleration()));
					if(TankGame->Tank[1].getSpeed() > TankGame->Tank[1].getMaxSpeed())
						{
						TankGame->Tank[1].setSpeed( TankGame->Tank[1].getMaxSpeed());
						}
			}
			else if(TankGame->Tank[1].getDown() == true)
			{	
				TankGame->Tank[1].setSpeed((TankGame->Tank[1].getSpeed() - TankGame->Tank[1].getAcceleration()));
					if(TankGame->Tank[1].getSpeed() < TankGame->Tank[1].getMinSpeed())
						{
									TankGame->Tank[1].setSpeed(TankGame->Tank[1].getMinSpeed());
						}
			}
			else
			{
				TankGame->Tank[1].setSpeed(TankGame->Tank[1].getSpeed() * 0.98f);
				//	if it is in the range -0.01 to 0.01, make it 0
						if(TankGame->Tank[1].getSpeed() >= -0.01f && TankGame->Tank[1].getSpeed() <=0.01f)
						{
							TankGame->Tank[1].setSpeed(0.0f);
						}
			}
		//Tank2 rotation on keypress
		if(TankGame->Tank[1].getRight() == true)// determines the tank rotate speed - RIGHT
			{ 
				TankGame->Tank[1].setRotation ((TankGame->Tank[1].getRotation() - 2.0f));
			}
		if(TankGame->Tank[1].getLeft() == true)// determines the tank rotate speed - LEFT
			{  
				TankGame->Tank[1].setRotation ((TankGame->Tank[1].getRotation() + 2.0f));
			}
		
			//Tank 1 shooting
			if(TankGame->Tank[0].getFire() == true && TankGame->Tank[0].getReloaded() == true)
			{ 
				if(TankGame->Tank[0].Bullet[0].bGetPosx() != TankGame->Tank[0].getPos_x() && TankGame->Tank[0].Bullet[0].bGetPosy() != TankGame->Tank[0].getPos_y())
				{	//setting the bullet position to same position as tank position
					TankGame->Tank[0].Bullet[0].bSetPosx(TankGame->Tank[0].getPos_x()); 
					TankGame->Tank[0].Bullet[0].bSetPosy(TankGame->Tank[0].getPos_y());
				}
				TankGame->Tank[0].Bullet[0].bSetRot(TankGame->Tank[0].Turret[0].tGetRot());// setting the bullet rotation to same value as turret rotation
				TankGame->Tank[0].Bullet[0].bSetSpeed(( 0.05f + TankGame->Tank[1].Bullet[1].bGetAcceleration()));
				TankGame->Tank[0].setReloaded(false);
			}
			else if(TankGame->Tank[0].Bullet[0].bGetPosx() == 100.0f && TankGame->Tank[0].Bullet[0].bGetPosy() == 100.0f)
			{
				TankGame->Tank[0].setReloaded(true);
			}
			if(TankGame->Tank[0].getTurLeft() == true)
				{
					TankGame->Tank[0].Turret[0].tSetRot ((TankGame->Tank[0].Turret[0].tGetRot() + 2.0f));
				}
			if(TankGame->Tank[0].getTurRight() == true)
				{ 
					TankGame->Tank[0].Turret[0].tSetRot ((TankGame->Tank[0].Turret[0].tGetRot() - 2.0f));
				}

			//Tank 2 shooting
			if(TankGame->Tank[1].getFire() == true && TankGame->Tank[1].getReloaded() == true)
			{
				if(TankGame->Tank[1].Bullet[1].bGetPosx() != TankGame->Tank[1].getPos_x() && TankGame->Tank[1].Bullet[1].bGetPosy() != TankGame->Tank[1].getPos_y() )
				{	//setting the bullet position to same position as tank position
					TankGame->Tank[1].Bullet[1].bSetPosx(TankGame->Tank[1].getPos_x());
					TankGame->Tank[1].Bullet[1].bSetPosy(TankGame->Tank[1].getPos_y());
				}

				TankGame->Tank[1].Bullet[1].bSetRot(TankGame->Tank[1].Turret[1].tGetRot()); // setting the bullet rotation to same value as turret rotation
				TankGame->Tank[1].Bullet[1].bSetSpeed(( 0.05f + TankGame->Tank[1].Bullet[1].bGetAcceleration()));
				TankGame->Tank[1].setReloaded(false);
			}
			else if(TankGame->Tank[1].Bullet[1].bGetPosx() == 100.0f && TankGame->Tank[1].Bullet[1].bGetPosy() == 100.0f)
			{
				TankGame->Tank[1].setReloaded(true);
			}
			//tank 2 turret rotation
			if(TankGame->Tank[1].getTurLeft() == true)
				{
					TankGame->Tank[1].Turret[1].tSetRot ((TankGame->Tank[1].Turret[1].tGetRot() + 2.0f));
				}
			if(TankGame->Tank[1].getTurRight() == true)
				{ 
					TankGame->Tank[1].Turret[1].tSetRot ((TankGame->Tank[1].Turret[1].tGetRot() - 2.0f));
				}

					
		//Tank1
		TankGame->Tank[0].setVelocity ( (TankGame->Tank[0].getSpeed() * TankGame->Tank[0].getScale()));
		TankGame->Tank[0].setPos_y (TankGame->Tank[0].getPos_y() + TankGame->Tank[0].getVelocity());
		TankGame->Tank[0].setPos_x ((TankGame->Tank[0].getPos_x() +  (TankGame->Tank[0].getSpeed() * (cos(TankGame->Tank[0].getRotation() * 0.01745f )))));
		TankGame->Tank[0].setPos_y (TankGame->Tank[0].getPos_y() + (TankGame->Tank[0].getSpeed() * (sin(TankGame->Tank[0].getRotation() * 0.01745f ))));
		//Tank2 Bullet
		TankGame->Tank[0].Bullet[0].bSetPosy (TankGame->Tank[0].Bullet[0].bGetPosy() + TankGame->Tank[0].getVelocity());
		TankGame->Tank[0].Bullet[0].bSetPosx ((TankGame->Tank[0].Bullet[0].bGetPosx() +  (TankGame->Tank[0].Bullet[0].bGetSpeed() * (cos(TankGame->Tank[0].Bullet[0].bGetRot() * 0.01745f )))));
		TankGame->Tank[0].Bullet[0].bSetPosy (TankGame->Tank[0].Bullet[0].bGetPosy() + (TankGame->Tank[0].Bullet[0].bGetSpeed() * (sin(TankGame->Tank[0].Bullet[0].bGetRot() * 0.01745f ))));
		//Making the turret inherit tank1 position and rotation
		TankGame->Tank[0].Turret[0].tSetPosy (TankGame->Tank[0].getPos_y() + TankGame->Tank[0].getVelocity());
		TankGame->Tank[0].Turret[0].tSetPosx ((TankGame->Tank[0].getPos_x() +  (TankGame->Tank[0].getSpeed() * (cos(TankGame->Tank[0].getRotation() * 0.01745f )))));
		TankGame->Tank[0].Turret[0].tSetPosy (TankGame->Tank[0].getPos_y() + (TankGame->Tank[0].getSpeed() * (sin(TankGame->Tank[0].getRotation() * 0.01745f ))));
				
		//Tank2
		TankGame->Tank[1].setVelocity ( (TankGame->Tank[1].getSpeed() * TankGame->Tank[1].getScale()));
		TankGame->Tank[1].setPos_y (TankGame->Tank[1].getPos_y() + TankGame->Tank[1].getVelocity());
		TankGame->Tank[1].setPos_x ((TankGame->Tank[1].getPos_x() +  (TankGame->Tank[1].getSpeed() * (cos(TankGame->Tank[1].getRotation() * 0.01745f )))));
		TankGame->Tank[1].setPos_y (TankGame->Tank[1].getPos_y() + (TankGame->Tank[1].getSpeed() * (sin(TankGame->Tank[1].getRotation() * 0.01745f ))));
		//Tank2 Bullet
		TankGame->Tank[1].Bullet[1].bSetPosy (TankGame->Tank[1].Bullet[1].bGetPosy() + TankGame->Tank[1].getVelocity());
		TankGame->Tank[1].Bullet[1].bSetPosx ((TankGame->Tank[1].Bullet[1].bGetPosx() +  (TankGame->Tank[1].Bullet[1].bGetSpeed() * (cos(TankGame->Tank[1].Bullet[1].bGetRot() * 0.01745f )))));
		TankGame->Tank[1].Bullet[1].bSetPosy (TankGame->Tank[1].Bullet[1].bGetPosy() + (TankGame->Tank[1].Bullet[1].bGetSpeed() * (sin(TankGame->Tank[1].Bullet[1].bGetRot() * 0.01745f ))));
		//Making the turret inherit tank1 position and rotation
		TankGame->Tank[1].Turret[1].tSetPosy (TankGame->Tank[1].getPos_y() + TankGame->Tank[1].getVelocity());
		TankGame->Tank[1].Turret[1].tSetPosx ((TankGame->Tank[1].getPos_x() +  (TankGame->Tank[1].getSpeed() * (cos(TankGame->Tank[1].getRotation() * 0.01745f )))));
		TankGame->Tank[1].Turret[1].tSetPosy (TankGame->Tank[1].getPos_y() + (TankGame->Tank[1].getSpeed() * (sin(TankGame->Tank[1].getRotation() * 0.01745f ))));
		
		
		



		//making the tank appear on the other side if it reaches certain position
			//tank1
			if(TankGame->Tank[0].getPos_y() >= 1.9f)
			{
					TankGame->Tank[0].setPos_y(-2.15f);
			}
			else if(TankGame->Tank[0].getPos_y() <= -2.15f)
			{
					TankGame->Tank[0].setPos_y(1.9f);
			}
			else if(TankGame->Tank[0].getPos_x() >= 2.69f)
			{
					TankGame->Tank[0].setPos_x(-2.7f);
			}
			else if(TankGame->Tank[0].getPos_x() <= -2.75f)
			{
					TankGame->Tank[0].setPos_x(2.7f);
			}	
			else{}
			//tank2
			if(TankGame->Tank[1].getPos_y() >= 1.9f)
			{
					TankGame->Tank[1].setPos_y(-2.15f);
			}
			else if(TankGame->Tank[1].getPos_y() <= -2.15f)
			{
					TankGame->Tank[1].setPos_y(1.9f);
			}
			else if(TankGame->Tank[1].getPos_x() >= 2.69f)
			{
					TankGame->Tank[1].setPos_x(-2.7f);
			}
			else if(TankGame->Tank[1].getPos_x() <= -2.75f)
			{
					TankGame->Tank[1].setPos_x(2.7f);
			}
			else{}
		
			
			
		//setting the bullet position to 100,100 if it gets out of screen border
		//tank 1 bullet
			if(TankGame->Tank[0].Bullet[0].bGetPosy() >= 1.9f || TankGame->Tank[0].Bullet[0].bGetPosy() <= -2.15f)
			{
				TankGame->Tank[0].Bullet[0].bSetPosy(100.0f);
				TankGame->Tank[0].Bullet[0].bSetPosx(100.0f);
			}
			
			if(TankGame->Tank[0].Bullet[0].bGetPosx() >= 2.69f || TankGame->Tank[0].Bullet[0].bGetPosx() <= -2.75f)
			{
					TankGame->Tank[0].Bullet[0].bSetPosx(100.0f);
					TankGame->Tank[0].Bullet[0].bSetPosy(100.0f);
			}
		//tank2 bullet
			if(TankGame->Tank[1].Bullet[1].bGetPosy() >= 1.9f || TankGame->Tank[1].Bullet[1].bGetPosy() <= -2.15f)
			{
				TankGame->Tank[1].Bullet[1].bSetPosy(100.0f);
				TankGame->Tank[1].Bullet[1].bSetPosx(100.0f);
			}
			
			if(TankGame->Tank[1].Bullet[1].bGetPosx() >= 2.69f || TankGame->Tank[1].Bullet[1].bGetPosx() <= -2.75f)
			{
					TankGame->Tank[1].Bullet[1].bSetPosx(100.0f);
					TankGame->Tank[1].Bullet[1].bSetPosy(100.0f);
			}
			
			
			
		}
