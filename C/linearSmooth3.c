//3点平滑滤波
#include <stdio.h>
#include <stdlib.h>
#define SIZE 46
void linearSmooth3 ( double in[], double out[], int N );

int main(void)
{
    int i = 0;
    double in[SIZE] = { 1,	2,	3,	4,	5,	6,	2,	8,	9,	10,	11,	12,	6,
    14,	15,	16,	17,	18,	19,	20,	16,	22,	23,	24,	25,	26,
    27,	18,	29,	30,	31,	23,	33,	34,	35,	36,	37,	29,	39,	40,	41,	42,	43,	44,	39,	46,
};

    double out[SIZE] = {0};

    printf("Before linear smooth3:\n");
    for(i = 0; i < SIZE; i++)
    {
        printf("%8.2f", in[i]);
        if((i+1)%8 == 0)
            printf("\n");
    }

    linearSmooth3(in, out, SIZE);
    printf("\n\nAfter linear smooth3:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%8.2f", out[i]);
        if((i+1)%8 == 0)
            printf("\n");
    }

    i = 0;

    //把linear smooth 后的数组打印到
    FILE *fp;
    fp = fopen("array.txt", "w");
    while(i < 46)
    {
        fprintf(fp, "%8.2f, ", out[i]);
        i++;
    }
    fclose(fp);
    return 0;
}
void linearSmooth3 ( double in[], double out[], int N )
{
    int i;
    if ( N < 3 )
    {
        for ( i = 0; i <= N - 1; i++ )
        {
            out[i] = in[i];
        }
    }
    else
    {
        out[0] = ( 5.0 * in[0] + 2.0 * in[1] - in[2] ) / 6.0;

        for ( i = 1; i <= N - 2; i++ )
        {
            out[i] = ( in[i - 1] + in[i] + in[i + 1] ) / 3.0;
        }

        out[N - 1] = ( 5.0 * in[N - 1] + 2.0 * in[N - 2] - in[N - 3] ) / 6.0;
    }
}
