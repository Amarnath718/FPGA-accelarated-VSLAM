#include "conv_layer.h"

void conv_layer(
    float input[CIN][H][W],
    float kernel[COUT][CIN][K][K],
    float output[COUT][H-K+1][W-K+1]
){

#pragma HLS INTERFACE s_axilite port=return bundle=control

for(int oc = 0; oc < COUT; oc++){

    for(int i = 0; i < H-K+1; i++){

        for(int j = 0; j < W-K+1; j++){

#pragma HLS PIPELINE

            float sum = 0;

            for(int ic = 0; ic < CIN; ic++){

                for(int ki = 0; ki < K; ki++){

                    for(int kj = 0; kj < K; kj++){

                        sum += input[ic][i+ki][j+kj] *
                               kernel[oc][ic][ki][kj];

                    }

                }

            }

            output[oc][i][j] = sum;

        }

    }

}

}
