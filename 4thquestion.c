# include<pthread.h>
# include<stdio.h>
# include<stdlib.h>
int process[100],runtime[100],waitingtime[100],turnaroundtime[100],c[100],arrivaltime[100],n,total,temp,sum=0,i,j,pos;
float priority,avgwaitingtime=0,avgturnaroundtime=0;
void *input();
void *sort();
int main()
{
pthread_t t1,t2,t3;
pthread_create(&t1,NULL,input,NULL);
pthread_create(&t2,NULL,sort,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
return 0;    
}

void *input()
{
printf("Enter number of process and number should be less than 100:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("\nenter burst time of process%d:",i+1);
 scanf("%d",&runtime[i]);
 printf("enter arrival time of process%d:",i+1);
 scanf("%d",&arrivaltime[i]); 
 c[i]=0;
 sum+=runtime[i];
 process[i]=i+1;
}

sort();

printf("\nprocess\tarrival time\tBurst time\tWaiting time\tpriority  Turnaround time ");
  for(total=arrivaltime[0];total<sum;)
  {
   float r=-1;
   int k;
  for(i=0;i<n;i++)
  {

   if(arrivaltime[i]<=total && c[i]!=1)
    {
              priority=1 + (total-arrivaltime[i])/runtime[i];
              if(r <= priority)
               {
                r=priority;
                 k=i;
               }
          
   }
  
   }
  
  
   total+=runtime[k]; 
    
   waitingtime[k]=total-arrivaltime[k]-runtime[k];
   turnaroundtime[k]=total-arrivaltime[k];
    c[k]=1;
   avgwaitingtime+=waitingtime[k];
   avgturnaroundtime+=turnaroundtime[k];
printf("\n %d\t\t%d\t\t%d\t\t%d\t %.2f\t\t%d",process[k],arrivaltime[k],runtime[k],waitingtime[k],priority,turnaroundtime[k]);
  }

printf("\nAverage waiting time:%.2f\n",avgwaitingtime/n);
printf("\nAverage turn around time:%.2f\n",avgturnaroundtime/n);
return 0;
}
void *sort()
{
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(arrivaltime[j]<arrivaltime[pos])
   pos=j;
}
  temp=arrivaltime[i];
  arrivaltime[i]=arrivaltime[pos];
  arrivaltime[pos]=temp;

  temp=runtime[i];
  runtime[i]=runtime[pos];
  runtime[pos]=temp;

  temp=process[i];
  process[i]=process[pos];
  process[pos]=temp;
    }
}
