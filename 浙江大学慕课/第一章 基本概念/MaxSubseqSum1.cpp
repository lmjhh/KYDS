#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int MaxSubseqSum(int A[], int N){
	int MaxSum = 0;
	for(int i = 0; i < N; i++){
		int thisSum = 0;
		for(int j = i; j < N; j++){
			thisSum += A[j];
			if(thisSum > MaxSum){
				MaxSum = thisSum;
			}
		}
	}
	return MaxSum;
}

int main(){
	int A[8] = {4,-3,5,-2,-1,2,6,-2};
	cout << MaxSubseqSum(A,8) << endl;
	return 0;
}