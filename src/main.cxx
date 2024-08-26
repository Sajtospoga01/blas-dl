#include <cblas.h>
#include "layers/linear.hxx"
#include "layers/relu.hxx"
#include "layers/softmax.hxx"

int main(){

    auto linear = Linear(1, 4);
    auto relu = ReLU(4);
    auto linear2 = Linear(4, 4);
    auto relu2 = ReLU(4);
    auto final = Linear(4, 2);
    auto softmax = Softmax(2);
    auto input = new double[1];
    input[0] = -2.0;

    auto output = linear.forward(input);
    auto reluOutput = relu.forward(output);
    
    auto output2 = linear2.forward(reluOutput);
    auto reluOutput2 = relu2.forward(output2);
    
    auto output3 = final.forward(reluOutput2);
    auto finalOutput = softmax.forward(output3);
    

    

    for (int i = 0; i < 4; ++i) {
        printf("%f\n", output2[i]);
    }

    printf("Final output:\n");
    for (int i = 0; i < 2; ++i) {
        printf("%f ", finalOutput[i]);
    }
    printf("\n");
    // printf("Length of final output: %d\n", sizeof(finalOutput)/sizeof(finalOutput[0]));

    

    return 0;
}