#include<bits/stdc++.h>
#include "location.h"
using namespace std;

location::location()
{
      x=rand()%1365 +1;
      y=rand()%705 +1;
}
//double getX(){return x;};
//double getY(){return y;};
int location:: movee(int vel)
{
      double dx,dy,a,dis;
      dx=x1 -x;
      dy=y1 -y;
      a =atan2(dy,dx);
      dis=sqrt((dx*dx)+(dy*dy));

      if(vel<=dis){
            x = (x +vel*cos(a));
            y = (y +vel*sin(a));
            return 0;
      }
      else{
            x=x1;
            y=y1;
            return 1;
      }


}
int location::infect_other(location other,int radius)
{
      int prob;
      double Dx,Dy;
      Dx=x-other.x;
      Dy=y-other.y;
      if(sqrt((Dx*Dx)+(Dy*Dy))<radius)
      {
            prob=rand()%100 +1;
            if(prob<=50)return 1;
            else return 0;
      }

}
