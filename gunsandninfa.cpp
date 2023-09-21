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
int frame_w=250/4;
int frame_h=400/4;
	


void fechajanela();
void allegro_start(char *title,int height,int width);
void tempo_do_sistema();
void ani();
void titulo();
void menu();
void game();
void game2();
void carta();
void gameover();
void cidade();
void saveflor();


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
			}else if (estado_screen==cida){
				
				
				cidade();
				
			}else if (estado_screen==flu){
				saveflor();
				
			}else if (estado_screen==gama2){
				game2();
				
			}
		
		}
	}
	
	allegro_exit();
	return 0;	
}

END_OF_MAIN();

void saveflor(){
	
	bool fl=false;
	BITMAP *buffer=create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP *m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP *player=load_bitmap("sprite/spritemaleman.bmp",NULL);
	BITMAP *minu=load_bitmap("sprite/miniman.bmp",NULL);
	int linha,coluna;
	int **mapa=carrega_mapa("mapa4.txt",&linha,&coluna);
	Lista_mini *l=create_lista_mini();
	
	x=-2000;
	y=-500;
	while ((!fecha) && (!fl)){
		
		while (fps>=1){
			atualiza_tecla();
			span_mini(l,mile);
			prepara_colisao(mapa,linha,coluna);
			
			if (estado_screen==gama2)
				fl=true;
			
			desenha_mapa(m,buffer,mapa,linha,coluna);
			update_lista_mini(l,minu,buffer,x,y,mile);
			perso(player,buffer,frame_w,frame_h,mile);
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			
			fps--;
		}
		
		
		
		
	}
	
	fecha_mapa(mapa,linha);
	destroy_lista_mini(l);
	destroy_bitmap(minu);
	destroy_bitmap(player);
	destroy_bitmap(m);
	destroy_bitmap(buffer);
	
	
}

void cidade(){
	
	bool ci=false;
	
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* player=load_bitmap("sprite/spritemaleman.bmp",NULL);
	BITMAP* m=load_bitmap("sprite/mapa.bmp",NULL);
	BITMAP* ni=load_bitmap("sprite/ninfa.bmp",NULL);
	BITMAP* lo=load_bitmap("sprite/loja.bmp",NULL);
	BITMAP* moedinha=load_bitmap("sprite/coin.bmp",NULL);
	FONT *asman=load_font("fonte/asman.pcx",NULL,NULL);
	int linha,coluna;
	int** mapa=carrega_mapa("mapa2.txt",&linha,&coluna);
	Lista_ninfa *n=create_lista_ninfa();
	
	while ((!fecha) && (!ci)){
		
		while(fps>=1){
			atualiza_tecla();
			span_ninfa(n,x,y,mile);
			
			
			
			
			desenha_mapa(m,buffer,mapa,linha,coluna);
			ci=para_floresta(buffer,m,ci);
			loja(m,buffer,lo);
			update_ninfa(n,ni,buffer,x,y,mile,sex);
			if (!lojaopen)
				perso(player,buffer,frame_w,frame_h,mile);
			else
				persotwo(player,buffer,frame_w,frame_h,mile,asman);
			
			
			draw_sprite(buffer,moedinha,SCREEN_W-120,0);
			textprintf_ex(buffer,asman,SCREEN_W-110,0,makecol(255,255,255),30,"%d",rale);
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			
			fps--;
		}
		
		
		
		
	}
	fecha_mapa(mapa,linha);
	destroy_lista_n(n);
	destroy_bitmap(moedinha);
	destroy_bitmap(lo);
	destroy_bitmap(ni);
	destroy_bitmap(player);
	destroy_bitmap(m);
	destroy_bitmap(buffer);
	destroy_font(asman);
	
	
	
	
	
	
}

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
	BITMAP* moedinha= load_bitmap("sprite/coin.bmp",NULL);
	BITMAP* buffer= create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP* inimi=load_bitmap("sprite/spriteinimigo.bmp",NULL);
	BITMAP* obj=load_bitmap("sprite/item/obj.bmp",NULL);
	SAMPLE* musica= logg_load("music/musica.ogg");//logg.h só serve para converter arquivo.ogg para .wav
	LOCK_FUNCTION(logg_load);
	lock_sample(musica);
	
	
	
	play_sample(musica,255,255,1000,TRUE);
	LOCK_FUNCTION(play_sample);
	int i=0;
	
	
	
	//Fadia *f1= new Fadia(vx,vy,ht,es);
	Compara *com= new Compara();
	Lista_inimi *l= create_lista_inimi();
	Lista_fad *ll= create_lista_fad();
	Lista_moeda *lll= create_lista_moeda();
	int backup=myhp,mudcor=255,ulti=rale,tem=mile;
	
		while((!fecha) && (!ga)){
		
		while (fps>=1){
			
			atualiza_tecla();
			if (aperta(KEY_ESC)){ga=true;estado_screen=mena;}
			if (aperta(KEY_F))pro=true;
			if (round==5){ga=true;estado_screen=cida;x=0;y=0;}
			span(l,ll,x, y, mile,qtd,vida);
			span_moeda(lll,mile);
			
			
			Compara *com= new Compara();
			if (ulti !=rale)
				mudcor=0;

			if (mile - tem >= 2000){
				ulti=rale;
				mudcor=255;
				tem=mile;
			}
			
			desenha_mapa(m,buffer,mapa,linha,coluna);
			update_lista_moeda(lll,moedinha,buffer);
			update_lista(l,ll,com,grande,life,player,inimi,buffer,pro,tam,x,y,mile,qtd);// spana inimigo
		
			
			perso(player,buffer,frame_w,frame_h,mile);
			equipa(roupa,buffer,obj);
			if (estado_screen==cida){
				myhp=backup;
				clear(buffer);
				textout_centre(buffer,asman,"LOADING",SCREEN_W/2,SCREEN_H/2,makecol(255,255,255));
			}
			//rectfill(buffer,800+x,400+y,840+x,440+y,makecol(255,0,0));
			textprintf_centre(buffer,asman,SCREEN_W/2,30,makecol(255,255,255),"ROUND: %d",round);
			draw_sprite(buffer,moedinha,SCREEN_W-120,0);
			textprintf_ex(buffer,asman,SCREEN_W-110,0,makecol(255,255,mudcor),30,"%d",rale);
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
	destroy_lista_moeda(lll);
	//free(f1);
	free(com);
	fecha_mapa(mapa,linha);
	destroy_font(asman);
	destroy_bitmap(moedinha);
	destroy_bitmap(obj);
	destroy_bitmap(grande);
	destroy_bitmap(inimi);
	destroy_bitmap(life);
	destroy_bitmap(m);
	destroy_bitmap(player);
	destroy_bitmap(buffer);

}

void game2(){//os miniman aparece
	
	bool ga2=false;
	
	
	BITMAP *buffer=create_bitmap(SCREEN_W,SCREEN_H);
	BITMAP *min=load_bitmap("sprite/miniman.bmp",NULL);
	BITMAP *player=load_bitmap("sprite/maleman.bmp",NULL);
	BITMAP *m=load_bitmap("sprite/mapa.bmp",NULL);
	int linha,coluna;
	int **mapa=carrega_mapa("mapa.txt",&linha,&coluna);
	
	while((!ga) && (!fecha)){//talvez seja necessario criar um novo update da lista
		
		while (fps >=1){
			
			
			
			
			draw_sprite(screen,buffer,0,0);
			clear(buffer);
			fps--;
		}
		
		
	}
	
	destroy_bitmap(player);
	destroy_bitmap(m);
	destroy_bitmap(min);
	destroy_bitmap(buffer);
	fecha_mapa(mapa,linha);
	
	
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
	//install_sound(DIGI_AUTODETECT,MIDI_NONE,NULL);
	install_mouse();
	
	
	
	
	
}


void fechajanela(){
	
	fecha=true;
}
END_OF_FUNCTION(fechajanela);

void ani(){mile++;}
END_OF_FUNCTION(ani);