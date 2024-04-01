/*
	Calculating the address of each element of an array A(1:3, 1:2, 3:3, 1:3).
	The array has a base address b=100 and a component length L=6, 
	while the upper and lower bounds of its indices are as mentioned above.
*/


#include <stdio.h>
#define b 100
#define L 6

int main(){
	int c[5], j, addr; 
	int l[4] = {1, 1, 3, 1};	//The lower bounds of the indices
	int u[4] = {3, 2, 3, 3};	//The upper bounds of the indices
	int i[4];	// Array of content values
	i[2] = 3;	// The index i3 is always 3
	c[4] = L;	// Calculating c[i] for 0 < i <= 4
	for (j = 4; j > 1; j--){
		c[j-1] = (u[j-1] - l[j-1] + 1)*c[j];
	}
	c[0] = b;	// Calculating c[0] based on the formula C_0 = b - C_1 * l_1 - C_2 * l_2 - C_3 * l_3 - C_4 * l_4
	for (; j < 5; j++){
		c[0]+=-c[j]*l[j-1];
	}
	//		The user provides an element of the array and expects to receive its address
	for (j = 0; j < 2; j++){	
		printf("Enter an integer number between %d and %d:", l[j], u[j]);
		scanf("%d", &i[j]);
	}
	printf("Enter an integer number between %d and %d:", l[3], u[3]);
	scanf("%d", &i[3]);
	addr = c[0];
	for (j = 0; j < 4; j++){
		addr+=c[j+1]*i[j];
	}
	printf("The address of the data (%d, %d, %d, %d): %d",i[0], i[1], i[2], i[3], addr);
	
	
	return 0;
}
