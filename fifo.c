#include <stdio.h>

int main()
{
    int incomingstream[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int m, n, s, pages;
    int pagefaults=0;
    int frames=3;
    pages=sizeof(incomingstream)/sizeof(incomingstream[0]);
    int temp[frames];
    for(int i=0;i<frames;i++)
    {
        temp[i]=-1;
    }
    printf("incoming \t frame 1 \t frame 2 \tframe 3");
    for(m=0;m<pages;m++)
    {
        s=0;
        for(n=0;n<frames;n++)
        {
            if(incomingstream[m]==temp[n])
            {
                s++;
                pagefaults--;
            }
        }
        pagefaults++;
        if((pagefaults<=frames)&&(s==0))
        {
            temp[m]=incomingstream[m];
        }
        else if(s==0)
        {
            temp[(pagefaults-1)%frames]=incomingstream[m];
        }
        printf("\n%d",incomingstream[m]);
        for(n=0;n<frames;n++)
        {
            if(temp[n]!=-1)
            {
                printf("\t\t%d",temp[n]);
            }
            else{
                printf("\t\t-");
            }
        }
    }
    printf("\n\ntotal page faults is %d",pagefaults);
    return 0;
}