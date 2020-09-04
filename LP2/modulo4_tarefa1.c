#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lista 
{
      int conteudo;
      char nome[60];
      float preco;
      struct lista *prox,*ant;
};

typedef struct lista Lista;

Lista *insere (int x,char *name, float value, Lista *l)
{
   Lista *novo,*aux_ins;
   aux_ins=l;
   novo = (Lista *)malloc (sizeof (Lista));
   novo->conteudo = x;
   strcpy(novo->nome,name);
   novo->preco=value;
   if(l==NULL)
   {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
   }
   else
   {
        novo->ant=aux_ins;
        novo->prox=aux_ins->prox;
        aux_ins->prox=novo;
   }   
   return l;
}

void imprime (Lista *li) 
{
    Lista *aux_imp1=li,*aux_imp2,*aux_imp3;
    int i,op_imp;
    printf("informe a ordem (1 para inicio-> fim; 2 para fim->inicio):");
    scanf("%d",&op_imp);
    if(op_imp == 1)
    {
        printf("============ INICIO ===========\n");   
        for (aux_imp1 = li; aux_imp1 != NULL; aux_imp1 = aux_imp1->prox){
            printf("Codigo: %d\n", aux_imp1->conteudo);
            printf("Nome: %s",aux_imp1->nome);
            printf("Valor: %.2f\n",aux_imp1->preco);
            printf("================================\n");
        }
    }
    else
    {
        for(aux_imp1=li;aux_imp1->prox != NULL;aux_imp1=aux_imp1->prox){
            if(aux_imp1->prox==NULL){
                //aux_imp2 = aux_imp1;
            }
        }
        printf("============ FIM ============\n");
        for(aux_imp1; aux_imp1 != NULL;aux_imp1 = aux_imp1->ant){
            printf("Codigo: %d\n ",aux_imp1->conteudo);
            printf("Nome: %s",aux_imp1->nome);
            printf("Valor: %.2f\n",aux_imp1->preco);
            printf("================================\n"); 
        }
    }        
}

Lista *consulta(int y, Lista *lis)
{
    Lista *aux_cons;
    for(aux_cons = lis; aux_cons != NULL; aux_cons = aux_cons->prox)   
        if(y == aux_cons->conteudo){
            break;
        }
    return aux_cons;
}

Lista *remover(int z, Lista *listt)//Parei aqui
{
    Lista *aux_rem,*atual;
    aux_rem = NULL;
    atual = listt;
    while (atual->prox != NULL && atual->conteudo != z) 
        /* percorre a lista e para se encontra o elemento ou se chega ao fim */
        atual = atual->prox;
    if (atual->conteudo !=z)
        /* não encontrou: retorna lista original */        
        return listt;
    else 
        if ((atual->ant == NULL)&&(atual->prox != NULL))
        {   /* retira elemento do inicio */
            aux_rem=atual->prox;        
            aux_rem->ant=NULL;
            free(atual);
            return aux_rem;
        }
        else
            if(atual->prox != NULL) 
            {
                /* retira elemento do meio da lista */
                aux_rem = atual->ant;
                aux_rem->prox=atual->prox;
                aux_rem = atual->prox; //inserido hoje
                aux_rem->ant = atual->ant; //inserido hoje
                free(atual);
                return listt;
            }
            else
                if((atual->prox == NULL)&&(atual->ant != NULL))
                {
                    /* retira elemento do final da lista */        
                    aux_rem = atual->ant;
                    aux_rem->prox = NULL;
                    free(atual);
                    return listt;
                }
                else
                if((atual->ant == NULL)&&(atual->prox == NULL))
                {
                    /* retira o último elemento da lista */        
                    aux_rem=NULL;
                    free(atual);
                    return aux_rem;
                }
}  

void libera (Lista* listtt)
{
    Lista* r = listtt;
    while (r != NULL) 
    {
        Lista* s = r->prox; /* guarda referência para o próximo elemento*/
        free(r); /* libera a memória apontada por r */
        r = s; /* faz r apontar para o próximo */
    }
}

int main(){
    Lista *list = NULL,*pont_cons=NULL,*pont_rem;    
    int opcao=1,valor,valor_cons,valor_rem;
    float value;
    char name[60];    
    while(opcao != 0)
    { 
        printf("------------------------------------------------\n");        
        printf("Informe a opcao:\n");
        printf("1 - inserir elemento na lista.\n");
        printf("2 - fazer uma consulta na lista.\n");
        printf("3 - remover um elemento da lista.\n");
        printf("4 - imprimir lista.\n");
        printf("0 - sair do programa.\n");
        printf("opcao:");        
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                printf("informe o codigo a ser inserido:");
                scanf("%d",&valor);   
                fflush(stdin);
                printf("Informe o nome do produto: ");
                fgets(name,59,stdin);
                printf("Informe o valor: ");
                scanf("%f",&value);           
                list=insere(valor,name,value,list);
            break;
            case 2:
                printf("informe o codigo a ser consultado:");
                scanf("%d",&valor_cons);
                pont_cons=consulta(valor_cons,list);
                if(pont_cons != NULL){
                    printf("================================\n");
                    printf("Codigo: %d\n",pont_cons->conteudo);
                    printf("Nome: %s",pont_cons->nome);
                    printf("Valor: %.2f\n",pont_cons->preco);
                }
                else
                    printf("Valor nao encontrado!\n");
            break;
            case 3:
                printf("informe o codigo a ser removido:");
                scanf("%d",&valor_rem);
                pont_rem=consulta(valor_rem,list);
                if(pont_rem != NULL)
                {        
                    list=remover(valor_rem,list);
                }
                else
                    printf("Valor nao encontrado!\n");
            break;
            case 4:      
                imprime(list);
            break;
            case 0:
            break;
            default:
                printf("opcao invalida! digite novamente!\n");
        }
                printf("------------------------------------------------\n");
     }
    libera(list);
    return 0;
}
