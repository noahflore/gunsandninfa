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
	virtual void update(BITMAP *inimi, BITMAP *buffer,int x, int y);
	
};

typedef struct no_inimi{
	
	Pai *inimi;
	struct no_inimi *prox;
	
	
}No_inimi;


typedef struct lista_inimi{
	
	 No_inimi* inicio;
	
	
	
}Lista_inimi;

class Ninfa{//lembra de fazer a lista encadeada
	
	public:
	
	float pos_x;
	float pos_y;
	float vel_x;
	float vel_y;
	float limx;
	float limy;
	float ace;
	float varx;
	float vary;
	int wid,dee,dess,frame_w,frame_h;
	int hi,hp,tx,ty,tempox,tempoy,mysex;
	bool ativo,esq,cima,pare,spare;
	int hit;

		Ninfa(int mile){
	
		srand(time(NULL));
		this->pos_x= rand() % 3000;
		srand(mile);
		this->pos_y= rand() % 3000;
		this->mysex= rand() % 100;
		this->limx=this->pos_x;
		this->limy=this->pos_y;
		this->varx=300;
		this->vary=300;
		this->ace= 0.2;
		this->tx=0;
		this->ty=0;
		this->tempox=0;
		this->tempoy=0;
		this->vel_x= ace;
		this->vel_y= ace;
		this->frame_w=222/4;
		this->frame_h=400/3;
		this->ativo=true;
		this->esq=true;
		this->cima=true;
		this->pare=false;
		this->spare=true;
	
	
	
	}
	
	void update(BITMAP *ni, BITMAP *buffer,int x, int y,int mile,int sex){
		
		if ((this->pos_x + x <= SCREEN_W/2+300) || (this->pos_x + x >= SCREEN_W/2-500)
			|| (this->pos_y + y <= SCREEN_H/2+300) || (this->pos_y + y >= SCREEN_H/2-500)){
		
				
				this->atracao(ni,buffer,x,y,mile,sex);
			
			//this->espera(ni,buffer,x,y,mile);
			
		}else {
			
			this->espera(ni,buffer,x,y,mile);
			
		}
	}
	
	void atracao(BITMAP *ni,BITMAP *buffer, int x, int y, int mile,int sex){
		
		
		if (this->vel_x < 4)
			this->vel_x+=this->ace;
		
		if (this->vel_y < 4)
			this->vel_y+=this->ace;
		
		if ((sex >= this->mysex - 10) &&  (sex < this->mysex))
			this->espera(ni,buffer,x,y,mile);
		
		if (sex < this->mysex - 10){//ninfas foge
			
			if (this->pos_x + x < SCREEN_W/2-100)
				this->pos_x-=this->vel_x;
			
			if (this->pos_x + x > SCREEN_W/2-100)
				this->pos_x+=this->vel_x;
			
			if (this->pos_y + y < SCREEN_H/2-100)
				this->pos_y-=this->vel_y;
			
			if (this->pos_y + y > SCREEN_H/2-100)
				this->pos_y+=this->vel_y;
			
			
			
		}
		
		if ((sex >= this->mysex) && (!this->pare)){//ninfas atraindas
			
			if (this->pos_x + x < SCREEN_W/2-100)
				this->pos_x+=this->vel_x;
			
			if (this->pos_x + x > SCREEN_W/2-100)
				this->pos_x-=this->vel_x;
			
			if (this->pos_y + y < SCREEN_H/2-100)
				this->pos_y+=this->vel_y;
			
			if (this->pos_y + y > SCREEN_H/2-100)
				this->pos_y-=this->vel_y;
			
			masked_blit(ni,buffer,0,0,this->pos_x + x,this->pos_y + y,64,130);
		}
		
		if (((this->pos_x + x >= SCREEN_W/2-100) &&
			 (this->pos_x + x <= SCREEN_W/2-60) &&
			(this->pos_y + y >= SCREEN_H/2-100) &&
			(this->pos_y + y <= SCREEN_H/2-50)) || (pare)){
			
			this->pare=true;
			if ((this->pare) && (this->spare)){
				qtdm++;
				this->spare=false;
				
			}
			masked_blit(ni,buffer,1 * this->frame_w,0,this->pos_x + x,this->pos_y + y,this->frame_w,this->frame_h);
			
		}
		
		
	}
	
	void espera(BITMAP *ni, BITMAP *buffer,int x, int y,int mile){
		static int salto=0,cor1=0;
		
		if (this->pos_x + x == this->limx + x){
			
			srand(mile);
			this->esq= rand() % 2;
			this->varx=rand() % 300;
			this->tempox= rand() % 500;
			
		}
		
		if (this->pos_y + y == this->limy + y){
			
			srand(time(NULL));
			this->cima= rand() % 2;
			this->vary=rand() % 300;
			this->tempoy= rand() % 500;
			
		}
		
		if (mile - tx >= tempox){
			
			if ((this->pos_x + x >= this->limx + x - 300) && (this->esq))
				this->pos_x--;

			if ((this->pos_x + x <= this->limx + x + 300) && (!this->esq))
				this->pos_x++;
			this->tx=mile;
		}
		
		if (mile - ty >= tempoy){
			
			if ((this->pos_y + y >= this->limy + y - 300) && (this->cima))
				this->pos_y--;

			if ((this->pos_y + y <= this->limy + y + 300) && (!this->cima))
				this->pos_y++;
		
			this->ty=mile;
		}
		
		if (this->pos_x + x < this->limx + x - this->varx)
			this->esq=false;
		
		if (this->pos_x + x > this->limx + x + this->varx)
			this->esq=true;
		
		if (this->pos_y + y < this->limy + y - this->vary)
			this->cima=false;
		
		if (this->pos_y + y > this->limy + y + this->vary)
			this->cima=true;
		
		if ((!this->esq) && (!this->cima)){
			
			salto=(mile/tempoy) % 4;
			if (salto == 2)
				cor1=5;
			else
				cor1=0;
			masked_blit(ni,buffer,salto * this->frame_w,2 * this->frame_h,this->pos_x + x,this->pos_y + y,this->frame_w - cor1,this->frame_h);
		}
		
		if ((this->esq) && (!this->cima)){
			
			salto=(mile/tempoy) % 4;
			if (salto == 2)
				cor1=5;
			else
				cor1=0;
			masked_blit(ni,buffer,salto * this->frame_w,1 * this->frame_h,this->pos_x + x,this->pos_y + y,this->frame_w - cor1,this->frame_h);
		}
		
		if ((!this->esq) && (this->cima)){
			
			salto=(mile/tempoy) % 4;
			if (salto == 2)
				cor1=5;
			else
				cor1=0;
			masked_blit(ni,buffer,salto * this->frame_w,3 * this->frame_h + 3,this->pos_x + x,this->pos_y + y,this->frame_w - cor1,this->frame_h);
		}
		
		if ((this->esq) && (this->cima)){
			
			salto=(mile/tempoy) % 4;
			if (salto == 2)
				cor1=5;
			else
				cor1=0;
			masked_blit(ni,buffer,salto * this->frame_w,4 * this->frame_h + 9,this->pos_x + x,this->pos_y + y,this->frame_w - cor1,this->frame_h);
		}
		
	}
	
	
};

typedef struct no_ninfa{
	
	Ninfa *nina;
	struct no_ninfa *prox;
	
	
}No_ninfa;


typedef struct lista_ninfa{
	
	 No_ninfa* inicio;
	
	
	
}Lista_ninfa;

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


class Moeda{
	public:
	
	float pos_x,pos_y,vel_x,vel_y,ace;
	bool cima,esq,ativo;
	
	Moeda(int mile){
		pos_x=SCREEN_W/2-100;
		pos_y=SCREEN_H/2-100;
		ace=0.3;
		vel_x=10;
		vel_y=10;
		srand(time(NULL));
		cima= rand() % 2;
		srand(mile);
		esq= rand() % 2;
		ativo=true;
		
	}
	
	void update(BITMAP *buffer,BITMAP *c){
		
		this->anima(buffer,c);
	}
	
	void anima(BITMAP *buffer,BITMAP *c){
		
		if (cima)
			this->pos_y-=this->vel_y;
		else
			this->pos_y+=this->vel_y;
		
		if (esq)
			this->pos_x-=this->vel_x;
		else
			this->pos_x+=this->vel_x;
		
		this->vel_x-=this->ace;
		this->vel_y-=this->ace;
		
		
		
		draw_sprite(buffer,c,this->pos_x,this->pos_y);
		
		if ((this->vel_x <= 0) || (this->vel_y <=0))
			this->ativo=false;
	}
	
};

typedef struct no_moeda{
	
	Moeda *mo;
	struct no_moeda *prox;
	
	
}No_moeda;


typedef struct lista_moeda{
	
	 No_moeda* inicio;
	
	
	
}Lista_moeda;

class Mini_man{
	public:
	
	float pos_x,pos_y,vel_x,vel_y,ace,da,db;
	int w,h,frame,p,i;
	bool ativo,ani;
	
	Mini_man(){
		
		pos_x=1100;
		pos_y=-20;
		p=1;
		i=1;
		ace=0.1;
		vel_x=ace;
		vel_y=ace;
		da=0;
		db=0;
		ativo=true;
		ani=false;
		w=102/4;
		h=85/2;
		
		
	}
	
	void update(BITMAP *buffer,BITMAP *min,int x,int y,int mile,int conp,float xgym[],float ygym[]){
		
		if (ani){
			this->ani=true;
			this->caminha(buffer,min,x,y,mile);
			
		}else
		 this->centro(buffer,min,x,y,mile);
		
		this->obst(x,y,conp,xgym,ygym);
		this->fale_mini(min,buffer,x,y);
	}
	
	void centro(BITMAP *buffer,BITMAP *min,int x,int y,int mile){
		
		if (this->pos_y + y < 1000 + y)
			this->pos_y+= this->vel_y;
		
		if (this->pos_y + y >= 1000 + y){//isso precisa se ajustado
			
			this->ani=true;
			srand(time(NULL));
			this->pos_x= rand () % 4600;
			srand(mile);
			this->pos_y= rand () % 2700;
			
			this->i = -i;
			this->p = -p;
			
			if (this->pos_x <=720)
				this->pos_x=720;
			
			if (this->pos_y <=420)
				this->pos_y=420;
			
		}
		
		if (((mile/200) % 2 == 1))
		this->vel_y+=this->ace;
		
		this->frame= (mile/200) % 4;
		masked_blit(min,buffer,this->frame * this->w,0,this->pos_x + x,this->pos_y + y,this->w,this->h);
		
	}
	
	void caminha(BITMAP *buffer,BITMAP *min,int x, int y, int mile){
		
		if (this->pos_x + x <= 720 + x)
			this->i= -i;
		
		if (this->pos_x + x >= 4600 + x)
			this->i= -i;
		
		if (this->pos_y + y <= 420 + y)
			this->p= -p;
		
		if (this->pos_y + y >= 2700 + y)
			this->p= -p;
		
		this->pos_x+=this->i;
		this->pos_y+=this->p;
		
		circle(buffer,this->pos_x + x,this->pos_y + y,50,makecol(255,0,0));//colisÃ£o circula
		this->frame= (mile/200) % 4;
		masked_blit(min,buffer,this->frame * this->w,0,this->pos_x + x,this->pos_y + y,this->w,this->h);
	}
	
	void obst(int x,int y,int conp,float xgym[],float ygym[]){//colisão dentro da matriz
		
		for (int i=0;i<= conp;i++){
			
			if ((xgym[i] !=0) && (ygym[i] !=0)){//corrigido
			
				this->da=((this->pos_x + x) - (xgym[i] + x +40))* ((this->pos_x + x) - (xgym[i] + x +40));
				this->db=((this->pos_y + y) - (ygym[i] + y +65)) * ((this->pos_y + y) - (ygym[i] + y +65));
				
				if ((this->da + this->db <= (50 + 50) * (50 + 50))){

					if (this->pos_x + x < xgym[i] + x )
						this->i= -1;
					if (this->pos_x + x  > xgym[i] + x )
						this->i=1;
					if (this->pos_y + y < ygym[i] + y )
						this->p=-1;
					if (this->pos_y + y > ygym[i] + y )
						this->p=1;
				}
				
			}
			
		}
		
		
		
	}
	
	
void fale_mini(BITMAP *min,BITMAP *buffer,int x,int y){//precisa se corrigido
	
	//rectfill(buffer,SCREEN_W/2,SCREEN_H/2-100,SCREEN_W/2+100,SCREEN_H/2,makecol(255,255,255));
	
	if ((this->pos_x + x - 720 >=SCREEN_W/2) && (this->pos_x + x - 720 <= SCREEN_W/2+100)
		&& (this->pos_y + y - 420 >=SCREEN_H/2-100) && (this->pos_y + y - 420 <=SCREEN_H/2)){
		
		rectfill(buffer,50,50,50,50,makecol(255,255,255));
		
	}
	
	
}
	
};

typedef struct no_mini{
	
	Mini_man *mi;
	struct no_mini *prox;
	
	
}No_mini;


typedef struct lista_mini{
	
	 No_mini* inicio;
	
	
	
}Lista_mini;


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
					
					l->hp-=this->hit;
					if (l->hp <= 0){
					l->ativo=false;
					coin=true;
					}
					
				
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
	
	if (this->pos_y + y> SCREEN_H/2-100){
		
		
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
		
		if ((this->pos_y + y> SCREEN_H/2-90) && (this->pos_x + x >= SCREEN_W/2-110) && (this->pos_x + x <= SCREEN_W/2-100 + this->wid))
	masked_blit(inimi,buffer,0 * this->wid, 3 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
		
	}
	
	if (this->pos_y + y <= SCREEN_H/2-100){
		
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
		
		if ((this->pos_x + x >= SCREEN_W/2-110) && (this->pos_x + x <= SCREEN_W/2-100+ this->wid))
	masked_blit(inimi,buffer,0 * this->wid, 0 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
		
	
	
	}	
}