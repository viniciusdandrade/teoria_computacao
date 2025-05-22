#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define REPETICOES 30

bool subset_sum(int set[], int target, int n) {
    if (target == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > target)
        return subset_sum(set, target, n - 1);
    return subset_sum(set, target, n - 1) || subset_sum(set, target - set[n - 1], n - 1);
}

int calcular_soma(int set[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += set[i];
    }
    return soma;
}

void medir_execucao(double* media, double* desvio, int set[], int n, int target) {
    double tempos[REPETICOES];
    for (int i = 0; i < REPETICOES; i++) {
        clock_t inicio = clock();
        subset_sum(set, target, n);
        clock_t fim = clock();
        tempos[i] = (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    double soma = 0.0;
    for (int i = 0; i < REPETICOES; i++) soma += tempos[i];
    *media = soma / REPETICOES;

    double variancia = 0.0;
    for (int i = 0; i < REPETICOES; i++)
        variancia += pow(tempos[i] - *media, 2);
    *desvio = sqrt(variancia / REPETICOES);
}

int main() {
    double mean_p, std_p, mean_m, std_m, mean_g, std_g;

    int pequena[] = {1, 2, 3, 4, 5};
    int n_pequena = sizeof(pequena) / sizeof(pequena[0]);
    int alvo_pequena = calcular_soma(pequena, n_pequena) / 2;
    medir_execucao(&mean_p, &std_p, pequena, n_pequena, alvo_pequena);

    int media[15];
    for (int i = 0; i < 15; i++) media[i] = i + 1;
    int alvo_media = calcular_soma(media, 15) / 2;
    medir_execucao(&mean_m, &std_m, media, 15, alvo_media);

    int grande[33];
    for (int i = 0; i < 33; i++) grande[i] = i + 1;
    int alvo_grande = calcular_soma(grande, 33) / 2;
    medir_execucao(&mean_g, &std_g, grande, 33, alvo_grande);

    FILE* arquivo = fopen("results_c.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "mean-p=%.6f\n", mean_p);
        fprintf(arquivo, "mean-m=%.6f\n", mean_m);
        fprintf(arquivo, "mean-g=%.6f\n", mean_g);
        fprintf(arquivo, "std-p=%.6f\n", std_p);
        fprintf(arquivo, "std-m=%.6f\n", std_m);
        fprintf(arquivo, "std-g=%.6f\n", std_g);
        fclose(arquivo);
        printf("Resultados salvos em data/results_c.txt\n");
    } else {
        printf("Erro ao abrir o arquivo 'data/results_c.txt' para escrita.\n");
    }

    return 0;
}
