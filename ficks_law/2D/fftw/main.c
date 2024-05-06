#include <stdio.h>
#include <fftw3.h>
#include <math.h>

#define N 10000

int main()
{
    float D = 1;
    float delT = 0.1;
    int delX = 1;
    FILE *fp;

    fftw_complex *in, *out;
    fftw_plan plan_forward, plan_backward;

    in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);

    for (int i = 25; i < 75; i++)
    {
        for (int j = 25; j < 75; j++)
        {
            in[i * 100 + j][0] = 1;
            in[i * 100 + j][1] = 0;
        }
    }

    plan_forward = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    plan_backward = fftw_plan_dft_1d(N, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);

    fp = fopen("output.txt", "w");

    for (int t = 0; t < 10000; t++)
    {
        fftw_execute(plan_forward);

        for (int k = 0; k < N; k++)
        {
            float kx = 2 * M_PI * k / N;
            float factor = 1 - (D * delT * delT * kx / (delX * delX));

            float real = out[k][0];
            float imag = out[k][1];

            out[k][0] = real * factor;
            out[k][1] = imag * factor;
        }

        fftw_execute(plan_backward);

        for (int x = 0; x < N; x++)
        {
            in[x][0] /= N;
            in[x][1] /= N;
        }

        if (t % 1000 == 0)
        {
            for (int i = 0; i < N; i++)
            {
                fprintf(fp, "%f, ", in[i][0]);
            }

            fprintf(fp, "\n \n \n ");
        }
    }

    fclose(fp);

    fftw_destroy_plan(plan_forward);
    fftw_destroy_plan(plan_backward);
    fftw_free(in);
    fftw_free(out);

    return 0;
}