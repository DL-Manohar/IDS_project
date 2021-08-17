#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// a function which sorts the given array in ascending order using insertion sort
// also returns the total number of comparisons occured during the process
int insertionSort(int sequence[], int length) {
	int n1,n2,temp;
	// no of comparisons intialized to zero
	int comparisons = 0;

	// sorting process begins
	for(n1 = 1; n1 <= length-1; n1++) {
		// initialization for second while loop
		n2 = n1;
		while(n2 > 0) {
			// just before a comparison occurs 1 is added to comparisons
			comparisons = comparisons + 1;
			// comparison occurs
			if(sequence[n2] < sequence[n2 - 1]) {
				// swapping n2 and n2-1 elements in the sequence (array)
				temp = sequence[n2];
				sequence[n2] = sequence[n2-1];
				sequence[n2-1] = temp;
			}
			else {
				break;
			}

			n2 = n2 - 1;
		}
	}

	// returns total number of comparisons
	return comparisons;
}

// a function to shuffle the given sequence in random order
void randomizing_sequence(int sequence[], int length) {
	int temp;

	srand(time(NULL));

	for(int n = 0; n < length; n++) {
		int random = rand()%(n+1);

		temp = sequence[n];
		sequence[n] = sequence[random];
		sequence[random] = temp;
	}
}

// a function to print elements of the given sequence (or array)
void print_sequence(int sequence[], int length) {
	for(int i=0; i<length; i++) {
		printf("%d ", sequence[i]);
	}
}

int main() {
	int N,a,r;
	int comparisons;

	// taking the inputs N,a and r
	printf("Enter number of elemnts 'N' = ");
	scanf("%d",&N);
	printf("Enter first element (scale ratio) 'a' = ");
	scanf("%d",&a);
	printf("Enter common ratio 'r' = ");
	scanf("%d",&r);

	// initializing 3 arrays to store ascending, descending and random sequences
	int ascending[N];
	int descending[N];
	int random[N];

	// creating ascending sequence
	ascending[0] = a;
	int temp = a;
	for(int i=1; i<N; i++) {
		temp = temp*r;
		ascending[i] = temp;
	}

	// creating descending sequence
	int j = N - 1;
	for(int i=0; i<N; i++) {
		descending[i] = ascending[j];
		j = j - 1;
	}

	// For creating random sequence
	// first copying the ascending sequence into random
	for(int i=0; i<N; i++) {
		random[i] = ascending[i];
	}
	// Now calling the randomizing_sequence to create random sequence
	randomizing_sequence(random, N);

	printf("\n");

	// printing output for ascending order
	printf("Ascending order  : ");
	print_sequence(ascending,N);
	comparisons = insertionSort(ascending,N);
	printf("= %d Comparisons\n", comparisons);

	// printing output for descending order
	printf("Descending order : ");
	print_sequence(descending,N);
	comparisons = insertionSort(descending,N);
	printf("= %d Comparisons\n", comparisons);

	// printing output for random order
	printf("Random order     : ");
	print_sequence(random,N);
	comparisons = insertionSort(random,N);
	printf("= %d Comparisons\n", comparisons);
}