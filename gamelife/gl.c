#include<stdio.h>
#include<stdlib.h>
#define FILA 13
#define COLUMNA 13
#define DEAD 'X'

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

