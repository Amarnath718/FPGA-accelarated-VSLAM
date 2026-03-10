#include "dsc_block.h"

// Depthwise convolution
void depthwise_conv(
float input[CIN][H][W],
float kernel[CIN][K][K],
float output[CIN][H][W])
{

for(int c=0;c<CIN;c++)
{
    for(int i=1;i<H-1;i++)
    {
        for(int j=1;j<W-1;j++)
        {

#pragma HLS PIPELINE

            float sum=0;

            for(int ki=0;ki<K;ki++)
            {
                for(int kj=0;kj<K;kj++)
                {
                    sum += input[c][i+ki-1][j+kj-1] *
                           kernel[c][ki][kj];
                }
            }

            output[c][i][j] = sum;

        }
    }
}

}


// Pointwise convolution
void pointwise_conv(
float input[CIN][H][W],
float weight[COUT][CIN],
float output[COUT][H][W])
{

for(int oc=0; oc<COUT; oc++)
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {

#pragma HLS PIPELINE

            float sum = 0;

            for(int ic=0; ic<CIN; ic++)
            {
                sum += input[ic][i][j] *
                       weight[oc][ic];
            }

            output[oc][i][j] = sum;

        }
    }
}

}


// Top function
void dsc_block(
float input[CIN][H][W],
float depth_kernel[CIN][K][K],
float point_kernel[COUT][CIN],
float output[COUT][H][W]
)
{

#pragma HLS DATAFLOW

float depth_out[CIN][H][W];

depthwise_conv(input,depth_kernel,depth_out);

pointwise_conv(depth_out,point_kernel,output);

}
