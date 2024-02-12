#ifndef HW1_ASCII_ART_TOOL_H
#define HW1_ASCII_ART_TOOL_H

#include "../RLEList.h"
#include <stdio.h>
#include <stdlib.h>
#define CHUNK_SIZE 256

/**
* asciiArtRead: Reads the given file and compress it in RLE method .
*
* @param in_stream - object from type *FILE that contains the picture to be compressed.
* @return
* 	A RLEList that containts all the chars in the picture.
*/
RLEList asciiArtRead(FILE* in_stream);


/**
* asciiArtPrint: Writes a picture that represented by a RLE list into a file.
*
* @param list - RLE list that contains all the chars in the picture.
* @param out_stream - FILE* file to which we'll write the picture.
* @return
* 	RLE_LIST_NULL_ARGUMENT - if one of the params are NULL.
*   RLE_LIST_SUCCESS - in case of success.
*/
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);


/**
* asciiArtPrintEncoded: Writes the picture in a compressed manner.
*
* @param list - RLE list that contains all the chars in the picture.
* @param out_stream - FILE* file to which we'll write the compressed picture.
* @return
* 	RLE_LIST_NULL_ARGUMENT - if one of the params are NULL.
*   RLE_LIST_SUCCESS - in case of success.
*/
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);

#endif //HW1_ASCII_ART_TOOL_H