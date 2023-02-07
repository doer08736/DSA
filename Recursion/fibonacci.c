# include <stdio.h>
# include <stdlib.h>

int getTerm(){
	int term;
	printf("Enter the term: ");
	scanf("%d", &term);
	return term;
}

int fibo(int n){
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	return fibo(n-1)+fibo(n-2);
}

int main(){
	int choice, term;
	while(1){
		printf("find fibonacci of:\n1. nth term\n2. list till nth term\n3. exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("%d\n", fibo(getTerm()));
				break;
			case 2:
				term = getTerm();
				for(int i=1; i<=term; ++i)
					printf("%d ", fibo(i));
				printf("\n");
				break;
			case 3:
				exit(0);
		}
	}
	return 0;
}

/*
eg:
		   fibo(5)
		     |
	   fibo(4)  +      fibo(3)
	     |                |
     fibo(3)+fibo(2)  fibo(2)+fibo(1)
	|
fibo(2)+fibo(1)

2+1=5  
*/

/*
Time Complexity:
T(n) = T(n-1)+T(n-2)-1
T(n) = 2T(n-1)+1 (let n-1=n-2)
T(n) = 2^kT(n-k)+2^(k-1)+..+1
T(n) = 2^nT(0)+2^(n-1)+..+1
T(n) = 1+2+4+..+2^ n = (2^(n+1)-1)/(2-1)
T(n) = 2^n

=> O(2^n)
*/
