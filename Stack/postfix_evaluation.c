# include <stdio.h>
# include <string.h>
# include <math.h>

int stack[20];
int top = 0;

int evaluate(char *str){
	int size = strlen(str);
	for(int i=0; i<size; i++){
		if(str[i]>='0' && str[i]<='9')
			stack[top++] = str[i]-'0';
		else{
			int op1 = stack[--top];
			int op2 = stack[--top];
			switch(str[i]){
				case '+':
					stack[top++] = op1+op2;
					break;
				case '-':
					stack[top++] = op1-op2;
					break;
				case '*':
					stack[top++] = op1*op2;
					break;
				case '/':
					stack[top++] = op1/op2;
					break;
				case '^':
					stack[top++] = pow(op1, op2);
					break;
			}
		}
	}
	return stack[top-1];
}

int main(){
	char str[20];
	scanf("%[^\n]s", str);
	printf("%d\n", evaluate(str));
	return 0;
}
				
