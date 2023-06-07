#ifndef _FUNCAO_H_
#define _FUNCAO_H_
#include <allegro.h>



float x=0,y=0,velx=0,vely=0,ace=0.10;
bool p=false,pp=false;
int tecla_ante[KEY_MAX],frame=0;
void atualiza_tecla();
bool aperta(int tecla);
bool segura(int tecla);
bool solta(int tecla);
void perso(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile);





#endif