//
//  round_robin2.c
//  Sudershan@C++
//
//  Created by Sudershan Sridhar on 31/10/18.
//  Copyright © 2018 Sudershan Sridhar. All rights reserved.
//

#include<stdio.h>

int bt[10];

void sort(int bt[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(bt[j]<bt[i])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
}
int main()
{
    
    int count,n,time,x,flag=0,time_quantum;
    int wait_time=0,turnaround_time=0,at[10],rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d",&n);
    x=n;
    for(count=0;count<n;count++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
    }
    sort(bt,n);
    time_quantum=0;
    if(!n%2)
    {
      for(int i=0;i<n;i++)
      {
          time_quantum+=bt[i];
          
      }
      time_quantum/=n;
    }
    else
        time_quantum = bt[n/2];
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(time=0,count=0;x!=0;)
    {
        if(rt[count]<=time_quantum && rt[count]>0)
        {
            time+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0)
        {
            rt[count]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[count]==0 && flag==1)
        {
            x--;
            printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
            wait_time+=time-at[count]-bt[count];
            turnaround_time+=time-at[count];
            flag=0;
        }
        if(count==n-1)
            count=0;
        else if(at[count+1]<=time)
            count++;
        else
            count=0;
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
    return 0;
}

