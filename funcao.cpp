#include "h/classe.h"
#include "classe.cpp"
#include "h/funcao.h"


int **carrega_mapa(const char *arquivo,int *linha,int *coluna){
	
	FILE *f=fopen(arquivo,"r");
	int **matriz;
	
	if (f !=NULL){
		
		fscanf(f, "%d %d",linha,coluna);
		
		matriz= (int**) malloc ((*linha) * sizeof(int*));
		for (int i=0; i< *linha; i++)
			matriz[i]= (int*) malloc((*coluna) * sizeof(int));
		
		for (int i=0; i< *linha; i++){
			for(int j=0;j< *coluna; j++){
				
				fscanf(f,"%d",&matriz[i][j]);
				
			}
			
			
			
		}
		
		fclose(f);
	}
	
	return matriz;
	
	
}
void desenha_mapa(BITMAP* m,BITMAP* buffer,int **mapa,int linha,int coluna){
	
	int m_w=569/5;
	int m_h=411/4;
	for (int i=0; i< linha; i++){
		for (int j=0;j< coluna; j++){
			
			if ((mapa[i][j]== grama) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,0 *m_w,0 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
			}else if ((mapa[i][j]== concreto) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,1 *m_w,0 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
			}else if ((mapa[i][j]== agua) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				if ((SCREEN_W/2-60 >= j * 80+x) && (SCREEN_W/2-60 <= j* 80 + x + m_w)
				   && (SCREEN_H/2-100 >= i* 85 + y)&& (SCREEN_H/2-100 <= i* 85 + y + m_h)){//objeto a
					
					y-=vely;
					x-=velx;
				}else if ((j * 80+x >= SCREEN_W/2-100) && ( j* 80 + x <= SCREEN_W/2)
				   && ( i* 85 + y >= SCREEN_H/2-100)&& ( i* 85 + y <=SCREEN_H/2-50)) {
					
					y+=vely;
					x+=velx;
					
					
				}
				
				if ((SCREEN_W/2-50 >= j * 80+x) && (SCREEN_W/2-50 <= j* 80 + x + m_w)
				   && (SCREEN_H/2-100 >= i* 85 + y)&& (SCREEN_H/2-100 <= i* 85 + y + m_h)){
					
					y-=vely;
					x+=velx;
				}else if ((j * 80+x +m_w >= SCREEN_W/2-60) && ( j* 80 + x + m_w <= SCREEN_W/2)
				   && ( i* 85 + y >= SCREEN_H/2-100)&& ( i* 85 + y <=SCREEN_H/2-50)){
					
					y+=vely;
					x-=velx;
					
				}
				
				if ((SCREEN_W/2-50 >= j * 80+x) && (SCREEN_W/2-50 <= j* 80 + x + m_w)
				   && (SCREEN_H/2-50 >= i* 85 + y)&& (SCREEN_H/2-50 <= i* 85 + y + m_h)){
					
					y+=vely;
					x+=velx;
				}else if ((j * 80+x + m_w >= SCREEN_W/2-60) && ( j* 80 + x + m_w <= SCREEN_W/2)
				   && ( i* 85 + y + m_h >= SCREEN_H/2-100)&& ( i* 85 + y + m_h <=SCREEN_H/2-50)){
					
					y-=vely;
					x-=velx;
					
				}
				
				if ((SCREEN_W/2-60 >= j * 80+x) && (SCREEN_W/2-60 <= j* 80 + x + m_w)
				   && (SCREEN_H/2-50 >= i* 85 + y)&& (SCREEN_H/2-50 <= i* 85 + y + m_h)){
					
					y+=vely;
					x-=velx;
				}else if ((j * 80+x >= SCREEN_W/2-100) && ( j* 80 + x <= SCREEN_W/2)
				   && ( i* 85 + y + m_h >= SCREEN_H/2-100)&& ( i* 85 + y + m_h <=SCREEN_H/2-50)){
					
					y-=vely;
					x+=velx;
					
				}
					
					
				masked_blit(m,buffer,2 *m_w,0 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
			}
			
		}
		
		
		
	}
	
	
}
void fecha_mapa(int **m,int linha){
	
	for (int i=0; i< linha; i++){
		
		free(m[i]);
	}
	free(m);
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
Pai *ini[20];
int tam=0;

void span(int x,int y,int mile,int qtd){
	static int i=0;
	static	int macadora=mile;
	static bool tempo;
	
				if (mile - macadora >= 5000)
					tempo=true;
			
			
				if (( mile - macadora >= 500) &&   (tam <qtd) && (tempo)){
				
					ini[tam]= new Pai(x,y,mile);

					macadora=mile;
					tam++;
					
				}
			
	
}

void atua(BITMAP* inimi,BITMAP* buffer){
	
	for (int i=0;i<tam;i++)
				
				ini[i]->update(inimi,buffer,x,y);
	
	
	
}