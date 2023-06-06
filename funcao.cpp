#include "h/funcao.h"
#include "h/classe.h"


void perso(){
	
	
		
		if ((velx<=8) && (segura(KEY_D))){
			
			velx+=ace;
			x+=velx;
			p=false;
			
			
		}else if (segura(KEY_D)){
			
			x+=velx;
			
		}
	
		
		if ((velx<=8) && (segura(KEY_A))){
			velx+=ace;
			x-=velx;
			p=true;
			
			
		}else if (segura(KEY_A)){
			
			x-=velx;
			
		}
	
	
	if((vely<=8) && (segura(KEY_W))){
		
			vely+=ace;
			y-=vely;
			pp=false;
		
			
		}else if (segura(KEY_W)){
			
			y-=vely;
			
		}
		
		
		
	

		if ((vely<=8) && (segura(KEY_S))){
			vely+=ace;
			y+=vely;
			
			pp=true;
			
		}else if (segura(KEY_S)){
			
		
			y+=vely;
			
			
		}
		
		if ((velx>=0) && (!key[KEY_A]) && (!key[KEY_D])){
			velx-=ace;
			if(p){x-=velx;}else{x+=velx;}
			
			
		}
	
		if ((vely>=0) && (!key[KEY_S]) && (!key[KEY_W])){
			vely-=ace;
			if(pp){y+=vely;}else{y-=vely;}
			
			
		}
	
	
	
}

Botao *create_botao(BITMAP *img,BITMAP *h_img,int pos_x,int pos_y){
	
	Botao *b= (Botao*) malloc(sizeof(Botao));
	
	b->img=img;
	b->h_img=h_img;
	b->pos_x=pos_x;
	b->pos_y=pos_y;
	b->highon=false;
	b->ativado=false;
	
	return b;
	
	
	
}

	void botao_veri(Botao *b){
		
		if (mouse_x > b->pos_x && mouse_x < b->pos_x + b->img->w
		   && mouse_y > b->pos_y && mouse_y < b->pos_y + b->img->h
		   && getpixel(b->img,mouse_x - b->pos_x,mouse_y - b->pos_y) != makecol(255,0,255)){
			
			b->highon=true;
			
			if (mouse_b== 1){
				mouse_b=0;
				
				if (b->ativado){
					
					b->ativado=false;
					
				}else{
					
					b->ativado=true;
				}
			}
			
			
		}else{
			
			b->highon=false;
		
		
	}
		
	}
	void botao_acao(Botao  *b){
		
		if (b->ativado){
			
			
		}
		
	}
	void botao_draw(Botao *b,BITMAP *buffer){
		
		draw_sprite(buffer,b->img,b->pos_x,b->pos_y);
		
		if (b->highon){
			
			draw_sprite(buffer,b->h_img,b->pos_x,b->pos_y);
		}
	}
	void destroy_botao(Botao *b){
		
		free(b);
		
	}

void atualiza_tecla(){
	
	
	for (int i=0;i<=KEY_MAX;i++){
		
		tecla_ante[i]=key[i];
		
		
	}
	poll_keyboard();
	
	
}

bool aperta(int tecla){
	
	if ((!key[tecla])&&(tecla_ante[tecla])){
		
		return true;
		
	}else{
		
		return false;
	}
	
	
}
bool segura(int tecla){
	
	if ((key[tecla])&&(tecla_ante[tecla])){
		
		return true;
		
	}else{
		
		return false;
	}
	
	
	
	
}
bool solta(int tecla){
	
	if ((key[tecla])&&(!tecla_ante[tecla])){
		
		return true;
		
	}else{
		
		return false;
	}
	
	
	
	
	
	
	
}

