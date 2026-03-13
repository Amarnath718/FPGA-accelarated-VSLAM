#include <iostream>
#include "conv_layer.h"

int main(){

float input[CIN][H][W];
float kernel[COUT][CIN][K][K];
float output[COUT][H-K+1][W-K+1];

for(int c=0;c<CIN;c++)
for(int i=0;i<H;i++)
for(int j=0;j<W;j++)
input[c][i][j] = 1;

for(int oc=0;oc<COUT;oc++)
for(int ic=0;ic<CIN;ic++)
for(int i=0;i<K;i++)
for(int j=0;j<K;j++)
kernel[oc][ic][i][j] = 1;

conv_layer(input,kernel,output);

for(int oc=0;oc<2;oc++){
    std::cout<<"Output Channel "<<oc<<std::endl;

    for(int i=0;i<H-K+1;i++){
        for(int j=0;j<W-K+1;j++){
            std::cout<<output[oc][i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

return 0;
}
