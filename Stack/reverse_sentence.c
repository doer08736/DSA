# include <stdio.h>

int top = 0;
int stack[30];

char *reverseSentence(char *sentence){
	int i = 0;
	while(sentence[i]!='\0'){
		stack[top++] = sentence[i++];
	}
}

int main(){
	char sentence[30];
	printf("Enter the sentence: ");
	scanf("%[^\n]s", sentence);
	reverseSentence(sentence);
	while(top!=0)
		printf("%c", stack[top--]);
	printf("\n");
	return 0;
}
