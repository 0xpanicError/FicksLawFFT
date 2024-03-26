#include <stdio.h>
#define N 100

int main()
{
    float D = 1;
    float delT = 0.1;
    int delX = 1;
    FILE *fp;

    float C[N] = {0};

    for (int i = 25; i < 75; i++)
    {
        C[i] = 1;
    }
    fp = fopen("output.txt", "w");

    for (int t = 0; t < 10000; t++)
    {
        for (int x = 0; x < 100; x++)
        {
            C[x] = C[x] + (D * delT / (delX * delX)) * (C[(x + 1 + N) % 100] - 2 * C[x] + C[(x - 1 + N) % 100]);
        }

        if (t % 1000 == 0)
        {

            for (int i = 0; i < 100; i++)
            {
                fprintf(fp, "%f, ", C[i]);
            }

            fprintf(fp, "\n \n \n ");
        }
    }
    fclose(fp);
}