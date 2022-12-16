# include <stdio.h>

void Darray(char *arr[], int start, int len){
	if(start>=len){
		printf("\n");
		return;
	}
	printf("%s ", arr[start]);
	Darray(arr, start+1, len);
}

int main(){
	char *arr[] = {"hi", "die", "shit"};
	Darray(arr, 0, 3);
	return 0;
}
