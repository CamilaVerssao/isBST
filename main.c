#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

Arvore* construcaoArv(void);

Arvore* cria_arv_vazia(void) {
    return NULL;
}

Arvore* arv_constroi(char c, Arvore* e, Arvore *d) {
    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    a->info = c;
    a->esq = e;
    a->dir = d;
    return a;
}

Arvore* construcaoArv() {
    Arvore *a, *a1, *a2, *a3, *a4, *a5;
    a1 = arv_constroi(4, cria_arv_vazia(), cria_arv_vazia());
    a2 = arv_constroi(2, cria_arv_vazia(), a1);
    a3 = arv_constroi(5, cria_arv_vazia(), cria_arv_vazia());
    a4 = arv_constroi(6, cria_arv_vazia(), cria_arv_vazia());
    a5 = arv_constroi(3, a3, a4);
    a = arv_constroi(1, a2, a5);
    return a;
}

int maxValue(Arvore *a) {
    if(a == NULL) {
        return 0;
    }

    int leftMax = maxValue(a->esq);
    int rightMax = maxValue(a->dir);

    int value = 0;
    if(leftMax > rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }

    if(value < a->info) {
        value = a->info;
    }

    return value;
}

int minValue(Arvore *a) {
    if(a == NULL) {
        return 0;
    }

    int leftMin = minValue(a->esq);
    int rightMin = minValue(a->dir);

    int value = 0;
    if(leftMin < rightMin) {
        value = leftMin;
    }
    else {
        value = rightMin;
    }

    if(value > a->info) {
        value = a->info;
    }

    return value;
}

int isBST(Arvore *a) {
    if(a == NULL) {
        return 1;
    }

    if(a->esq != NULL && maxValue(a->esq) > a->info) {
        return 0;
    }

    if(a->dir != NULL && minValue(a->dir) < a->info) {
        return 0;
    }

    if (!isBST(a->esq) || !isBST(a->dir)) {
        return 0;
    }

    return 1;
}

int main(void)
{
    Arvore *a = construcaoArv();
    if(isBST(a)) {
        printf("Is BST");
    }
    else {
        printf("Not a BST");
    }

    return 0;


}
