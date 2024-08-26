
#ifndef LINEAR_HXX
#define LINEAR_HXX

class Linear
{
    public:
        Linear(int inFeat, int outFeat);
        ~Linear();
        virtual double* forward(double* input);
    private:
        int inFeatures;
        int outFeatures;
        double* weightMatrix;
        double* bias;
};

#endif