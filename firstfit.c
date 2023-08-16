#include <stdio.h>

void firstfit(int processes, int blocks, int processsize[], int blocksize[])
{
    int allocate[processes];
    int occupied[blocks];
    for(int i=0;i<processes;i++)
    {
        allocate[i]=-1;
    }
    for(int i=0;i<blocks;i++)
    {
        occupied[i]=0;
    }
    for(int m=0;m<processes;m++)
    {
        for(int n=0;n<blocks;n++)
        {
            if(!occupied[n]&&blocksize[n]>=processsize[m])
            {
                occupied[n]=1;
                allocate[m]=n;
                break;
            }
        }
    }
    printf("process no\tprocess size\tblockno\n");
    for(int i=0;i<processes;i++)
    {
        printf("%d \t %d",i+1,processsize[i]);
        if(allocate[i]!=-1)
        {
            printf("\t%d\n",allocate[i]+1);
        }
        else{
            printf("not alloc\n");
        }
    }
}

int main()
{
    int blocksize[]={30,5,10};
    int processsize[]={10,6,9};
    int blocks=sizeof(blocksize)/sizeof(blocksize[0]);
    int processes=sizeof(processsize)/sizeof(processsize[0]);
    firstfit(processes,blocks,processsize,blocksize);
    return 0;
}