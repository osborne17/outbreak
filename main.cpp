 #include <bits/stdc++.h>
#include<graphics.h>
#include "location.h"
#include "destination.h"
#include "person.h"
#include "mobility.h"
using namespace std;

int main()
{
	//parameters
	int n=500, n_S=0, n_I=0, n_R=0,n_D=0,di,ru;
	double size=5, radius=15, t=0, dt=0.05;

	int i,j,gd,gm;
	char text[80];
	location loc[1000];
	destination des[10];
	person per[1000];
	mobility mob[1000];

	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,2);

	//initialize the population
	for(i=0; i<n; i++)
	{
            di=rand()%20;
            if(di<10){
                  loc[i].x1 = des[di].x2 ;
                  loc[i].y1 = des[di].y2 ;
            }
            else{
                  loc[i].x1=rand()%1365 +1;
                  loc[i].y1=rand()%705 +1;
            }

		n_S ++;
	}

	//infect 3 people from the population
	for(i=0; i<3; i++)
	{
		per[i].status = 1;
		n_I ++;
		n_S --;
	}

	delay(2000);

	while(n_I != 0)
	{
		cleardevice();

		n_S=0, n_I=0, n_R=0,n_D=0;
		//draw the population
		for(i=0; i<n; i++)
		{

			if(per[i].status == 0)
			{
				setfillstyle(1,1);
				setcolor(1);
				n_S++;
			}
			else if(per[i].status == 1)
			{
				setfillstyle(1,4);
				setcolor(4);
				n_I++;
				setcolor(14);
				//circle(P[i].x, P[i].y, radius);
			}
			else if(per[i].status == 2)
			{
				setfillstyle(1,10);
				setcolor(10);
				n_R++;
			}
			else if(per[i].status == 3)
			{
				setfillstyle(1,8);
				setcolor(8);
				n_D++;
			}

			fillellipse(loc[i].x, loc[i].y, size, size);
		}

		//print stats
		setcolor(15);
		sprintf(text,"t=%.1f S=%.2f%% I=%.2f%% R=%.2f%% D=%.2f%%",t,n_S*100.0/n,n_I*100.0/n,n_R*100.0/n,n_D*100.0/n);
		outtextxy(0,0,text);

		//update status and positions
		for(i=0; i<n; i++)
		{
			if(per[i].status == 0)
			{
				//check for infections
				for(j=0; j<n; j++)
				{
				      if((i!=j) && (per[j].status==1) && mob[i].m==1 && mob[j].m==1){
                                     if(loc[i].infect_other(loc[j],radius))per[i].status = 1;
				      }
					/*if( (i!=j) && (per[j].status==1) && (sqrt((loc[i].x-loc[j].x)*(loc[i].x-loc[j].x) + (loc[i].y-loc[j].y)*(loc[i].y-loc[j].y)) < radius) )
						per[i].status = 1;*/
				}
			}
			else if(per[i].status == 1)
			{
				per[i].recovery_time -= dt;

				if(per[i].recovery_time <= 0){
                              per[i].alive_dead(n_I,n);

                              /*ru=rand()%100 +1;
					if(ru<=70)per[i].status = 2;
					else per[i].status = 3;*/
                        }
			}
			if(per[i].status == 3)mob[i].m=0;

			if(mob[i].m){
			if(loc[i].movee(per[i].vel)){

			/*double dx,dy,a,dis;
			dx=loc[i].x1 - loc[i].x;
			dy=loc[i].y1 - loc[i].y;
			a =atan2(dy,dx);
			dis=sqrt((dx*dx)+(dy*dy));

			if(per[i].vel<=dis){
			loc[i].x = (loc[i].x + per[i].vel*cos(a));
			loc[i].y = (loc[i].y + per[i].vel*sin(a));
			}
			else{
                        loc[i].x=loc[i].x1;
                        loc[i].y=loc[i].y1;
			}

			if(loc[i].x == loc[i].x1 && loc[i].y == loc[i].y1){*/

                        di=rand()%20;
                        if(di<10){
     		                  loc[i].x1 = des[di].x2 ;
		                  loc[i].y1 = des[di].y2 ;
                        }
                        else{
                              loc[i].x1=rand()%1365 +1;
                              loc[i].y1=rand()%705 +1;
                        }
			}
		}
            }

		t += dt;
		Sleep(50);
	}

	getch();
	return 0;
}

