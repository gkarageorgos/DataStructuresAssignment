/*
	Stack (LIFO) using an array.
*/


#include <stdio.h>
#define max 10

void push(int *stack, int *ptr, int value){
	if (*ptr < max-1){
		*ptr+=1;
		stack[*ptr] = value;
	}
	else{
		printf("The stack is full\n");
	}
}

void pop(int *stack, int *ptr, int *ptr1){
	if (*ptr >= 0){
		*ptr1 = stack[*ptr];
		*ptr-=1;
	}
	else{
		printf("The stack is empty\n");
	}
}

void readAll(int *stack, int *ptr){
	if (*ptr>=0){
		int i;
		printf("*****************************************************\n");
		for (i = *ptr; i >= 0; i--){
			printf("%d\n", stack[i]);
		}
		printf("*****************************************************\n");
	}
	else{
		printf("The stack is empty\n");
	}
}

int main(){
	int stack[max];
	int top = -1;
	int value, x, choice;
	while (1){
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display stack\n");
		printf("4.Exit\n");
		scanf("%d", &choice);
		if (choice == 1){
			printf("Enter a number:");
			scanf("%d", &value);
			push(stack, &top, value);
		}
		else if (choice == 2){
			if (top>=0){
				pop(stack, &top, &x);
				printf("%d exported from the stack\n", x);
			}
			else{
				pop(stack, &top, &x);
			}
			
		}
		else if (choice == 3){
			readAll(stack, &top);
		}
		else if (choice == 4){
			printf("Bye bye!");
			return 0;
		}
	}
}
