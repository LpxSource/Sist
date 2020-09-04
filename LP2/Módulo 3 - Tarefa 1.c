
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cliente{
	char nome[50],endereco[50];
	int telefone;
	float salario1,salario2,salario3,rendatrime,credito;
}*c;

int main(){
	setlocale(LC_ALL,"Portuguese");
	int j=0,i,quant=0,b=0,a=0;
	char resp[] = "s";
	c = (struct c *) malloc(j*sizeof(struct cliente));
	while(strcmp(resp,"s")==0){
		printf("Digite seu nome:\n");
		setbuf(stdin,NULL);
		fgets(c[j].nome,50,stdin);
		printf("Digite seu endereco:\n");
		setbuf(stdin,NULL);
		fgets(c[j].endereco,50,stdin);
		printf("Informe seus tres ultimos salarios\n");
		printf("1° Salario:\n");
		scanf("%f",&c[j].salario1);
		printf("2° Salario:\n");
		scanf("%f",&c[j].salario2);
		printf("3° Salario:\n");
		scanf("%f",&c[j].salario3);
		printf("Deseja fazer um novo cadastro? [s/n]");
		setbuf(stdin,NULL);
		scanf("%[^\n]s",&resp);
		if(resp=="s")
		{
			quant ++;
			c = realloc(c,quant*sizeof(c));
			j++;
		};
		
	};
	for(b=0;b<j;b++){
		c[b].rendatrime=(c[b].salario1+c[b].salario2+c[b].salario3)/3;
		c[b].credito=(c[b].rendatrime*0.3);
		printf("Nome:%s\n",c[a].nome);
		printf("Endereco:%s\n",c[a].endereco);
		printf("Media Trimestral:%.2f\n",c[a].rendatrime);
		printf("Credito:%.2f",c[a].credito);
	}
    free(c);
    return 0;
}
