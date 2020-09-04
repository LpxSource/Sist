//colocar um loop while
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Aluno{
    char nome[60];
    int periodo;
    float rendimento;
    struct Aluno *prox,*ant;
};
typedef struct Aluno aluno;

aluno *cadastro(aluno *l){
    aluno *novo,*aux,*ord;
    int peri;
    char name[60];
    float rend;
    aux=l;
    novo=(aluno*)malloc(sizeof(aluno));
    if(novo==NULL){
        printf("Erro 1: memoria insuficiente.");
        return 0;
    }
    fflush(stdin);
    printf("Informe o nome do aluno: ");
    fgets(name,59,stdin);
    printf("Informe o periodo: ");
    scanf("%d",&peri);
    printf("Informe o rendimento: ");
    scanf("%f",&rend);
    strcpy(novo->nome,name);
    novo->periodo=peri;
    novo->rendimento=rend;
    if(aux==NULL){
        novo->prox=NULL;
        novo->ant=NULL;
    }else{
        for(aux;aux->prox!=NULL;aux=aux->prox){
            if(strcmp(novo->nome,aux->nome)==-1){
                novo->prox=aux;
                novo->ant=aux->ant;
                aux->ant=novo;
                if(novo->ant==NULL){
                    return novo;
                }else{
                    return l;
                }
                
            }
            
        }
        if(strcmp(novo->nome,aux->nome)==-1){
            novo->prox=aux;
            novo->ant=aux->ant;
            aux->ant=novo;
        }else{
            novo->prox=aux->prox;
            aux->prox=novo;
            novo->ant=aux;
            return l;
        }
        
        
    }

     /*else{
        for(l;l!=NULL;l=l->prox){
            printf("Rodou o for\n");
            if(strcmp(novo->nome,l->nome)==-1){
                novo->ant=l->ant;
                novo->prox=l;
                l->ant=novo;
                printf("Rodou o primeiro if do for que verifica os nomes\n");
            }else{
                novo->prox=l->prox;
                l->prox=novo;
                novo->ant=l;
            } 
                novo->prox=l->prox;
                l->prox=novo;
                novo->ant=l;*/      
return novo;}

aluno *pesquisa(aluno *l){
    aluno *pcons;
    char nomeConsul[60];
    printf("Informe o nome para pesquisa: \n");
    fgets(nomeConsul,59,stdin);
    for(pcons=l;pcons!=NULL;pcons=pcons->prox){
        if(strcmp(pcons->nome,nomeConsul)==0){
            printf("==============Pesquisa===============\n");
            printf("Nome: %s",pcons->nome);
            printf("Periodo: %d\n",pcons->periodo);
            printf("Rendimento: %.2f\n",pcons->rendimento);
            printf("=====================================\n");
        }
    }
    return pcons;
}

void visualiza(aluno *l){ 
   aluno *lista,*alunoAux=NULL;
   int def;
   printf("Exibir de A-Z(1) ou Z-A(2)? ");
   scanf("%d",&def);
   switch(def){
       case 1:
            printf("============Lista============\n");
            for(lista=l;lista!=NULL;lista=lista->prox){
                printf("Nome: %s",lista->nome);
                printf("Periodo: %d\n",lista->periodo);
                printf("Rendimento: %.2f\n",lista->rendimento);
                printf("===============================\n");
            }
        break;
        case 2:
            for(lista=l;lista->prox!=NULL;lista=lista->prox){
              alunoAux=lista->prox;
            }
            for(alunoAux;alunoAux!=NULL;alunoAux=alunoAux->ant){
                printf("Nome: %s",alunoAux->nome);
                printf("Periodo: %d\n",alunoAux->periodo);
                printf("Rendimento: %.2f\n",alunoAux->rendimento);
                printf("===============================\n");
            }
        break;
            
    }
}
void porPeriodo(aluno *l){
    int p;
    aluno *aux=NULL;
    printf("============Pesquisa por periodo============\n");
    printf("Informe o periodo desejado ou digite 0 para sair: ");
    scanf("%d",&p);
    while(p!=0){
        printf("======Lista do %d Periodo======\n",p);
        for(aux=l;aux!=NULL;aux=aux->prox){
            if(aux->periodo==p){
                printf("Nome: %s",aux->nome);
                printf("Periodo: %d\n",aux->periodo);
                printf("Rendimento: %.2f\n",aux->rendimento);
                printf("===============================\n");
                
            }
        }
        printf("Informe outro periodo para busca ou digite 0 para finalizar: ");
        scanf("%d",&p);
    }
}
void maiorRend(aluno *l){
    aluno *rendi=NULL,*maior=NULL;
    maior=(aluno *)malloc(sizeof(aluno));
    maior->rendimento=0;
    maior->prox=NULL;
    maior->ant=NULL;
    for(rendi=l;rendi!=NULL;rendi=rendi->prox){
        if(rendi->prox==NULL){
            maior=rendi;
        }else{
            if(rendi->rendimento>maior->rendimento){
                maior=rendi;
            }else{
                maior=rendi->prox;
            }
        }
        
    }
    printf("==========Maior rendimento academico==========\n");
    printf("Nome: %s\n",maior->nome);
    printf("Periodo: %d\n",maior->periodo);
    printf("Rendimento: %.2f\n",maior->rendimento);
    printf("==============================================\n");
}
aluno *removedor(char n[60],aluno *l){
    aluno *auxRem=NULL,*atual=l;
    while(atual->prox!=NULL && strcmp(atual->nome,n)!=0){
        atual=atual->prox;}
    if(strcmp(atual->nome,n)!=0){return l;}
    else{
        if((atual->ant==NULL)&&(atual->prox!=NULL)){
            auxRem=atual->prox;
            auxRem->prox=NULL;
            free(atual);
            return auxRem;
        }else{
            if((atual->prox!=NULL)){
                auxRem=atual->ant;
                auxRem->prox=atual->prox;
                auxRem=atual->prox;
                auxRem->ant=atual->ant;
                free(atual);
                return l;
            }else{
                if((atual->prox==NULL)&&(atual->ant!=NULL)){
                    auxRem=atual->ant;
                    auxRem->prox=NULL;
                    free(atual);
                    return l;
                }else{
                    if((atual->ant==NULL)&&(atual->prox==NULL)){
                        auxRem=NULL;
                        free(atual);
                        return auxRem;
                    }
                }
            }
        }
    }

}
int main(int argc, char const *argv[]){
    aluno *lista=NULL,*consult=NULL,*rendi=NULL,*maior=NULL;
    char nomeConsul[60],remov[60];
    int loop=1;
    int nav;
    while(loop==1){
        printf("==========MENU==========\n");
        printf("1.Cadastro de estudante. \n");
        printf("2.pesquisa.\n");
        printf("3.Visualizar dados de alunos cadastrados.\n");
        printf("4.Visualizar alunos por periodo.\n");
        printf("5.Aluno com maior rendimento.\n");
        printf("6.Excluir aluno.\n");
        scanf("%d",&nav);
        switch (nav){
        case 1:
            lista=cadastro(lista);
            break;
        case 2:
            fflush(stdin);
            consult=pesquisa(lista);
            break;
        case 3:
            visualiza(lista);
        break;
        case 4:
            porPeriodo(lista);
        break;
        case 5:
           maiorRend(lista);
        break;
        case 6:
        fflush(stdin);
        printf("==========Remocao academica===========\n");
        printf("Informe o nome do academico para remocao: ");
        fgets(remov,59,stdin);
        removedor(remov,lista);
        }
        printf("Deseja retornar ao menu? (1/0): ");
        scanf("%d",&loop);
    }
    free(lista);
    return 0;
}