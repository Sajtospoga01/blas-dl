#include "softmax.hxx"

Softmax::Softmax(int inFeat) : inFeatures(inFeat)
{
}

Softmax::~Softmax()
{
}

double* Softmax::forward(double* input)
{
    printf("Forwarding softmax layer with size %d\n", inFeatures);
    double* output = new double[inFeatures];

    double sum = 0.0;
    for (int i = 0; i < inFeatures; ++i) {
        output[i] = exp(input[i]);
        sum += output[i];
    }

    for (int i = 0; i < inFeatures; ++i) {
        output[i] /= sum;
    }

    return output;
}

