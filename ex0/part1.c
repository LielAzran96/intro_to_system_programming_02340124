#include <stdio.h>
#include <stdlib.h>

int readSize();
int powerOfTwo(int numberFromArray);
int* readNumbers(int size);

/* Reads an integer from the standard input
returns:
 1) size - the size that the user gave.
*/
int readSize() {
	int size = 0;
	printf("Enter size of input:\n");
	scanf("%d", &size);
	return size;
}

/* Reads numbers from the standard input and returns the array with those numbers
inputs :
 1) size - the size of the array.
 
returns:
 1) NULL if one of the inputs is not an integer.
 2) The array of numbers if the array's update is success.
*/
int* readNumbers(int size){
    int *numbersArray = malloc(size * sizeof(*numbersArray));
    if (numbersArray == NULL) {
        return NULL;
    }
    printf("Enter numbers:\n");
    for(int i=0; i<size; i++){
        if(scanf("%d", &numbersArray[i]) != 1){
            free(numbersArray);
            return NULL;
        }
    }
    return numbersArray;
}


/* Check if a number is a power of 2 and if so it calculates the exponent
input:
 1) numberFromArray - the number that needs to be checked.

returns:
 1) exponent -
     if the number is a power of 2 it returns the actual exponent. 
     if the number isn't power of 2 it returns -1.
*/
int powerOfTwo(int numberFromArray){
    int exponent = -1;
    if (numberFromArray>0){
        exponent = 0;
        while (numberFromArray>1){
            if (numberFromArray % 2 == 0){
                numberFromArray /= 2;
                exponent++;
            }
            else {
                exponent = -1;
                break;
            }
        }
    }
    return exponent;
}

int main(){

    int size = 0;
    int exponentSum = 0;
    int exponent;

    size = readSize();
    if (size < 1) {
		printf("Invalid size\n");
        return 0;
	}

    int* numbersArrayFromUser = readNumbers(size);
    if (numbersArrayFromUser == NULL){
        printf("Invalid number\n");
        return 0;
    }

    for(int i=0; i<size; i++){
       exponent = powerOfTwo(numbersArrayFromUser[i]);
       if (exponent != -1){
        printf("The number %d is a power of 2: %d = 2^%d\n",numbersArrayFromUser[i], numbersArrayFromUser[i], exponent);
        exponentSum = exponentSum + exponent;
       }
    }
    printf("Total exponent sum is %d\n",exponentSum);
    free(numbersArrayFromUser);
    return 0;
}

