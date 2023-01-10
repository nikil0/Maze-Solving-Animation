#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#define SIZE 7
//size 7 for maze1 , 11 for maze 2 and 15 for maze 3
void ball(int x,int y);
void maze1();
void maze2();
void maze3();
void choice();
void displaymaze();
void matrixmaze();
int matrixval[SIZE][SIZE], solution[SIZE][SIZE], matrixchoice;
int solvemaze(int r, int c);
void backtracking();
void animate(int , int, int ,int );

void backtracking()
{
int i,j;
for(i=0;i<SIZE;i++)
{
for(j=0;j<SIZE;j++)
solution[i][j]=0;
}
if(!solvemaze(0,0))
{
ball(75,75);
printf("No solution for the maze");
getch();
exit(0);
}
}

int solvemaze(int r,int c)
{
if((r==SIZE-1)&&(c==SIZE-1))
{
solution[r][c]=1;
return 1;
}
if(r>=0 && c>=0 && r<SIZE &&c<SIZE && solution[r][c]==0 && matrixval[r][c]==1)
{
//if safe to visit then visit the cell
solution[r][c]=1;
//going down
if(solvemaze(r+1,c))
return 1;
//going right
if(solvemaze(r,c+1))
return 1;
//going up
if(solvemaze(r-1,c))
return 1;
//going left
if(solvemaze(r,c-1))
return 1;
//backtracking
solution[r][c]=0;
return 0;
}
return 0;
}

void matrixmaze()
{
int i,j;
displaymaze();
for(i=75;i<=75+(SIZE-1)*25;i=i+25)
{
for(j=75;j<=75+(SIZE-1)*25;j=j+25)
{
if(getpixel(i,j)==0)
matrixval[j/25-3][i/25-3]=1;
else
matrixval[j/25-3][i/25-3]=0;
}
}
}

void ball(int x,int y)
{
setcolor(BLUE);
if((x+y)%2==0)
setfillstyle(BKSLASH_FILL,BLUE);
else
setfillstyle(SLASH_FILL,BLUE);
circle(x,y,15);
floodfill(x,y,BLUE);
setcolor(7);
}

void animate(int x1,int y1,int x2,int y2)
{
int i;
if(x1==x2)
{
if(y1<y2)
{
for(i=y1;i<=y2;i++)
{
displaymaze();
ball(x1,i);
delay(10);
cleardevice();
}
}
else
{
for(i=y1;i>=y2;i--)
{
displaymaze();
ball(x1,i);
delay(10);
cleardevice();
}
}
}
if(y1==y2)
{
if(x1<x2)
{
for(i=x1;i<=x2;i++)
{
displaymaze();
ball(i,y1);
delay(10);
cleardevice();
}
}
else
{
for(i=x1;i>=x2;i--)
{
displaymaze();
ball(i,y1);
delay(10);
cleardevice();
}
}
}
}

int main()
{
int i=0,j=0,gd=0,gm;
clrscr();
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
choice();
cleardevice();
matrixmaze();
backtracking();
displaymaze();
ball(75,75);
setcolor(14);
outtextxy(20,20,"Press any key to start");
setcolor(15);
getch();
while(i!=SIZE-1 || j!=SIZE-1)
{
if(solution[i+1][j]==1)
{
animate(75+j*25,75+i*25,75+j*25,75+(i+1)*25);
solution[i][j]=0;
i=i+1;
}
else if(solution[i-1][j]==1 && i>0)
{
animate(75+j*25,75+i*25,75+j*25,75+(i-1)*25);
solution[i][j]=0;
i=i-1;
}
else if(solution[i][j+1]==1)
{
animate(75+j*25,75+i*25,75+(j+1)*25,75+i*25);
solution[i][j]=0;
j=j+1;
}
else if(solution[i][j-1]==1 && j>0)
{
animate(75+j*25,75+i*25,75+(j-1)*25,75+i*25);
solution[i][j]=0;
j=j-1;
}
}
displaymaze();
ball(75+25*(SIZE-1),75+25*(SIZE-1));
setcolor(14);
outtextxy(20,20,"Press any key to exit");
setcolor(15);
getch();
closegraph();
return 0;
}

void maze1()
{
int wall[]={50,50,250,50,250,250,50,250,50,50} ;
drawpoly(5,wall);
//horizontal lines
line(50,100,100,100);
line(150,100,200,100);
line(100,150,200,150);
line(50,200,150,200);
line(200,200,250,200);
//line(50,200,250,200);
//vertical lines
line(200,100,200,200);
circle(75+25*(SIZE-1),75+25*(SIZE-1),15);
}

void maze2()
{
int wall[]={50,50,350,50,350,350,50,350,50,50} ;
drawpoly(5,wall);
//horizontal lines
line(50,100,100,100);
line(150,100,200,100);
line(250,100,300,100);
line(100,150,150,150);
line(100,200,150,200);
line(200,200,250,200);
line(50,250,150,250);
line(200,250,250,250);
line(100,300,200,300);
//vertical lines
line(100,100,100,150);
line(100,250,100,300);
line(150,150,150,200);
line(200,100,200,200);
line(200,250,200,300);
line(250,100,250,200);
line(250,300,300,300);
line(300,100,300,300);
circle(75+25*(SIZE-1),75+25*(SIZE-1),15);
}

void maze3()
{
int wall[]={50,50,450,50,450,450,50,450,50,50} ;
drawpoly(5,wall);
//horizontal lines
line(150,100,250,100);
line(350,100,400,100);
line(150,150,200,150);
line(300,150,350,150);
line(100,200,150,200);
line(100,250,150,250);
line(300,250,350,250);
line(200,300,250,300);
line(300,300,400,300);
line(150,350,200,350);
line(250,350,300,350);
line(50,400,100,400);
line(150,400,250,400);
line(350,400,400,400);
//vertical lines
line(100,100,100,200);
line(100,300,100,400);
line(150,150,150,200);
line(150,250,150,350);
line(150,400,150,450);
line(200,150,200,250);
line(250,100,250,300);
line(250,350,250,400);
line(300,100,300,150);
line(300,200,300,250);
line(300,400,300,450);
line(350,150,350,250);
line(350,350,350,450);
line(400,100,400,400);
circle(75+25*(SIZE-1),75+25*(SIZE-1),15);
}

void choice()
{
char ch;
cleardevice();
	outtextxy(200,20,"Maze Solving Animation");
	outtextxy(200,30,"======================");
	outtextxy(200,100,"1)Maze 1");
    outtextxy(200,150,"2)Maze 2");
    outtextxy(200,200,"3)Maze 3");
    outtextxy(200,250,"4)Exit");
	outtextxy(100,300,"Please enter your choice: ");
    ch=	getch();
	switch(ch)
	{
		case '1':
			matrixchoice=1;
			break;
			case '2':
				matrixchoice=2;
				break;
				case '3':
					matrixchoice=3;
					break;
					case '4':
					exit(0);
					default:
						cleardevice();
						printf("\a");
						outtextxy(200,50,"\nInvalid Input!! Redirecting in 2 seconds.");
						delay(2000);
						choice();
	}

}

void displaymaze()
{
if(matrixchoice==1)
maze1();
else if(matrixchoice==2)
maze2();
else if(matrixchoice==3)
maze3();
}

