#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}