#include <stdio.h>
#include <stdlib.h>

/* Ej4 TP3
-El siguiente programa calcula cuantos dias transcurrieron
desde una fecha inicial y final elegidas por el usuario.
-Las fechas pueden ser cargadas en 2 tipos de formato
	Formato 1: dd/mm/aa
	Formato 2: dd/mm/aaaa

Grupo 3
Matias Gasparri
Francisco Ledesma
Dimas Bosch
*/


int doscifras (int, int);												//Prototipo funcion doscifras
int cuatrocifras (int, int, int, int);					//Prototipo funcion cuatrocifras
int diames (int, int, int);											//Prototipo funcion diames
int validar (int, int, int);										//Prototipo funcion Validar
int checkdates(int,int,int,int,int,int);				//Prototipo funcion checkdates
int fecha();																		//Prototipo funcion fecha
int anos();																			//Prototipo funcion anos


int main (void)
{
	int formato;		//variable para evaluar el formato elegido.
	do
	{
		printf("Elegi el formato que vas a usar:\nFormato1: dd/mm/aa.\nFormato2: dd/mm/aaaa\n\nElijo el formato numero ");
		formato=getchar()-'0'; //se imprime un mensaje y se espera que el usuario ingrese un caracter seguido de enter.
	}
	while (formato !=1 && formato !=2); //El programa esperara que el usuario elija el formato 1 o 2, caso contrario no realizara otra operacion
	getchar(); //libero el buffer del teclado

	int num;	//inicializo variable para manejar el numero de los años mas adelante
	printf("Fecha inicial:");	//imprimo en pantalla Fecha inicial

	int diai=fecha ();				//invoco a la funcion fecha para manejar el ingreso de la fecha inicial

	getchar();				//Aqui libero el buffer del caracter '/' entre las cifras de la fecha

	int mesi=fecha ();				//invoco a la funcion fecha para almacenar el numero de mes inicial

	getchar();				//Aqui libero el buffer del caracter '/' entre las cifras de la fecha

	if (formato==1)						//el siguiente if else maneja la parte del ingreso del año inicial
	{													//en el caso del formato 1 se esperan 2 caracteres para el año
		int ai1=getchar(), ai2=getchar();	//guardo digitos del año
		num=doscifras (ai1, ai2);					//invoco la funcion doscifras que me devuelve el numero entero del año completo


		if(num>=30){num=num+1900;}else{num=num+2000;}	//en el caso del formato 1, los años contemplados van de 1930 a 2029

	}
	else																//caso contrario, es el formato 2, se esperan 4 caracteres para el año
	{
		int ai1=getchar(), ai2=getchar(), ai3=getchar(), ai4=getchar();	//guardo los 4 caracteres
		num=cuatrocifras (ai1, ai2, ai3, ai4);						// y invoco funcion cuatrocifras que me devuelve el entero del año escogido
	}
	int anoi=num;												//guardo el numero del año inicial
	printf ("%d/%d/%d\n", diai, mesi, anoi);	//imprimo en pantalla la fecha elegida
	if (validar(diai, mesi, anoi)==0)					// y verifico si la fecha existe
	{
		printf("ERROR, FECHA NO VALIDA\n");			//si no existe la fecha imprimo en pantalla un mensaje de error
		return 0;																// y el programa termina
	}
	getchar();			//libero buffer teclado '\n'

	printf("Fecha final:");		//imprimo en pantalla Fecha final
	int diaf=fecha ();				//invoco a la funcion fecha para manejar el ingreso de la fecha final

	getchar();				//Aqui libero el buffer del caracter '/' entre las cifras de la fecha

	int mesf=fecha ();				//invoco a la funcion fecha para almacenar el numero de mes final

	getchar();				//Aqui libero el buffer del caracter '/' entre las cifras de la fecha

	if (formato==1)						//el siguiente if else maneja la parte del ingreso del año final
	{													//en el caso del formato 1 se esperan 2 caracteres para el año
		int af1=getchar(), af2=getchar();	//guardo digitos del año
		num=doscifras (af1, af2);	//invoco la funcion doscifras que me devuelve el numero entero del año completo
		if(num>=30){num=num+1900;}else{num=num+2000;}	//en el caso del formato 1, los años contemplados van de 1930 a 2029
	}
	else										//caso contrario, es el formato 2, se esperan 4 caracteres para el año
	{
		int af1=getchar(), af2=getchar(), af3=getchar(), af4=getchar();	//guardo los 4 caracteres
		num=cuatrocifras (af1, af2, af3, af4);	// y invoco funcion cuatrocifras que me devuelve el entero del año escogido
	}
	int anof=num;		//guardo el numero del año final
	printf ("%d/%d/%d\n", diaf, mesf, anof);	//imprimo en pantalla la fecha elegida
	if (validar(diaf, mesf, anof)==0)					// y verifico si la fecha existe
	{
		printf("ERROR, FECHA NO VALIDA");				//si no existe la fecha imprimo en pantalla un mensaje de error
		return 0;																// y el programa termina
	}

	if (checkdates(diai,mesi,anoi,diaf,mesf,anof)==0)			//verifico si fecha final es posterior a fecha inicial
	{
		printf("ERROR, FECHA FINAL ES ANTERIOR A FECHA INICIAL\n"); //si la fecha final es anterior indico error
		return 0;																										//y el programa termina
	}


	int mdf=diames (diaf, mesf, anof);			//invoco diames con la fecha final y guardo valor en variable
	int mdi=diames (diai, mesi, anoi);			//invoco diames con la fecha inicial y guardo valor en variable
	int difmd=mdf-mdi;											//La resta de estas 2 variables me da la cantidad de dias de diferencia entre los meses
	int dify=anos(anoi, anof);							//invoco anos para guardar la cantidad de diferencia entre los años elegidos
	int dif=(dify*365.25)+difmd;						//calculo final de los dias totales
 	
 	printf("\nDiferencia=%d dias\n", dif);	//imprimo en pantalla los dias finales

	return 0;																//fin del programa
}


/*Funcion fecha
Que hace?
-Espera el ingreso por teclado
	de 1 numero de 2 cifras, luego
	invoca funcion doscifras para convertir el valor
	en ASCII a entero.
Que recibe?
- Nada.
Que devuelve?
-Devuelve un entero con el valor de las 2 cifras ingresadas.
*/
int fecha ()
{
	int f1,f2;											//declaro variables a utilizar
	f1=getchar(), f2=getchar();			//guardo en las variables los caracteres ingresados por teclado
	int f=doscifras (f1, f2);				//convierto a entero decimal
	return f;												//devuelvo el entero decimal
}



/*Funcion doscifras
Que hace?
-Convierte 2 cifras en ASCII al entero correspondiente
	Ej: '2','1' vuelve como el numero 21 decimal.
Que recibe?
- 2 valores en ASCII correspondientes al simbolo de las cifras ingresadas
Que devuelve?
-Devuelve un entero decimal.
*/
int doscifras (int c1, int c2)
{
	int num;
	if (c2 !='\n')
	{
		c1=(c1-'0')*10;
		c2=c2-'0';
		num=c1+c2;
	}
	else
	{
		c1=c1-'0';
		num=c1;
	}

	return num;
}


/*Funcion cuatrocifras
Que hace?
-Convierte 4 cifras en ASCII al entero correspondiente
	Ej: '2','1','3','4' vuelve como el numero 2134 decimal.
Que recibe?
- 4 valores en ASCII correspondientes al simbolo de las cifras ingresadas
Que devuelve?
-Devuelve un entero decimal.
*/
int cuatrocifras (int c1, int c2, int c3, int c4)
{


	c1=(c1-'0')*1000;
	c2=(c2-'0')*100;
	c3=(c3-'0')*10;
	c4=c4-'0';
	int num=c1+c2+c3+c4;
	return num;
}



/*Funcion diames
Que hace?
-calcula la cantidad de dias transcurridos en ese año
Que recibe?
- recibe 3 enteros correspondientes a la fecha (dia, mes, año)
Que devuelve?
-1 entero correspondiente a la cantidad de dias.
*/

int diames (int dia, int mes, int year)
{
	int bis=((year%4==0) || (year%400==0));
	int u, f=0, p;

	if (mes>2)
	{
		f=1;
	}


	switch (mes)
	{
		case 1:
		{
			u=0;
			p=0;
			break;

		}
		case 2:case 3:
		{
			u=1;
			p=0;
			break;
		}
		case 4:
		{
			u=2;
			p=0;
			break;
		}
		case 5:
		{
			u=2;
			p=1;
			break;
		}
		case 6:
		{
			u=3;
			p=1;
			break;
		}
		case 7:
		{
			u=3;
			p=2;
			break;
		}
		case 8:
		{
			u=4;
			p=2;
			break;
		}
		case 9:
		{
			u=5;
			p=2;
			break;
		}
		case 10:
		{
			u=5;
			p=3;
			break;
		}
		case 11:
		{
			u=6;
			p=3;
			break;
		}
		case 12:
		{
			u=6;
			p=4;
			break;
		}
	}
																	//		u=cantidad de meses transcurridos con 31 dias
																	//		f --> si paso febrero F=1 caso contrario f=0
																	//    p=cantidad de meses transcurridos con 30 dias.
	int md=dia+31*u+(28+bis)*f+30*p; //Calculo completo de los dias transcurridos en el año.
	return md;
}


/*Funcion anos
Que hace?
-Calcula la diferencia de años.
-Los años pueden ser ingresados como 2 cifras o 4.
Que recibe?
- recibe 2 enteros correspondientes a los años.
Que devuelve?
- 1 entero con el valor de la diferencia de años
*/
int anos(int year1,int year2)
	{
	int years;

	if(year1<100)
		{   if(year1>year2)		// ejemplo (12,1,97)y(1,4,12)el 12 seria 2012, entonces tengo que hacer una cuenta distinta porque sino me daria mal la cantidad de anos
			{  year2=year2+100;	//le sumo 100 para poder hacer la resta
			   years=year2-year1;	// cantidad de anos entre fechas
			}
		   else
			 years=year1-year2;		// aca seria lo contrario(12/2/12)y(12/2/97) como el primer ano es menor que el segundo se refiere a 1912 y no a 2012

		 }
	if (year1<year2)
		{
		years=year2-year1;
		}
	else
	years=year1-year2;

	return years;
	}

/*Funcion validar
Que hace?
-Verifica que las fechas ingresadas existan.
-Contempla años bisiesto y los dias que hay por cada mes.
Que recibe?
- recibe 3 enteros correspondientes al dia, mes y año.
Que devuelve?
- 1 entero con valor 1 si es valida o 0 sino lo es.
*/

int validar(int day,int month,int year)
{
  while(year>=0)	//reviso que no cargo un año negativo
  {
    switch(month)				//en funcion del mes elegido verifico la cantidad de dias
    {
      case 1:case 3:case 5:case 6:case 8:case 10:case 12:			//enero, marzo,mayo,junio,Agosto,octubre y diciembre
	if(day<=31)																								  //tienen 31 dias, por lo tanto day no puede ser mayor.
	{
		return 1;
	}
	else
	{
		return 0;
	}

      case 2:				//febrero, Day no puede ser mayor a 28, a menos que el año sea bisiesto, en ese caso maximo es 29
            if(year%4==0){
                        if(day<=29){return 1;}else {return 0;}
                        }
            if(year%400==0){
                          if(day<=29){return 1;}else {return 0;}
                          }
            if(day<=28){return 1;}else {return 0;}

      case 4:case 7:case 9:case 11: if(day<=30){return 1;}else{return 0;}

      default: return 0;
    }
  }
	return 0;
}

/*Funcion checkdates
Que hace?
-Verifica que una fecha final sea posterior a una fecha inicial.
Que recibe?
- recibe 3 enteros correspondientes a dia, mes, año inicial.
- recibe 3 enteros correspondientes a dia, mes, año final.
Que devuelve?
- 1 entero con valor 1 si la fecha es posterior o 0 sino lo es.
*/
int checkdates(int diai,int mesi,int anoi,int diaf,int mesf,int anof)
{
	if(anoi<anof){return 1;}
	if(anoi==anof)
	{
		if(mesi<mesf){return 1;}
		if(mesi==mesf)
		{
			if(diai<diaf){return 1;}
			if(diai==diaf){return 1;}
		}
	}
	return 0;
}
