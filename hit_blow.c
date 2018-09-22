#include <stdio.h>
#include <stdlib.h>
void parse(int n,char *b);
int main()
{
    int result=0;
    int n;
    char a[4],b[4];
    char hit=0,blow=0,i,j;
    printf("Hit and Blow game!!\n");
    //printf("Input a 4-digit number\n");
    //scanf("%d",&n);
    //printf("Your number is %d\n",n);
    
    // Generate 4 digits
    for (i=0;i<4;i++) {
        a[i] = rand()%10;
        result = result*10+a[i];
        printf("result is: %d %d %d %d %d\n",result,a[0],a[1],a[2],a[3]);
    }
    do {
        hit = 0;
        blow = 0;
        printf("Input a 4-digit number\n");
        scanf("%d",&n);
        printf("Your number is %d\n",n);
        parse(n,b);
        
        // Hit calculatioin
        for (i=0;i<4;i++) {
            if (a[i] == b[i])
                hit++;
        }
        
        // Blow calculation
        for (i=0;i<4;i++) {
            for (j=0;j<4;j++) {
                if ((a[i]==b[j])&&(i!=j)) {
                    blow++;
                }
            }
        }
        printf("%d hit, %d blow\n",hit,blow);
    }
    while (result-n);
    printf("Good!\n");
    
    return 0;
}

void parse(int n,char *b)
{
    int i;
    for (i=3;i>=0;i--) {
        b[i] = n%10;
        n = n/10;
    }
    printf("digits: %d %d %d %d\n",b[0],b[1],b[2],b[3]);
}
