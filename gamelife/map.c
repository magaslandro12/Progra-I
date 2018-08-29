#include<stdio.h>
#include<stdlib.h>


#define VIVE	'O'
#define	MUERE	'x'

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
	char mapa[13][13];

	for(int y=0;y<13;y++)
	{
		for(int x=0;x<13;x++)
		{
			if(x==y)
			{
				mapa[x][y]=VIVE;
			}else{mapa[x][y]=MUERE;}

		}
	}





	for(int y=0;y<13;y++)
	{
		for(int x=0;x<13;x++)
		{
			printf(" %c",mapa[x][y]);

		}
		printf("\n");
	}

	return 0;
}

/*

int get_status(int mapa[][])
{
	mapa[x][y];

}
*/

