# include <stdio.h>

int fact(int n){
	if(n==1)
		return 1;
	return n*fact(n-1);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", fact(n));
	return 0;
}

/*
Time Complexity:
T(n) = T(n-1)+3 (3 for constant operation add, sub, comparison)
T(n) = T(n-k)+k
T(n) = T(n-n)+n (n = k)
T(n) = T(0)+n
T(n) = n

=> O(n)
*/

/*
eg: fact(5)
5*fact(4) = 120 (5*24)
4*fact(3) = 24 (4*6)
3*fact(2) = 6 (3*2)
2*fact(1) = 2 (2*1)
*/
