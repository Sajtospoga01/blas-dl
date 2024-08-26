#include <cstdio>
#include <cmath>
#ifndef SOFTMAX_HXX
#define SOFTMAX_HXX

class Softmax
{
    public:
        Softmax(int inFeat);
        ~Softmax();
        virtual double* forward(double* input);
    private:
        int inFeatures;
};

#endif