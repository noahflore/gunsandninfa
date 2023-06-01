#include <allegro.h>
#include "funcao.cpp"

/* o personagem pode se mexer no cenario fechado 
	mulheres engravida e recruta soldado
	
	*/

volatile bool fecha= false;


void fechajanela();
void allegro_start(char *title,int height,int width);

int main(){
	allegro_start("guns and ninfa",1200,800);
	LOCK_VARIABLE(fecha);
	LOCK_FUNCTION(fechajanela);
	set_close_button_callback(fechajanela);
	
	
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	
	while(!fecha){
		atualiza_tecla();
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