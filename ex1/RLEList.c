#include "RLEList.h"
#include <stdlib.h>


struct RLEList_t {
    char charData;
    int charCounter;
    RLEList next;
};

/**
* countDigits: countes how many digits are in a given number

* @param number - the number which it's digits are needed to be counted
* @return
*   the number of digits
*/
static int countDigits(int charNumber);

/**
* updateListIfCharsEqual: gets two lists, and check if the first char at each list
* is identical. if so, it delets the first node from list2.
* note - we will use it on the same list, which mean list2 will be list1->next

* @param list1 - the RLEList to check
* @param list2 - the RLEList to check and delete the first node if needed
* @return
*   true - if the chars are identical, and the update had been made
    false - otherwise.
*/
static bool updateListIfCharsEqual(RLEList list1, RLEList list2);

/**
* createStringToExport: create and allocate an empty string in which we will compress the data.

* @param list - the RLEList which needed to be compressed
* @return
*   NULL - if the memory allocation failed.
    str - the empty string 
*/
static char* createStringToExport(RLEList list);

/**
* updateStringToExport: gets the empty string and the list, and update the values in a compressed way.

* @param str - the emptry string which needed to be updated
* @param list - the RLEList which needed to be compressed
*/
static void updateStringToExport(char* str, RLEList list);


static int countDigits(int number){
    int digitCounter = 0;
    while(number!=0){
        number /= 10;
        digitCounter++;
    }
    return digitCounter;
}

static bool updateListIfCharsEqual(RLEList list1, RLEList list2) {
    RLEList toDelete = NULL;
    if(list1->charData == list2->charData) {
        list1->charCounter += list2->charCounter;
        list1->next = list2->next;
        toDelete = list2;
        list2 = list2->next;
        free(toDelete); /*deleting the first node of list2*/
        return true;
    }
    return false;
}   

static char* createStringToExport(RLEList list){
    int digitCounter = 0;
    /*calculate and sum the number of digits of list->charCounter in each iteration*/
    if(RLEListSize(list)>0){
        while(list){
            digitCounter += countDigits(list->charCounter) + 2;/*adding one for the char itself and one for \n*/
            list = list->next;
        }
    }
    digitCounter++;
    char* str = malloc(sizeof(*str)*digitCounter); /*1 for the '\0' in the end of the string*/
    if(!str) {
        return NULL;
    }
    return str;
}

static void updateStringToExport(char* str, RLEList list) {
    int digitCounter = 0;
    int index = 0;
    int tempCharCounter = 0;

    if (RLEListSize(list) > 0) {
        while(list){
            str[index++] = list->charData;
            tempCharCounter = list->charCounter;
            digitCounter = countDigits(tempCharCounter);
            /*place each digit as a char in the right place indise stringFromRLEList*/
            for(int i = digitCounter - 1; i >= 0; i--) {
                str[index+i] = (char)(tempCharCounter % 10 + '0');
                tempCharCounter /= 10;
            } 
            index += digitCounter;
            digitCounter = 0;
            str[index++] = '\n'; /*after every node we placed in the string*/
            list = list->next;
        }
    }
    str[index] = '\0';
}


RLEList RLEListCreate() {
    RLEList newList = malloc(sizeof(*newList));
    if (!newList) {
        return NULL;
    }
    newList->charData = '\0';
    newList->charCounter = 0;
    newList->next = NULL;
    return newList;
}

int RLEListSize(RLEList list) {
    if(!list) {
        return -1;
    }
    int totalCharsNumber = 0;
    while(list) {
        totalCharsNumber += list->charCounter;
        list = list->next;
    }
    return totalCharsNumber;
}

RLEListResult RLEListAppend(RLEList list, char value) {
    if(!list || !value) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    /*in case the list is empty*/
    if(RLEListSize(list) == 0) {
        list->charData = value;
        list->charCounter++;
    }
    else {
        while(list->next != NULL) {
            list = list->next;
        }
        /*check if the last char is identical to value*/
        if (list->charData == value){
            list->charCounter++;
        }
        /*if not, append to the end*/
        else {
            RLEList newNode = RLEListCreate();
            if (!newNode) {
                return RLE_LIST_OUT_OF_MEMORY;
            }
            newNode->charData = value;
            newNode->charCounter++;
            list->next = newNode;
        }
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult RLEListRemove(RLEList list, int index) {
    if(!list) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    int listSize = RLEListSize(list);
    if (listSize == 0 || index < 0 || index > listSize-1) {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    int currentIndex = 0;
    RLEList newList = list;
    while (list){
        currentIndex+=list->charCounter;
        if (index<currentIndex){
            break;
        }
        newList = list;
        list = list->next;
    }

    list->charCounter--;
    /*in case we stopped in a char with no duplications*/
    if(list->charCounter == 0) {
        /*if the list contains more than single char*/
        if(listSize != 1) {
            /*remove first char*/
            if(index == 0) {
                list = list->next;
                newList->charData = list->charData;
                newList->charCounter = list->charCounter;
            }
            newList->next = list->next;
            free(list);
        }
        /*case of single char only*/
        else {
            list->charData = '\0';
        }
    }
    return RLE_LIST_SUCCESS;
}

char RLEListGet(RLEList list, int index, RLEListResult *result) {
    RLEListResult tempResult;
    char wantedChar = 0;

    if(!list) {
        tempResult = RLE_LIST_NULL_ARGUMENT;
    }
    else if(RLEListSize(list) == 0 || index < 0 || index > RLEListSize(list)-1) {
        tempResult = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    else {
        int currentIndex=0;
        while(list){
            currentIndex += list->charCounter;
            if(currentIndex > index) {
                break;
            }
            list = list->next;
        }
        wantedChar = list->charData;
        tempResult = RLE_LIST_SUCCESS;
    }
    // if result is different than NULL, update result's value
    if (result != NULL) {
        *result = tempResult;
    }
    return wantedChar;
}

char* RLEListExportToString(RLEList list, RLEListResult* result) {
    RLEListResult tempResult;
    char* stringFromRLEList = NULL;

    if(!list) {
        tempResult = RLE_LIST_NULL_ARGUMENT;
    }
    else {
        RLEList tempList = list;
        bool isListEmpty = (RLEListSize(list)>0) ? false : true;
 
        while(tempList) {
            if(!isListEmpty && tempList->next != NULL) {
                if(updateListIfCharsEqual(tempList, tempList->next)) {
                    continue;
                } 
            }
            tempList = tempList->next;
        }

        stringFromRLEList = createStringToExport(list);
        if(!stringFromRLEList) {
            if(result != NULL) {
                *result = RLE_LIST_OUT_OF_MEMORY;
            }
            return NULL;
        }

        updateStringToExport(stringFromRLEList, list);
        tempResult = RLE_LIST_SUCCESS;
    }

    if (result != NULL) {
        *result = tempResult;
    }
    return stringFromRLEList;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    if (!list || !map_function){
        return RLE_LIST_NULL_ARGUMENT;
    }
    while(list){
        list->charData = map_function(list->charData);
        list = list->next;
    }
    return RLE_LIST_SUCCESS;
}  

void RLEListDestroy(RLEList list) {
    while(list) {
        RLEList toDelete = list;
        list = list->next;
        free(toDelete);
    }
}

int main (){

    RLEList list = RLEListCreate();
    RLEListAppend(list, 'a');
    RLEListAppend(list, 'b');
    RLEListAppend(list, 'a');
    RLEListRemove(list,1);
    RLEListResult result;
    char* str = RLEListExportToString(list,&result);
    RLEListDestroy(list); 
}