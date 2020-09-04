#include <stdio.h>
#include <stdlib.h>
  void veridica_vetor(int *v, int *me, int *ma, float *med){
    for (int i=0;i<5;i++) {
      if (v[i]>*ma) {
        *ma=v[i];
      }
      if(v[i]<*me){
          *me=v[i];
        }
      *med+=v[i];
      }
      *med=*med/5;
}
int main(int argc, char const *argv[]) {
    int vet[5];
    int *v, men=99999, mai=0;
    float meds=0;
    for (int i=0;i<5;i++) {
      setbuf(stdin,NULL);
      printf("Informe o numero para a posicao %d: ",i+1);
      scanf("%d",&vet[i]);
    }
    veridica_vetor(vet,&men,&mai,&meds);
    printf("O maior eh: %d\n",mai);
    printf("O menor eh: %d\n",men);
    printf("A media eh: %.2f",meds);
  return 0;
}
