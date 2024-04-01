/*
	We use the push and pop operations on a LIFO stack to evaluate the expression 
	4 - [(10+3) x (12-6)]. At each step, we determine the contents of the stack.
*/


#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data;
	struct stack *next;
};
struct stack *top;

void push(int value){
	struct stack *temp;
	temp = malloc(sizeof(struct stack));
	temp->data = value;
	temp->next = top;
    top = temp;
}

void pop(int *ptr){
	if (top == NULL){
		printf("The stack is empty\n");
	}
	else{
		*ptr = top->data;
		top = top->next;
	}
}

void readAll(){
	struct stack *temp;
	temp = top;
	if(temp == NULL){
		printf("The stack is empty\n");
        return;
    }
    printf("*****************************************************\n");
	while (temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
	printf("*****************************************************\n");
}

int main(){
	int x, y;
	push(4);
	push(10);
	push(3);
	readAll();
	pop(&x);
	pop(&y);
	readAll();
	push(x+y);
	readAll();
	push(12);
	push(6);
	readAll();
	pop(&x);
	pop(&y);
	readAll();
	push(y-x);
	readAll();
	pop(&x);
	pop(&y);
	readAll();
	push(x*y);
	readAll();
	pop(&x);
	pop(&y);
	readAll();
	push(y-x);
	readAll();
	pop(&x);
	readAll();
	printf("4-[(10+3)x(12-6)]=%d", x);
	
	return 0;
}
