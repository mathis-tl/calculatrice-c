#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Initialise l'analyseur syntaxique
void init_parser(const char *input);

// Analyse l'expression et retourne le résultat
float parse_expression();

#endif
