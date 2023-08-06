//#include "classe.cpp"
#include "h/funcao.h"
#include "h/classe.h"

void habilidade(){
	
	vida*=2;
	
	srand(time(NULL));
	
//	sel= rand() % 10;
	sel=3;
	if (sel == 1){
	no1= "fadia submissa";
		
	}else if (sel == 2){
		
		no1= "homem masculo";
	}else if (sel == 3){
		
		no1= "alpha";
	}else if (sel == 4){
		
		
		no1="mais fadia";
		
		
	}else if(sel == 5){
		
		no1="deus grego";
		
	}else if(sel == 6){
		
		no1="a queda";
		
	}else if(sel == 7){
		
		no1="humilhação";
		
	}else if(sel == 8){
		
		no1="fadia rebeliao";
		
	}else if(sel == 9){
		
		no1="o beta";
		
	}else{
		
		no1="fraco";
	}
	no2= "teste";
	no3= "teste";
	v1= rand() % 50;
	v2= rand() % 50;
	v3= rand() % 10;
	d1= rand() % 10;
	d2= rand() % 10;
	d3= rand() % 100;
	v4= rand() % 100;
	v5= rand() % 100;
	v6= rand() % 100;
	d4= rand() % 100;
	d5= rand() % 100;
	d6= rand() % 100;
	v7= rand() % 100;
	v8= rand() % 100;
	v9= rand() % 100;
	d7= rand() % 100;
	d8= rand() % 100;
	d9= rand() % 100;
	
	
	
}



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
				
			}else if((mapa[i][j]== piso) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				
				
				masked_blit(m,buffer,3 *m_w,0 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
			}else if ((mapa[i][j]== casa) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,4 *m_w,0 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
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




void perso(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile){//meu boneco
	
	static int fixa=0,fixa2=0;
		
		
	
		if ((velx<=limpx) && (segura(KEY_D))){
			
			velx+=ace;
			x-=velx;
			p=true;
			stopf=2;
			
			frame=(mile /300) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w + fixa - fixa2,frame_h);
			
			
		}else if (segura(KEY_D)){
			
			x-=velx;
			
			frame=(mile /150) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w + fixa - fixa2,frame_h);
			
		}
	
		
		if ((velx<=limpx) && (segura(KEY_A))){
			velx+=ace;
			x+=velx;
			p=false;
			stopf=3;
			
			frame=(mile /300) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w + fixa - fixa2,frame_h);
		}else if (segura(KEY_A)){
			
			x+=velx;
			
			frame=(mile /150) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w + fixa - fixa2,frame_h);
			
		}
	
	
	if((vely<=limpy) && (segura(KEY_W))){
		
			vely+=ace;
			y+=vely;
			pp=true;
			stopf=1;
		
		
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}else if (segura(KEY_W)){
			
			y+=vely;
		
			
			frame=(mile /150) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
		
		
		
	

		if ((vely<=limpy) && (segura(KEY_S))){
			vely+=ace;
			y-=vely;
			stopf=0;
			pp=false;
			
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}else if (segura(KEY_S)){
			
		
			y-=vely;
			
			
			frame=(mile /150) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
		
		if ((velx>=0) && (!key[KEY_A]) && (!key[KEY_D])){//desacelaçao
			velx-=ace;
			if(p){x-=velx;}else{x+=velx;}
			
			if ((!key[KEY_S]) && (!key[KEY_W]))
			frame=(mile /300) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w + fixa - fixa2,frame_h);
			
		}
	
		if ((vely>=0) && (!key[KEY_S]) && (!key[KEY_W])){
			vely-=ace;
			if(pp){y+=vely;}else{y-=vely;}
			
			if ((!key[KEY_A]) && (!key[KEY_D]))
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
		}
	
		if ((!key[KEY_A]) && (!key[KEY_D]) && (!key[KEY_W]) && (!key[KEY_S]) && (velx<0) && (vely<0)){//boneco parado
			
			
			
			
			masked_blit(player,buffer,0 * frame_w,stopf * frame_h,SCREEN_W/2-100,SCREEN_H/2-100,frame_w,frame_h);
			
		}
	
	
	
}

void persotwo(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile){//meu boneco
	
	static int fixa=0,fixa2=0,px=30,py=600;
		
		
	
		if ((velx<=limpx) && (segura(KEY_D))){
			
			velx+=ace;
			px+=velx;
			p=true;
			stopf=2;
			
			frame=(mile /300) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,px,py,frame_w + fixa - fixa2,frame_h);
			
			
		}else if (segura(KEY_D)){
			
			px+=velx;
			
			frame=(mile /150) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,px,py,frame_w + fixa - fixa2,frame_h);
			
		}
	
		
		if ((velx<=limpx) && (segura(KEY_A))){
			velx+=ace;
			px-=velx;
			p=false;
			stopf=3;
			
			frame=(mile /300) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,px,py,frame_w + fixa - fixa2,frame_h);
		}else if (segura(KEY_A)){
			
			px-=velx;
			
			frame=(mile /150) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,px,py,frame_w + fixa - fixa2,frame_h);
			
		}
	
	
	if((vely<=limpy) && (segura(KEY_W))){
		
			vely+=ace;
			py-=vely;
			pp=true;
			stopf=1;
		
		
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
			
		}else if (segura(KEY_W)){
			
			py-=vely;
		
			
			frame=(mile /150) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
			
		}
		
		
		
	

		if ((vely<=limpy) && (segura(KEY_S))){
			vely+=ace;
			py+=vely;
			stopf=0;
			pp=false;
			
			
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
			
		}else if (segura(KEY_S)){
			
		
			py+=vely;
			
			
			frame=(mile /150) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
			
		}
		
		if ((velx>=0) && (!key[KEY_A]) && (!key[KEY_D])){//desacelaçao
			velx-=ace;
			if(p){x-=velx;}else{x+=velx;}
			
			if ((!key[KEY_S]) && (!key[KEY_W]))
			frame=(mile /300) % 4;
			if ((frame == 3) || (frame==1))
			fixa=5;
			else
				fixa=0;
			
			if (frame==2)
				fixa2=5;
			else
				fixa2=0;
			masked_blit(player,buffer,frame * frame_w + fixa2,stopf * frame_h,px,py,frame_w + fixa - fixa2,frame_h);
			
		}
	
		if ((vely>=0) && (!key[KEY_S]) && (!key[KEY_W])){
			vely-=ace;
			if(pp){y+=vely;}else{y-=vely;}
			
			if ((!key[KEY_A]) && (!key[KEY_D]))
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
		}
	
		if ((!key[KEY_A]) && (!key[KEY_D]) && (!key[KEY_W]) && (!key[KEY_S]) && (velx<0) && (vely<0)){//boneco parado
			
			
			
			
			masked_blit(player,buffer,0 * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
			
		}
	
	
	
}

bool protege(BITMAP *grande,BITMAP *buffer,bool vpro,int mile){
	static int temes=mile;
	static bool conr=false;
		
	
		if (mile  - temes >= tempopro){


				temes=mile;

				vpro=false;
			}
		
	
		draw_sprite(buffer,grande,60,10);
		textprintf(buffer,font,60+55,10,makecol(255,255,255),"%d",cuv);

		if ((vpro) && (cuv >0)){

				if (!conr)
				cuv--;
				conr=true;
			
			circle(buffer,SCREEN_W/2-100,SCREEN_H/2-100,100,makecol(255,0,124));
			return true;
		}else{

			conr=false;
			return false;
		}
	
		
	
}


Botao *create_botao(BITMAP *img,BITMAP *h_img,int pos_x,int pos_y,int index){
	
	Botao *b= (Botao*) malloc(sizeof(Botao));
	
	b->img=img;
	b->h_img=h_img;
	b->pos_x=pos_x;
	b->pos_y=pos_y;
	b->index=index;
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
	bool botao_acao(Botao  *b, int mile,bool ca,BITMAP *buffer){
		static int a=mile,bb=mile;
		static bool mudo=false;
		
		if ((b->ativado) && (b->index==1)){
			
			if  (sel== 1){//aumenta atributos da fada
				
				vx=v1;
				vy=v2;
				ht+=v3;
				tempopro-=d1;
				limpx-=d2;
				limpy-=d3;
				
				if (limpx <= 0)limpx=1;
				if (limpy <=0)limpy=1;
				
				
			}else if  ((sel== 2) && (!parou)){//aumenta atributos do maleman
				
				if (myhp <3)
					myhp=3;
				myhp*=2;
				
				limpx+=v3;
				limpy+=v3;
				
				tempopro-=300;
				vx-=1;
				vy-=1;
				parou=true;
				
			}else if  ((sel== 3) && (!parou)){// aumenta a magia 
				
				tempopro+=v1;
				cuv+=3;
				parou=true;
				
			}else if ((sel == 4) && (!parou)){
				
				tamf++;
				parou=true;
				
			}else if (sel == 5){//aumenta a conquista de ninfa
				
				
				
				
			}
			
			if (mile - bb >= 5000){
				
				tam=0;
				qtd*=2;
				ca=true;
				tempo=false;
				
				bb = mile;
				return ca;
			}
				
			
			
			if (mile - a >= 1000){
			
				if (mudo){
					mudo=false;
				}else{
					mudo=true;
				}
			
				a=mile;
			}
			
			
			
			
			if (mudo)
				draw_sprite(buffer,b->h_img,b->pos_x,b->pos_y);
		}
		
				
				ca=false;
				return ca;
		
	}
	void botao_draw(Botao *b,BITMAP *buffer){
		
		draw_sprite(buffer,b->img,b->pos_x,b->pos_y);
		
		if ((b->highon) && (b->index==1)){
			textprintf_centre(buffer,font,b->pos_x+50,b->pos_y+150,makecol(255,255,255),"habili: %s\n vanta: %d %d %d\n desvan: %d %d %d",no1.c_str(),v1,v2,v3,d1,d2,d3);
			draw_sprite(buffer,b->h_img,b->pos_x,b->pos_y);
		}else if ((b->highon) && (b->index==2)){
			textprintf_centre(buffer,font,b->pos_x+50,b->pos_y+150,makecol(255,255,255),"habili: %s \n vanta: %d %d %d \n desvan: %d %d %d",no2.c_str(),v4,v5,v6,d4,d5,d6);
			draw_sprite(buffer,b->h_img,b->pos_x,b->pos_y);
		}else if ((b->highon) && (b->index==3)){
			textprintf_centre(buffer,font,b->pos_x+50,b->pos_y+150,makecol(255,255,255),"habili: %s \n vanta: %d %d %d \n desvan: %d %d %d",no3.c_str(),v7,v8,v9,d7,d8,d9);
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


Lista_inimi *create_lista_inimi(){//cria a lista
	
	Lista_inimi* l= (Lista_inimi*) malloc(sizeof(Lista_inimi));
	
	l->inicio=NULL;
	
	return l;
	
	
}

Lista_fad *create_lista_fad(){//cria a lista
	
	Lista_fad* l= (Lista_fad*) malloc(sizeof(Lista_fad));
	
	l->inicio=NULL;
	
	return l;
	
	
}

Lista_ninfa *create_lista_ninfa(){//cria a lista
	
	Lista_ninfa* l= (Lista_ninfa*) malloc(sizeof(Lista_ninfa));
	
	l->inicio=NULL;
	
	return l;
	
	
}


void destroy_inimi (Pai *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista(Lista_inimi *l){
	
	No_inimi *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_inimi(aux->inimi);
		free(aux);
		
	}
	
	
}

void destroy_fad (Fadia *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_f(Lista_fad *l){
	
	No_fad *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_fad(aux->fad);
		free(aux);
		
	}
	
	
}

void destroy_ninfa (Ninfa *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_n(Lista_ninfa *l){
	
	No_ninfa *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_ninfa(aux->nina);
		free(aux);
		
	}
	
	
}

void update_lista(Lista_inimi *l,Lista_fad *ll,Compara *com,BITMAP *grande,BITMAP* life,BITMAP *player,BITMAP* ini,BITMAP *buffer,bool vpro,int tam,int x,int y,int mile,int qtd){
	
	//No_inimi *aux=l->inicio;
	//No_inimi *aux2=l->inicio;
	No_fad *aux3=ll->inicio;
	No_fad *aux4=ll->inicio;
	
	static int calma=mile;
	 
	
	pro=protege(grande,buffer,vpro,mile);
	while (aux3 !=NULL){
		
		
		No_inimi *aux=l->inicio;
		No_inimi *aux2=l->inicio;
		
		aux3->fad->espera(player,buffer,mile);
		if (aux3->fad->ativo){
			
			
				
			
			while (aux != NULL){//objeto ativo
				
				

				if (aux->inimi->ativo){

				//	span(l,x, y, mile,qtd);
					
					atua(ini,buffer,aux->inimi);
					com->colisao(player,buffer,aux->inimi,aux3->fad,tam,x,y);
					vid(life,buffer,aux->inimi,x,y,mile);
				//	com->colisao(player,buffer,aux2->inimi,aux4->fad,tam,x,y);
					aux2=aux;
					aux= aux->prox;
					

				}else{

					if (aux == aux2){//elemento igual no aux e aux2

						l->inicio=l->inicio->prox;
						destroy_inimi(aux->inimi);
						free(aux);
						aux2=aux= l->inicio;

					}else{

						aux2->prox=aux->prox;
						destroy_inimi(aux->inimi);
						free(aux);
						aux=aux2->prox;
					}

				}


			}
			
			aux4=aux3;
			aux3= aux3->prox;
			
		}else {
			
			if (aux3 == aux4){//elemento igual no aux e aux2

						ll->inicio=ll->inicio->prox;
						destroy_fad(aux3->fad);
						free(aux3);
						aux4=aux3= ll->inicio;

					}else{

						aux4->prox=aux3->prox;
						destroy_fad(aux3->fad);
						free(aux3);
						aux3=aux4->prox;
					}
			
			
			
			
		}
		
		
	}
	
}

void span_ninfa(Lista_ninfa *l,int x,int y,int mile){
	static int marco=mile;
	
	if (mile - marco >= 500){
		
		
		if (ou <= qtdn){
	
		No_ninfa *novo= (No_ninfa*) malloc(sizeof(No_ninfa));
		novo->nina= new Ninfa(mile);
		novo->prox=l->inicio;
		l->inicio=novo;

			ou++;
		}
		
		marco=mile;
	}
	
}

void update_ninfa(Lista_ninfa *l,BITMAP *ni,BITMAP *buffer,int x,int y,int mile,int sex){
	
	No_ninfa *aux=l->inicio;
	No_ninfa *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->nina->ativo){
			
			
			aux->nina->update(ni,buffer,x,y,mile,sex);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			
			if (aux == aux2){
				
				l->inicio=l->inicio->prox;
				destroy_ninfa(aux->nina);
				free(aux);
				aux=aux2=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_ninfa(aux->nina);
				free(aux);
				aux->prox=aux2->prox;
				
				
			}
			
			
			
		}
		
		
		
	}
	
}

void span(Lista_inimi *l,Lista_fad *ll,int x,int y,int mile,int qtd,int vida){
	static	int macadora=mile;
	 static int inde=0;
	
	
	
				if (ii < tamf){
					
					inde++;
					
					No_fad *novo2= (No_fad*) malloc(sizeof(No_fad));
					novo2->fad= new Fadia(vx,vy,ht,es,inde);
					novo2->prox=ll->inicio;
					ll->inicio=novo2;
					
					ii++;
				}
	
	
				if (mile - macadora >= 5000)
					tempo=true;
			
			
				if (( mile - macadora >= 1000) &&   (tam <qtd) && (tempo)){
					
					No_inimi* novo= (No_inimi*) malloc(sizeof(No_inimi));
				
					novo->inimi= new Pai(x,y,mile,vida);
					novo->prox= l->inicio;
					l->inicio=novo;

					
					comeca=true;
					macadora=mile;
					tam++;
					
				}
			
	
}

void atua(BITMAP* inimi,BITMAP* buffer,Pai *p){
	
	
				
				p->update(inimi,buffer,x,y);
	
	
	
}

void vid(BITMAP *life,BITMAP *buffer,Pai *inimi,int x,int y,int mile){
	static bool fato=false;
	static int tem=mile;
	
	if ((mile - tem >=3000) && (fato)){
		
		fato=false;
		tem=mile;
	}
	
	if (!pro){
	
		if ((inimi->pos_x + x <= SCREEN_W/2) && (inimi->pos_x + x >= SCREEN_W/2-100) &&
			(inimi->pos_y + y <= SCREEN_H/2) && (inimi->pos_y + y >= SCREEN_H/2-100) && (!fato)){

			fato=true;
			myhp--;


		}

		if ((inimi->pos_x + x + inimi->wid <= SCREEN_W/2) && (inimi->pos_x + x + inimi->wid >= SCREEN_W/2-100) &&
			(inimi->pos_y + y <= SCREEN_H/2) && (inimi->pos_y + y >= SCREEN_H/2-100) && (!fato)){

			fato=true;
			myhp--;

		}

		if ((inimi->pos_x + x + inimi->wid <= SCREEN_W/2) && (inimi->pos_x + x + inimi->wid >= SCREEN_W/2-100) &&
			(inimi->pos_y + y + inimi->hi <= SCREEN_H/2) && (inimi->pos_y + y + inimi->hi >= SCREEN_H/2-100) && (!fato)){

			fato=true;
			myhp--;

		}

		if ((inimi->pos_x + x <= SCREEN_W/2) && (inimi->pos_x + x  >= SCREEN_W/2-100) &&
			(inimi->pos_y + y + inimi->hi <= SCREEN_H/2) && (inimi->pos_y + y + inimi->hi >= SCREEN_H/2-100) && (!fato)){

			fato=true;
			myhp--;

	}
		
	}
	
		draw_sprite(buffer,life,5,10);
		textprintf(buffer,font,55,10,makecol(255,255,255),"%d",myhp);
		
		
		
	
	if (myhp<= 0){
		estado_screen=over;
		ga=true;
		
	}
	
}

void loja(BITMAP *m,BITMAP *buffer,BITMAP *lo){
	int m_w=569/5;
	int m_h=411/4;
	
	if (((500 + x >= SCREEN_W/2-100) &&
		(500 + x <= SCREEN_W/2-50) &&
		(500 + y >= SCREEN_H/2-100) &&
		(500 + y <= SCREEN_H/2-50)) || (lojaopen)){
		x=-10000;
		y=-10000;
		lojaopen=true;
		draw_sprite(buffer,lo,0,0);
	}
	
	rect(buffer,500 + x,500 + y,500 + x,500 + y,makecol(255,255,255));
		
	masked_blit(m,buffer,0 *m_w,1 *m_h,500 + x, 500 + y,m_w,m_h);
	
}