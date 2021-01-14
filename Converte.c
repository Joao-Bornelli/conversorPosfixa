/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Converte.h"
#include <stdlib.h>

void inicializa_pilha_converte(Pilha* p, int tam){
    p->capacidade = tam;
    p->dados = malloc(sizeof(char) * tam);
    p->topo = -1;   
}

int pilha_cheia(Pilha p){
    return p.topo == p.capacidade -1;
}


int pilha_vazia(Pilha p){
    return p.topo == ERRO_PILHA_VAZIA;
}


int le_topo(Pilha p, char* info){
    if(pilha_vazia(p))
        return ERRO_PILHA_VAZIA;
    
    *info =  p.dados[p.topo];
    return 1;
}

int empilha(Pilha* p, char info){
    if (pilha_cheia(*p))
        return ERRO_PILHA_CHEIA;
    p->topo++;
    p->dados[p->topo] = info;
    
    return 1;
}

int desempilha(Pilha* p, char* info){
    if(pilha_vazia(*p))
        return ERRO_PILHA_CHEIA;
    
    *info = p->dados[p->topo];
    p->topo--;
    return 1;
}



