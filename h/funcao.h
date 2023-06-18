#ifndef _FUNCAO_H_
#define _FUNCAO_H_
#include <allegro.h>
#include <cstdio>



float x=-2000,y=-2000,velx=0,vely=0,ace=0.10;
bool p=false,pp=false;
int tecla_ante[KEY_MAX],frame=0,stopf=0;
int qtd=22;
void atualiza_tecla();
bool aperta(int tecla);
bool segura(int tecla);
bool solta(int tecla);
void perso(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile);
void span(Lista_inimi *l,int x,int y,int mile,int qtd);
void atua(BITMAP* inimi,BITMAP* buffer,Pai *p);

enum{
	
	grama=0,
	concreto=1,
	agua=2,
	titula=100,
	mena=101,
	gama=103
	
	
	
	
};

int **carrega_mapa(const char *arquivo,int *linha,int *coluna);
void desenha_mapa(BITMAP* m,BITMAP* buffer,int **mapa,int linha,int coluna);
void fecha_mapa(int **m,int linha);


#endif