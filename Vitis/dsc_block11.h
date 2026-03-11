#ifndef DSC_BLOCK_H
#define DSC_BLOCK_H

#define CIN 32
#define COUT 64
#define H 8
#define W 8
#define K 3

void dsc_block11(
float input[CIN][H][W],
float depth_kernel[CIN][K][K],
float point_kernel[COUT][CIN],
float output[COUT][H][W]
);

#endif
