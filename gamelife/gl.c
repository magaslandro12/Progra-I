#include<stdio.h>
#include<stdlib.h>



/*
* Life Game
* Funciones de acceso al mundo
* ¡El objetivo de las mismas es que sean independientes de las reglas del
juego!
*/



int delay (int);

void initialize_world (void);
int get_world_width (void);
int get_world_height (void);

int get_cell_state (int x, int y);
void set_cell_state (int x, int y, int state );
void finalize_evolution (void);
void output_world (void);



int main(void)
{
	int mapa[13][13];


}






int delay(int time)
{

	do
	{
		for(int i=15000;i>0;i--)
		{
			for(int i=20000;i>0;i--)
			{

			}
		}	
	time--;
	}while(time>0);
	return 0;
}


