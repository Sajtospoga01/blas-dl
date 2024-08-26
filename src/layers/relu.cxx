#include "relu.hxx"

ReLU::ReLU(int inFeat) : inFeatures(inFeat)
{
}

ReLU::~ReLU()
{
}

double* ReLU::forward(double* input)
{
    printf("Forwarding relu layer\n");
    double* output = new double[inFeatures];

    for (int i = 0; i < inFeatures; ++i) {
        output[i] = input[i] > 0 ? input[i] : 0;
    }

    return output;
}

