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

// --- Create/Free Lexer ---

Lexer *create_lexer(const char *source) {
    if (source == NULL) return NULL;

    Lexer *lexer = malloc(sizeof(Lexer));
    if (lexer == NULL) return NULL;

    // Initializing feilds
    lexer->soruce = source;
    lexer->source_len = strlen(source);

    lexer->token_count = 0;
    lexer->token_capacity = 16;
    lexer->tokens = malloc(sizeof(Token) * lexer->token_capacity);
    if (lexer->tokens == NULL) {
        printf("Error creating lexer: couldnt allocate tokens array\n");
        free(lexer);
        return NULL;
    }

    lexer->start = 0;
    lexer->current = 0;
    lexer->line = 1;
    lexer->line_start = 0;

    lexer->indent_capacity = 16;
    lexer->indent_stack = malloc(sizeof(int) * lexer->indent_capacity);

    if (lexer->indent_stack == NULL) {
        free(lexer->tokens);
        free(lexer);
        return NULL;
    }

    lexer->indent_stack[0] = 0;
    lexer->indent_depth = 1;
    lexer->is_at_line_start = true;
    
    return lexer;
}

void free_lexer(Lexer *lexer) {
    if (lexer == NULL) return;

    free(lexer->tokens);
    free(lexer->indent_stack);

    free(lexer);
}