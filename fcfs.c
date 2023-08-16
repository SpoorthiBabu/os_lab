#include<stdio.h>
#include<conio.h>

typedef struct fcfs
{
    int process;
    int burst;
    int arrival;
    float tat;
    float wt;
} fcfs;

void sort(int arr[],int n)
{
    //bubble sort
}

void main()
{
    // int i, j, n, at[max], bt[max], wt[max], tat[max], temp[max];
    // float awt=0, atat=0;
    int n;
    int temp=0;
    int avtat=0, avwt=0;
    printf("enter the numbver of processes\n");
    scanf("%d",&n);
    fcfs arr[n];
    int tct[n];
    for(int i=0;i<n;i++)
    {
        printf("enter process number\n");
        scanf("%d",&arr[i].process);
        printf("enter arrival time\n");
        scanf("%d",arr[i].arrival);
        printf("enter burst time\n");
        scanf("%d",arr[i].burst);
    }
    sort(arr,n);
    for(int i=0;i<n;i++)
    {
        tct[i]=temp+arr[i].burst;
        temp=tct[i];
        arr[i].tat=tct[i]-arr[i].arrival;
        arr[i].wt=arr[i].tat-arr[i].burst;
        avtat+=arr[i].tat;
        avwt+=arr[i].wt;
    }
    //print all at,bt,ct,tat etc
    avtat=avtat/(float)n;
    avwt=avwt/(float)n;
    // print these two
    return 0;
}



// printf("enter the burst times of processes\n");
    // for(int i=0;i<n;i++)
    // {
    //     scanf("%d",&bt[i]);
    // }
    // printf("enter the arrival times of processes\n");
    // for(int i=0;i<n;i++)
    // {
    //     scanf("%d",&at[i]);
    // }
    // temp[0]=0;