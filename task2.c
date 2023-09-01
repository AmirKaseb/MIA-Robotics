#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start;
    scanf("%d",&start);

    for(int i=start; i>=1; i--)
    {
        printf("%d\n",i);
        sleep(1);
    }
    printf("Blast off to the moon!");
}