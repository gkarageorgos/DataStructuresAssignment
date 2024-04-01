/*
	Assuming A, B, C are arrays with indices 1 to 10.
    Using the retrieve and update functions, 
    we implement the addition of matrices A := B + C.
*/


#include <stdio.h>

#define N 10

float retrieve(float* array, int i) {
    return array[i - 1];
}

void update(float* array, int i, float value)
{
		array[i - 1] = value;
}

void addArrays(float* A, float* B, float* C) {
    for (int i = 1; i <= N; i++) {
        float sum = retrieve(B, i) + retrieve(C, i);
        update(A, i, sum);
    }
} 
 
int main()
{
	float A[N], B[N], C[N];
	
	float numbers_B[N] = {1.0, 2.0, 3.4, 9.0, 5.6, 7.2, 8.5, 10.2, 6.7, 4.3};
    float numbers_C[N] = {0.5, 2.3, 6.7, 8.9, 3.1, 7.4, 1.2, 5.6, 9.8, 2.0};
    
    for (int i = 0; i < N; i++) {
        update(B, i + 1, numbers_B[i]);
        update(C, i + 1, numbers_C[i]);
    }
 
	addArrays(A, B, C);

    // Printing array A.
    printf("The array A after addition:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");
    
	return 0;
}
 
