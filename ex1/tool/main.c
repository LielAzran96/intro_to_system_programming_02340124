#include "AsciiArtTool.h"
#include <string.h>

/**
* invertPicture: gets a char an invert it from @ to ' ' and vice versa.
*
* @param charToInvert - a given char that may needed to be inverted
* @return
    '@' - if the given char is ' ' 
    ' ' - if the given char is '@
* 	charToInvert - if non of the above is true.
*/
static char invertPicture(char charToInvert);

/**
* error: gets a message to print, and the file name, and print to stderr.
*
* @param 
    message - a message to print
    fileName - the name of the file that did not open
*/
static void error(char* message, char *fileName);

static char invertPicture(char charToInvert){
    if(charToInvert ==' ') {
        return '@';
    }
    else if(charToInvert == '@') {
        return ' ';
    }
    else {
        return charToInvert;
    } 
}

static void error(char* message, char *filename){
    fprintf(stderr, "%s %s\n", message, filename ? filename : "");
}

int main(int argc, char** argv) {
    if(argc != 4) {
        error("Usage: AsciiArtTool <file1> <file2>", NULL);
        return 0;
    }
    FILE* inputFile = fopen(argv[2], "r");
    if(!inputFile) {
        error("Error: cannot open", argv[2]);
        return 0;
    }
    
    FILE* outputFile = fopen(argv[3], "w");
    if (!outputFile){
        error("Error: cannot open", argv[3]);
        fclose(inputFile);
        return 0;
    }

    RLEList newList = asciiArtRead(inputFile);
    if(!newList) {
        error("Error: allocation for new list failed",NULL);
        fclose(inputFile);
        fclose(outputFile);
        return 0;
    }

    if(!strcmp(argv[1], "-i")) {
        RLEListMap(newList, invertPicture);
        asciiArtPrint(newList, outputFile);
    } 
    else if(!strcmp(argv[1],"-e")) {
        asciiArtPrintEncoded(newList,outputFile);
    }
    else {
        error("Error: the available flags are -i or -e!", NULL);
    }
    fclose(inputFile);
    fclose(outputFile);
    RLEListDestroy(newList);
    return 0;
}