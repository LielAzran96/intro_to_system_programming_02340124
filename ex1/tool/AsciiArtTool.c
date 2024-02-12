#include "AsciiArtTool.h"

RLEList asciiArtRead(FILE* in_stream) {
    RLEList list = RLEListCreate();
    if(!list) {
        return NULL;
    }
    char buffer[CHUNK_SIZE];
    int i = 0;
    RLEListResult resultFromRLEListAppend = RLE_LIST_SUCCESS;
    while(fgets(buffer, CHUNK_SIZE, in_stream) != NULL) {
        /*appending until encounters new line*/
        while(buffer[i] != '\0') {
            resultFromRLEListAppend = RLEListAppend(list, buffer[i]);
            if (resultFromRLEListAppend != RLE_LIST_SUCCESS){
                return NULL;
            }
            i++;
        }
        i = 0;
    }
    return list;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream) {
    if(!list || !out_stream) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    int listSize = RLEListSize(list);
    RLEListResult resultFromRLEListGet = RLE_LIST_SUCCESS;
    char* stringToCopy = malloc(sizeof(*stringToCopy)*listSize + 1);
    stringToCopy[listSize] = '\0';
    for(int i = 0; i < listSize; i++) {
        stringToCopy[i] = RLEListGet(list, i, &resultFromRLEListGet);
    } 
    fputs(stringToCopy, out_stream);
    free(stringToCopy);
    return resultFromRLEListGet;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream) {
    if(!list || !out_stream) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEListResult resultFromRLEListExport; 
    char* stringToCopy = RLEListExportToString(list, &resultFromRLEListExport);
    if(stringToCopy != NULL){
        fputs(stringToCopy, out_stream);
    }
    free(stringToCopy);
    return resultFromRLEListExport;
}

