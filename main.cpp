#include <iostream>
#include "C:\Users\pc\Desktop\iti38\graphics.h"
#include<conio.h>

using namespace std;

class Point
{
    private:
    int x;
    int y;

public:
    point();
    point(int m ,int n);
    void setx (int m);
    void  sety (int n);
    int getx ();
    int gety ();

    Point()
    {
        x=10;
        y=10;
    }
    Point (int m ,int n)
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

class Line
{
    private:
    Point start;
    Point End;

public:
    void setStart(int,int);
    void setEnd(int ,int );

    Line(int x1, int y1 , int x2, int y2): start(x1,y1),End(x1,x2)
    {

    }
    void Draw()
    {
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



class Rect
{
   private:
       Point ul;
       Point lr;
   public:
    Rect(int x1 ,int y1,int x2 ,int y2):ul(x1,y1),lr (x2,y2)
    {

    }
    void draw()
    {
        rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
    }
};

class Circle
{
private:
    Point center;
    int radius;
public:
    Circle(int m ,int n,int r):center(m,n)
    {
        radius =r;
    }
    void draw ()
    {
        circle(center.getx(),center.gety(),radius);
    }
 void setcenter(int x, int y)
 {
     center.setx(x);
     center.sety(y);
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
      Circle cArr[3]={Circle(90,50,50),Circle(290,50,50),Circle(460,50,50)};
    Rect   rArr[2]={Rect(370,110,240,180),Rect(120,175,500,300)};
    Line   lArr[2]={Line(75,50,200,100),Line(15,50,30,35 )};

    while(1)
    {

    for(i=0;i<50;i++)
    {
         clrscr();
         cArr[0].setcenter(90,50+2*i);
         cArr[1].setcenter(260+2*i,50);
         cArr[2].setcenter(460,50+2*i);

    mypic.setCircles(3,cArr);
    setcolor(5);
      mypic.paint();


    mypic.setRects(2,rArr);
    setcolor(1);
      mypic.paint();


    mypic.setLines(2,lArr);
    setcolor(3);
    mypic.paint();
     Sleep(40);

    }
    }
    getch();
    return 0;
}




