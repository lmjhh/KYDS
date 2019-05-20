#include "CommonHeader.hpp"

int MaxSubseqSum3(int A[], int N){
    int MaxSum = 0, thisSum = 0;
    for(int i = 0; i < N; i++){
        thisSum += A[i];
        if(thisSum > MaxSum)
            MaxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return MaxSum;
}

//int main(){
//    int A[8] = {4,-3,5,-2,-1,2,6,-2};
//    cout << MaxSubseqSum(A,8) << endl;
//    return 0;
//}

