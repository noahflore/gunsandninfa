#include "h/funcao.h"
#include "h/classe.h"


void fadia(BITMAP *player,BITMAP *buffer,int mile){
	
	
	//lado horizontal da fada
	
	
	if (fadia_x == SCREEN_W/2-100){
		
		srand(mile);
		esq= rand() % 2;
		
		limx=rand() % 100 ;
		
	}

	
	
		if ((esq) && (fadia_x <= SCREEN_W/2+200)){
		
		fadia_x++;
		
	}else if ((!esq) && (fadia_x >= SCREEN_W/2-200)){
		
		fadia_x--;
		
		
	}
	
	if (fadia_x >= SCREEN_W/2+limx){
		
		esq=false;
	}else if (fadia_x <= SCREEN_W/2-limx-100){
		
		
		esq=true;
	}
	
	//lado vertical da fada
	
	
	if (fadia_y == SCREEN_H/2-100){
		
		srand(time(NULL));
		cima= rand() % 2;
		limy=rand() % 100 ;
		
	}

	
	
	if ((cima) && (fadia_y <= SCREEN_H/2+200)){
		
		fadia_y++;
		
	}else if ((!cima) && (fadia_y >= SCREEN_H/2-200)){
		
		fadia_y--;
		
		
	}
	
	if (fadia_y >= SCREEN_H/2+limy){
		
		cima=false;
	}else if (fadia_y <= SCREEN_H/2-limy-100){
		
		
		cima=true;
	}
	
		masked_blit(player,buffer,262,471,fadia_x,fadia_y,fadia_w,fadia_h);
}

void perso(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile){
	
	
		
		if ((velx<=8) && (segura(KEY_D))){
			
			velx+=ace;
			x-=velx;
			p=true;
			stopf=2;
			
			frame=(mile /150) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
			
		}else if (segura(KEY_D)){
			
			x-=velx;
			
			frame=(mile /150) % 4;
			
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
	
		
		if ((velx<=8) && (segura(KEY_A))){
			velx+=ace;
			x+=velx;
			p=false;
			stopf=3;
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
		}else if (segura(KEY_A)){
			
			x+=velx;
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
	
	
	if((vely<=8) && (segura(KEY_W))){
		
			vely+=ace;
			y+=vely;
			pp=true;
			stopf=1;
		
		
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}else if (segura(KEY_W)){
			
			y+=vely;
		
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
		
		
		
	

		if ((vely<=8) && (segura(KEY_S))){
			vely+=ace;
			y-=vely;
			stopf=0;
			pp=false;
			
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}else if (segura(KEY_S)){
			
		
			y-=vely;
			
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
		
		if ((velx>=0) && (!key[KEY_A]) && (!key[KEY_D])){
			velx-=ace;
			if(p){x-=velx;}else{x+=velx;}
			
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
	
		if ((vely>=0) && (!key[KEY_S]) && (!key[KEY_W])){
			vely-=ace;
			if(pp){y+=vely;}else{y-=vely;}
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
		}
	
		if ((!key[KEY_A]) && (!key[KEY_D]) && (!key[KEY_W]) && (!key[KEY_S])){
			
			
			
			
			masked_blit(player,buffer,0 * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
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

