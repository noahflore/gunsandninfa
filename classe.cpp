#include <allegro.h>


class Pai{
	
	public:
	float pos_x;
	float pos_y;
	float vel_x;
	float vel_y;
	float ace;
	int wid,dee,dess;
	int hi,hp;
	bool ativo;
	int hit;
	Pai(int x,int y,int mile,int vida);
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
	bool esq,cima,espe,ativo;
	int limx,limy,me;
	int fadia_w,fadia_h,fadia_x,fadia_y,velx,vely,escudo,hit;
	int fadia_eixox,quem;
	bool teste,casa;
	void volta(BITMAP *player,BITMAP *buffer);
	void espera(BITMAP *player,BITMAP *buffer,int mile);
	void ataca(BITMAP* player,BITMAP* buffer,Pai *inimi,int x,int y);
	Fadia(int vx,int vy,int ht,int es,int index);
	
	
};

typedef struct no_fad{
	
	Fadia *fad;
	struct no_fad *prox;
	
	
}No_fad;


typedef struct lista_fad{
	
	 No_fad* inicio;
	
	
	
}Lista_fad;


class Compara{
	
	public:
	Compara();
	void colisao(BITMAP* player,BITMAP* buffer,Pai *l,Fadia* f1,int tam,int x,int  y);
	
	
	
	
};

 Compara::Compara(){
	 
	 
	 
	 
 }

	void Compara::colisao(BITMAP* player,BITMAP* buffer,Pai *l,Fadia* f1,int tam,int x,int y){
		
		if ((f1->teste)  && (l->hit == NULL)){
			
		//	for (int i=0;i<tam;i++){
				
				if ((l->pos_x + x >= f1->fadia_x-600) && 
					(l->pos_x + x <= f1->fadia_x +f1->fadia_w+600) &&
					(l->pos_y + y >= f1->fadia_y-600) &&
					(l->pos_y + y <= f1->fadia_y +f1->fadia_h+600)){
					
					f1->teste=false;
					f1->casa=false;
					f1->espe=true;
					l->hit=f1->me;
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

	Fadia::Fadia(int vx,int vy,int ht,int es,int index){
		
		srand(time(NULL));
		esq=true;
		cima=true;
		espe=false;
		teste=true;
		casa=false;
		ativo=true;
		velx=vx;
		vely=vy;
		hit=ht;
		escudo=es;
		me=index;
	 fadia_w=291-262;
	 fadia_h=20;
	 fadia_x= rand() % 300;
	 fadia_y= rand() % 400;
	 limx=100;
	 limy=100;
	 fadia_eixox=262;
		
	}

void Fadia::ataca(BITMAP* player,BITMAP* buffer,Pai *l,int x,int y){

	if (l->hit == this->me){
		
		
			if (this->fadia_x >= l->pos_x+ x){
				
				this->fadia_x-=velx;
			}else if (this->fadia_x <= l->pos_x+ x){
				
				this->fadia_x+=velx;
				
			}
	
	
			if (this->fadia_y >= l->pos_y+ y){
				
				this->fadia_y-=vely;
			}else if (this->fadia_y <= l->pos_y+ y){
				
				this->fadia_y+=vely;
				
			}
	
	
				if ((this->fadia_x >= l->pos_x+ x) &&
				   	(this->fadia_x <= l->pos_x+ x + l->wid)&&
				    (this->fadia_y >= l->pos_y+ y)&&
				    (this->fadia_y <= l->pos_y+ y +l->hi)){
					
					l->hp--;
					if (l->hp <= 0)
					l->ativo=false;
					
				
					this->casa=true;
						
					
				}
	
			
			masked_blit(player,buffer,fadia_eixox,471,fadia_x,fadia_y,fadia_w,fadia_h);
	}


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

	Pai::Pai(int x, int y,int mile,int vida){
		
		srand(mile);
		pos_x=   rand() % 10000;
		srand(mile);
		pos_y= rand() % 2000;
		ace=0.01;
		vel_x=ace;
		vel_y=ace;
		wid=416/4;
		hi=618/8;
		hp=vida;
		dee=0;
		dess=0;
		ativo=true;
		hit=false;
	}


void Pai::update(BITMAP *inimi, BITMAP *buffer,int x, int y){
	
	
	
	if ((this->pos_x + x >= SCREEN_W/2-100) && ((this->pos_x + x > SCREEN_W/2-100) || (this->pos_x + x >= SCREEN_W/2-100+ this->wid))){
		
		
		this->pos_x-=this->vel_x;
		if ((this->vel_x <=2) && (!this->dess)){
			
			this->vel_x+=this->ace;
							
							
		}else if (this->dess){
			
			if (this->vel_x >=0){
			
			this->vel_x-=this->ace;
			
			if (this->vel_x <=0)
				this->dess=false;
		}else if (this->pos_x + x == SCREEN_W/2-100){this->dess=true;}
		
		
	}
		masked_blit(inimi,buffer,0 * this->wid, 1 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
		
	}else if ((this->pos_x + x <= SCREEN_W/2-100) && ((this->pos_x + x <= SCREEN_W/2-110) || (this->pos_x + x >= SCREEN_W/2-100+ this->wid))){
		
		this->pos_x+=this->vel_x;
		if ((this->vel_x <=2) && (!this->dess)){
			
			this->vel_x+=this->ace;
							
							
		}else if (this->dess){
			
			if (this->vel_x >=0){
			
			this->vel_x-=this->ace;
			
			if (this->vel_x <=0)
				this->dess=false;
		}else if (this->pos_x + x == SCREEN_W/2-100){this->dess=true;}
		
		
	}
		masked_blit(inimi,buffer,0 * this->wid, 2 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
		
	}
	
	if ((this->pos_y + y> SCREEN_H/2-100) && (this->pos_x + x >= SCREEN_W/2-110) && (this->pos_x + x <= SCREEN_W/2-100 + this->wid)){
		
		
		this->pos_y-=this->vel_y;
	
		if ((this->vel_y <=2) && (!this->dee)){
			
			this->vel_y+=this->ace;
							
							
		}else if (this->dee){
			
				if (this->vel_y >=0){

				this->vel_y-=this->ace;

				if (this->vel_y <=0)
					this->dee=false;
			}else if (this->pos_y + y == SCREEN_H/2-100){this->dee=true;}
		
		}
		
		if (this->pos_y + y> SCREEN_H/2-90)
	masked_blit(inimi,buffer,0 * this->wid, 3 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
		
	}
	
	if ((this->pos_y + y <= SCREEN_H/2-100) && (this->pos_x + x >= SCREEN_W/2-110) && (this->pos_x + x <= SCREEN_W/2-100+ this->wid)){
		
		this->pos_y+=this->vel_y;
		
		if ((this->vel_y <=2) && (!this->dee)){
			
			this->vel_y+=this->ace;
							
							
		}else if (this->dee){
			
			if (this->vel_y >=0){
			
			this->vel_y-=this->ace;
			
			if (this->vel_y <=0)
				this->dee=false;
		}else if (this->pos_y + y == SCREEN_H/2-100){this->dee=true;}
		
		}
		
	masked_blit(inimi,buffer,0 * this->wid, 0 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
		
	
	
	}	
}