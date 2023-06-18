#ifndef _CLASSE_H_
#define _CLASSE_H_
#include <allegro.h>
#include <stdlib.h>
#include "../classe.cpp"

typedef struct botao{
	
	BITMAP * img;
	BITMAP * h_img;
	int pos_x, pos_y;
	
	bool highon;
	bool ativado;
	
	
}Botao;


	Botao *create_botao(BITMAP *img,BITMAP *h_img,int pos_x,int pos_y);
	void botao_veri(Botao *b);
	void botao_acao(Botao  *b);
	void botao_draw(Botao *b,BITMAP *buffer);
	void destroy_botao(Botao *b);




void update_lista(Lista_inimi *l,Compara *com,BITMAP *player,BITMAP* ini,BITMAP *buffer,Fadia *f1,int tam,int x,int y,int mile,int qtd);
Lista_inimi *create_lista_inimi();
void destroy_inimi (Pai *i);
void destroy_lista(Lista_inimi *l);

#endif