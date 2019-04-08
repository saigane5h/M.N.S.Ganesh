#include<stdio.h>
int main()
{
	int Id[20],Burst_time[20], Priority[20], Waiting_time[20],Turn_around_time[20],i, k, n, Temp;
	float Average_waiting_time, Average_turn_around_time;
	printf("Enter the number of people (Student + teacher): ");
	scanf("%d",&n);
for(i=0;i<n;i++)
{
Id[i] = i;
printf("Time taken by person %d: ", i);
scanf("%d",&Burst_time[i]);
printf("Enter priority: Teacher/Student(0/1): ");
scanf("%d", &Priority[i]);
}

for(i=0;i<n;i++)
{
	for(k=i+1;k<n;k++)
	{
		if(Priority[i] > Priority[k])
		{
			Temp = Id[i];
	        Id[i] = Id[k];
			Id[k] = Temp;
	        Temp = Burst_time[i];
		    Burst_time[i] = Burst_time[k];
		    Burst_time [k] = Temp;
		    Temp = Priority[i];
		    Priority[i] = Priority[k];
	        Priority[k] = Temp;
		}
		Average_waiting_time = Waiting_time[0] = 0;
		Average_turn_around_time = Turn_around_time[0] = Burst_time[0];
		for(i=1;i<n;i++)
		{
			Waiting_time[i] = Waiting_time[i-1] + Burst_time[i-1];
			Turn_around_time[i] = Turn_around_time[i-1] + Burst_time[i];
			Average_waiting_time = Average_waiting_time + Waiting_time[i];
			Average_turn_around_time = Average_turn_around_time + Turn_around_time[i];
		}
	}
}
printf("\n Person \t Priority \t Allotted Time \t Waiting Time \t Turnaround Time ");
for(i=0;i<n;i++)
printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d ",Id[i],Priority[i],Burst_time[i], Waiting_time[i], Turn_around_time[i]);
printf("\n\n Average Waiting Time: %f",Average_waiting_time/n);
printf("\n Average Turnaround Time: %f",Average_turn_around_time/n);
getch();
}
