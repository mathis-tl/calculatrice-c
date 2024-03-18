#ifndef LEXER_H
#define LEXER_H


// Les types de tokens
typedef enum {
    TOKEN_INTEGER, // Un nombre entier
    TOKEN_FLOAT,   // Un nombre flottant
    TOKEN_PLUS,    // Le symbole +
    TOKEN_MINUS,   // Le symbole -
    TOKEN_MUL,     // Le symbole *
    TOKEN_DIV,     // Le symbole /
    TOKEN_LPAREN,  // Parenthèse ouvrante (
    TOKEN_RPAREN,  // Parenthèse fermante )
    TOKEN_EOF,     // Fin de l'entrée
    TOKEN_INVALID  // Token invalide (pour gérer les caractères inattendus)
} TokenType;

// Structure d'un token
typedef struct {
    TokenType type; // Le type de token
    double value;   // La valeur du token, utilisé pour TOKEN_INTEGER et TOKEN_FLOAT
} Token;

// Fonction pour initialiser l'analyseur lexical avec l'entrée fournie
void init_lexer(const char *input);

// Fonction pour obtenir le prochain token de l'entrée
Token get_next_token();

#endif // LEXER_H
