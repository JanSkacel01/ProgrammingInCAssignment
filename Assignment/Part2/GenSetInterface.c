#include <stdio.h>
#include <string.h>

#include "GenSetLibrary/GenSet.h"

// Define the Movies struct
typedef struct {
    char name[100];
    double rating;
} Movies;

void testIntSet();
void testStringSet();
void testFloatSet();
void testDoubleSet();
void testCharSet();
void testMovieSet();
void exportMovie(void* element, FILE* file);
void displayMovies(void* item);
bool compareMovies(void* item1, void* item2);

int main() {

    testIntSet();

    printf("---------------------------------------\n");

    testStringSet();

    printf("---------------------------------------\n");

    testFloatSet();

    printf("---------------------------------------\n");

    testDoubleSet();

    printf("---------------------------------------\n");

    testCharSet();

    printf("---------------------------------------\n");

    testMovieSet();

    return 0;
}


void testIntSet() {
    // Create sets
    GenericSet_t set1 = initSet(5, DATATYPE_INT);
    GenericSet_t set2 = initSet(5, DATATYPE_INT);
    GenericSet_t set3 = initSet(5, DATATYPE_INT);
    GenericSet_t set4 = initSet(5, DATATYPE_INT);

    // Add elements to set1
    int element1 = 1;
    addToSet(&set1, &element1, compareInt);
    int element2 = 2;
    addToSet(&set1, &element2, compareInt);
    int element3 = 3;
    addToSet(&set1, &element3, compareInt);

    // Call the `export()` function with the relative file path
    export(set1, "../TextFiles/ints.txt", exportInt);

    // Add elements to set2
    int element4 = 2;
    addToSet(&set2, &element4, compareInt);
    int element5 = 3;
    addToSet(&set2, &element5, compareInt);
    int element6 = 4;
    addToSet(&set2, &element6, compareInt);

    // Add elements to set3
    int element7 = 1;
    addToSet(&set3, &element7, compareInt);
    int element8 = 2;
    addToSet(&set3, &element8, compareInt);

    // Display sets
    printf("Set 1: ");
    displaySet(set1, displayInt);
    printf("Set 2: ");
    displaySet(set2, displayInt);
    printf("Set 3: ");
    displaySet(set3, displayInt);
    printf("Set 4: ");
    displaySet(set4, displayInt);

    // Check if set3 is a subset of set1
    bool isSubset = isSubsetSet(set3, set1, compareInt);
    if (isSubset) {
        printf("Set 3 is a subset of Set 1\n");
    } else {
        printf("Set 3 is not a subset of Set 1\n");
    }

    // Check if set4 is empty
    bool empty = isEmptySet(set4);
    if (empty) {
        printf("Set 4 is empty\n");
    } else {
        printf("Set 4 is not empty\n");
    }

    // Perform union of set1 and set2
    GenericSet_t unionResult = unionSet(set1, set2, compareInt);
    printf("Union of Set 1 and Set 2: ");
    displaySet(unionResult, displayInt);

    // Perform intersection of set1 and set2
    GenericSet_t intersectResult = intersectSet(set1, set2, compareInt);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(intersectResult, displayInt);

    // Perform difference of set1 and set2
    GenericSet_t difference = diffSet(set1, set2, compareInt);
    printf("Result of Set 1 - Set 2: ");
    displaySet(difference, displayInt);

    // Count elements in set1
    int count = countSet(set1);
    printf("Number of elements in Set 1: %d\n", count);

    // Deallocate memory
    deInit(&set1);
    deInit(&set2);
    deInit(&set3);
    deInit(&set4);
    deInit(&unionResult);
    deInit(&intersectResult);
    deInit(&difference);
}

void testCharSet() {
    // Create sets
    GenericSet_t set1 = initSet(5, DATATYPE_CHAR);
    GenericSet_t set2 = initSet(5, DATATYPE_CHAR);
    GenericSet_t set3 = initSet(5, DATATYPE_CHAR);
    GenericSet_t set4 = initSet(5, DATATYPE_CHAR);

    // Add elements to set1
    char element1 = 'a';
    addToSet(&set1, &element1, compareChar);
    char element2 = 'b';
    addToSet(&set1, &element2, compareChar);
    char element3 = 'c';
    addToSet(&set1, &element3, compareChar);

    // Add elements to set2
    char element4 = 'b';
    addToSet(&set2, &element4, compareChar);
    char element5 = 'c';
    addToSet(&set2, &element5, compareChar);
    char element6 = 'd';
    addToSet(&set2, &element6, compareChar);

    // Call the `export()` function with the relative file path
    export(set1, "../TextFiles/chars.txt", exportChar);

    // Add elements to set3
    char element7 = 'a';
    addToSet(&set3, &element7, compareChar);
    char element8 = 'b';
    addToSet(&set3, &element8, compareChar);

    // Display sets
    printf("Set 1: ");
    displaySet(set1, displayChar);
    printf("Set 2: ");
    displaySet(set2, displayChar);
    printf("Set 3: ");
    displaySet(set3, displayChar);
    printf("Set 4: ");
    displaySet(set4, displayChar);

    // Check if set2 is a subset of set1
    bool isSubset = isSubsetSet(set2, set1, compareChar);
    if (isSubset) {
        printf("Set 2 is a subset of Set 1\n");
    } else {
        printf("Set 2 is not a subset of Set 1\n");
    }

    // Check if set1 is empty
    bool empty = isEmptySet(set1);
    if (empty) {
        printf("Set 1 is empty\n");
    } else {
        printf("Set 1 is not empty\n");
    }

    // Perform union of set1 and set3
    GenericSet_t unionResult = unionSet(set1, set3, compareChar);
    printf("Union of Set 1 and Set 3: ");
    displaySet(unionResult, displayChar);

    // Perform intersection of set1 and set3
    GenericSet_t intersectResult = intersectSet(set1, set3, compareChar);
    printf("Intersection of Set 1 and Set 3: ");
    displaySet(intersectResult, displayChar);

    // Perform difference of set2 and set1
    GenericSet_t difference = diffSet(set2, set1, compareChar);
    printf("Result of Set 2 - Set 1: ");
    displaySet(difference, displayChar);

    // Count elements in set1
    int count = countSet(set1);
    printf("Number of elements in Set 1: %d\n", count);

    // Deallocate memory
    deInit(&set1);
    deInit(&set2);
    deInit(&set3);
    deInit(&set4);
    deInit(&unionResult);
    deInit(&intersectResult);
    deInit(&difference);
}

void testDoubleSet() {
    // Create sets
    GenericSet_t set1 = initSet(5, DATATYPE_DOUBLE);
    GenericSet_t set2 = initSet(5, DATATYPE_DOUBLE);
    GenericSet_t set3 = initSet(5, DATATYPE_DOUBLE);
    GenericSet_t set4 = initSet(5, DATATYPE_DOUBLE);

    // Add elements to set1
    double element1 = 1.1;
    addToSet(&set1, &element1, compareDouble);
    double element2 = 2.2;
    addToSet(&set1, &element2, compareDouble);
    double element3 = 3.3;
    addToSet(&set1, &element3, compareDouble);

    // Add elements to set2
    double element4 = 2.2;
    addToSet(&set2, &element4, compareDouble);
    double element5 = 3.3;
    addToSet(&set2, &element5, compareDouble);
    double element6 = 4.4;
    addToSet(&set2, &element6, compareDouble);

    // Call the `export()` function with the relative file path
    export(set1, "../TextFiles/doubles.txt", exportDouble);

    // Add elements to set3
    double element7 = 1.1;
    addToSet(&set3, &element7, compareDouble);
    double element8 = 2.2;
    addToSet(&set3, &element8, compareDouble);

    // Display sets
    printf("Set 1: ");
    displaySet(set1, displayDouble);
    printf("Set 2: ");
    displaySet(set2, displayDouble);
    printf("Set 3: ");
    displaySet(set3, displayDouble);
    printf("Set 4: ");
    displaySet(set4, displayDouble);

    // Check if set3 is a subset of set1
    bool isSubset = isSubsetSet(set3, set1, compareDouble);
    if (isSubset) {
        printf("Set 3 is a subset of Set 1\n");
    } else {
        printf("Set 3 is not a subset of Set 1\n");
    }

    // Check if set4 is empty
    bool empty = isEmptySet(set4);
    if (empty) {
        printf("Set 4 is empty\n");
    } else {
        printf("Set 4 is not empty\n");
    }

    // Perform union of set1 and set2
    GenericSet_t unionResult = unionSet(set1, set2, compareDouble);
    printf("Union of Set 1 and Set 2: ");
    displaySet(unionResult, displayDouble);

    // Perform intersection of set1 and set2
    GenericSet_t intersectResult = intersectSet(set1, set2, compareDouble);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(intersectResult, displayDouble);

    // Perform difference of set1 and set2
    GenericSet_t difference = diffSet(set1, set2, compareDouble);
    printf("Result of Set 1 - Set 2: ");
    displaySet(difference, displayDouble);

    // Count elements in set1
    int count = countSet(set1);
    printf("Number of elements in Set 1: %d\n", count);

    // Deallocate memory
    deInit(&set1);
    deInit(&set2);
    deInit(&set3);
    deInit(&set4);
    deInit(&unionResult);
    deInit(&intersectResult);
    deInit(&difference);
}

void testStringSet(){
    // Create sets
    GenericSet_t set1 = initSet(5, DATATYPE_STRING);
    GenericSet_t set2 = initSet(5, DATATYPE_STRING);
    GenericSet_t set3 = initSet(5, DATATYPE_STRING);
    GenericSet_t set4 = initSet(5, DATATYPE_STRING);

    // Add elements to set1
    char* element1 = "apple";
    addToSet(&set1, element1, compareString);
    char* element2 = "banana";
    addToSet(&set1, element2, compareString);
    char* element3 = "orange";
    addToSet(&set1, element3, compareString);

    // Call the `export()` function with the relative file path
    export(set1, "../TextFiles/strings.txt", exportString);

    // Add elements to set2
    char* element4 = "banana";
    addToSet(&set2, element4, compareString);
    char* element5 = "orange";
    addToSet(&set2, element5, compareString);
    char* element6 = "kiwi";
    addToSet(&set2, element6, compareString);

    // Add elements to set3
    char* element7 = "apple";
    addToSet(&set3, element7, compareString);
    char* element8 = "banana";
    addToSet(&set3, element8, compareString);

    // Display sets
    printf("Set 1: ");
    displaySet(set1, displayString);
    printf("Set 2: ");
    displaySet(set2, displayString);
    printf("Set 3: ");
    displaySet(set3, displayString);
    printf("Set 4: ");
    displaySet(set4, displayString);

    // Check if set3 is a subset of set1
    bool isSubset = isSubsetSet(set3, set1, compareString);
    if (isSubset) {
        printf("Set 3 is a subset of Set 1\n");
    } else {
        printf("Set 3 is not a subset of Set 1\n");
    }

    // Check if set4 is empty
    bool empty = isEmptySet(set4);
    if (empty) {
        printf("Set 4 is empty\n");
    } else {
        printf("Set 4 is not empty\n");
    }

    // Perform union of set1 and set2
    GenericSet_t unionResult = unionSet(set1, set2, compareString);
    printf("Union of Set 1 and Set 2: ");
    displaySet(unionResult, displayString);

    // Perform intersection of set1 and set2
    GenericSet_t intersectResult = intersectSet(set1, set2, compareString);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(intersectResult, displayString);

    // Perform difference of set3 and set1
    GenericSet_t difference = diffSet(set3, set1, compareString);
    printf("Result of Set 3 - Set 1: ");
    displaySet(difference, displayString);

    // Count elements in set1
    int count = countSet(set1);
    printf("Number of elements in Set 1: %d\n", count);

    // Deallocate memory
    deInit(&set1);
    deInit(&set2);
    deInit(&set3);
    deInit(&set4);
    deInit(&unionResult);
    deInit(&intersectResult);
    deInit(&difference);
}

void testFloatSet() {
    // Create sets
    GenericSet_t set1 = initSet(5, DATATYPE_FLOAT);
    GenericSet_t set2 = initSet(5, DATATYPE_FLOAT);
    GenericSet_t set3 = initSet(5, DATATYPE_FLOAT);
    GenericSet_t set4 = initSet(5, DATATYPE_FLOAT);

    // Add elements to set1
    float element1 = (float)1.1;
    addToSet(&set1, &element1, compareFloat);
    float element2 = (float)2.2;
    addToSet(&set1, &element2, compareFloat);
    float element3 = (float)3.3;
    addToSet(&set1, &element3, compareFloat);

    // Call the `export()` function with the relative file path
    export(set1, "../TextFiles/floats.txt", exportFloat);

    // Add elements to set2
    float element4 = (float)2.2;
    addToSet(&set2, &element4, compareFloat);
    float element5 = (float)3.3;
    addToSet(&set2, &element5, compareFloat);
    float element6 = (float)4.4;
    addToSet(&set2, &element6, compareFloat);

    // Add elements to set3
    float element7 = (float)1.1;
    addToSet(&set3, &element7, compareFloat);
    float element8 = (float)2.2;
    addToSet(&set3, &element8, compareFloat);

    // Display sets
    printf("Set 1: ");
    displaySet(set1, displayFloat);
    printf("Set 2: ");
    displaySet(set2, displayFloat);
    printf("Set 3: ");
    displaySet(set3, displayFloat);
    printf("Set 4: ");
    displaySet(set4, displayFloat);

    // Check if set3 is a subset of set4
    bool isSubset = isSubsetSet(set3, set4, compareFloat);
    if (isSubset) {
        printf("Set 3 is a subset of Set 4\n");
    } else {
        printf("Set 3 is not a subset of Set 4\n");
    }

    // Check if set2 is empty
    bool empty = isEmptySet(set2);
    if (empty) {
        printf("Set 2 is empty\n");
    } else {
        printf("Set 2 is not empty\n");
    }

    // Perform union of set1 and set4
    GenericSet_t unionResult = unionSet(set1, set4, compareFloat);
    printf("Union of Set 1 and Set 4: ");
    displaySet(unionResult, displayFloat);

    // Perform intersection of set1 and set4
    GenericSet_t intersectResult = intersectSet(set1, set4, compareFloat);
    printf("Intersection of Set 1 and Set 4: ");
    displaySet(intersectResult, displayFloat);

    // Perform difference of set1 and set2
    GenericSet_t difference = diffSet(set1, set2, compareFloat);
    printf("Result of Set 1 - Set 2: ");
    displaySet(difference, displayFloat);

    // Count elements in set4
    int count = countSet(set4);
    printf("Number of elements in Set 4: %d\n", count);

    // Deallocate memory
    deInit(&set1);
    deInit(&set2);
    deInit(&set3);
    deInit(&set4);
    deInit(&unionResult);
    deInit(&intersectResult);
    deInit(&difference);
}

void exportMovie(void* element, FILE* file) {
    Movies* movie = (Movies*)element;
    fprintf(file, "Name: %s\nRating: %lf\n\n", movie->name, movie->rating);
}

// Custom display function for the Movies struct
void displayMovies(void* item) {
    Movies* movie = (Movies*) item;
    printf("Movie: %s, Rating: %.1f\n", movie->name, movie->rating);
}

bool compareMovies(void* item1, void* item2) {
    Movies* movie1 = (Movies*)item1;
    Movies* movie2 = (Movies*)item2;
    return (movie1->rating == movie2->rating && strcmp(movie1->name, movie2->name) == 0);
}

void testMovieSet() {
    // Create sets
    GenericSet_t set1 = initSet(5, DATATYPE_CUSTOM);
    GenericSet_t set2 = initSet(5, DATATYPE_CUSTOM);
    GenericSet_t set3 = initSet(5, DATATYPE_CUSTOM);
    GenericSet_t set4 = initSet(5, DATATYPE_CUSTOM);

    // Add elements to set1
    Movies movie1 = {"Movie 1", 7.5};
    addToSet(&set1, &movie1, compareMovies);
    Movies movie2 = {"Movie 2", 8.2};
    addToSet(&set1, &movie2, compareMovies);
    Movies movie3 = {"Movie 3", 6.9};
    addToSet(&set1, &movie3, compareMovies);

    // Call the `export()` function with the relative file path
    export(set1, "../TextFiles/movies.txt", exportMovie);

    // Add elements to set2
    Movies movie4 = {"Movie 2", 8.2};
    addToSet(&set2, &movie4, compareMovies);
    Movies movie5 = {"Movie 3", 6.9};
    addToSet(&set2, &movie5, compareMovies);
    Movies movie6 = {"Movie 4", 7.8};
    addToSet(&set2, &movie6, compareMovies);

    // Add elements to set3
    Movies movie7 = {"Movie 1", 7.5};
    addToSet(&set3, &movie7, compareMovies);
    Movies movie8 = {"Movie 2", 8.2};
    addToSet(&set3, &movie8, compareMovies);

    // Display sets
    printf("Set 1:\n");
    displaySet(set1, displayMovies);
    printf("Set 2:\n");
    displaySet(set2, displayMovies);
    printf("Set 3:\n");
    displaySet(set3, displayMovies);
    printf("Set 4:\n");
    displaySet(set4, displayMovies);

    // Check if set3 is a subset of set1
    bool isSubset = isSubsetSet(set3, set1, compareMovies);
    if (isSubset) {
        printf("Set 3 is a subset of Set 1\n");
    } else {
        printf("Set 3 is not a subset of Set 1\n");
    }

    // Check if set4 is empty
    bool empty = isEmptySet(set4);
    if (empty) {
        printf("Set 4 is empty\n");
    } else {
        printf("Set 4 is not empty\n");
    }

    // Perform union of set1 and set2
    GenericSet_t unionResult = unionSet(set1, set2, compareMovies);
    printf("Union of Set 1 and Set 2:\n");
    displaySet(unionResult, displayMovies);

    // Perform intersection of set1 and set2
    GenericSet_t intersectResult = intersectSet(set1, set2, compareMovies);
    printf("Intersection of Set 1 and Set 2:\n");
    displaySet(intersectResult, displayMovies);

    // Perform difference of set1 and set2
    GenericSet_t difference = diffSet(set1, set2, compareMovies);
    printf("Result of Set 1 - Set 2:\n");
    displaySet(difference, displayMovies);

    // Count elements in set1
    int count = countSet(set1);
    printf("Number of elements in Set 1: %d\n", count);

    // Deallocate memory
    deInit(&set1);
    deInit(&set2);
    deInit(&set3);
    deInit(&set4);
    deInit(&unionResult);
    deInit(&intersectResult);
    deInit(&difference);
}

