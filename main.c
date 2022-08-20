#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
typedef struct 
{
	int x1, x2, y1, y2;
} mokhtasat;

int mokhtasat_arr(int x, int y, mokhtasat mostatil[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(mostatil[i][j].x1 < x && x < mostatil[i][j].x2 && y < mostatil[i][j].y2 && y > mostatil[i][j].y1)
			{
				return i*10 + j;
			}
		}
	}
}


int arr_mokhtasat(int x, int y, mokhtasat mostatil[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(mostatil[i][j].x1 < x && x < mostatil[i][j].x2 && y < mostatil[i][j].y2 && y > mostatil[i][j].y1)
			{
				int x_c = (mostatil[i][j].x1 + mostatil[i][j].x2) / 2;
				int y_c = (mostatil[i][j].y1 + mostatil[i][j].y2) / 2;
				return x_c * 1000 + y_c;
			}
		}
	}
}

void draw_line(int i, int j, mokhtasat mostatil[3][3])
{
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	
	al_draw_line(mostatil[i][j].x1 + 20, mostatil[i][j].y1 + 20, mostatil[i][j].x2 - 20, mostatil[i][j].y2 - 20, black, 10);
	al_draw_line(mostatil[i][j].x1 + 146, mostatil[i][j].y1 + 20, mostatil[i][j].x2 - 146, mostatil[i][j].y2 - 20, black, 10);
	al_flip_display();
}
int main () {
	
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_ttf_addon();
	al_init_font_addon();
	al_install_audio(); 
	al_install_mouse();
	al_init_acodec_addon();
	
	
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR white = al_map_rgb(225, 255, 255);
	ALLEGRO_COLOR red = al_map_rgb(233, 48, 48);
	ALLEGRO_COLOR green = al_map_rgb(59, 255, 53);
	ALLEGRO_COLOR yellow = al_map_rgb(248,255,4);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	
	ALLEGRO_FONT *font = al_load_ttf_font("arial.ttf", 50, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("arial.ttf", 40, 0);
	ALLEGRO_FONT *font1 = al_load_ttf_font("GOT.ttf", 40, 0);
	
	
	ALLEGRO_SAMPLE *song;
	ALLEGRO_SAMPLE_INSTANCE *songinstance;
	
	al_reserve_samples(1);
	
	song = al_load_sample("The_Witcher_3_Wild_Hunt_OST_Silver.ogg");

	songinstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songinstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songinstance, al_get_default_mixer());
	al_play_sample_instance(songinstance);
	
	
	ALLEGRO_DISPLAY *display = al_create_display(500, 600);
	
	srand(time(0));
	
	mokhtasat mostatil[3][3];
	for(int i = 0; i < 3; i++) 
	{
		for(int j = 0; j < 3; j++)
		{
			mostatil[i][j].x1 = j * 166;
			mostatil[i][j].y1 = i * 166;
			mostatil[i][j].x2 = j * 166 + 166;
			mostatil[i][j].y2 = i * 166 + 166;
		}
	}
	int x, y, i, j, k = 0, flag = 0, z = 0;
	
	int map[3][3] = {0};
	

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_mouse_event_source());
	
	al_clear_to_color(white);
    al_draw_text(font, black, 80, 120, 0, "do you want to");
    al_draw_text(font, black, 130, 180, 0, "start first?");
    al_draw_filled_rounded_rectangle(30, 280, 200, 350, 10, 10, yellow);
    al_draw_filled_rounded_rectangle(300, 280, 470, 350, 10, 10, yellow);
    al_draw_text(font2, black, 75, 295, 0, "YES");
    al_draw_text(font2, black, 360, 295, 0, "NO");
	
	al_flip_display();
    
	
	while(1) 
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(ev.mouse.button == 1)
			{
				x = ev.mouse.x;
				y = ev.mouse.y;
				break;
			}
		}
	}
	if(x > 30 && x < 200 && y > 280 && y < 350)
		k = 0;
	else
		k = 1;
	al_clear_to_color(white);
	al_draw_rectangle(0, 0, 500, 500, red, 15);
	al_draw_line(166, 0, 166, 500, red, 10);
	al_draw_line(332, 0, 332, 500, red, 10);
	al_draw_line(0, 166, 500, 166, red, 10);
	al_draw_line(0, 332, 500, 332, red, 10);
	al_flip_display();
	while(z != 9)
	{
		if(k == 0)
		{
			while(1) 
			{
				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);
				if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{
					if(ev.mouse.button == 1)
					{
						x = ev.mouse.x;
						y = ev.mouse.y;
						break;
					}
				}
			}	
			i = mokhtasat_arr(x, y, mostatil) / 10;
			j = mokhtasat_arr(x, y, mostatil) % 10;
			int x_m = arr_mokhtasat(x, y, mostatil) / 1000;
			int y_m = arr_mokhtasat(x, y, mostatil) % 1000;
			if(map[i][j] == 0)
			{
				map[i][j] = 1;
				al_draw_circle(x_m, y_m, 50, black, 10);
				al_flip_display();
			}else
			{
				al_draw_text(font, black, 130, 520, 0, "Try Again");
				al_flip_display();
				al_rest(1);
				al_draw_filled_rectangle(0, 510, 500, 600, white);
				al_flip_display();
				continue;
			}
			k = 1;
		}else
		{
			i = rand() % 3;
			j = rand() % 3;
			while(1)
			{
				if(map[i][j] == 0)
				{
					map[i][j] = 2;
					al_rest(0.7);
					draw_line(i, j, mostatil);
					break;
				}else
				{
					i = rand() % 3;
					j = rand() % 3;
				}
			}
			k = 0;
		}
		
		
		
		
		for(int l = 0; l < 3; l++) 
		{
            if(map[l][0] == map[l][1] && map[l][0] == map[l][2]) 
			{
                if(map[l][0] != 0) 
				{
                    if(map[l][0] == 1)
					{
                        al_clear_to_color(green);
                        al_draw_text(font1, black, 140, 220, 0, "you  won");
                        al_flip_display();
                        al_rest(5);
						flag = 1;
                        break;
                    }else 
					{
						al_clear_to_color(red);
                        al_draw_text(font1, black, 140, 220, 0, "you  lost");
                        al_flip_display();
                        al_rest(5);
                        flag = 1;
                        break;
                    }
                }
            }
        }	
		if(flag == 1)
            break;
		for(int l = 0; l < 3; l++) 
		{
            if(map[0][l] == map[1][l] && map[0][l] == map[2][l])
			{
                if(map[0][l] != 0) 
				{
                    if(map[0][l] == 1)
					{
						al_clear_to_color(green);
                        al_draw_text(font1, black, 140, 220, 0, "you  won");
                        al_flip_display();
                        al_rest(5);
                        flag = 1;
                        break;
                    }else 
					{
						al_clear_to_color(red);
                        al_draw_text(font1, black, 140, 220, 0, "you  lost");
                        al_flip_display();
                        al_rest(5);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1)
            break;
            
        if(map[0][0] == map[1][1] && map[0][0] == map[2][2]) 
		{
            if(map[0][0] != 0) 
			{
                if(map[0][0] == 1)
				{
					al_clear_to_color(green);
                   	al_draw_text(font1, black, 140, 220, 0, "you  won");
                    al_flip_display();
                    al_rest(5);
                    flag = 1;
                    break;
                }else 
				{
					al_clear_to_color(red);
                  	al_draw_text(font1, black, 140, 220, 0, "you  lost");
                    al_flip_display();
                    al_rest(5);
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            break;
            
        if(map[0][2] == map[1][1] && map[0][2] == map[2][0])
		{
            if(map[0][2] != 0) 
			{
                if(map[0][2] == 1)
				{
					al_clear_to_color(green);
                  	al_draw_text(font1, black, 140, 220, 0, "you  won");
                    al_flip_display();
                    al_rest(5);
                    flag = 1;
                    break;
                }else 
				{
					al_clear_to_color(red);
                    al_draw_text(font1, black, 140, 220, 0, "you  lost");
                    al_flip_display(); 
                    al_rest(5);
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            break;
            
    	z++;
	}
	if(flag == 0) 
	{
		al_clear_to_color(yellow);
        al_draw_text(font1, black, 220, 220, 0, "tie");
    	al_flip_display();
    	al_rest(5);
    }
	
	return 0;
}