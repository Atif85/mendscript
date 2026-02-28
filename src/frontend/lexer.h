#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

// TokenType Enum
typedef enum {
    // Single-character tokens
    TK_LPAREN,
    TK_RPAREN,
    TK_COLON,
    TK_COMMA,
    TK_PLUS,
    TK_MINUS,
    TK_STAR,
    TK_SLASH,
    TK_PERCENT,
    TK_UNDERSCORE,

    // One or two character tokens
    TK_EQUAL,
    TK_EQUAL_EQUAL,
    TK_PLUS_EQUAL,
    TK_MINUS_EQUAL,
    TK_BANG,
    TK_BANG_EQUAL,
    TK_LESS,
    TK_LESS_EQUAL,
    TK_GREATER,
    TK_GREATER_EQUAL,
    TK_ARROW,  // ->
    TK_PLUS_PLUS,
    TK_MINUS_MINUS,

    // Literals
    TK_IDENTIFIER,
    TK_STRING_LIT,
    TK_INTEGER_LIT,
    TK_FLOAT_LIT,

    // Keywords
    TK_BREAK,
    TK_CASE,
    TK_CLASS,
    TK_CONST,
    TK_DO,
    TK_ELSE,
    TK_ELIF,
    TK_ENUM,
    TK_CONTINUE,
    TK_FALSE,
    TK_FN,
    TK_FOR,
    TK_IN,
    TK_IF,
    TK_LET,
    TK_MATCH,
    TK_RETURN,
    TK_TRUE,
    TK_VAR,
    TK_WHILE,
    TK_AND,
    TK_OR,
    TK_NOT,

    // Control tokens
    TK_INDENT,
    TK_DEDENT,
    TK_NEWLINE,
    TK_EOF
} TokenType;

// --- Structs ---

// Token struct
typedef struct {
    TokenType type; // TokenType of the token
    const char *lexeme_start; // Pointer to the source string (to avoid malloc) 
    int lexeme_length; // Length of the lexeme starting from lexeme_start
    int line_num; // Line number in source
    int column_num; // Column on the line
} Token;

#endif // LEXER_H