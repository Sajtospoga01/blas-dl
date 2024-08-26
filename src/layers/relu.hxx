#include <cstdio>
#ifndef RELU_HXX
#define RELU_HXX

class ReLU
{
    public:
        ReLU(int inFeat);
        ~ReLU();
        virtual double* forward(double* input);
    private:
        int inFeatures;
};

#endif