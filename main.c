/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: João Luís Bornelli e Rafaela Fernanda
 *
 * Created on 9 de janeiro de 2021, 18:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Converte.h"

#define ERRO_STRING_INVALIDA -3
/*
 * 
 */
int precedencia(int operador);

int main() {
    
    Pilha p1;
    int erro = 0;
    int qnt = 0;
    int i;
    int topo = 0;
    char eq_infixa[50] = "1+2*3-4";
    char eq_posfixa[50];
    int index_posf;
    
    
    char c;
    char x;
    
    inicializa_pilha_converte(&p1, strlen(eq_infixa));
    index_posf = 0;
    
    for (i = 0; i < strlen(eq_infixa); i++) {
        c = eq_infixa[i];
        if(erro > 0)
            break;
        
        switch (c){
            default:
                printf("Caractere invalido\n");
                erro = ERRO_STRING_INVALIDA;
                break;
            
            case '(':
                empilha(&p1,c);
                break;
            
            case ')':
                while(le_topo(p1,&x) > -1 && x != '('){
                    desempilha(&p1,&x);
                    eq_posfixa[index_posf] = x;
                    index_posf++;
                }
                if(pilha_vazia(p1) == ERRO_PILHA_VAZIA){
                    printf("Erro '(' sem ')'\n");
                    erro = ERRO_STRING_INVALIDA;
                }
                else{
                    desempilha(&p1,&x);
                }
                break;
                
            case '+':

                le_topo(p1,&x);
                if(pilha_vazia(p1) == ERRO_PILHA_VAZIA || x == '('){
                    empilha(&p1,c);
                }
                else{
                    while (le_topo(p1,&x)!= ERRO_PILHA_VAZIA && (precedencia(x)>= precedencia(c))){
                        desempilha(&p1,&x);
                        eq_posfixa[index_posf] = x;
                        index_posf++;
                    }
                    empilha(&p1,c);
                }
                break;
            
            case '-':
                le_topo(p1,&x);
                if(pilha_vazia(p1) == ERRO_PILHA_VAZIA || x == '('){
                    empilha(&p1,c);
                }
                else{
                    while (le_topo(p1,&x)!= ERRO_PILHA_VAZIA && (precedencia(x)>= precedencia(c))){
                        desempilha(&p1,&x);
                        eq_posfixa[index_posf] = x;
                        index_posf++;
                    }
                    empilha(&p1,c);
                }
                break;
            
            case '*':
                le_topo(p1,&x);
                if(pilha_vazia(p1) == ERRO_PILHA_VAZIA || x == '('){
                    empilha(&p1,c);
                }
                else{
                    while (le_topo(p1,&x)!= ERRO_PILHA_VAZIA && (precedencia(x)>= precedencia(c))){
                        desempilha(&p1,&x);
                        eq_posfixa[index_posf] = x;
                        index_posf++;
                    }
                    empilha(&p1,c);
                }
                break;
            
            case '/':
                le_topo(p1,&x);
                if(pilha_vazia(p1) == ERRO_PILHA_VAZIA || x == '('){
                    empilha(&p1,c);
                }
                else{
                    while (le_topo(p1,&x)!= ERRO_PILHA_VAZIA && (precedencia(x)>= precedencia(c))){
                        desempilha(&p1,&x);
                        eq_posfixa[index_posf] = x;
                        index_posf++;
                    }
                    empilha(&p1,c);
                }
                break;
                
            case '0':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
                
            case '1':
                eq_posfixa[index_posf] = c;
                index_posf++;

                break;
                
            case '2':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '3':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '4':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '5':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '6':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '7':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '8':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
            
            case '9':
                eq_posfixa[index_posf] = c;
                index_posf++;
                break;
        }
    }
    if(erro == 0){
        while((le_topo(p1,&x)!= ERRO_PILHA_VAZIA) && x != '('){
            desempilha(&p1,&x);
            eq_posfixa[index_posf] = x;
            index_posf++;
                
        }
        if((le_topo(p1,&x)== ERRO_PILHA_VAZIA)){
            eq_posfixa[index_posf] = '\0';
            printf("%s\n",eq_posfixa);
        }
        else{
            printf("Erro: '(' nao foi fechado!\n");
        }
    }
    return 1;
}


int precedencia(int operador){
    if(operador == '(')
        return 0;
    else if((operador == '+') || (operador == '-'))
        return 1;
    else if((operador == '*') || (operador == '/'))
        return 2;   
}

