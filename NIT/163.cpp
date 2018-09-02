#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	return x>0?1:-1;
}
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
struct Circle  
{  
    Point c;  
    double r;  
    Circle(){}  
    Circle(Point a, double b)
    {
		c=a;
		r=b;
	}
};
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{  
  double Bx=p2.x-p1.x,By=p2.y-p1.y;  
  double Cx=p3.x-p1.x,Cy=p3.y-p1.y;  
  double D=2*(Bx*Cy-By*Cx);  
  double cx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;  
  double cy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;  
  Point p=Point(cx,cy);
  return Circle(p,length(p1-p));
}
int main()
{
	double r;
	Point p;
	while(~scanf("%lf%lf%lf",&p.x,&p.y,&r))
	{
		Circle a,b;
		a=Circle(p,r);
		Point p1,p2,p3;
		p1.input();
		p2.input();
		p3.input();
		b=CircumscribedCircle(p1,p2,p3);
	/*	if(a.c==b.c)
		{
			puts("No");
			continue;
		}*/
		if((sgn(a.r+b.r-dist(a.c,b.c))==0)||(sgn(fabs(a.r-b.r)-dist(a.c,b.c)))==0) puts("Yes");
		else puts("No");
	}
	return 0;
}