#include "CommonHeader.hpp"
#include "MathCalcTool.hpp"

int MaxSubseqSum2(int A[], int left, int right){
	if(left == right){
		if(A[left] > 0) return A[left];
		else  return 0;
	}
	int center = (left + right) / 2;
    int maxLeftSum = MaxSubseqSum2(A,left,center);
    int maxRightSum = MaxSubseqSum2(A,center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for(int i = center; i >= left; i--){
		leftBorderSum += A[i];
		if(maxLeftBorderSum < leftBorderSum){
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for(int i = center + 1; i <= right; i++){
		rightBorderSum += A[i];
		if(maxRightBorderSum < rightBorderSum){
			maxRightBorderSum = rightBorderSum;
		}
	}

	return Max3(maxRightBorderSum + maxLeftBorderSum, maxLeftSum, maxRightSum);
}

//int main(){
//    int A[8] = {4,-3,5,-2,-1,2,6,-2};
//    cout << MaxSubseqSum(A,0,7) << endl;
//    return 0;
//}
