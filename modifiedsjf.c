//
//  modifiedsjf.c
//  Sudershan@C++
//
//  Created by Sudershan Sridhar on 31/10/18.
//  Copyright © 2018 Sudershan Sridhar. All rights reserved.
//

#include<stdio.h>

int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,ctr1;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
    wt[0]=0;
    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        
        if(wt[i]>=bt[i+1])     //modified code which solves the Starvation process
        {
            wt[i+1]=wt[i];      //Solves Starvation 
            wt[i]+=bt[i+1];
            total+=wt[i]+wt[i+1];
            i++;
            ctr1++;
            continue;
        }
        total+=wt[i];
    }
    
    avg_wt=(float)total/n;
    total=0;
    
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\np%d\t\t\t  %d\t\t\t\t   %d\t\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    
    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
