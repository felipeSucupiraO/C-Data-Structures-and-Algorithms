#include <stdio.h>
#define MAX_SIZE 100;

struct {
    int value;
    int key;
} typedef Cedule;

struct {
    Cedule list[MAX_SIZE];
    int length;
    int capacity;
} typedef List;

int getLength(List *list) {
    return 
}