#ifndef _FUNCAO_H_
#define _FUNCAO_H_
#include <allegro.h>
#include <cstdio>
#include <string>

BITMAP * a1;
BITMAP * a2;
BITMAP * a3;
BITMAP * a4;



float x=-2000,y=-2000,velx=0,vely=0,ace=0.10,sex=100,xgym[30],ygym[30];//controla variavels do cenario
bool p=false,pp=false,comeca=false,parou=false,ga=false,pro=false,lojaopen=false;
bool tempo=false;
int tecla_ante[KEY_MAX],frame=0,stopf=0,sel,vx=2,vy=2,ht=1,es,tam=0,tamf=1,ii=0,round=5,ou=0,qtdn=30,coni=0,conp=0;
int v1,v2,v3,v4,v5,v6,v7,v8,v9,d1,d2,d3,d4,d5,d6,d7,d8,d9;
std::string no1="t",no2="t",no3="t",merda,merda2,merda3,merda4;
int qtd=50,vida=1,limpx=8,limpy=8;//atributos do inimigo
int myhp=300,tempopro=3000,cuv=3,rale=30,preco1=0,preco2=0,preco3=0,preco4=0,roupa=1;//atributos do maleman
void atualiza_tecla();
bool aperta(int tecla);
bool segura(int tecla);
bool solta(int tecla);
void item(BITMAP *buffer,bool lojaa,int px,int py,FONT *fonte);
void perso(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile);
bool protege(BITMAP * grande,BITMAP *buffer,bool vpro,int mile);
void habilidade();
void span(Lista_inimi *l,Lista_fad *ll,int x,int y,int mile,int qtd);
void vid(BITMAP *life,BITMAP *buffer,Pai *inimi,int x,int y,int mile);
void atua(BITMAP* inimi,BITMAP* buffer,Pai *p,int mile);

enum{
	
	grama=0,
	concreto=1,
	agua=2,
	piso=3,
	casa=4,
	forest=5,
	cerca=6,
	gym1=7,
	gym2=8,
	gym3=9,
	gym4=10,
	gym5=11,
	gym6=12,
	gym7=13,
	gym8=14,
	branco=15,
	titula=100,
	mena=101,
	gama=103,
	muda=104,
	over=105,
	cida=106,
	flu=107,
	gama2=108
	
	
	
};

int estado_screen=gama2;

int **carrega_mapa(const char *arquivo,int *linha,int *coluna);
void desenha_mapa(BITMAP* m,BITMAP* buffer,int **mapa,int linha,int coluna);
void fecha_mapa(int **m,int linha);


#endif