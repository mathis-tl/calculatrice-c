#include "lexer.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


static const char *current_input;

void init_lexer(const char *input) {
    current_input = input;
}

Token get_next_token() {
    Token token;

    while (*current_input == ' ') current_input++;

    if (isdigit(*current_input) || *current_input == '.') { //Reconnaître les flottants
        char* end;
        token.value = strtod(current_input, &end);
        if (end != current_input) { // Un nombre a été lu
            token.type = (*current_input == '.') ? TOKEN_FLOAT : TOKEN_INTEGER;
            current_input = end;
        }
    } else {
        switch (*current_input) {
            case '+': token.type = TOKEN_PLUS; break;
            case '-': token.type = TOKEN_MINUS; break;
            case '*': token.type = TOKEN_MUL; break;
            case '/': token.type = TOKEN_DIV; break;
            case '(': token.type = TOKEN_LPAREN; break;
            case ')': token.type = TOKEN_RPAREN; break;
            case '\0': token.type = TOKEN_EOF; break;
            default: token.type = TOKEN_INVALID; break;
        }
        current_input++;
    }
    return token;
}
