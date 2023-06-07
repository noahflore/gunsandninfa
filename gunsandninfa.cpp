#include <allegro.h>
#include "funcao.cpp"

/* o personagem pode se mexer no cenario fechado 
	mulheres engravida e recruta soldado
	
	*/

volatile bool fecha= false;
volatile int fps= 0,mile;

	


void fechajanela();
void allegro_start(char *title,int height,int width);
void tempo_do_sistema();
void ani();



int main(){
	allegro_start("guns and ninfa",1200,800);
	LOCK_VARIABLE(fecha);
	LOCK_FUNCTION(fechajanela);
	LOCK_VARIABLE(fps);
	LOCK_FUNCTION(tempo_do_sistema);
	LOCK_VARIABLE(mile);
	LOCK_FUNCTION(ani);
	
	install_int_ex(tempo_do_sistema,BPS_TO_TIMER(60));
	install_int_ex(ani,MSEC_TO_TIMER(1));
	set_close_button_callback(fechajanela);
	
	
	BITMAP* player= load_bitmap("sprite/spritemaleman.bmp",NULL);
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	
	//MIDI* musica= load_midi("music/musica.midi");
	
	
	
	int frame_w=259/4;
	int frame_h=305/4;
	
//	play_midi(musica,TRUE);
	while(!fecha){
		
		while (fps>=1){
			
			atualiza_tecla();
			perso(player,buffer,frame_w,frame_h,mile);






			rectfill(buffer,800+x,400+y,840+x,440+y,makecol(255,0,0));
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			fps--;
		}
	}
	
//	destroy_midi(musica);
	destroy_bitmap(player);
	destroy_bitmap(buffer);
	allegro_exit();
	return 0;	
}

END_OF_MAIN();


void tempo_do_sistema(){fps++;}
END_OF_FUNCTION(tempo_do_sistema);


void allegro_start(char *title,int height,int width){
	
	
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,height,width,0,0);
	set_window_title(title);
	
//	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	install_keyboard();
	install_timer();
	
	
	
	
	
}


void fechajanela(){
	
	fecha=true;
}
END_OF_FUNCTION(fechajanela);

void ani(){mile++;}
END_OF_FUNCTION(ani);