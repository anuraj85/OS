#include<stdio.h>
int at[3][10],bt[3][10],rt[3][10],priority[3][10],number[3];
int waiting_time=0,overall_time=0,turnaround_time=0;
int time_quantum = 10;
int n,remain,type;
int i,j,flag=0,count =0 ,t_quat=4,fcfsnumber=0;
void sorted(int queue)
{
	int max ,k,l,temp;
	for(k = 0;k<number[queue];k++)
	{
		max = priority[queue][k];		
		for( l=0;l<number[queue];l++)
			if(max>priority[queue][l])
			{
				temp=max;
				max = priority[queue][l];
				priority[queue][l]=temp;
			}	
	}
}
int main()
{
	
	printf("Enter Total Process:\t "); 
 	scanf("%d",&n);
	remain=n;
	for(i=0;i<3;i++) 
	{
		number[i]=0;
	}
	printf("Instructions - Time quantum over structure is 10\n1. CPU PROCESS Queue\n2. User process Queue\n3. IO Process Queue");
	printf("\nqueue list %d %d %d",number[0],number[1],number[2]);
	for(i=0;i<n;i++)
	{	
		printf("\nProcess no %d\nProcess Type:",i+1);
		scanf("%d",&type);type-=1;
		printf("Arrival Time :");
		scanf("%d",&at[type][i]);
		printf("Burst Time :");
		scanf("%d",&bt[type][i]);
		printf("Priority :");
		scanf("%d",&priority[type][i]);
		rt[type][i]=bt[type][i];
		number[type]++;		
	}
	printf("\nqueue list %d %d %d",number[0],number[1],number[2]);
	for(i=0;i<3;i++)
	{
		sorted(i);
	}
	printf("\n\nProcess\t|\tArr. Time\t|\tPriority\t|\tCompletion Time\t|\tTurnaround Time\t|\tWaiting Time\n\n");

	for(overall_time = 0;remain!=0;)
	{
		//roundRobin(time_quantum);
		FCFS(time_quantum);
	}
	/*
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  */
return 0;
	
}
int FCFS(int quat)
{
	for(count = fcfsnumber;number[2]!=0&&quat>0;)
	{
		if(rt[2][count]<=quat && rt[2][count]>0)
		{
			overall_time+=rt[2][count];
			quat-=rt[2][count];
			rt[2][count]=0;
			flag=1;
		}
		else if(rt[2][count]>0 && rt[2][count]>quat)
		{
			overall_time+=quat;
			rt[2][count]-=quat;
			quat =0;
		}
		if(rt[2][count]==0 && flag==1) 
    		{ 
      			number[2]--;
			remain--; 
      			print_comp(2,overall_time,count);
      			flag=0;
			count++; 
    		}
		if(quat==0)
			fcfsnumber=count;
		if(at[2][count]<=overall_time) 
  	    		count++;
	}
}
int roundRobin(int quat)
{
	for(count=0,t_quat=4;number[0]!=0 && quat>0;)
	{
		if(t_quat>quat)
		{
			t_quat=quat;
		}
		if(rt[0][count]<=t_quat && rt[0][count]>0) 
    		{ 
      			overall_time+=rt[0][count]; 
			quat-=t_quat;
    			rt[0][count]=0; 
    			flag=1; 
    		}	 
    		else if(rt[0][count]>0) 
   		{ 
      			rt[0][count]-=t_quat; 
      			overall_time+=t_quat; 
			quat-=t_quat;
    		}	 	
    		if(rt[0][count]==0 && flag==1) 
    		{ 
      			number[0]--;
			remain--; 
      			print_comp(0,overall_time,count);
      			flag=0; 
    		}	 
    		if(count==number[0]) 
      			count=0; 
    		else if(at[0][count+1]<=overall_time) 
  	    		count++; 
    		else 
      			count=0;
		
	 
  	}
	 
return 0;
}
void print_comp(int type,int time,int c)
{
	printf("\nP[%d%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",type,c+1,at[type][c],priority[type][c],time,time-at[type][c],time-at[type][c]-bt[type][c]); 
      			waiting_time+=time-at[type][c]-bt[type][c]; 
      			turnaround_time+=time-at[type][c];
}

