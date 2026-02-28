#include "lexer.h"
#include <string.h>
#include <stdbool.h>

#include <stdlib.h> 
#include <stdio.h> 
#include <ctype.h>

// Centralized Memory Management
void* reallocate(void* pointer, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, new_size);
    if (result == NULL) exit(1); // Handle out-of-memory
    return result;
}