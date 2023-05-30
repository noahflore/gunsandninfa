#include <allegro.h>

/* o personagem pode se mexer no cenario fechado 
	mulheres engravida e recruta soldado
	
	*/

volatile bool fecha= false;
int x=1,y=1,p=1,p2=1,p3=1,p4=1;

void fechajanela();
void allegro_start(char *title,int height,int width);
void perso();


int main(){
	allegro_start("guns and women",1200,800);
	LOCK_VARIABLE(fecha);
	LOCK_FUNCTION(fechajanela);
	set_close_button_callback(fechajanela);
	
	
	BITMAP* buffer= create_bitmap(1200,800);
	
	while(!fecha){
		
		perso();
		rectfill(buffer,800+x,400+y,840+x,440+y,makecol(255,0,0));
		draw_sprite(screen,buffer,0,0);
		clear(buffer);
		
	}
	
	
	destroy_bitmap(buffer);
	allegro_exit();
	return 0;	
}

END_OF_MAIN();

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
		
		if ((p3>=-8) && (key[KEY_W])){
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


void allegro_start(char *title,int height,int width){
	
	
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,height,width,0,0);
	set_window_title(title);
	
	install_keyboard();
	install_timer();
	
	
	
	
	
}


void fechajanela(){
	
	fecha=true;
}
END_OF_FUNCTION(fechajanela);