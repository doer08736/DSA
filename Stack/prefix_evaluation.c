# include <stdio.h>
# include <string.h>
# include <math.h>

// stack of array
int stack[20];
// no of index
int top = 0;

int evaluate(char *str){
	// here is the length of the string minus 1 cause we need last index
	int i = strlen(str)-1;
	// run this loop until the first stuff is met in given string
	while(i>=0){
		// if the value is 0-9 then add in the stack
		if(str[i]>='0' && str[i]<='9')
			// str[i]-'0' because it will store the ascii value of that number
			stack[top++] = str[i]-'0';
		else{
			// if we meet operator pop the top 2 element and do operation
			int op1 = stack[--top];
			int op2 = stack[--top];
			// check which operator and so operation and store in the stack
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
		// decrement of i cause need to go lower
		i--;
	}
	// return the top most element that is the value/result
	return stack[top-1];
}		

int main(){
	char str[30];
	scanf("%[^\n]s", str);
	printf("%s\n", str);
	printf("%d\n", evaluate(str));
	return 0;
}
