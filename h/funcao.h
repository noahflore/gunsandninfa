#ifndef _FUNCAO_H_
#define _FUNCAO_H_
#include <allegro.h>
int x=1,y=1,p=1,p2=1,p3=1,p4=1;
int tecla_ante[KEY_MAX];
void atualiza_tecla();
bool aperta(int tecla);
bool segura(int tecla);
bool solta(int tecla);
void perso();


#endif