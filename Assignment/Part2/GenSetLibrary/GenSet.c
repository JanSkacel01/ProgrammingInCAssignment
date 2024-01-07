//
// Created by Jan Skácel on 05.01.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "GenSet.h"

GenericSet_t initSet(int capacity, DataType type) {
    GenericSet_t set;
    set.capacity = capacity;
    set.size = 0;
    set.data = malloc(capacity * sizeof(void*));
    set.type = type;
    return set;
}



void deInit(GenericSet_t* set) {
    free(set->data);
    set->data = NULL;
    set->size = 0;
    set->capacity = 0;
    set->type = 0;
}

bool contains(GenericSet_t set, void* element, bool (*compareFunc)(void*, void*)) {
    for (int i = 0; i < set.size; i++) {
        if (compareFunc(set.data[i], element)) {
            return true;  // Element found
        }
    }
    return false;  // Element not found
}

bool compareChar(void* item1, void* item2) {
    char* char1 = (char*)item1;
    char* char2 = (char*)item2;
    return (*char1 == *char2);
}

bool compareInt(void* item1, void* item2) {
    int* int1 = (int*)item1;
    int* int2 = (int*)item2;
    return (*int1 == *int2);
}

bool compareFloat(void* item1, void* item2) {
    float* float1 = (float*)item1;
    float* float2 = (float*)item2;
    return (*float1 == *float2);
}

bool compareDouble(void* item1, void* item2) {
    double* double1 = (double*)item1;
    double* double2 = (double*)item2;
    return (*double1 == *double2);
}

bool compareString(void* item1, void* item2) {
    char* string1 = (char*)item1;
    char* string2 = (char*)item2;
    return (strcmp(string1, string2) == 0);
}

void addToSet(GenericSet_t* set, void* element, bool (*compareFunc)(void*, void*)) {
    if (set->size >= set->capacity) {
        printf("Set is full, cannot add more elements\n");
        return;  // Set is full, do nothing
    }

    if (contains(*set, element, compareFunc)) {
        return;  // Element already exists, do nothing
    }

    // Add the new element to the set
    set->data[set->size] = element;
    set->size++;
}

void displaySet(GenericSet_t set, void (*displayFunc)(void*)) {
    for (int i = 0; i < set.size; i++) {
        if (displayFunc != NULL) {
            displayFunc(set.data[i]);
        }
    }
    printf("\n");
}

void displayChar(void* data) {
    char value = *((char*)data);
    printf("%c ", value);
}

void displayInt(void* data) {
    int value = *((int*)data);
    printf("%d ", value);
}

void displayFloat(void* data) {
    float value = *((float*)data);
    printf("%f ", value);
}

void displayDouble(void* data) {
    double value = *((double*)data);
    printf("%lf ", value);
}

void displayString(void* data) {
    char* value = (char*)data;
    printf("%s ", value);
}

GenericSet_t unionSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*)) {
    GenericSet_t result;
    if (set1.type != set2.type) {
        printf("Error: Sets have different data types\n");
        result = initSet(0, set1.type);  // Return an empty set of the same type as set1
        return result;
    }

    result = initSet(set1.size + set2.size, set1.type);

    for (int i = 0; i < set1.size; i++) {
        addToSet(&result, set1.data[i], compareFunc);
    }
    for (int i = 0; i < set2.size; i++) {
        addToSet(&result, set2.data[i], compareFunc);
    }

    return result;
}

GenericSet_t intersectSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*)) {
    GenericSet_t result;
    if (set1.type != set2.type) {
        printf("Error: Sets have different data types\n");
        result = initSet(0, set1.type);  // Return an empty set of the same type as set1
        return result;
    }

    result = initSet(set1.size, set1.type);

    for (int i = 0; i < set1.size; i++) {
        if (contains(set2, set1.data[i], compareFunc)) {
            addToSet(&result, set1.data[i], compareFunc);
        }
    }

    return result;
}

int countSet(GenericSet_t set) {
    return set.size;
}

GenericSet_t diffSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*)) {
    GenericSet_t result;
    if (set1.type != set2.type) {
        printf("Error: Sets have different data types\n");
        result = initSet(0, set1.type);  // Return an empty set of the same type as set1
        return result;
    }

    result = initSet(set1.size, set1.type);

    for (int i = 0; i < set1.size; i++) {
        if (!contains(set2, set1.data[i], compareFunc)) {
            addToSet(&result, set1.data[i], compareFunc);
        }
    }

    return result;
}

bool isSubsetSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*)) {
    if (set1.type != set2.type) {
        // Error: Sets have different data types
        return false;
    }

    if (set1.size > set2.size) {
        // set1 cannot be a subset if it has more elements than set2
        return false;
    }

    for (int i = 0; i < set1.size; i++) {
        if (!contains(set2, set1.data[i], compareFunc)) {
            return false;  // Element from set1 is not found in set2
        }
    }

    return true;  // All elements of set1 are found in set2
}

bool isEmptySet(GenericSet_t set) {
    return set.size == 0;
}

void export(GenericSet_t set, const char* filename, void (*exportFunc)(void*, FILE*)) {
    FILE* file = fopen(filename, "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < set.size; i++) {
        exportFunc(set.data[i], file);
    }

    fclose(file);
}

void exportChar(void* element, FILE* file) {
    char* ch = (char*)element;
    fprintf(file, "%c\n", *ch);
}

void exportInt(void* element, FILE* file) {
    int* num = (int*)element;
    fprintf(file, "%d\n", *num);
}

void exportFloat(void* element, FILE* file) {
    float* f = (float*)element;
    fprintf(file, "%f\n", *f);
}

void exportDouble(void* element, FILE* file) {
    double* d = (double*)element;
    fprintf(file, "%lf\n", *d);
}

void exportString(void* element, FILE* file) {
    char* str = (char*)element;
    fprintf(file, "%s\n", str);
}
