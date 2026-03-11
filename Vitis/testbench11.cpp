#include <iostream>
#include "dsc_block11.h"

int main()
{

static float input[CIN][H][W];
static float depth_kernel[CIN][K][K];
static float point_kernel[COUT][CIN];
static float output[COUT][H][W];


// initialize input
for(int c=0;c<CIN;c++)
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            input[c][i][j] = 1;
        }
    }
}


// initialize depthwise kernel
for(int c=0;c<CIN;c++)
{
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<K;j++)
        {
            depth_kernel[c][i][j] = 0.1;
        }
    }
}


// initialize pointwise kernel
for(int oc=0;oc<COUT;oc++)
{
    for(int ic=0;ic<CIN;ic++)
    {
        point_kernel[oc][ic] = 0.1;
    }
}


// run block
dsc_block11(input,depth_kernel,point_kernel,output);


// print output sample
std::cout<<"Output sample: "
         <<output[0][10][10]
         <<std::endl;

return 0;

}
