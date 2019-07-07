#include<graphics.h>
#include<iostream>
#include<string>
#include<windows.h>
#include "interpolacion.h"
#include<conio.h>

//Esta constante define el numero de puntos que se marcaran en el plano por el usuario
#define MAXP 31

using namespace std;

//Declaracion de las funciones
void ginput(int X[], int Y[], int num_points);
void plano();
void trazar(int X[], int Y[], int num_points);
void trazar2(float X[], float Y[], int num_points);

int main()
{	
	int X[MAXP], Y [MAXP]; // Vectores que almacenan las coordenadas [X,Y] que el usuario 
	float dx[MAX2],ddx[MAX2],dy[MAX2],ddy[MAX2]; //Vectores Resultado de las derivadas
	float int_x[MAX2], int_y[MAX2]; // Vectores resultado de la interpolacion guardando las coordenadas [X,Y]
	int size_x,size_y; // Variables que indican el tamaño de la interpolacion en X y Y
		
	
	// Creando la ventana grafica con un tamaño de 600x600 pixeles
	initwindow(600, 600, "Ruta", 50,50); 
	
	plano(); //Pintando los ejes X y Y 
	ginput(X,Y,MAXP); // Ingresando los puntos
	trazar(X,Y,MAXP); // Uniendo los puntos
	
	//Realizando la interpolacion con la funcion Interpolar
	//Esta funcion esta dentro de la libreria interpolacion.h
	Interpolar(X,Y,dx,ddx,dy,ddy,int_x,int_y,&size_x,&size_y, MAXP); 
	system("cls");
	getch();	
	
	//Trazando nuevamente los ejes X y Y
	plano();
	//Dibujando la ruta con los resultados de la interpolacion utilizando los puntos
	//marcados en los vecotres int_x e int_y
	trazar2(int_x,int_y,size_x);
	getch();
	
	//Cerrando la ventana grafica
	closegraph();
	
	return 0;
}

// La funcion ginput tiene la funcion de guardar en los vectores X y Y las coordenadas de los
// puntos ingresados por el usuario.
//El parametro num_points es el que define el limite de puntos que el usuario podra ingresar

void ginput(int X[], int Y[], int num_points)
{
	POINT cursor; //Tipo de dato que capruta las coordenadas X y Y
	int cont=0; //variable que cuenta el numero de puntos que va ingresando el usuario
	
	while(cont < num_points)
	{
		GetCursorPos(&cursor); //Esta funcion detecta las coordenadas de la posicion del puntero (mouse)
		setcolor(WHITE); //Definiendo el color blanco con el que se va a dibujar
		
		//La funcion GetAsyncKeyState(VK_LBUTTON) detecta si ocurre el evento de
		//realizar un click con el boton izquierdo del raton.
		//En caso de que ocurra el evento dibujara un circulo marcando el lugar y guardara las coordenadas
		if(GetAsyncKeyState(VK_LBUTTON))
		{
			circle(cursor.x, cursor.y, 3); //Dibujando el circulo en la posicion donde se realizo el click con un radio de 3 pixeles
			X[cont] = cursor.x; //Guardando la coordenada X
			Y[cont] = cursor.y; //Guardando la coordenada Y
			//cout << "x = " << X[cont] << ", y =" << X[cont] << endl;
			delay(100);
			cont++; //Aumentando el contador
		}
	}
}

//La funcion plano tiene la funcion de dibujar las lineas de los ejes X y Y
void plano()
{
	clearviewport(); //Limpiando la pantalla grafica
	setcolor(5); //Definiendo el color purpura para dibujar
	
	//Dibujando la linea del eje Y
	//Moviendo el origen donde se iniciara el trazado a las coordenadas [300,0] para trazar una linea
	//hasta la coordenadas [300,600] 
	moveto(300,0); 
	lineto(300,600);
	
	//Dibujando la linea del eje X
	//Moviendo el origen donde se iniciara el trazado a las coordenadas [0,300] para trazar una linea
	//hasta la coordenadas [600,300] 
	moveto(0,300);
	lineto(600,300);
}


//La funcion trazar tiene como unico objetivo unir los puntos marcados por el usuario
//Recibiendo como parametros los vectores con las coordenadas en X y Y y el numero de puntos
//Esta funcion unira los puntos con una linea para ver de una mejor forma la ruta trazada por el usuario
void trazar(int X[], int Y[], int num_points)
{
	char n[3];
	int i;
	for(i=0; i < num_points-1; i++)	
	{
		// pasando la variable i que es entera a una de tipo char guardandola en "n"
		//Esto para visualizar el numero del punto marcado e imprimiendolo en la pantalla
		sprintf(n,"%d", i+1);
		outtextxy(X[i]+10,Y[i]+10,n); //Imprimiendo el numero del punto en las coordenadas X y Y con una suma de 10 pixeles para que no se encimen
		
		//moviendo el origen donde se trazara la linea y dibujandola
		//hacia el siguiente punto
		moveto(X[i],Y[i]);
		lineto(X[i+1],Y[i+1]);
	}
}


//La funcion trazar2 tiene como unico objetivo el unir los puntos que salen como resultado al realizar
//la interpolacion 
void trazar2(float X[], float Y[], int num_points)
{
	int i;
	printf("num_points = %d ", num_points);
	setcolor(WHITE);
	for(i=1; i < num_points-1; i++)	
	{
		//Moviendo el origen donde se iniciara el trazo de la linea y dubujandola
		//hasta el punto siguiente
		moveto(X[i],Y[i]);
		lineto(X[i+1],Y[i+1]);
	}
}
