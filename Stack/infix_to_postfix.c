# include <stdio.h>
# include <string.h>

char stack[20];
int top = 0;

int isOperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return 1;
	return 0;
}

int precedence(char op){
	if(op=='^')
		return 3;
	else if(op=='/' || op=='*')
		return 2;
	else if(op=='+' || op=='-')
		return 1;
	else
		return 0;
}

void infixToPostfix(char *exp, char *result){
	int resultIndex = 0;
	stack[top++] = '(';
	strcat(exp, ")");
	int size = strlen(exp);
	for(int i=0; i<size; ++i){
		// if operand then push to result
		if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z')
			 result[resultIndex++] = exp[i];
		// push to stack if (
		else if(exp[i]=='(')
			stack[top++] = exp[i];
		// pop from the stack and add to result untii ( is not found
		else if(exp[i]==')'){
			while(stack[top-1]!='('){
				result[resultIndex++] = stack[--top];
			}
			stack[--top];
		}
		// check if the char is operator
		else if(isOperator(exp[i])){
			while(isOperator(stack[top-1]) && precedence(stack[top-1])>=precedence(exp[i]))
				result[resultIndex++] = stack[--top];
			stack[top++] = exp[i];
		}
	}
	//result[resultIndex++] = '\0';
}

int main(){
	char exp[20], postFixExp[20];
	scanf("%[^\n]s", exp);
	infixToPostfix(exp, postFixExp);
	printf("%s\n", postFixExp);
	return 0;
}
