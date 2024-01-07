//
// Created by Jan Skácel on 06.01.2024.
//

#ifndef PART2_GENSET_H
#define PART2_GENSET_H


#include <stdio.h>
#include <stdbool.h>

typedef enum {
    DATATYPE_CHAR,
    DATATYPE_INT,
    DATATYPE_FLOAT,
    DATATYPE_DOUBLE,
    DATATYPE_STRING,
    DATATYPE_CUSTOM
} DataType;

typedef struct {
    int capacity;
    int size;
    void** data;
    DataType type;
} GenericSet_t;

GenericSet_t initSet(int capacity, DataType type);
void deInit(GenericSet_t* set);
bool contains(GenericSet_t set, void* element, bool (*compareFunc)(void*, void*));
bool compareChar(void* item1, void* item2);
bool compareInt(void* item1, void* item2);
bool compareFloat(void* item1, void* item2);
bool compareDouble(void* item1, void* item2);
bool compareString(void* item1, void* item2);
void addToSet(GenericSet_t* set, void* element, bool (*compareFunc)(void*, void*));
void displaySet(GenericSet_t set, void (*displayFunc)(void*));
void displayChar(void* data);
void displayInt(void* data);
void displayFloat(void* data);
void displayDouble(void* data);
void displayString(void* data);
GenericSet_t unionSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*));
GenericSet_t intersectSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*));
GenericSet_t diffSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*));
int countSet(GenericSet_t set);
bool isSubsetSet(GenericSet_t set1, GenericSet_t set2, bool (*compareFunc)(void*, void*));
bool isEmptySet(GenericSet_t set);
void export(GenericSet_t set, const char* filename, void (*exportFunc)(void*, FILE*));
void exportChar(void* element, FILE* file);
void exportInt(void* element, FILE* file);
void exportFloat(void* element, FILE* file);
void exportDouble(void* element, FILE* file);
void exportString(void* element, FILE* file);

#endif //PART2_GENSET_H
