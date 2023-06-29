#include <allegro.h>
#include <logg.h>
#include "h/classe.h"
#include "h/funcao.h"
#include "funcao.cpp"



/* o personagem pode se mexer no cenario fechado 
	mulheres engravida e recruta soldado
	
	*/

volatile bool fecha= false;
volatile int fps= 0,mile=0;

	


void fechajanela();
void allegro_start(char *title,int height,int width);
void tempo_do_sistema();
void ani();
void titulo();
void menu();
void game();
void carta();
void gameover();


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
	
	
	
	
	while(!fecha){
		
		while (fps>=1){
			
			
			if (estado_screen==mena){
				
				menu();
				
			}else if (estado_screen==titula){
				
				titulo();
				
			}else if (estado_screen==gama){
				
				game();
			}else if (estado_screen==muda){
				
				carta();
				
			}else if(estado_screen==over){
				
				gameover();
			}
		
		}
	}
	
	allegro_exit();
	return 0;	
}

END_OF_MAIN();

void gameover(){
	
	bool ov=false;
	ga=false;
	
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	
	while ((!fecha) && (!ov)){
		
		while(fps>=1){
			atualiza_tecla();
			
			if (aperta(KEY_ENTER)){
				
				ov=true;
				estado_screen=gama;
				
			}
			textout_centre_ex(buffer,font,"game over",SCREEN_W/2,SCREEN_H/2,makecol(255,255,255),-1);
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			
			fps--;
		}
		
		
		
		
	}
	destroy_bitmap(buffer);
	
	
	
}


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
	ga=false;
	
	while ((!fecha) && (!me)){
		
		while (fps>=1){
			
			atualiza_tecla();
			if (aperta(KEY_ESC)){me=true;estado_screen=gama;}
			
			
			
			fps--;
		}
		
		
		
	}
	
	
}

void game(){
	
	
	parou=false;
	int linha,coluna;
	int ** mapa=carrega_mapa("mapa.txt",&linha,&coluna);
	FONT *asman=load_font("fonte/asman.pcx",NULL,NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* player= load_bitmap("sprite/spritemaleman.bmp",NULL);
	BITMAP* grande= load_bitmap("sprite/escudo.bmp",NULL);
	BITMAP* life= load_bitmap("sprite/life.bmp",NULL);
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* inimi=load_bitmap("sprite/spriteinimigo.bmp",NULL);
	SAMPLE* musica= logg_load("music/musica.ogg");//logg.h só serve para converter arquivo.ogg para .wav
	LOCK_FUNCTION(logg_load);
	lock_sample(musica);
	
	
	
	play_sample(musica,255,255,1000,TRUE);
	LOCK_FUNCTION(play_sample);
	int frame_w=259/4;
	int frame_h=305/4,i=0;
	
	
	
	//Fadia *f1= new Fadia(vx,vy,ht,es);
	Compara *com= new Compara();
	Lista_inimi *l= create_lista_inimi();
	Lista_fad *ll= create_lista_fad();
	
	
		while((!fecha) && (!ga)){
		
		while (fps>=1){
			
			atualiza_tecla();
			if (aperta(KEY_ESC)){ga=true;estado_screen=mena;}
			if (aperta(KEY_F))pro=true;
			span(l,ll,x, y, mile,qtd,vida);
			
			
			Compara *com= new Compara();

			
			desenha_mapa(m,buffer,mapa,linha,coluna);
			update_lista(l,ll,com,grande,life,player,inimi,buffer,pro,tam,x,y,mile,qtd);// spana inimigo
		
			
			perso(player,buffer,frame_w,frame_h,mile);
			//f1->espera(player,buffer,mile);
			rectfill(buffer,800+x,400+y,840+x,440+y,makecol(255,0,0));
			textprintf_centre(buffer,asman,SCREEN_W/2,30,makecol(255,255,255),"ROUND: %d",round);
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			if ((l->inicio == NULL) && (comeca)){
				estado_screen=muda;
				
				
				ga=true;
			}
			fps--;
		}
	}
	
	destroy_sample(musica);
	if ((fecha) && (l->inicio !=NULL))
	destroy_lista(l);
	destroy_lista_f(ll);
	//free(f1);
	free(com);
	fecha_mapa(mapa,linha);
	destroy_font(asman);
	destroy_bitmap(grande);
	destroy_bitmap(inimi);
	destroy_bitmap(life);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_bitmap(buffer);

}

	
void carta(){
	
	bool ca=false;
	ga=false;
	ii=0;
	round++;
	
	BITMAP *deck=load_bitmap("sprite/deck.bmp",NULL);
	BITMAP *h_deck=load_bitmap("sprite/h_deck.bmp",NULL);
	BITMAP *mouse=load_bitmap("sprite/mouse.bmp",NULL);
	BITMAP *buffer=create_bitmap(SCREEN_W,SCREEN_H);
	Botao *bot=create_botao(deck,h_deck,SCREEN_W/2-300,SCREEN_H/2-200,1);
	Botao *bot2=create_botao(deck,h_deck,SCREEN_W/2-200,SCREEN_H/2-200,2);
	Botao *bot3=create_botao(deck,h_deck,SCREEN_W/2-100,SCREEN_H/2-200,3);
	
	habilidade();
	estado_screen=gama;
	comeca=false;
	
	while ((!ca) && (!fecha)){
		
		while (fps>=1){
			
			botao_veri(bot);
			botao_veri(bot2);
			botao_veri(bot3);
			
			
			
			botao_draw(bot,buffer);
			botao_draw(bot2,buffer);
			botao_draw(bot3,buffer);
			ca=botao_acao(bot,mile,ca,buffer);
			draw_sprite(buffer,mouse,mouse_x-16,mouse_y-18);
			//show_mouse(buffer);
		//	masked_blit(deck,buffer,15,6,SCREEN_W/2,SCREEN_H/2,82,73);
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			
			fps--;
			
		}
		
		
		
		
		
	}
	destroy_bitmap(h_deck);
	destroy_bitmap(mouse);
	destroy_botao(bot);
	destroy_botao(bot2);
	destroy_botao(bot3);
	destroy_bitmap(buffer);
	destroy_bitmap(deck);
	
	
}
	
	

void tempo_do_sistema(){fps++;}
END_OF_FUNCTION(tempo_do_sistema);


void allegro_start(char *title,int height,int width){
	
	
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,height,width,0,0);
	set_window_title(title);
	
	
	install_keyboard();
	install_timer();
	//detect_digi_driver(0);
	install_sound(DIGI_AUTODETECT,MIDI_NONE,NULL);
	install_mouse();
	
	
	
	
	
}


void fechajanela(){
	
	fecha=true;
}
END_OF_FUNCTION(fechajanela);

void ani(){mile++;}
END_OF_FUNCTION(ani);