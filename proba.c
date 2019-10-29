#include <stdio.h>
#include <math.h>

void Est_Med(float p, float n, float x, float s, float gc){
  float z;
  if (gc == 99 ){
    z = 2.58;
  }
  if (gc == 95 ){
    z = 1.96;
  }
  if (gc == 90 ){
    z = 1.65;
  }

  float Med_up, Med_down, error;
  if(p == 0){
    error = z*(s/sqrt(n));
  }
  else if(p/n > 0.05){
    error = z*(s/sqrt(n))*sqrt((p-n)/(p-1));
    }
  else{
    error = z*(s/sqrt(n));
  }
  Med_up = x+error;
  Med_down = x-error;

  printf("Estimativa de média pontual: %.2f\n", x);
  printf("Estimativa de média intervalar: %.2f a %.2f\n", Med_down, Med_up);
  printf("Erro de estimação: %.2f\n", error);
}


void Est_Prop(float N, float n, float x, float gc){

  float z;
  if (gc == 99 ){
    z = 2.58;
  }
  if (gc == 95 ){
    z = 1.96;
  }
  if (gc == 90 ){
    z = 1.65;
  }

  float p = x / n;

  float Prop_up, Prop_down, error;

  if(N/n > 0.05){
    error = z * sqrt((p*(1-p))/n) * sqrt((N-n)/(N-1));
  }
  else{
    error = z * sqrt((p*(1-p))/n);
  }

  Prop_up = (p + error);
  Prop_down = (p - error);

  printf("Estimativa de Proporção pontual: %.2f %%\n", p * 100);
  printf("Estimativa de Proporção intervalar: %.2f %% a %.2f %%\n", Prop_down * 100, Prop_up * 100);
  printf("Erro de estimação: %.2f %%\n", error * 100);
}


int main(){
  int menu;
  printf("Bem-vindo! O que desejas?\n1 - Estimativa de média;\n2 - Estimativa de proporção;\n");
  scanf("%d", &menu);
  if (menu == 1){
    float p,n,x,s,gc;

    printf("Digite o tamanho da população (se não souber, use 0): ");
    scanf("%f",&p);
    printf("Digite o tamanho da amostra: ");
    scanf("%f",&n);
    printf("Digite a média amostral: ");
    scanf("%f",&x);
    printf("Digite o desvio padrão amostral: ");
    scanf("%f",&s);
    printf("Digite o grau de confiança (%): ");
    scanf("%f",&gc);

    Est_Med(p,n,x,s,gc);
  }

  if (menu == 2){
    float N,n,x,gc;

    printf("Digite o tamanho da população: ");
    scanf("%f",&N);
    printf("Digite o tamanho da amostra: ");
    scanf("%f",&n);
    printf("Digite o número de itens na amostra: ");
    scanf("%f",&x);
    printf("Digite o grau de confiança (%): ");
    scanf("%f",&gc);

    Est_Prop(N,n,x,gc);
  }
}
