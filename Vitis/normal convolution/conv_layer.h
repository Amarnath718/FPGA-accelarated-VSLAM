#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#define H 8
#define W 8
#define CIN 8
#define COUT 16
#define K 3

void conv_layer(
    float input[CIN][H][W],
    float kernel[COUT][CIN][K][K],
    float output[COUT][H-K+1][W-K+1]
);

#endif
