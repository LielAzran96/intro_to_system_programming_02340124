#include <stdio.h>
#include <stdlib.h>

int readSize();
int readNumbers(int numbersArray[], int size);
int powerOfTwo(int numberFromArray);

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

/* Reads numbers from the standard input and update the array with those numbers
inputs :
 1) numbersArray -array which needed to be updated with the numbers from the user's input.
 2) size - the size of the array.
 
returns:
 1) 1 if one of the inputs is not an integer.
 2) 0 if the array's update is success.
*/
int readNumbers(int numbersArray[], int size){
    printf("Enter numbers:\n");
    for(int i=0; i<size; i++){
        if(scanf("%d", &numbersArray[i]) != 1){
            printf("Invalid number\n");
            return 1;
        }
    }
    return 0;
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
    int checkValidNumbers = 0; // 0 if the numbers from users are valid(integers), and 1 if one of them isn't integer
    int size = 0;
    int exponentSum = 0;
    int exponent;
    size = readSize();
    if (size < 1) {
		printf("Invalid size\n");
        return 1;
	}
    int *numbersArrayFromUser = malloc(size * sizeof(*numbersArrayFromUser));
    if (numbersArrayFromUser == NULL) {
        return 0;
    }
    
    checkValidNumbers = readNumbers(numbersArrayFromUser, size);
    if (checkValidNumbers == 1){
        return 1;
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

