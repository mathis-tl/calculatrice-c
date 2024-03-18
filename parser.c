#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

static Token current_token;
static void next_token();
static float expression();
static float term();
static float factor();

void init_parser(const char *input) {
    init_lexer(input);
    next_token();
}

float parse_expression() {
    return expression();
}

static void next_token() {
    current_token = get_next_token();
}

static float expression() {
float result = term();

    while (current_token.type == TOKEN_PLUS || current_token.type == TOKEN_MINUS) {
        Token op = current_token;
        next_token();
        if (op.type == TOKEN_PLUS) {
            result += term();
        } else if (op.type == TOKEN_MINUS) {
            result -= term();
        }
     
    }
    
    return result;
}

static float term() {
    float result = factor();
    while (current_token.type == TOKEN_MUL || current_token.type == TOKEN_DIV) {
        Token op = current_token;
        next_token(); // Passer à l'opérande suivant
        if (op.type == TOKEN_MUL) {
            result *= factor();
        } else if (op.type == TOKEN_DIV) {
            float divisor = factor();
            if (divisor != 0.0) {
                result /= divisor;
            } else {
                printf("Erreur : division par zéro.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return result;
}

static float factor() {
     float result = 0.0;
    if (current_token.type == TOKEN_INTEGER) {
        result = (float)current_token.value; // Convertit la valeur entière du token en float
        next_token(); // Avance au token suivant après avoir traité un nombre
    } else if (current_token.type == TOKEN_LPAREN) {
        next_token(); // Passer '('
        result = expression(); // Calcule ce qui est à l'intérieur des parenthèses
        if (current_token.type != TOKEN_RPAREN) {
            printf("Erreur : parenthèse fermante attendue.\n");
            exit(EXIT_FAILURE);
        }
        next_token(); // Passe ')'
    } else {
        printf("Erreur : nombre ou parenthèse ouvrante attendue.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
