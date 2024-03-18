#include "lexer.h"
#include "parser.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>


#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE];

    printf("Calculatrice simplifiée. Entrez 'q' pour quitter.\n");
    while (1) {
        printf("> ");
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            printf("Erreur de lecture de l'entrée.\n");
            continue;
        }

        // Enlève le saut de ligne à la fin de l'entrée si présent
        input[strcspn(input, "\n")] = 0;

        // Vérifie si l'utilisateur souhaite quitter
        if (strcmp(input, "q") == 0) {
            break;
        }

        // Initialise le lexer et le parser avec l'entrée de l'utilisateur
        init_parser(input);

        // Exécute le parseur et affiche le résultat
        float result = parse_expression();
        printf("%f\n", result);
    }

    return 0;
}
