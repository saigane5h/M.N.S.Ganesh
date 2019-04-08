#include<stdio.h>

main()
{
	int timer=0,i=0,bt=0;
	int process[4]={1,2,3,4};
	int arrival[4]={0,5,13,17};
	int burst_time[4]={20,36,19,42};
	int burst[4]={20,36,19,42};
	int process_arrived[4]={1};
	double priority[4]={0};
	int complete[4]={0};
		while(1)
	{
		int k;
		for(k=0;k<4;k++)
		{
			if(timer>=arrival[k] && burst[k]!=(-1)) 
			{
				priority[k]=1+((timer-arrival[k])/burst[k]);
			}
		}
		int p,q;
		for(p=0;p<4;p++)
		{
			for(q=0;q<4-1-p;q++)
			{
				if(priority[q]<priority[q+1] && process_arrived[q]!=0 && process_arrived[q+1]!=0)
				{
					double t1=priority[q];
					priority[q]=priority[q+1];
					priority[q+1]=t1;
					int t2=process_arrived[q];
					process_arrived[q]=process_arrived[q+1];
					process_arrived[q+1]=t2;
				}
				else if(priority[q]==priority[q+1]  && process_arrived[q]!=0 && process_arrived[q+1]!=0)
				{
					if(burst[q]<burst[q+1])
					{
						int t=process_arrived[q];
						process_arrived[q]=process_arrived[q+1];
						process_arrived[q+1]=t;
					}
				}
			}
		}
		int y=process_arrived[0];
		bt=burst[y-1];
		do
		{
			printf("\ntimer : %d",timer);
			int x;
			for(x=0;x<4;x++)
			{
				if(timer==arrival[x])
				{		
					process_arrived[x]=x+1;
					printf("\nprocess %d arrived\n",x);
				}	
			}
			bt=bt-1;
			timer=timer+1;
			if(bt==0)
			{
				printf("\nprocess %d completed\n",y );
				complete[y-1]=timer;
				i=i+1;
				burst[y-1]=-1;
				//priority[0]=0;
				for(x=0;x<4;x++)
				{
					priority[x]=0;
					if(process_arrived[x]!=0)
					{
						process_arrived[x]=x+1;
					}
				}
				break;
			}
		}while(1);
		if(i==4)
			break;

	}

  }
