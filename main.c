#include <stdio.h>
#include <stdlib.h>


struct lista
{
    int Info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *ListaInserir (Lista *L, int x)
{
    Lista *Novo = (Lista*) malloc(sizeof (Lista));
    Novo -> Info = x;
    Novo -> prox = L;
    return Novo;
}


//2.4
Lista *JuntarListas(Lista *L1, Lista *L2)
{
    Lista *p1;
    for(p1=L1; p1!=NULL; p1=p1->prox)
    {
        if(p1->prox==NULL)
            break;
    }
    p1->prox=L2;
    return L1;
}

//2.7
Lista *merge(Lista *L1, Lista *L2)
{
    Lista *Novo = NULL;
    Lista *temp = NULL;

    while (L1 != NULL || L2 != NULL)
    {
        if (L1 != NULL)
        {
            if (Novo == NULL)
            {
                Novo = temp = (Lista *)malloc(sizeof(Lista));
            }
            else
            {
                temp->prox = (Lista *)malloc(sizeof(Lista));
                temp = temp->prox;
            }
            temp->Info = L1->Info;
            temp->prox = NULL;
            L1 = L1->prox;
        }

        if (L2 != NULL)
        {
            if (Novo == NULL)
            {
                Novo = temp = (Lista *)malloc(sizeof(Lista));
            }
            else
            {
                temp->prox = (Lista *)malloc(sizeof(Lista));
                temp = temp->prox;
            }
            temp->Info = L2->Info;
            temp->prox = NULL;
            L2 = L2->prox;
        }
    }

    return Novo;
}

//2.9
int igual(Lista *L1, Lista *L2)
{
    Lista *p1, *p2;
    for(p1=L1, p2=L2; p1!=NULL && p2!=NULL; p1=p1->prox, p2=p2->prox)
    {
        if(p1->Info != p2->Info)
            return 0;
    }
    return p1 == p2;
}

//2.10
Lista *copia(Lista *L)
{
    Lista *p, *ant=NULL, *Novo;
    for(p=L; p!=NULL; p=p->prox)
    {
        if(p->prox==NULL);
        break;
        ant=p;
    }
    Novo=(Lista*) malloc(sizeof(Lista));
    Novo->Info=p->Info;
    Novo->prox=p;
    if(ant!=NULL)
        ant->prox=Novo;
    else
        Novo=L;
    return Novo;
}

void ListaImprimir(Lista *L1)
{
    for(Lista *p=L1; p!=NULL; p=p->prox)
    {
        printf("%d\n", p -> Info);
    }
}

int main()
{
    Lista *L1 = NULL;
    Lista *L2 = NULL;
    Lista *L3 = NULL;
    Lista *L4 = NULL;

    L1 = ListaInserir(L1, 20);
    L1 = ListaInserir(L1, 10);
    L2 = ListaInserir(L2, 40);
    L2 = ListaInserir(L2, 30);

    printf("Lista 1:\n");
    ListaImprimir(L1);
    printf("Lista 2:\n");
    ListaImprimir(L2);

    // Não está funcionando junto com a intercalada, o código para
    //L1 = JuntarListas(L1, L2);
    //printf("Lista juntada:\n");
    //ListaImprimir(L1);

    L3 = merge(L1, L2);
    printf("Lista intercalada:\n");
    ListaImprimir(L3);

    L4= copia(L2);
    printf("Lista copiada:\n");
    ListaImprimir(L4);

    return 0;
}
