#include<stdio.h>
#include<stdlib.h>



/*
* Life Game
* Funciones de acceso al mundo
* ¡El objetivo de las mismas es que sean independientes de las reglas del
juego!
*/




int main(void)
{
	int mapa[13][13];


void initialize_world (void);
/* returns the width (x) and height (y) of the world
*/
int get_world_width (void);
int get_world_height (void);
/* returns the state (DEAD or ALIVE) of the cell at (x,y);
* coordinates go from x = 0 ,... ,width -1 and
* y = 0 ,... ,height -1; returns DEAD for cells outside this
* range
*/
int get_cell_state (int x, int y);
/* sets the state (DEAD or ALIVE) of the cell at (x,y) in
* the next generation; range of coordinates same as in
* get_cell_state()
*/
void set_cell_state (int x, int y, int state );
/* updates world state to next generation and resets all
* next generation states to DEAD
*/
void finalize_evolution (void);
/* outputs the current world state to the console
*/
void output_world (void);

}