
class Pai{
	
	public:
	float pos_x;
	float pos_y;
	float vel_x;
	float vel_y;
	float ace;
	int wid;
	int hi;
	Pai(int x,int y,int mile);
	void update(BITMAP *inimi, BITMAP *buffer,int x, int y);
	
};

class Fadia{
	
	public:
	bool esq,cima;
	int limx,limy;
	int fadia_w,fadia_h,fadia_x,fadia_y;
	int fadia_eixox;
	void espera(BITMAP *player,BITMAP *buffer,int mile);
	Fadia();
	
	
};

	Fadia::Fadia(){
		
		esq=true;
		cima=true;
	 fadia_w=291-262;
	 fadia_h=20;
	 fadia_x=300;
	 fadia_y=400;
	 limx=100;
	 limy=100;
	 fadia_eixox=262;
		
	}

void Fadia::espera(BITMAP *player,BITMAP *buffer,int mile){
	static int macador= mile;
	
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

	Pai::Pai(int x, int y,int mile){
		
		srand(time(NULL));
		pos_x=   rand() % 500;
		srand(mile);
		pos_y= rand() % 500;
		ace=0.10;
		vel_x=ace;
		vel_y=ace;
		wid=416/4;
		hi=618/8;
	}


void Pai::update(BITMAP *inimi, BITMAP *buffer,int x, int y){
	
	
	masked_blit(inimi,buffer,0 * this->wid, 0 * this->hi,this->pos_x + x,this->pos_y + y,this->wid,this->hi);
	
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
	
	
}