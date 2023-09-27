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

void equipa(int roupa,BITMAP *buffer,BITMAP *obj){
	
	if (roupa == 1)
		masked_blit(obj,buffer,0,0,SCREEN_W/2-92,SCREEN_H/2-74,49,43);
	
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

void prepara_colisao(int **mapa,int linha,int coluna){//prepara a colisão da matriz no draw
	
	static bool paru=false;
	
	if (!paru){
		
		for (int i=0;i<30;i++){
			xgym[i]=0;
			ygym[i]=0;
			
			
		}
		
		
		for (int i=0;i< linha;i++){
			for (int j=0;j<coluna;j++){

				if ((mapa[i][j] == gym1) || (mapa[i][j] == gym2) || (mapa[i][j] == gym3) || (mapa[i][j] == gym4) || (mapa[i][j] == gym5) || (mapa[i][j] == gym6) || (mapa[i][j] == gym7) || (mapa[i][j] == gym8)){

					conp++;
				}



			}


		}
		paru=true;
		
	}
	
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
				
			}else if ((mapa[i][j]== forest) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,1 *m_w,1 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
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
				
			}else if ((mapa[i][j]== cerca) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,2 *m_w,1 *m_h,j * 80+x,i *85+y,m_w,m_h);
				
				//rect(buffer,j*80+ x+ 13,i *85 +y + 90,j*80+ x + 90,i *85 +y + 130,makecol(255,255,255));
				
				if ((SCREEN_W/2-100 >= j*80+x+13) && (SCREEN_W/2-100 <= j*80+x+90) &&
					(SCREEN_H/2-100 >= i*85+y+90) && (SCREEN_H/2-100 <= i*85+y+130))
						estado_screen=gama2;
				
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
				
			}else if ((mapa[i][j] == gym1) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
			//	circle(buffer,j* 80 + x + 40,i* 85 + y + 65,50,makecol(255,0,0));
				masked_blit(m,buffer,3 *m_w,1 *m_h,j * 80+x + 4,i *85+y - 3,m_w,m_h);
				
				
				
			}else if((mapa[i][j] == gym2) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,4 *m_w,1 *m_h,j * 80+x+ 13,i *85+y - 5,m_w,m_h + 2);
				
				
			}else if((mapa[i][j] == gym3) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,0 *m_w,2 *m_h + 5,j * 80+x,i *85+y,m_w,m_h);
				
				
			}else if((mapa[i][j] == gym4) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,1 *m_w,2 *m_h + 6,j * 80+x,i *85+y,m_w,m_h);
				
			}else if((mapa[i][j] == gym5) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,2 *m_w,2 *m_h + 5,j * 80+x,i *85+y,m_w,m_h);
				
			}else if((mapa[i][j] == gym6) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,3 *m_w,2 *m_h + 5,j * 80+x,i *85+y,m_w,m_h);
			}else if((mapa[i][j] == gym7) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,4 *m_w,2 *m_h + 5,j * 80+x,i *85+y,m_w,m_h);
				
			}else if((mapa[i][j] == gym8) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,0 *m_w,3 *m_h + 5,j * 80+x,i *85+y,m_w,m_h);
				
			}else if((mapa[i][j] == branco) && (j* 80+x < SCREEN_W) && (j* 80+x >-100) && (i* 85+y < SCREEN_H)&& (i* 85+y > -100)){
				
				masked_blit(m,buffer,1 *m_w,3 *m_h + 5,j * 80+x,i *85+y,m_w,m_h);
				
			}
			
		
		
		
		if ((mapa[i][j] == gym1) || (mapa[i][j] == gym2) || (mapa[i][j] == gym3) || (mapa[i][j] == gym4) || (mapa[i][j] == gym5) || (mapa[i][j] == gym6) || (mapa[i][j] == gym7) || (mapa[i][j] == gym8)){
				//isso aqui não desenha o mapa e sim coloca o x e y dentro da array
				
				if (coni <= conp){
					
					xgym[coni]= j * 80;
					ygym[coni]= i * 85;
					
					coni++;
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

void persotwo(BITMAP *player,BITMAP *buffer,int frame_w,int frame_h,int mile,FONT *fonte){//meu boneco
	
	static int fixa=0,fixa2=0,px=30,py=600;
	
	item(buffer,lojaopen,px,py,fonte);
	
		
		if (px <30)
			px=30;
		else if (px > 940)
			px=940;
		else if (py >600)
			py=600;
		else if (py <387)
			py=387;
	
		//rect(buffer,650,630,990,780,makecol(255,0,0));
	
		if ((px >= 650) && (px <=990) && (py + 30 >=630) && (py <=780)){
			x=0;
			y=0;
			px=30;
			py=600;
			lojaopen=false;
			
		}
	
	
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
			if(p){px+=velx;}else{px-=velx;}
			
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
			if(pp){py-=vely;}else{py+=vely;}
			
			if ((!key[KEY_A]) && (!key[KEY_D]))
			frame=(mile /300) % 4;
			masked_blit(player,buffer,frame * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
		}
	
		if ((!key[KEY_A]) && (!key[KEY_D]) && (!key[KEY_W]) && (!key[KEY_S]) && (velx<0) && (vely<0)){//boneco parado
			
			
			
			
			masked_blit(player,buffer,0 * frame_w,stopf * frame_h,px,py,frame_w,frame_h);
			
		}
	
	
}

void item(BITMAP *buffer,bool lojaa,int px,int py,FONT *fonte){
	static int slot1=0,slot2=0,slot3=0,slot4=0,seleto=0;
	static bool umavez=false;

		srand(time(NULL));
	while ((slot1 == 0) || (slot2 == 0) || (slot3 == 0) || (slot4 == 0)){
		
			seleto= rand() % 10;
		
		if ((seleto != slot1) && (seleto != slot2) && (seleto != slot3) && (seleto != slot4)){
			
			if (slot1 == 0)
				
				slot1 = seleto;
			else if (slot2 == 0)
				
				slot2 = seleto;
			else if (slot3 == 0)
				
				slot3 = seleto;
			else if (slot4 == 0)
				
				slot4 = seleto;
			
			
		}
			
			
			
		}
	
//	circle(buffer,300,400,20,makecol(255,255,0));
//	circle(buffer,320,400,20,makecol(255,255,0));
//	circle(buffer,340,400,20,makecol(255,255,0));
//	circle(buffer,360,400,20,makecol(255,255,0));
	
	switch (slot1){
			
		case 1:
			merda ="sprite/item/1.bmp";
			preco1=30;
			break;
		case 2:
			merda ="sprite/item/2.bmp";
			break;
		case 3:
			merda ="sprite/item/3.bmp";
			break;
		case 4:
			merda ="sprite/item/4.bmp";
			break;
		case 5:
			merda ="sprite/item/5.bmp";
			preco1=5;
			break;
		case 6:
			merda ="sprite/item/6.bmp";
			break;
		case 7:
			merda ="sprite/item/7.bmp";
			break;
		case 8:
			merda ="sprite/item/8.bmp";
			break;
		case 9:
			merda ="sprite/item/9.bmp";
			break;
		case 10:
			merda ="sprite/item/10.bmp";
			break;
			
			
	}


	
	switch (slot2){
			
		case 1:
			merda2 ="sprite/item/1.bmp";
			preco2=30;
			break;
		case 2:
			merda2 ="sprite/item/2.bmp";
			break;
		case 3:
			merda2 ="sprite/item/3.bmp";
			break;
		case 4:
			merda2 ="sprite/item/4.bmp";
			break;
		case 5:
			merda2 ="sprite/item/5.bmp";
			break;
		case 6:
			merda2 ="sprite/item/6.bmp";
			break;
		case 7:
			merda2 ="sprite/item/7.bmp";
			break;
		case 8:
			merda2 ="sprite/item/8.bmp";
			break;
		case 9:
			merda2 ="sprite/item/9.bmp";
			break;
		case 10:
			merda2 ="sprite/item/10.bmp";
			break;
			
			
	}

	
	switch (slot3){
			
		case 1:
			merda3 ="sprite/item/1.bmp";
			preco3=30;
			break;
		case 2:
			merda3 ="sprite/item/2.bmp";
			break;
		case 3:
			merda3 ="sprite/item/3.bmp";
			break;
		case 4:
			merda3 ="sprite/item/4.bmp";
			break;
		case 5:
			merda3 ="sprite/item/5.bmp";
			break;
		case 6:
			merda3 ="sprite/item/6.bmp";
			break;
		case 7:
			merda3 ="sprite/item/7.bmp";
			break;
		case 8:
			merda3 ="sprite/item/8.bmp";
			break;
		case 9:
			merda3 ="sprite/item/9.bmp";
			break;
		case 10:
			merda3 ="sprite/item/10.bmp";
			break;
			
			
	}
	
	
	switch (slot4){
			
		case 1:
			merda4 ="sprite/item/1.bmp";
			preco4=30;
			break;
		case 2:
			merda4 ="sprite/item/2.bmp";
			break;
		case 3:
			merda4 ="sprite/item/3.bmp";
			break;
		case 4:
			merda4 ="sprite/item/4.bmp";
			break;
		case 5:
			merda4 ="sprite/item/5.bmp";
			break;
		case 6:
			merda4 ="sprite/item/6.bmp";
			break;
		case 7:
			merda4 ="sprite/item/7.bmp";
			break;
		case 8:
			merda4 ="sprite/item/8.bmp";
			break;
		case 9:
			merda4 ="sprite/item/9.bmp";
			break;
		case 10:
			merda4 ="sprite/item/10.bmp";
			break;
			
			
	}
	
	if (!umavez){
		
		
	a1= load_bitmap(merda.c_str(),NULL);
	a2= load_bitmap(merda2.c_str(),NULL);
	a3= load_bitmap(merda3.c_str(),NULL);
	a4 = load_bitmap(merda4.c_str(),NULL);
		
		
	}
		
		
	
	umavez=true;
	
	draw_sprite(buffer,a1,300,340);
	draw_sprite(buffer,a2,380,340);
	draw_sprite(buffer,a3,470,340);
	draw_sprite(buffer,a4,560,340);
	
	rect(buffer,330,440,390,500,makecol(255,0,0));
	rect(buffer,410,440,470,500,makecol(255,0,0));
	rect(buffer,490,440,550,500,makecol(255,0,0));
	rect(buffer,570,440,630,500,makecol(255,0,0));
	
	if ((px >= 300) && (px<= 360) && (py>= 400) && (py<= 500))
		textprintf(buffer,fonte,330,330,makecol(255,255,255),"(B) this cost $%d",preco1);
	
	if ((px >= 380) && (px<= 440) && (py>= 400) && (py<= 500))
		textprintf(buffer,font,400,330,makecol(255,255,255),"B");
	
	if ((px >= 460) && (px<= 520) && (py>= 400) && (py<= 500))
		textprintf(buffer,font,480,330,makecol(255,255,255),"B");
	
	if ((px >= 540) && (px<= 600) && (py>= 400) && (py<= 500))
		textprintf(buffer,font,560,330,makecol(255,255,255),"B");
	
	if ((px >= 300) && (px<= 360) && (py>= 400) && (py<= 500) && (aperta[KEY_B])){
		if (rale >= preco1){
			
			rale-=preco1;
			roupa=slot1;
		}
	}
		
	
	if ((px >= 380) && (px<= 440) && (py>= 400) && (py<= 500))
		textprintf(buffer,font,400,330,makecol(255,255,255),"B");
	
	if ((px >= 460) && (px<= 520) && (py>= 400) && (py<= 500))
		textprintf(buffer,font,480,330,makecol(255,255,255),"B");
	
	if ((px >= 540) && (px<= 600) && (py>= 400) && (py<= 500))
		textprintf(buffer,font,560,330,makecol(255,255,255),"B");
	
	if (!lojaa){
		destroy_bitmap(a1);
		destroy_bitmap(a2);
		destroy_bitmap(a3);
		destroy_bitmap(a4);
		umavez=false;
		
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
				
			}else if ((sel == 5) && (!parou)){//aumenta a conquista de ninfa
				
				sex+=3;
				parou=true;
				
				
			}else if ((sel == 6) && (!parou)){// aumenta o exp dos miniman
				
				
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
		}//esse é o deck primeiro
		
				
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

Lista_moeda *create_lista_moeda(){//cria a lista
	
	Lista_moeda* l= (Lista_moeda*) malloc(sizeof(Lista_moeda));
	
	l->inicio=NULL;
	
	return l;
	
	
}

Lista_mini *create_lista_mini(){//cria a lista
	
	Lista_mini* l= (Lista_mini*) malloc(sizeof(Lista_mini));
	
	l->inicio=NULL;
	
	return l;
	
	
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

void destroy_mini (Mini_man *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_mini(Lista_mini *l){
	
	No_mini *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_mini(aux->mi);
		free(aux);
		
	}
	
	
}

void destroy_moeda (Moeda *i){//recebe o objeto
	
	free(i);
	
	
}

void destroy_lista_moeda(Lista_moeda *l){
	
	No_moeda *aux;
	
	while (l->inicio != NULL){
		
		aux= l->inicio;
		l->inicio =l->inicio->prox;
		destroy_moeda(aux->mo);
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


void update_lista_mini(Lista_mini *l,BITMAP *min,BITMAP *buffer,int x,int y,int mile,bool denovo=false,float *posx_ini=0,float *posy_ini=0){
	
	No_mini *aux=l->inicio;
	No_mini *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->mi->ativo){
			
			aux->mi->update(buffer,min,x,y,mile,conp,xgym,ygym,denovo,posx_ini,posy_ini);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_mini(aux->mi);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_mini(aux->mi);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
	}
	
	
}


void update_lista_moeda(Lista_moeda *l,BITMAP *c,BITMAP *buffer){
	
	No_moeda *aux=l->inicio;
	No_moeda *aux2=l->inicio;
	
	while (aux != NULL){
		
		if (aux->mo->ativo){
			
			aux->mo->update(buffer,c);
			aux2=aux;
			aux=aux->prox;
			
		}else{
			if (aux2==aux){
				l->inicio=l->inicio->prox;
				destroy_moeda(aux->mo);
				free(aux);
				aux2=aux=l->inicio;
				
				
			}else{
				
				aux2->prox=aux->prox;
				destroy_moeda(aux->mo);
				free(aux);
				aux=aux2->prox;
				
			}
			
			
			
		}
		
		
		
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

void span_moeda(Lista_moeda *l,int mile){
	static int ip=0,del=mile;
	
	if ((coin) && (mile - del >= 100)){
		
		ip++;

		
	No_moeda *novo= (No_moeda*) malloc(sizeof(No_moeda));
	novo->mo= new Moeda(mile);
	novo->prox=l->inicio;
	l->inicio=novo;
		
	
		if (ip >= 4){
			
		coin=false;
		ip=0;
		rale+=4;
			
		}
	
		del=mile;
	}
	
	
}

void span_mini(Lista_mini *l,int mile,bool ban=false){//configura esse span por os mini-man
	static int ie=0,deu=mile;
	
	if (ban)
		ie=0;
	
	if (ie<=qtdm){
	//if ((coin) && (mile - del >= 100)){
		
	

		
	No_mini *novo= (No_mini*) malloc(sizeof(No_mini));
	novo->mi= new Mini_man();
	novo->prox=l->inicio;
	l->inicio=novo;
		
	
		
	
	ie++;
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
				
					novo->inimi= new Pai(x,y,mile,vida,tam);
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

bool para_floresta(BITMAP *buffer,BITMAP *flor,bool ci){
	
	int m_w=569/5;
	int m_h=411/4;
	int xf=0,yf=1100;
	
	
	masked_blit(flor,buffer,1 * m_w,1 * m_h,xf + x,yf + y,m_w,m_h);
	
	if ((xf + x >= SCREEN_W/2-100) && (xf + x <= SCREEN_W/2) && (yf + y >= SCREEN_H/2-100) && (yf + y <= SCREEN_H/2)){
		ci=true;
		estado_screen=flu;
	
	}else
		ci=false;
	
	return ci;
	
}

void loja(BITMAP *m,BITMAP *buffer,BITMAP *lo){
	int m_w=569/5;
	int m_h=411/4;
	
	if (((500 + x >= SCREEN_W/2-100) &&
		(500 + x <= SCREEN_W/2-50) &&
		(2600 + y >= SCREEN_H/2-100) &&
		(2600 + y <= SCREEN_H/2-50)) || (lojaopen)){
		x=-10000;
		y=-10000;
		lojaopen=true;
		draw_sprite(buffer,lo,0,0);
	}
	
	//rect(buffer,500 + x,500 + y,500 + x,500 + y,makecol(255,255,255));
		
	masked_blit(m,buffer,0 *m_w,1 *m_h,500 + x, 2600 + y,m_w,m_h);
	
}
