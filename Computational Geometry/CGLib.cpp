#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<iterator>
#include<sstream>
#define INF 100000000
#define EPS 0.0001
#define PI acos(-1.0)
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;

double DEG_to_RAD(double theta){
       return (PI/180)*theta;
       }
       
//points
struct point{
       double x,y;
       point(double _x, double _y){
                 x=_x;
                 y=_y;
                 }
       // check
       /*          
       bool operator < (point other){
            if(fabs(x-other.x)<EPS)return y<other.y;
            return x<other.x;
            }
       */
       };
       
bool pcomp(point p1, point p2){
     if(fabs(p1.x-p2.x)<EPS)return p1.y<p2.y;
     return p1.x<p2.x;
     }

struct point_i{
       int x,y;
       point_i(int _x, int _y){
                 x=_x;
                 y=_y;
                 }
       };
       
bool areSame(point p1, point p2){
     if(fabs(p1.x-p2.x)<EPS && fabs(p1.y-p2.y)<EPS)return true;
     }
     
double eucDistance(point p1, point p2){
       return hypot(p1.x-p2.x,p1.y-p2.y);
       }

point rotate(point p, double theta) {
      double rad = DEG_to_RAD(theta);                     // multiply theta with PI / 180.0
      return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
      }

//lines
struct line{
       double a,b,c;
       };
       
int pointsToLine(point p1, point p2, line *l) {
     l->a=p1.y-p2.y;
     l->b=p2.x-p1.x;
     l->c=p1.x*(p2.y-p1.y) + p1.y*(p1.x-p2.x);
     if(l->b){
               l->a/=l->b;
               l->c/=l->b;
               l->b=1;
               }
     else{
          if(l->c){
                   l->a/=l->c;
                   l->c=1;
                   }
          else{
               l->a=1;
               }
          }
     return 0;
     }
     
bool areParallel(line l1, line l2) {
     return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
     }
     
bool areSame(line l1, line l2) {
     return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
     }
     
bool intersect(line l1, line l2, point *p){
     if(areSame(l1,l2) || areParallel(l1,l2))return false;
     p->y=(l1.a*l2.c-l2.a*l1.c)/(l2.a*l1.b-l1.a*l2.b);
     if(l2.a)p->x=(-l2.c-l2.b*p->y)/l2.a;
     else{
          p->x=(-l1.c-l1.b*p->y)/l1.a;
          }
     }

// vector (not the STL)

struct vec{
       double x,y;
       vec(double _x, double _y){
                  x=_x;
                  y=_y;
                  }
       };

vec toVector(point p1, point p2){
    vec V(p2.x-p1.x,p2.y-p1.y);
    return V;
}

vec scaleVector(vec v, double s){
    return vec(v.x*s, v.y*s);
}

point translate(point p, vec v){
      return point(p.x+v.x,p.y+v.y);
      }

// point to line and line segment

double distToLine(point p, point A, point B, point *c) {
       // formula: cp = A + (p-A).(B-A) / |B-A| * (B-A)
       double scale = (double)((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
       c->x = A.x + scale * (B.x - A.x);
       c->y = A.y + scale * (B.y - A.y);
       return eucDistance(p, *c);
       }

double distToLineSegment(point p, point A, point B, point* c) {
       if ((B.x-A.x) * (p.x-A.x) + (B.y-A.y) * (p.y-A.y) < EPS) {
          c->x = A.x; c->y = A.y;            // closer to A
          return eucDistance(p, A);
          }                                  // Euclidean distance between p and A
       if ((A.x-B.x) * (p.x-B.x) + (A.y-B.y) * (p.y-B.y) < EPS) {
          c->x = B.x; c->y = B.y;            // closer to B
          return eucDistance(p, B);
          }                                 // Euclidean distance between p and B
       return distToLine(p, A, B, c);
       }

double cross(point p, point q, point r) { // cross product
       return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
       }
       
bool collinear(point p, point q, point r) {
     return fabs(cross(p, q, r)) < EPS;
     }

bool ccw(point p, point q, point r) {
     return cross(p, q, r) > 0;
     }

//circle
int inCircle(point_i p, point_i c, int r) {                // all integer version
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;              // all integer
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
    }
     
double inCircle(point p, point c, double r){               //determine whether a point is in a circle
       double dx = p.x - c.x, dy = p.y - c.y;
       double Euc = dx*dx + dy*dy, rSq = r*r;
       return (Euc-rSq)>EPS ? 2 : fabs(Euc-rSq)<EPS ? 1 : 0;
       }

void two_centres(point p1, point p2, double r, point *c1, point *c2){  //returns centre pf two circles give two points and a radius
     double w=p1.x-p2.x;
     double h=p1.y-p2.y;
     double deltax, deltay, distsq;
     distsq = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
     if(!w && !h)deltax=deltay=r;
     else{
          deltax=h*sqrt(r*r/distsq-0.25);
          deltay=w*sqrt(r*r/distsq-0.25);
          }
     c1->x= (p1.x+p2.x)*0.5 + deltax; 
     c1->y= (p1.y+p2.y)*0.5 + deltay;
     c2->x= (p1.x+p2.x)*0.5 - deltax; 
     c2->y= (p1.y+p2.y)*0.5 - deltay;
     }

//main

int main(){
    
    /*
    int A;
    cin>>A;
    */
    return 0;
}
