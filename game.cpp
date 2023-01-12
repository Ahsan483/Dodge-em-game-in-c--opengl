//============================================================================
// Name        : game.cpp
// Author      : Ahsan Mehmood
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<sstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
int key;
int  stop=0;
bool GameOver;
int score=0;
int live=3;
float a=20;
float b=100;
float c=100;
float d=100;
float z2 =20;
int i;
int j;
int f1=575,g1=160;
int f2=275,g2=260;
int f3=475,g3=470;
int f4=150,g4=560;
int f5=275,g5=680;
int f6=675,g6=560;
int f7=360,g7=470;
int f8=575,g8=360;
int f9=675,g9=260;
int f10=175,g10=160;


        float d2 =100;
float x = 100; 
	float y = 100; 
int menu=0;
int level;
// seed the random numbers generator by current time (see the documentation of srand for further help)...
	
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
        
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//FOOD
int foodPoints[5000][5000];




  

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.95/*Red Component*/, 0.35,	//148.0/255/*Green Component*/,
			0.15/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Scores
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10

	
if(menu==0)
{
	 DrawSquare( 0 , 0 ,850,colors[TOMATO]); 
	DrawSquare( 120, 130 ,600,colors[YELLOW]); 
DrawSquare( 230 , 220 ,400,colors[GOLD]); 
	 DrawString( 320, 500, "1. Press (1) to play",colors[BLACK]);
	  DrawString( 320, 450, "2. Press (2) for help",colors[BLACK]);
	   DrawString( 320, 400, "3. Press (3) to exit",colors[BLACK]);
}


if(menu==5)
{
  DrawSquare( 0 , 0 ,850,colors[ORANGE]);
  DrawString( 380, 500, "You Won!!!",colors[BLACK]);
  DrawString( 330, 450, "CONGRATULATIONS",colors[BLACK]);
}
if(menu == 6)
{
DrawSquare( 0 , 0 ,850,colors[TAN]);
DrawString( 380, 500, "You Lose!!!!!!",colors[BLACK]);
DrawString(330, 450, "Game will be quit soon !",colors[BLACK]);
}
if(menu==3)
{
	DrawSquare( 0 , 0 ,850,colors[RED]); 
DrawSquare( 0, 400 ,850,colors[MISTY_ROSE]); 
DrawSquare( 120 , 150 ,600,colors[SILVER]); 
	DrawString( 270, 600, "press left key to move left",colors[BLACK]);
	DrawString( 270, 550, "press right key to move right",colors[BLACK]);
	DrawString( 270, 500, "key up arrow key to move above",colors[BLACK]);
	DrawString( 270, 450, "down arrow key is to move down",colors[BLACK]);
	DrawString( 270, 400, "avoid collision with opponent car",colors[BLACK]);
	DrawString( 270, 350, "collect every gift to win",colors[BLACK]);
        DrawString( 270, 300, "Press p to pause the game",colors[BLACK]);
        DrawString( 270, 250, "GOODLUCK!!!!!!",colors[BLACK]);
}
if(menu==1 )
{//DRwaing player car	
	float width = 10; 
	float height = 5;
	float* color = colors[PALE_TURQUOISE]; 
	float radius = 2.0;
	DrawRoundRect(x,y-60,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y-60,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y-60+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y-60+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y-60+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y-60+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y-60+height*2, width, height, color, radius/2); // body right rect

        // Drawing computer car
      
	float width1 = 10; 
	float height1 = 5;
	float* color1 = colors[BLACK]; 
	float radius1 = 2.0;
	DrawRoundRect(z2+400,d2-60,width1,height1,color1,radius1); // bottom left tyre
	DrawRoundRect(z2+400+width1*3,d2-60,width1,height1,color1,radius1); // bottom right tyre
	DrawRoundRect(z2+400+width1*3,d2-60+height1*4,width1,height1,color1,radius1); // top right tyre
	DrawRoundRect(z2+400,d2-60+height1*4,width1,height1,color1,radius1); // top left tyre
	DrawRoundRect(z2+400, d2-60+height1*2, width1, height1, color1, radius1/2); // body left rect
	DrawRoundRect(z2+400+width1, d2-60+height1, width1*2, height1*3, color1, radius1/2); // body center rect
	DrawRoundRect(z2+400+width1*3, d2-60+height1*2, width1, height1, color1, radius1/2); // body right rect
	

        // Drawing Arena
	int gap_turn = 70;
	int sx = 10;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[PALE_GREEN];
	DrawRectangle(sx, sy+15, swidth+200, sheight, scolor); // bottom left
	DrawRectangle(sx+5+5 + swidth + gap_turn, sy+15, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight-5+10, sheight*2, swidth+100, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn-20, sheight*2, swidth+10, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810-20, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810-20, swidth+200, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn-20, sheight*2, swidth+10, scolor); // left up
	DrawRectangle(sx-sheight*2, sy-5+10+sheight, sheight*2, swidth+100, scolor); // left downs
       
	 // Drawing 2 Arena
	int gap_turn1 = 70;
	int sx1 = 10;
	int sy1 = 10;
	int swidth1 = 800/2 - gap_turn1/2; // half width
	int sheight1 = 10;
	float *scolor1 = colors[PALE_GREEN];
	DrawRectangle(sx1+100, sy1+100, swidth1-100, sheight1, scolor1); // bottom left
	DrawRectangle(sx1-5 + swidth1 + gap_turn, sy1+100, swidth1-90, sheight1, scolor1); // bottom right
	DrawRectangle(sx1-100+swidth1*2+gap_turn1, sy1+100-10+sheight1, sheight1*2, swidth1-100-20+10, scolor1); // right down
	DrawRectangle(sx1-100+swidth1*2+gap_turn1, sy1+5+sheight1+swidth1+gap_turn1, sheight1*2, swidth1+10-100, scolor1); // right up
	DrawRectangle(sx1 + swidth1 + gap_turn1, sy1+5+810-100, swidth1-100, sheight1, scolor1); // top left
	DrawRectangle(sx1+100, sy1+5+810-100, swidth1-100, sheight1, scolor1); // top right
	DrawRectangle(sx1+100-sheight1*2, sy1+5+2+sheight1+swidth1+gap_turn1-2, sheight1*2, swidth1-100+10, scolor1); // left up
	DrawRectangle(sx1-sheight1*2+100, sy1+sheight1+90, sheight1*2, swidth1-100, scolor1); // left down
        
        // Drawing 3 Arena
	int gap_turn2 = 70;
	int sx2 = 10;
	int sy2 = 10;
	int swidth2 = 800/2 - gap_turn2/2; // half width
	int sheight2 = 10;
	float *scolor2 = colors[PALE_GREEN];
	DrawRectangle(sx2+100+100, sy2-5+100+100, swidth2-100-100, sheight2, scolor2); // bottom left
	DrawRectangle(sx2-5 + swidth2 + gap_turn, sy2-5+100+100, swidth2-100-100+10, sheight2, scolor2); // bottom right
	DrawRectangle(sx2-100-100+swidth2*2+gap_turn2, sy2-5+100+100-5-5+sheight2, sheight2*2, swidth2-100-100, scolor2); // right down
	DrawRectangle(sx2-100-100+swidth2*2+gap_turn2, sy2+5+sheight2+swidth2+gap_turn2, sheight2*2, swidth2+10-100-90, scolor2); // right up
	DrawRectangle(sx2 + swidth2 + gap_turn2, sy2+5+820-200, swidth2-100-100, sheight2, scolor2); // top left
	DrawRectangle(sx2+100+100, sy2+5+820-200, swidth2-100-100, sheight2, scolor2); // top right
	DrawRectangle(sx2+100+100-sheight2*2, sy2+5+2+sheight2+swidth2+gap_turn2-2, sheight2*2, swidth2-100+10-90, scolor2); // left up
        DrawRectangle(sx2-sheight2*2+100+100, sy2-10-5+100+sheight2+100+90-90, sheight2*2, swidth2-100-100+5, scolor2); // left down

	// Drawing 4 Arena
	int gap_turn3 = 70;
	int sx3 = 10;
	int sy3 = 10;
	int swidth3 = 800/2 - gap_turn3/2; // half width
	int sheight3 = 10;
	float *scolor3 = colors[PALE_GREEN];
	DrawRectangle(sx3+100+100+100, sy3-5+100+100+100, swidth3-100-100-100, sheight3, scolor3); // bottom left
	DrawRectangle(sx3-5 + swidth3 + gap_turn, sy3-5+100+100+100, swidth3-100-100-100+10, sheight3, scolor3); // bottom right
	DrawRectangle(sx3-100-100-100+swidth3*2+gap_turn3, sy3-15+100+100+100+sheight3, sheight3*2, swidth3-100-100-100, scolor3); // right down
	DrawRectangle(sx3-100-100-100+swidth3*2+gap_turn3, sy3+5+sheight3+swidth3+gap_turn3, sheight3*2, swidth3+10-100-90-90, scolor3); // right up
	DrawRectangle(sx3 + swidth3 + gap_turn3, sy3+5+820-200-100+10, swidth3-100-100-100, sheight3, scolor3); // top left
	DrawRectangle(sx3+100+100+100, sy3+5+820-200-100+10, swidth3-100-100-100, sheight3, scolor3); // top right
	DrawRectangle(sx3+100+100+100-sheight3*2, sy3+5+2+sheight3+swidth3+gap_turn3-2, sheight3*2, swidth3-100+10-90-90, scolor3); // left up
        DrawRectangle(sx3-sheight3*2+100+100+100, sy3-20+100+100+100-5+sheight3+100+90-90-90, sheight3*2, swidth3-100-100-100+5, scolor3); // left down
        //cout<<x<<"   "<<y<<endl;








        //Drwaing square        
	float x612 = 50; 
	float y612 = 100; 
	float width612 = 50; 
	float height612 = 50;
	float* color612 = colors[PALE_GREEN]; 
	float radius612 = 40.5;
        DrawSquare(x612+340 , y612-15-10+300-45+50+20 ,radius612,colors[CHART_REUSE]);    
        
        
        //DRawing food
        
	float* _rcolor = colors[PEACH_PUFF];
	DrawCircle(f1,g1,20,_rcolor);
	DrawCircle(f2,g2,20,_rcolor);
	DrawCircle(f3,g3,20,_rcolor);
	DrawCircle(f4,g4,20,_rcolor);
	DrawCircle(f5,g5,20,_rcolor);
	DrawCircle(f6,g6,20,_rcolor);
	DrawCircle(f7,g7,20,_rcolor);
	DrawCircle(f8,g8,20,_rcolor);
	DrawCircle(f9,g9,20,_rcolor);
	DrawCircle(f10,g10,20,_rcolor);
	
	if(x <= f1 && x >= f1-20 && y == g1+40 && f1 != 1000)
	{
	f1+=1000;
	g1+=1000;
	score+=10;
	}
	
	if(x <= f2 && x >= f2-20 && y == g2+40 && f2 != 1000)
	{
	f2+=1000;
	g2+=1000;
	
	score+=10;
	}
	 
	if(f3 - x == 25  && y == g3+40 && f3 != 1000)
	{
	f3+=1000;
	g3+=1000;
	
	score+=10;
	}
	
	if(x == 140  && y == 580 && f4 != 1000 )
	{
	f4+=1000;
	g4+=1000;
	
	score+=10;
	}
	
	
	if(x == 225  && y == 720 && f5 != 1000 )
	{
	f5+=1000;
	g5+=1000;
	
	score+=10;
	}
	
	if(x == 650  && y == 635 && f6 != 1000 )
	{
	f6+=1000;
	g6+=1000;
	
	score+=10;
	}
	
	
	if(x == 340  && y == 500 && f7 != 1000 )
	{
	f7+=1000;
	g7+=1000;
	
	score+=10;
	}
	 
	
	if(x == 550  && y == 420  && f8 != 1000)
	{
	f8+=1000;
	g8+=1000;
	
	score+=10;
	}
	
	if(x == 650  && y == 330 && f9 != 1000 )
	{
	f9+=1000;
	g9+=1000;
	
	score+=10;
	}
	
	
	if(x == 170  && y == 200  && f10 != 1000)
	{
	f10+=1000;
	g10+=1000;
	
	score+=10;
	}
	  
//Moving Computer car
if(stop%2==0)
{
 if(z2>=-350 && z2<350 && d2==100 )
{
z2+=5;
}
 else if(d2>=100 && d2<820 && z2==350)
{
d2+=5;
}
 else if(z2>(-350) && z2<=350 && d2==820 )
{
z2-=5;
}
else if( d2<=820 && d2>100 && z2==-350)
{
d2-=5;
}
//Moving player car
   if(x>(40) && x<=(750) && y==100 )
 {
x-=5;
}
 else if(y>=100 && y<820 && x==40 )
{
y+=5;
}
else if(x>=40 && x<750 && y==820   )
{
x+=5;
}
else if( x==750 && y<=820 && y>100  )
{
y-=5;

}//2
 if(x>(140) && x<=(650) && y==200 )
 {
x-=5; 
}
 else if(y>=200 && y<720 && x==140 )
{
y+=5;
}
else if(x>=140 && x<650 && y==720  )
{
x+=5;
}
else if( x==650 && y<=720 && y>200  )
{
y-=5;
}
//3
 if(x>(240) && x<=(550) && y==300 )
 {
x-=5;
}
 else if(y>=300 && y<620 && x==240 )
{
y+=5;
}
else if(x>=240 && x<550 && y==620   )
{
x+=5;
}
else if( x==550 && y<=620 && y>300  )
{
y-=5;
}
//4
if(x>(340) && x<=(450) && y==400 )
 {
x-=5;
}
 else if(y>=400 && y<520 && x==340 )
{
y+=5;
}
else if(x>=340 && x<450 && y==520   )
{
x+=5;
}
else if( x==450 && y<=520 && y>400  )
{
y-=5;
}
}

if( y==820 &&d2==820)
{
if(z2+400-x==-10 || z2+400-x==10 || z2+350-x==-10 || z2+350-x==-10)
{

z2=20;
d2=100;
x=100;
y=100;
live--;
}
}
else if( y==100 && d2==100)
{
if(z2+400-x==-10 || z2+400-x==10 || z2+350-x==-10 || z2+350-x==-10)
{

z2=20;
d2=100;
x=100;
y=100;
live--;
}
}
else if( x==40 && z2==-350)
{
if(d2-y==10)
{

z2=20;
d2=100;
x=100;
y=100;
live--;
}
}
else if( x==750 && z2==350)
{
if(y-d2==10)
{

z2=20;
d2=100;
x=100;
y=100;
live--;
}
}

else if(live==0)
{
menu = 6;
}
 
if(score==100)
{
menu = 5;
}


}
	string s="/100",l="/3",l1,s1;
	
        DrawString( 50, 820, "Score=", colors[BLACK]);
        stringstream ss2;
        ss2 << score;
        ss2 >> s1;
        s1 += s;

	
	DrawString( 130, 820, s1,colors[BLACK]);
        
	stringstream ss1;
	ss1 << live;
	ss1 >> l1;
	l1+=l;
	
	
        DrawString( 680, 820, "live=",colors[BLACK]);
        DrawString( 730, 820, l1,colors[BLACK]);
        
        
        DrawString( 370, 820, "LEVEL 1",colors[BLACK]);


        glutSwapBuffers();// do not modify this line.. or draw anything below this line

}
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
 


void NonPrintableKeys(int key, int x11, int y11) {


	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
     	{
		if (x==140 && y<=470 && y>=450)
		{
			x-=100;
		}
		else if(x==240 && y<=470 && y>=450)
		{
			x-=100;
		}
		else if(x==340 && y<=470 && y>=450)
		{
			x-=100;
		}
		else if (x==440  &&  y<=470 && y>=450)
		{ 
			x-=100;
		}
		else if (x==550 && y<=470 && y>=450)
		{
			x-=100;
		}
		else if(x==440 && y<=470 && y>=450)
		{
			x-=100;
		}
                else if(x==640 && y<=470 && y>=450)
		{
			x-=100;
		}

//x-=8;
 
	}

	 
 if ( key== GLUT_KEY_RIGHT  /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
{
	if (x==40  &&  y<=470 && y>=450)
	{ 
		x+=100;
	}
	else if (x==140 && y<=470 && y>=450)
	{
		x+=100;
	}
	else if(x==240 && y<=470 && y>=450)
	{
		x+=100;
	}

	else if (x==550 && y<=470 && y>=450)
	{
		x+=100;
	}
	else if(x==450 && y<=470 && y>=450)
	{
		x+=100;
	}
	else if(x==650 && y<=470 && y>=450)
	{
		x+=100;
	}
//x+=8;
}
	else if (key== GLUT_KEY_UP  /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		if (x>=350 && x<=450 && y==100)
		{
			y+=100;
		}
		else if (x>=350 && x<=450 && y==200)
		{
			y+=100;
		}
		else if (x>=350 && x<=450 && y==300)
		{
			y+=100;
		}
		
		
		else if (x>=350 && x<=450 && y==520)
		{
			y+=100;
		}
		else if (x>=350 && x<=450 && y==620)
		{
			y+=100;
		}
		else if (x>=350 && x<=450 && y==720)
		{
			y+=100;
		}
		else if (x>=350 && x<=450 && y==800)
		{
			y+=100;
		}
  // y+=8;	
	}

	else if (key== GLUT_KEY_DOWN /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
  		if (x>=350 && x<=450 && y==200)
		{
			y-=100;
		}
		else if (x>=350 && x<=450 && y==300)
		{
			y-=100;
		}
		else if (x>=350 && x<=450 && y==400)
		{
			y-=100;
		}
		else if (x>=350 && x<=450 && y==820)
		{
			y-=100;
		}
		else if (x>=350 && x<=450 && y==620)
		{
			y-=100;
		}
		else if (x>=350 && x<=450 && y==720)
		{
			y-=100;
		} 
    
              
	

//y-=8;

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call

	 * this function*/
}

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
 {
	if (key == '2'/* Escape key ASCII*/) {
		menu=3; // exit the program when escape key is pressed.
	}

	 else if (key =='1')
			{
		//do something if b is pressed
		menu=1;
	}
	 else if (key =='3')
{
	exit(0);
}
   else if(key=='4')
{
  menu=0;
}
  if(key=='p'||key=='P')
{

stop++;

}
  if(key=='b' || key=='B')
{
x+=50;
x-=50;
y+=50;
y-=50;
}


	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	// implement your functionality here
      glutPostRedisplay(); 
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(5.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	//if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			//{
	//	cout << GLUT_DOWN << " " << GLUT_UP << endl;

	//} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	//		{

	//}
	//glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("DODGE EM GAME BY AHSAN MEHMOOD"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
