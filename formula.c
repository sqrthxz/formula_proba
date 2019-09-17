#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fatorial(int n){
    double fat;
    for(fat = 1; n > 1; n = n - 1){
        fat = fat * n;
    }
    return fat;
}

double combinacao(int n, int x){
    int C = fatorial(n) / ((fatorial(n-x) * fatorial(x)));
    return C;
}

double simples(){
    //variaveis
    int n,x;
    float p;
    printf("Digite o numero de observacoes (n): ");
    scanf("%d",&n);
    printf("Digite o numero de sucessos (x): ");
    scanf("%d", &x);
    printf("Digite o numero de probabilidade de sucesso absoluto (p): ");
    scanf("%f", &p);
    float q = 1 - p;
    //conta principal
    double resultado = (combinacao(n,x) * pow(p,x) * pow(q,n-x)) * 100;
    //resultado
    printf("Resultado: %.2f %% ", resultado);
}

double acumulado(){
    //variaveis
    int n,x;
    float p;
    printf("Digite o numero de observacoes (n): ");
    scanf("%d",&n);
    printf("Digite o numero de sucessos (x): ");
    scanf("%d", &x);
    printf("Digite o numero de probabilidade de sucesso absoluto (p): ");
    scanf("%f", &p);
    float q = 1 - p;


    for
}


int main(){

}



































