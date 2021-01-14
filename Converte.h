/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Converte.h
 * Author: joaobornelli
 *
 * Created on 9 de janeiro de 2021, 20:49
 */

#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2


typedef struct{
    char *dados;
    int topo;
    int capacidade;
    
}Pilha;


void inicializa_pilha_converte(Pilha *p, int capacidade);

int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);

int empilha(Pilha *p, char info);
int desempilha(Pilha *p, char *info);

int le_topo(Pilha  p, char *info);
