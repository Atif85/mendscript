#include "lexer.h"
#include <string.h>
#include <stdbool.h>

#include <stdlib.h> 
#include <stdio.h> 
#include <ctype.h>

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

// --- Main scanning logic ---

// Internal helper to add a token and grow the dynamic array if needed.
static void lexer_emit_token(Lexer *lexer, TokenType type, const char* lexeme_start, int lexeme_len) {
    if (lexer->token_count >= lexer->token_capacity) {
        int old_capacity = lexer->token_capacity;

        lexer->token_capacity = GROW_CAPACITY(old_capacity);
        lexer->tokens = GROW_ARRAY(Token, lexer->tokens, old_capacity, lexer->token_capacity);
    }

    Token *token = &lexer->tokens[lexer->token_count];
    token->type = type;
    token->line_num = lexer->line;
    token->column_num = lexer->current - lexer->line_start + 1; 
    
    token->lexeme_start = lexeme_start;
    token->lexeme_len = lexeme_len;

    lexer->token_count++;
}

bool is_at_end(Lexer *lexer) {
    // TODO
}

void scan_token(Lexer *lexer) {
    // TODO
}

void lexer_scan_tokens(Lexer *lexer) {
    if (!is_at_end(lexer)) {
        lexer->start = lexer->current;
        scan_token(lexer);
    }

    // Close any remaining open blocks at the end of the file
    while (lexer->indent_depth > 1) {
        lexer_emit_token(lexer, TK_DEDENT, lexer->soruce + lexer->current, 0);
        lexer->indent_depth--;
    }

    // Add a final line if there isnt one
    if (lexer->token_count > 0 && lexer->tokens[lexer->token_count - 1].type != TK_NEWLINE) {
        lexer_emit_token(lexer, TK_NEWLINE, "\n", 1);
    }

    lexer_emit_token(lexer, TK_EOF, "", 0);
}