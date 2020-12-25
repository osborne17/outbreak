#include<bits/stdc++.h>
#include "person.h"
using namespace std;

person::person()
{
      status=0;
      recovery_time=15;
      vel=rand()%4 +2;
}
int person::alive_dead(int I,int n)
{
      int ru;
      ru=rand()%100 +1;
      if(n/5<=I){
            if(ru<=85)status = 2;
            else status = 3;
      }
      else{
            if(ru<=95)status = 2;
            else status = 3;
      }
}
