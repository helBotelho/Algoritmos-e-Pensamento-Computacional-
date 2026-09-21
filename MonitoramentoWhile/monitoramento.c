#include <stdio.h>
 
int main(void) {
 
    double limiteTemperatura;      
    double leituraAtual;           
    double somaLeituras = 0.0;     
    double maiorLeitura = 0.0;     
    double menorLeitura = 0.0;     
 
    int totalLeituras = 0;         
    int totalAcimaLimite = 0;      
    int sequenciaAtual = 0;        
    int limiteValido = 0;          
    int leituraOk;                 
 
    printf("############################################\n");
    printf("#   MONITORAMENTO DE TEMPERATURA - SENSOR   #\n");
    printf("############################################\n\n");
 
    while (!limiteValido) {
 
        printf("Informe o limite de temperatura (C): ");
 
        leituraOk = scanf("%lf", &limiteTemperatura);
 
        if (leituraOk == EOF) {
            printf("\nEntrada encerrada pelo usuario. Fim do programa.\n");
            return 0;
        }
 
        if (leituraOk != 1) {
 
            printf("-> Entrada invalida. Digite apenas numeros.\n\n");
 
            while (getchar() != '\n');
 
        } else if (limiteTemperatura < 0) {
 
            printf("-> O limite nao pode ser negativo. Tente novamente.\n\n");
 
        } else {
 
            limiteValido = 1;
        }
    }
 
    printf("\nLimite definido: %.2lf C\n", limiteTemperatura);
    printf("Iniciando leituras do sensor...\n");
    printf("(o monitoramento encerra automaticamente apos 3 leituras\n");
    printf(" CONSECUTIVAS acima do limite)\n");
 
    do {
 
        printf("\n--- Leitura #%d ---\n", totalLeituras + 1);
        printf("Digite a temperatura lida pelo sensor: ");
 
        leituraOk = scanf("%lf", &leituraAtual);
 
        if (leituraOk == EOF) {
            printf("\nEntrada encerrada pelo usuario. Finalizando monitoramento.\n");
            break;
        }
 
        if (leituraOk != 1) {
 
            printf("-> Leitura invalida! Digite apenas numeros.\n");
 
            while (getchar() != '\n'); 
 
            continue; 
        }
 
        totalLeituras++;
        somaLeituras += leituraAtual;
 
        if (totalLeituras == 1) {
            maiorLeitura = leituraAtual;
            menorLeitura = leituraAtual;
        } else {
            if (leituraAtual > maiorLeitura) {
                maiorLeitura = leituraAtual;
            }
            if (leituraAtual < menorLeitura) {
                menorLeitura = leituraAtual;
            }
        }
 
        if (leituraAtual > limiteTemperatura) {
 
            sequenciaAtual++;
            totalAcimaLimite++;
 
            printf("-> ALERTA: temperatura acima do limite! ");
            printf("(%d seguida(s))\n", sequenciaAtual);
 
        } else {
 
            sequenciaAtual = 0;
            printf("-> Temperatura dentro do limite.\n");
        }
 
    } while (sequenciaAtual < 3);
 
    printf("\n============================================\n");
    printf("               RELATORIO FINAL\n");
    printf("============================================\n");
    printf("Total de leituras validas : %d\n", totalLeituras);
 
    if (totalLeituras > 0) {
 
        printf("Maior temperatura         : %.2lf C\n", maiorLeitura);
        printf("Menor temperatura         : %.2lf C\n", menorLeitura);
        printf("Media das temperaturas    : %.2lf C\n",
               somaLeituras / totalLeituras);
        printf("Leituras acima do limite  : %d (%.2lf%%)\n",
               totalAcimaLimite,
               (double) totalAcimaLimite / totalLeituras * 100);
 
        if (sequenciaAtual >= 3) {
            printf("\nMotivo do encerramento: foram registradas 3 temperaturas\n");
            printf("consecutivas acima do limite definido.\n");
            printf("Sistema encerrado automaticamente.\n");
        }
 
    } else {
        printf("Nenhuma leitura valida foi registrada.\n");
    }
 
    return 0;
}
 
