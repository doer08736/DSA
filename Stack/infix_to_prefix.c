# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char stack[30];
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

void reverseString(char *str){
	int temp, size = strlen(str);
	for(int i=0; i<size/2; ++i){
		temp = str[i];
		str[i] = str[size-1-i];
		str[size-1-i] = temp;
	}
}

void infixToPrefix(char *infixExp, char *prefixExp){
	int resultIndex = 0, temp, size = strlen(infixExp);
	reverseString(infixExp);
	for(int i=0; i<size; ++i){
		if(infixExp[i]==')')
			infixExp[i] = '(';
		else if(infixExp[i]=='(')
			infixExp[i] = ')';
	}
	stack[top++] = '(';
	strcat(infixExp, ")");
	size = strlen(infixExp);
	for(int i=0; i<size; ++i){
		if(infixExp[i]=='(')
			stack[top++] = infixExp[i];
		else if(infixExp[i]>='a' && infixExp[i]<='z' || infixExp[i]>='A' && infixExp[i]<='Z')
			prefixExp[resultIndex++] = infixExp[i];
		else if(infixExp[i]==')'){
			while(stack[top-1]!='(')
				prefixExp[resultIndex++] = stack[--top];
			stack[--top];
		}
		else if(isOperator(infixExp[i])){
			while(isOperator(stack[top-1]) && precedence(stack[top-1])>precedence(infixExp[i]))
				prefixExp[resultIndex++] = stack[--top];
			stack[top++] = infixExp[i];
		}
	}
	// to make sure string ends with null so that it won't contain some unwanted stuffs
	prefixExp[resultIndex++] = '\0';
	reverseString(prefixExp);
}

int main(){
	char infixExp[30], prefixExp[30];
	scanf("%[^\n]s", infixExp);
	
	infixToPrefix(infixExp, prefixExp);
	printf("%s\n", prefixExp);
	
	return 0;
}
