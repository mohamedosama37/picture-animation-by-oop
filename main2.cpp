#include <iostream>
#include "C:\Users\pc\Desktop\iti38\graphics.h"
#include<conio.h>

using namespace std;
class Shape
{
public:
    int colour;
    Shape()
    {
        colour=0;
    }
    Shape(int c)
    {
        colour=c;
    }

};

class Point:public Shape
{
    private:
    int x;
    int y;

public:

    void setx (int m);
    void  sety (int n);
    int getx ();
    int gety ();

    Point():Shape()
    {
        x=10;
        y=10;
    }
    Point (int m ,int n,int c=0):Shape( c)
    {
        x=m;
        y=n;
    }

};

void Point   ::setx(int m)
{
    x=m;
}
void Point ::sety(int n)
{
    y=n;
}

int Point ::getx()
{
    return x;
}

int Point ::gety()
{
    return y;
}

class Line:public Shape
{
    private:
    Point start;
    Point End;

public:
    void setStart(int,int);
    void setEnd(int ,int );

    Line(int x1, int y1 , int x2, int y2,int c): Shape(c),start(x1,y1),End(x2,y2)
    {

    }
    void Draw()
{

        setcolor(colour);
        line(start.getx(), start.gety(),End.getx(),End.gety());

    }
};
void Line :: setStart(int x1,int y1)
{
    start.setx(x1);
    start.sety(y1);
}
void Line ::setEnd(int x2,int y2)
{

    End.setx(x2);
    End.sety(y2);
}



class Rect:public Shape
{
   private:
       Point ul;
       Point lr;
   public:
    Rect(int x1 ,int y1,int x2 ,int y2, int c):ul(x1,y1),lr (x2,y2),Shape( c)
    {

    }
    void draw()
    {
        setcolor(colour);
        rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
    }
};

class Circle:public Shape
{
private:
    Point center;
    int radius;
public:
    Circle(int m ,int n,int r,int c):center(m,n),Shape(c)
    {
        radius =r;
    }
    void draw ()
    {
        setcolor(colour);
        circle(center.getx(),center.gety(),radius);
    }
};

class Picture
{
  int cnum;
  int rnum;
  int lnum;
  Circle *pcircles;
  Rect *prects;
  Line *plines;

  public:
      Picture()
      {
          cnum=0;
          rnum=0;
          lnum=0;
          pcircles=NULL;
          prects=NULL;
          plines=NULL;
      }
      Picture(int cn , int rn,int ln,Circle *pc,Rect *pr,Line *pl)
      {

          cnum=cn;
          rnum=rn;
          lnum=ln;
          pcircles=pc;
          prects=pr;
          plines=pl;
      }
      void setCircles(int,Circle*);
      void setRects(int , Rect*);
      void setLines(int ,Line*);
      void paint();
};
void Picture ::setLines(int ln,Line *lptr)
{
    lnum=ln;
    plines=lptr;
}
void Picture ::setRects(int ln,Rect *lptr)
{
    rnum=ln;
    prects=lptr;
}

void Picture ::setCircles(int ln,Circle *lptr)
{
    cnum=ln;
    pcircles=lptr;
}



void Picture :: paint()
{
    int i;
    for(i=0;i<cnum;i++)
    {
        pcircles[i].draw();
    }
    for(i=0;i<rnum;i++)
    {
        prects[i].draw();

    }
    for(i=0;i<lnum;i++)
    {
        plines[i].Draw();
    }
}


int main()
{
    int i;
    initgraph();
    Picture mypic;

    while(1)
    {

    for(i=0;i<50;i++)
    {
         clrscr();
      Circle cArr[3]={Circle(80,50+2*i,50,1),Circle(290+2*i,50,50,1),Circle(560,50+2*i,50,1)};
    Rect   rArr[2]={Rect(370,110,240,180,5),Rect(120,175,500,300,5)};
    Line   lArr[2]={Line(75,50,200,100,6),Line(15,50,30,35 ,6)};

    mypic.setCircles(3,cArr);

      mypic.paint();


    mypic.setRects(2,rArr);

      mypic.paint();


    mypic.setLines(2,lArr);

    mypic.paint();
    Sleep(40);

    }
    }
    getch();

    return 0;
}





