#ifndef _FUNCAO_H_
#define _FUNCAO_H_
#include <allegro.h>
#include <cstdio>
#include <string>


float x=-2000,y=-2000,velx=0,vely=0,ace=0.10;
bool p=false,pp=false,começa=false;
int tecla_ante[KEY_MAX],frame=0,stopf=0;
int v1,v2,v3,v4,v5,v6,v7,v8,v9,d1,d2,d3,d4,d5,d6,d7,d8,d9;
std::string no1,no2,no3;
int qtd=5;
void atualiza_tecla();
bool aperta(int tecla);
bool segura(int tecla);
bool solta(int tecla);
void perso(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile);
void habilidade();
void span(Lista_inimi *l,int x,int y,int mile,int qtd);
void atua(BITMAP* inimi,BITMAP* buffer,Pai *p);

enum{
	
	grama=0,
	concreto=1,
	agua=2,
	titula=100,
	mena=101,
	gama=103,
	muda=104
	
	
	
	
};

int **carrega_mapa(const char *arquivo,int *linha,int *coluna);
void desenha_mapa(BITMAP* m,BITMAP* buffer,int **mapa,int linha,int coluna);
void fecha_mapa(int **m,int linha);


#endif