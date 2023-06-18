#include <allegro.h>


class Pai{
	
	public:
	float pos_x;
	float pos_y;
	float vel_x;
	float vel_y;
	float ace;
	int wid;
	int hi;
	bool ativo;
	Pai(int x,int y,int mile);
	void update(BITMAP *inimi, BITMAP *buffer,int x, int y);
	
};

typedef struct no_inimi{
	
	Pai *inimi;
	struct no_inimi *prox;
	
	
}No_inimi;


typedef struct lista_inimi{
	
	 No_inimi* inicio;
	
	
	
}Lista_inimi;

class Fadia{
	
	public:
	bool esq,cima,espe;
	int limx,limy;
	int fadia_w,fadia_h,fadia_x,fadia_y;
	int fadia_eixox,quem;
	bool teste,casa;
	void volta(BITMAP *player,BITMAP *buffer);
	void espera(BITMAP *player,BITMAP *buffer,int mile);
	void ataca(BITMAP* player,BITMAP* buffer,Pai *inimi,int x,int y);
	Fadia();
	
	
};

class Compara{
	
	public:
	Compara();
	void colisao(BITMAP* player,BITMAP* buffer,Pai *l,Fadia* f1,int tam,int x,int  y);
	
	
	
	
};

 Compara::Compara(){
	 
	 
	 
	 
 }

	void Compara::colisao(BITMAP* player,BITMAP* buffer,Pai *l,Fadia* f1,int tam,int x,int y){
		
		if (f1->teste){
			
		//	for (int i=0;i<tam;i++){
				
				if ((l->pos_x + x >= f1->fadia_x-600) && 
					(l->pos_x + x <= f1->fadia_x +f1->fadia_w+600) &&
					(l->pos_y + y >= f1->fadia_y-600) &&
					(l->pos_y + y <= f1->fadia_y +f1->fadia_h+600)){
					
					f1->teste=false;
					f1->casa=false;
					f1->espe=true;
				//	f1->quem=i;
					
				}/*else if ((inimi[i]->pos_x + x >= f1->fadia_x) && 
					(inimi[i]->pos_x + x <= f1->fadia_x +f1->fadia_w) &&
					(inimi[i]->pos_y + y >= f1->fadia_y) &&
					(inimi[i]->pos_y + y <= f1->fadia_y +f1->fadia_h)){
					
					
					
				}*/
				
				
				
		//	}
			
			
			
			
		}else if (f1->casa){
			
			
			f1->volta(player,buffer);
			
			
			
		}else{
			
			
			f1->ataca(player,buffer,l,x,y);
		}
		
		
		
	}

	Fadia::Fadia(){
		
		esq=true;
		cima=true;
		espe=false;
		teste=true;
		casa=false;
	 fadia_w=291-262;
	 fadia_h=20;
	 fadia_x=300;
	 fadia_y=400;
	 limx=100;
	 limy=100;
	 fadia_eixox=262;
		
	}

void Fadia::ataca(BITMAP* player,BITMAP* buffer,Pai *l,int x,int y){

			if (this->fadia_x >= l->pos_x+ x){
				
				this->fadia_x-=6;
			}else if (this->fadia_x <= l->pos_x+ x){
				
				this->fadia_x+=6;
				
			}
	
	
			if (this->fadia_y >= l->pos_y+ y){
				
				this->fadia_y-=6;
			}else if (this->fadia_y <= l->pos_y+ y){
				
				this->fadia_y+=6;
				
			}
	
	
				if ((this->fadia_x >= l->pos_x+ x) &&
				   	(this->fadia_x <= l->pos_x+ x + l->wid)&&
				    (this->fadia_y >= l->pos_y+ y)&&
				    (this->fadia_y <= l->pos_y+ y +l->hi)){
					
					l->ativo=false;
					
				
					this->casa=true;
						
					
				}
	
			
			masked_blit(player,buffer,fadia_eixox,471,fadia_x,fadia_y,fadia_w,fadia_h);


}

void Fadia::volta(BITMAP *player,BITMAP *buffer){
	
	if (this->fadia_x <= SCREEN_W/2){
		
		
		this->fadia_x+=2;
	}
	
	if (this->fadia_x >= SCREEN_W/2){
		
		
		this->fadia_x-=2;
	}
	
	
	
	if (this->fadia_y <= SCREEN_H/2){
		
		
		this->fadia_y+=2;
	}
	
	if (this->fadia_y >= SCREEN_H/2){
		
		
		this->fadia_y-=2;
	}
	
	if (fadia_x == 599)
		fadia_x=600;
	if (fadia_y == 399)
		fadia_y=400;
	
	
	if ((this->fadia_x >= SCREEN_W/2-200) &&
		(this->fadia_x <= SCREEN_W/2+4) &&
		(this->fadia_y >= SCREEN_H/2-200) &&
	   (this->fadia_y <= SCREEN_H/2+4)){
		
		
		this->espe=false;
		this->casa=false;
		this->teste=true;
	}
	textprintf(buffer,font,fadia_x-20,fadia_y-20,makecol(255,255,255),"volta: %d %d",fadia_x,fadia_y);
	masked_blit(player,buffer,fadia_eixox,471,fadia_x,fadia_y,fadia_w,fadia_h);
}


void Fadia::espera(BITMAP *player,BITMAP *buffer,int mile){
	static int macador= mile;
	
	//lado horizontal da fada
	if (!this->espe){
	
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
	
	if (mile - macador >= 200){
		
		if (fadia_eixox == 262){
			
			fadia_eixox=299;
			
		}else{
			
			
			fadia_eixox=262;
		}
		
		macador=mile;
		
	}
	
		masked_blit(player,buffer,fadia_eixox,471,fadia_x,fadia_y,fadia_w,fadia_h);
	}
		
}

	Pai::Pai(int x, int y,int mile){
		
		srand(time(NULL));
		pos_x=   rand() % 2000;
		srand(mile);
		pos_y= rand() % 2000;
		ace=0.10;
		vel_x=ace;
		vel_y=ace;
		wid=416/4;
		hi=618/8;
		ativo=true;
	}


void Pai::update(BITMAP *inimi, BITMAP *buffer,int x, int y){
	
	
	
	if (this->pos_x + x >= SCREEN_W/2-100){
		
		
		this->pos_x-=this->vel_x;
		if (this->vel_x <=6){
			
			this->vel_x+=this->ace;
		
		}else if (this->pos_x + x == SCREEN_W/2-100){this->vel_x=0;}
		
	}else if (this->pos_x + x <= SCREEN_W/2-100){
		
		this->pos_x+=this->vel_x;
		if (this->vel_x <=6){
			
			this->vel_x+=this->ace;
							
							
		}else if (this->pos_x + x == SCREEN_W/2-100){this->vel_x=0;}
		
	}
	
	if (this->pos_y + y>= SCREEN_H/2-100){
		
		
		this->pos_y-=this->vel_y;
		
		if (this->vel_y <=6){
			
			this->vel_y+=this->ace;
							
							
		}else if (this->pos_y + y == SCREEN_H/2-100){this->vel_y=0;}
		
	}else if (this->pos_y + y <= SCREEN_H/2-100){
		
		this->pos_y+=this->vel_y;
		
		if (this->vel_y <=6){
			
			this->vel_y+=this->ace;
							
							
		}else if (this->pos_y + y == SCREEN_H/2-100){this->vel_y=0;}
		
	}
	
	masked_blit(inimi,buffer,0 * this->wid, 0 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
	
}