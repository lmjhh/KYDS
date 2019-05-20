#include <stdio.h>
int fac(int m, int n){
	if(m == 1){
		return 1;
	}
	if(n == 1){
		return 1;
	}
	if(m < n){
		return fac(m,m);
	}
	if(m == n){
		return 1 + fac(m,n-1);
	}
	return fac(m,n - 1) + fac(m - n, n);
}

int main()
{
	printf("%d\n", fac(6,4));
	return 0;
}