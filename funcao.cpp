#include "h/funcao.h"

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
void perso(){
	
	
	if ((key[KEY_D]) || (p>=0)){
		
		if ((p<=8) && (key[KEY_D])){
			p++;
			x+=p;
			
		}else{
			
			p--;
			x+=p;
		}
	}else if((key[KEY_A]) || (p2<=0)){
		
		if ((p2>=-8) && (key[KEY_A])){
			p2--;
			x+=p2;
			
		}else{
			
			p2++;
			x+=p2;
		}
	}else if((key[KEY_W]) || (p3<=0)){
		
		if ((p3>=-20) && (key[KEY_W])){
			p3--;
			y+=p3;
			
		}else{
			
			p3++;
			y+=p3;
		}
		
	}else if((key[KEY_S]) || (p4>=0)){
		
		if ((p4<=8) && (key[KEY_S])){
			p4++;
			y+=p4;
			
		}else{
			
			p4--;
			y+=p4;
		}
	}
	
	
}