#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  int n,par=0,impar=0,*p;
  printf("Informe a quantidade de numeros a serem lidos: ");
  scanf("%d",&n);
  p=(int *) malloc(n*sizeof(int));
  for (int i=0;i<n;i++){
    printf("Informe o numero para a posicao %d: ",i+1);
    scanf("%d",&p[i]);
    if(p[i]%2==0) {
      par++;
    }else{
      impar++;
    }
  }
  printf("A quantidade de numeros pares eh: %d\n ",par);
  printf("Aquantidade de numeros impares eh %d ",impar);
return 0;}
