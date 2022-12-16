# include <stdio.h>
# include <string.h>
# define shit main

char stack[30];
int top = 0;

int isEmpty(){
	if(top==0)
		return 1;
	return 0;
}

char *checkBalancedParantheses(char *exp){
	int size = strlen(exp);
	for(int i=0; i<size; ++i){
		// push to the stack if it is ( or [ or {
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			stack[top++] = exp[i];
		// if the stack is empty then return false
		else if(isEmpty()){
			return "False";
		}
		else{
			// if the top element of the stack and element current is right close and left close then pop top element form stack
			if(stack[top-1]=='(' && exp[i]==')' || stack[top-1]=='{' && exp[i]=='}' || stack[top-1]=='[' && exp[i]==']')
				top--;
			// if not matched then return false
			else
				return "False";
		}
	}
	if(isEmpty())
		return "True";
	return "False";
}	
	
int shit(){
	char exp[30];
	scanf("%[^\n]s", exp);
	printf("%s\n", exp);
	printf("%s\n", checkBalancedParantheses(exp));
	return 0;
}
