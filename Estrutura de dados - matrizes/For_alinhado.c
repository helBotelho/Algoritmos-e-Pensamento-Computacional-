#include <stdio.h>

int main(void) {
    int a, b, resultado = 0;
    
    printf("digite o primeiro numero: ");
    scanf("%d", &a);
    
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    
    for (int i = 0; i < a; i++) {
        for (int l = 0; l < b; l++) {
            resultado += 1;
        }
    }
    
    printf("O resultado da sua multiplicacao e: %d\n", resultado);

    return 0;
}
