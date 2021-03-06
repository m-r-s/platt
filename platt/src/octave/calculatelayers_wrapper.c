/*
 * This file is part of the PLATT reference implementation
 * Author (2018-2020) Marc René Schädler (marc.rene.schaedler@uni-oldenburg.de)
 */

#include <stdio.h>
#include <math.h>
#include "mex.h"
#include "constants.h"
#include "calculatelayers.c"

void mexFunction (int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {
  plhs[0] = mxDuplicateArray(prhs[0]); // 1. maxima
  plhs[1] = mxDuplicateArray(prhs[1]); // 2. layerbuffer
  plhs[2] = mxDuplicateArray(prhs[2]); // 3. layers
  int *layer = (int*) mxGetData(prhs[3]); // 4. layer

  float *maxima = (float*) mxGetData(plhs[0]);
  float *layerbuffer = (float*) mxGetData(plhs[1]);
  float *layers = (float*) mxGetData(plhs[2]);

  calculatelayers(maxima,
                  layerbuffer,
                  layers,
                  layer[0]);
}
