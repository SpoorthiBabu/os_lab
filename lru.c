#include<stdio.h>

int findlru(int time[], int n)
{
    int pos=0;
    int minimum=time[0];
    for(int i=0;i<n;i++)
    {
        if(time[i]<minimum)
        {
            minimum=time[i];
            pos=i;
        }
    }
    return pos;
}

int main()
{
    int flag1,flag2;
    int counter=0;
    int faults=0;
    int time[10];
    int no_of_frames,no_of_pages;
    printf("enter number of frames\n");
    scanf("%d",no_of_frames);
    printf("enter number of pages\n");
    scanf("%d",no_of_pages);

    int pages[no_of_pages], frames[no_of_frames];
    printf("enter reference string\n");
    for(int i=0;i<no_of_pages;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(int i=0;i<no_of_frames;i++)
    {
        frames[i]=-1;
    }
    for(int i=0;i<no_of_pages;i++)
    {
        flag1=flag2=0;
        for(int j=0;j<no_of_frames;j++)
        {
            if(frames[j]==pages[i])
            {
                counter++;
                time[j]=counter;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
            for(int j=0;j<no_of_frames;j++)
            {
                if(frames[j]==-1)
                {
                    counter++;
                    time[j]=counter;
                    faults++;
                    frames[j]=pages[i];
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0)
        {
            int pos=findlru(time,no_of_frames);
            counter++;
            faults++;
            frames[pos]=pages[i];
            time[pos]=counter;
        }
        for(int i=0;i<no_of_frames;i++)
        {
            printf("%d",frames[i]);
        }
    }
    printf("total page faults is %d",faults);
    return 0;
}