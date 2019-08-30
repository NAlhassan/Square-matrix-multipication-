#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *A, *B, *R;

int main(int argc, char *argv[]){
	int n = atoi(argv[argc - 1]);
	//printf("%f\n",n);

	A = (float *)malloc(n*n*sizeof(float));
	B = (float *)malloc(n*n*sizeof(float));
	R = (float *)malloc(n*n*sizeof(float));


//fillinig the matrix A
	srand(time(0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			*(A + i*n + j) =/* 3;*/ rand();
		}
	}

//Filling the matrix B
	srand(time(0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			*(B + i*n + j) =/*3;*/ rand();
		}
	}


//print the matrix A
/*	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%f ", *(A + i*n + j));
		}
		printf("\n");
	}

//Print the the *'s to seprate and distinguish between the matrices
	for(int i = 0; i < 30; i++)
		printf("*");
	printf("\n\n\n\n\n");

//Print the matrix B
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%f ",*(B + i*n + j));
		}
		printf("\n");
	}*/

//The variabels to start the calculating the excution time
	clock_t start, end;
	double total_time = 0;

//From here i start the calculating of time
	start = clock();

//The multitpication btween A & B
	float s = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				s += *(A + i*n + j) * *(B + i*n + j);
			}
			*(R + i*n + j) = s;
			s = 0;
		}
	}

//Here i stop the calcilating of time
	end = clock();


	total_time = (double) (end - start) / CLOCKS_PER_SEC; //Total time

//Print the Toatl time
	printf("%f\n\n", total_time);

//Print the *'s to seprate between the matrices
/*	for(int i = 0; i < 30; i++)
		printf("*");
	printf("\n\n\n\n\n");

//Print the matrix R
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%f ",*(R + i*n + j));
		}
		printf("\n");
	}
*/

//Free the matrices
	free(A);
	free(B);
	free(R);

	return 0;
}
