#include "stdlib.h"

void* newMem(int size) { return malloc(size); }

void deleteMem(void* ptr) { free(ptr); }