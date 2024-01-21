# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAX 20
char infix[MAX] = "A+(B*C-(D/E^F)*G)*H";
char postfix[MAX], stack[MAX];
int top_of_stack = -1;

void push(char symbol){
  stack[++top_of_stack] = symbol; 
}

char pop() {
  return stack[top_of_stack--];
}

int precedence(char ch)   {   
  switch (ch)   {   
    case '+':   
    case '-':   
        return 1;   
    case '*':   
    case '/':   
        return 2;   
    case '^':   
        return 3;   
    }   
    return -1;   
}

int main(void) {
  stack[++top_of_stack] = '(';
  infix[strlen(infix)] = ')';
  
  for(int i=0, j=0; infix[i] != '\0'; i++){
    if (infix[i] >= 'A' && infix[i] <= 'Z')
      postfix[j++] = infix[i];
    else if (infix[i] == '(' )
      push(infix[i]);
    else if (infix[i] == ')') {
      while (stack[top_of_stack] != '(')
        postfix[j++] = stack[top_of_stack--];
      top_of_stack--;
    }
    else {
      while (precedence(infix[i]) <= precedence(stack[top_of_stack]))
        postfix[j++] = pop();   
      push(infix[i]);   
    }
  }
  printf("\nInfix expression: %s", infix);
  printf("\nPostfix expression: %s\n", postfix);
 return 0; 
}

/* Output
Infix expression: A+(B*C-(D/E^F)*G)*H)
Postfix expression: ABC*DEF^/G*-H*+
*/