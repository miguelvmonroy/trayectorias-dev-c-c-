

En este documento se explica el funcionamiento del proyecto “Trayectorias”, el      
cual funciona con un programa en C++ que cuenta con un ambiente gráfico y una       
librería desarrollada en C que realiza todo el procesamiento de los datos, basada  
en el programa desarrollado por Miguel Eduardo Venegas Monroy en Matlab.              


El objetivo de este proyecto es el desarrollo de un software que provea la capacidad  
de que un usuario pueda ingresar ciertos puntos en un plano (X,Y) por medio de una  
interfaz gráfica y, que por medio de unos cálculos de interpolación, te retorne   
la misma gráfica pero con curvas más suaves.

Este proyecto consta de dos partes:

● C++: La primera parte esta desarrollada en el lenguaje C++, es la encargada
de proveer   
la interfaz gráfica con la que el usuario interactúa. Donde esté
ingresa los datos y muestra los resultados.

● C: La segunda parte es desarrollada en el lenguaje C, esta es la encargada
de la realización  
de todos los cálculos que se requieren, Como lo son los
cálculos de la interpolación, primera y    
segunda derivada. Para mayor
practicidad esta parte se implementó como una librería .h para   
ser incluida en
la parte del programa en C++.


A continuación se hará una descripción de las funciones que componen este proyecto, por
parte      
 de la interfaz gráfica desarrollada en C++ y la librería desarrollada en C.

2.1. Librería “interpolacion.h”                                     
La librería interpolación tiene como objetivo ser la que contenga las funciones que
realizan el procesamiento             
 de los datos de entrada que son los puntos o
coordenadas otorgados por el usuario, y de estos datos realizar               
 las operaciones para
calcular las derivadas y la interpolación de dichas coordenadas. Todo esto
desarrollado     
en el lenguaje C.

Funciones elaboradas                     
Dentro de esta librería se encuentran 8 funciones donde 5 de ellas tienen
comunicación entre sí y se dividieron         
 en funciones para un mejor orden y
entendimiento. Las funciones son las siguientes:

● Interpolar

● mi_interpolacion

● derivada

● segundaderivada

● set_k

● fill_array

● printArrI

● printArrF


A continuación se describirán cada una de estas funciones                    



2.1.1. Interpolar
Esta es la función principal del código ya que este es el que llama al resto de
funciones.        
Recibe once parámetros en los cuales 8 se almacenarán los resultados. Los
parámetros que recibe son     
 los siguientes:

● Vector X[ ]: Este vector contiene las coordenadas X ingresadas por el usuario.

● Vector Y[ ]: Este vector contiene las coordenadas Y ingresadas por el usuario.

● Vector dx[ ]: En este vector se almacenarán los resultados de la primera
derivada de X.

● Vector ddx[ ]: En este vector se almacenarán los resultados de la segunda
derivada de X.

● Vector dy[ ]: En este vector se almacenarán los resultados de la primera
derivada de Y.

● Vector ddy[ ]: En este vector se almacenarán los resultados de la segunda
derivada de Y.

● Vector int_x: En este vector se almacenarán los resultados de las
coordenadas de la interpolación en X.

● Vector int_y: En este vector se almacenarán los resultados de las
coordenadas de la interpolación en Y.

● Puntero size_x: En este puntero se guardará el valor de la longitud del vector
resultante de la interpolación en X (int_x).

● Puntero size_y: En este puntero se guardará el valor de la longitud del vector
resultante de la interpolación en Y (int_y).

● Entero punto: Esta variable entera indica el número de puntos que el usuario
marcó en el plano.

Dentro de esta función se llama a la función mi_interpolacion para realizar la
interpolación de “X” y “Y”         
llevándose los vectores necesarios y retornando el número
de datos que se utilizan.


Después por motivos de seguridad se realiza una condición donde se verifique que
los valores de tamaño  
 de datos a utilizar sea igual en x como en y, si son iguales ya
se puede calcular los valores de K, si no   
 despliega un mensaje.


si señor yo soy de peñasco
