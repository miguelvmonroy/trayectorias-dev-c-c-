#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

//Declaracion de constantes
#define MAX 35
#define MAX2 500 //Esta constante se definio con un numero alto para lograr aclmacenar una gran cantidad de puntos en el resultado de la interpolacion


//Declaracion de funciones
void Interpolar(int X[], int Y[], float dx[], float ddx[], float dy[], float ddy[], float int_x[], float int_y[], int *size_x, int *size_y, int puntos);
int mi_interpolacion(int D[], int puntos, int numero_des, float aa[], float pd[], float sd[]);
float derivada(int T[], int D[], float z);
float segundaderivada(int T[], int D[], float z);
void fill_array(int arr[],int Vi, int Vf);
void printArrI(int arr[], int size);
void printArrF(float arr[], int size);
void set_K(float dx[], float ddx[], float dy[], float ddy[], int tam, float K[]);


//La funcion interpolar es la funcion principal que llama al resto de funciones
//recibe como parametros punteros que son los vectores donde se alojan las coordenadas X y Y
//y tambien recibe punteros donde se almacenaran los resultados de las derivadas de X (dx,ddx), de Y(dy,ddy)
// los resultados de la interpolacion (int_x, int_y) y los tamaños de los vectores (size_x, size_y) y el numero de puntos
//con los que se trabaja
void Interpolar(int X[], int Y[], float dx[], float ddx[], float dy[], float ddy[], float int_x[], float int_y[], int *size_x, int *size_y, int puntos)
{
	int grosor_de_linea=3;
	float K[MAX2],Kmax,i;	 
	
	//Realizando la interpolacion y calculo de las derivadas de X
	*size_x = mi_interpolacion(X,puntos,35,int_x,dx,ddx); 
	//Realizando la interpolacion y calculo de las derivadas de Y
	*size_y = mi_interpolacion(Y,puntos,35,int_y,dy,ddy);
	
	
	//Verificando que el tamaño de ambos vectores sea el mismo
	if( size_x == size_y )
	{
		set_K(dx,ddx,dy,ddy,*size_x,K);//Calculando K
	}
	else
	{
		printf("Los tamaños de los vectores de X(%d) y Y(%d) son distintos",size_x,size_y);	
	}
	
}


//La funcion mi_interpolacion realiza el calculo de la interpolacion de las coordenadas dadas y el llamado de las funciones de 
//derivadas para sus realizar los respectivos calculos
//Recibe como parametros las coordenadas ya sea X o Y almacenadas en el vector D[], el numero de puntos, la resolucion (numero_des),
// y los vectores donde se almacenaran los resultados de la interpolacion (aa[]), la primera derivada (pd[]) y la segunda derivada (sd[])
int mi_interpolacion(int D[], int puntos, int numero_des,  float aa[], float pd[], float sd[])
{
    int valor_division_incremento=numero_des-1; //pedacitos
    int T[MAX],Ds[MAX],Ts[MAX];
    int M,j,i,b,c;
    float nc,resta,incremento_real,GG_1,z;
    
	fill_array(T,1,puntos+1);//Llenando el Vector T del 1 a puntos + 1
    j=1;
    M = puntos;
    nc = M-((M+2)%3); 
    //printf("nc = %.4f\n",nc);
    for(b=0; b <= nc-3; b = b+3)
    {
    	//printf("B: %d\n",b);
        resta=T[b+3]-T[b];
        incremento_real=resta/valor_division_incremento;
       // printf("Incremento real = %.4f\n",incremento_real);
        if( b == (nc-3) )
        {
            c = 0;
        }else{
            c = 1;
        }
        //getch();
        //printf("T[%d]: %d -- T = %.4f\n",b,T[b],T[b+3]-(c*incremento_real));
        //printf("T[%d]: %d\n",b,T[b]);
        if(b <= puntos-3)
        {
        	//Realizando la interpolacion y calculo de derivadas
	        for(z=T[b];z<=(T[b+3]-(c*incremento_real)); z = z+incremento_real) //z=T(b):incremento_real:(T(b+3)-c*incremento_real)
	        {
	        	//printf("Z: %.4f\n",z);
	            GG_1=(D[b]/1)*((z-T[b+1])*(z-T[b+2])*(z-T[b+3]))/(((T[b]-T[b+1])*(T[b]-T[b+2])*(T[b]-T[b+3])))+
				(D[b+1]/1)*((z-T[b])*(z-T[b+2])*(z-T[b+3]))/(((T[b+1]-T[b])*(T[b+1]-T[b+2])*(T[b+1]-T[b+3])))+
				(D[b+2]/1)*((z-T[b])*(z-T[b+1])*(z-T[b+3]))/(((T[b+2]-T[b])*(T[b+2]-T[b+1])*(T[b+2]-T[b+3])))+
				(D[b+3]/1)*((z-T[b])*(z-T[b+1])*(z-T[b+2]))/(((T[b+3]-T[b])*(T[b+3]-T[b+1])*(T[b+3]-T[b+2])));
	            fill_array(Ds,b,b+3);
	            //Ds = D(b:b+3);
	            fill_array(Ts,b,b+3);
	            //Ts = T(b:b+3);
	            pd[j]=derivada(Ts,Ds,z); //Calculando la primera derivada
	            
	            sd[j]=segundaderivada(Ts,Ds,z); //Calculando la segunda derivada
	            
	            aa[j] = GG_1; //Guardando punto de interpolacion
	            j= j+1;
	        }
	    }
     
    }
    //Se retorna el valor de j, que este almacena el numero de valores que contendra el vector interpolado
    return j;
}

//La funcion derivada realiza los calculos de la derivada del valor de z
float derivada(int T[], int D[], float z)
{
    int b,d,x,y,w;
    float D1,D2,D3,D4,Dsalida;
    b=1;
    d = T[b];
    x = T[b+1];
    y = T[b+2];
    w = T[b+3];

    D1 = D[b]/(((T[b]-T[b+1])*(T[b]-T[b+2])*(T[b]-T[b+3])));
    D2 = D[b+1]/(((T[b+1]-T[b])*(T[b+1]-T[b+2])*(T[b+1]-T[b+3])));
    D3 = D[b+2]/(((T[b+2]-T[b])*(T[b+2]-T[b+1])*(T[b+2]-T[b+3])));
    D4 = D[b+3]/(((T[b+3]-T[b])*(T[b+3]-T[b+1])*(T[b+3]-T[b+2])));

    Dsalida=D1*(3*(pow(z,2))-2*z*y-2*z*x+x*y-2*z*w+y*w+x*w)+D2*
	(3*(pow(z,2))-2*z*y-2*z*d+y*d-2*z*w+y*w+d*w)+D3*(3*(pow(z,2))-
	2*z*x-2*z*d+x*d-2*z*w+x*w+d*w)+D4*(3*(pow(z,2))-2*z*x-2*z*d+d*x-2*z*y+x*y+d*y);

    return Dsalida;
}

//La funcion segundaderivada realiza los calculos de la segunda derivada del valor de z
float segundaderivada(int T[], int D[], float z)
{
    int b,d,x,y,w;
    float DD1,DD2,DD3,DD4,DDsalida;
    b=1;
    d = T[b];
    x = T[b+1];
    y = T[b+2];
    w = T[b+3];

    DD1 = D[b]/(((T[b]-T[b+1])*(T[b]-T[b+2])*(T[b]-T[b+3])));
    DD2 = D[b+1]/(((T[b+1]-T[b])*(T[b+1]-T[b+2])*(T[b+1]-T[b+3])));
    DD3 = D[b+2]/(((T[b+2]-T[b])*(T[b+2]-T[b+1])*(T[b+2]-T[b+3])));
    DD4 = D[b+3]/(((T[b+3]-T[b])*(T[b+3]-T[b+1])*(T[b+3]-T[b+2])));

    DDsalida=DD1*(6*z-2*y-2*x-2*w)+DD2*(6*z-2*y-2*d-2*w)+DD3*(6*z-2*x-2*d-2*w)+DD4*(6*z-2*x-2*d-2*y);
    return DDsalida;
}

//Llena un arreglo en incrementos de 1 en 1
void fill_array(int arr[],int Vi, int Vf)
{
    int i,j=0;
    for(i=Vi; i<Vf; i++)
    {
        arr[j] = i;
        j++;
    }
}

//Esta funcion imprime en la pantalla los valores de un vector de enteros
void printArrI(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("arr[%d]: %d\n",i,arr[i]);
    }
}

//Esta funcion imprime en la pantalla los valores de un vector de flotantes
void printArrF(float arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("arr[%d]: %.4f\n",i,arr[i]);
    }
}

//Esta funcion realiza los calculos de K
//Recibiendo las derivadas (dx,ddx,dy,ddy) el tamaño de los vectores y el puntero del vector K
void set_K(float dx[], float ddx[], float dy[], float ddy[], int tam, float K[])
{
	int i;
	float p1=0, p2=0, p3=0;
	for(i=0; i < tam; i++)
	{
		p1 = dx[i] * ddy[i];
		p2 = dy[i] * ddx[i];		
		p3 = (pow(dx[i],2) + pow(dy[i],2));
		p3 = pow(p3, (3/2));		
		K[i] = fabs((p1 + (p2 * (-1)))/p3);		
	}
	
}
