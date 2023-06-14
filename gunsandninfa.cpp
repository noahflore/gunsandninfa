#include <allegro.h>
#include "funcao.cpp"


/* o personagem pode se mexer no cenario fechado 
	mulheres engravida e recruta soldado
	
	*/

volatile bool fecha= false;
volatile int fps= 0,mile=0;
int estado_screen=titula;
	


void fechajanela();
void allegro_start(char *title,int height,int width);
void tempo_do_sistema();
void ani();
void titulo();
void menu();
void game();



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
	
	
	
	//MIDI* musica= load_midi("music/musica.midi");
	
	
	
	
	
//	play_midi(musica,TRUE);
	while(!fecha){
		
		while (fps>=1){
			
			
			if (estado_screen==mena){
				
				menu();
				
			}else if (estado_screen==titula){
				
				titulo();
				
			}else if (estado_screen==gama){
				
				game();
			}
		
		}
	}
	
	allegro_exit();
	return 0;	
}

END_OF_MAIN();

void titulo(){
	
	bool ti=false;
	
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	
	while ((!fecha) && (!ti)){
		
		while(fps>=1){
			atualiza_tecla();
			
			if (aperta(KEY_ENTER)){
				
				ti=true;
				estado_screen=gama;
				
			}
			textout_centre_ex(buffer,font,"titulo inicial",SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1);
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			
			fps--;
		}
		
		
		
		
	}
	destroy_bitmap(buffer);
	
	
	
}
void menu(){
	
	bool me=false;
	
	while ((!fecha) && (!me)){
		
		while (fps>=1){
			
			atualiza_tecla();
			if (aperta(KEY_ESC)){me=true;estado_screen=gama;}
			
			
			
			fps--;
		}
		
		
		
	}
	
	
}

void game(){
	
	bool ga=false;
	int linha,coluna;
	int ** mapa=carrega_mapa("mapa.txt",&linha,&coluna);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* player= load_bitmap("sprite/spritemaleman.bmp",NULL);
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* inimi=load_bitmap("sprite/spriteinimigo.bmp",NULL);
	
	int frame_w=259/4;
	int frame_h=305/4,i=0;
	
	
	Fadia *f1= new Fadia();
	Compara *com= new Compara();
	
	//	if ( ini == NULL)
			//Pai *ini[20];
		//	tam=0;
			
		while((!fecha) && (!ga)){
		
		while (fps>=1){
			
			atualiza_tecla();
			if (aperta(KEY_ESC)){ga=true;estado_screen=mena;}
			span(x,y,mile,qtd);// spana inimigo
			



			desenha_mapa(m,buffer,mapa,linha,coluna);
			atua(inimi, buffer);//atualiza inimigos
			for (int t=0;t<tam;t++)
			com->colisao(player,buffer,&ini[t],f1,tam,x,y);
			
			perso(player,buffer,frame_w,frame_h,mile);
			f1->espera(player,buffer,mile);
			rectfill(buffer,800+x,400+y,840+x,440+y,makecol(255,0,0));
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			fps--;
		}
	}
	
//	destroy_midi(musica);
	for (int i=0;i<tam;i++)
	if (fecha){free(ini[i]);}
	free(f1);
	fecha_mapa(mapa,linha);
	destroy_bitmap(inimi);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_bitmap(buffer);

}

	
	
	
	

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