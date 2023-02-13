# include <stdio.h>


void towerOfHanoi(int disk, char beg, char aux, char end){
	if(disk==1){
		printf("%c - %c\n", beg, end);
		return;
	}
	towerOfHanoi(disk-1, beg, end, aux);
	printf("%c - %c\n", beg, end);
	towerOfHanoi(disk-1, aux, beg, end);
}

int main(){
	int disk;
	scanf("%d", &disk);

	towerOfHanoi(disk, 'A', 'B', 'C');

	return 0;
}

/*
Time complexity:
T(n) = T(n-1) + T(n-1) + 1
T(n) = 2T(n-1) + 1
T(n) = 2*2^(n-1) - 1
T(n) = 2^n-1
T(n) = O(2^n)

=> O(2^n)
*/

/*
Output:
5
A - C
A - B
C - B
A - C
B - A
B - C
A - C
A - B
C - B
C - A
B - A
C - B
A - C
A - B
C - B
A - C
B - A
B - C
A - C
B - A
C - B
C - A
B - A
B - C
A - C
A - B
C - B
A - C
B - A
B - C
A - C
*/
