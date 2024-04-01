/*
	Stack (LIFO) using a linked list.
*/


#include <stdio.h>
#include <stdlib.h>

// Structure for defining nodes of the stack implemented using a linked list
struct stack{
	int data;
	struct stack *next;// Pointer to the next node to enable linked list behavior
};
struct stack *top;// Pointer to the top of the stack


void push(int value){		// Since it is of dynamic length, there is no need to check if the stack is full
	struct stack *temp;
	temp = malloc(sizeof(struct stack));
	temp->data = value;		// When pushing an element onto the stack, it will go to the top, so the top pointer will point to this element
	temp->next = top;
    top = temp;
}

void pop(int *ptr){		// There is a need to check if the stack is empty, i.e., if top == NULL
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
			push(value);
		}
		else if (choice == 2){
			if (top == NULL){
				pop(&x);
			}
			else{
				pop(&x);
				printf("%d exported from the stack\n", x);
			}
		}
		else if (choice == 3){
			readAll();
		}
		else if (choice == 4){
			printf("Bye bye!");
			return 0;
		}
	}
}
