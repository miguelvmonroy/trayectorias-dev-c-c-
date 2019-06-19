>*En este documento se explica el funcionamiento del proyecto “Trayectorias”, el      
>cual funciona con un programa en C++ que cuenta con un ambiente gráfico y una       
>librería desarrollada en C que realiza todo el procesamiento de los datos, basada  
>en el programa desarrollado por Miguel Eduardo Venegas Monroy en Matlab.*           


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

►Librería “interpolacion.h”   

La librería interpolación tiene como objetivo ser la que contenga las funciones que
realizan el procesamiento             
 de los datos de entrada que son los puntos o
coordenadas otorgados por el usuario, y de estos datos realizar               
 las operaciones para
calcular las derivadas y la interpolación de dichas coordenadas. Todo esto
desarrollado     
en el lenguaje C.

►Funciones elaboradas                     
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



►Interpolar

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


Después, por motivos de seguridad, se realiza una condición donde se verifique que
los valores de tamaño  
 de datos a utilizar sea igual en x como en y, si son iguales, ya
se puede calcular los valores de K, si no,  
 despliega un mensaje.


►mi_interpolacion

En esta función se realiza la interpolación de las coordenadas de la ruta a tomar, así
como el cálculo de la    
primera y segunda derivada de los puntos. Esta función recibió
una modificación a comparación de la versión  
 anterior es el cambio de valor de una
variable dentro de uno de los ciclos. Este cambio se mostrara   
mas adelante.

Se reciben como parámetros:

● D[ ]: Este es el vector que contiene las coordenadas ya sea X o Y.

● puntos: El número de puntos o coordenadas que se envían.

● numero_des: Este ayuda para definir el incremento en la división o pedazos
por los que se analiza la gráfica.

Debido a que en C es difícil retornar un arreglo, se utilizó la ventaja de los punteros.
Esto se refiere a que referenciamos   
la ubicación de almacenamiento en memoria del
arreglo. de esta manera los cambios que se le hagan al arreglo   
dentro de la función
si lo afectarán sin la necesidad de realizar un retorno. En C al mandar un arreglo como parámetro  
 (int arr[ ]) ya estás indicando que es un puntero:

● aa[ ]: Este almacena los valores de la interpolación

● pd[ ]: Este arreglo almacena los valores de la primera derivada.

● sd[ ]: Aquí se almacenan los valores de la segunda derivada.

Después dentro de un ciclo se realiza el proceso de sacar la interpolación y las
derivadas del vector D[ ].

Al final de la función solamente se retorna el valor de j, donde este es un contador
para almacenar el número de datos almacenados en los arreglos y así saber el
tamaño de datos útiles.

►Modificación

Uno de los problemas que se tenía con la versión anterior era el tamaño que se
entregaba en los vectores,   
resultado de la interpolación y derivadas. Se realizó el
cambio en la inicialización de la variable b de 1 a 0;   
 Lo que nos entrega vectores más
grandes, permitiéndonos tener en el resultado final curvas más suaves.

-Derivada

Esta función realiza la primera derivada de la función. Los cambios hechos en el
traspaso de Matlab a C fueron casi nulos.

-Segunda derivada

De igual forma que en la función de la primera derivada, el cambio que se realizó fue
casi nulo quedando de la siguiente forma.

-set_K

En esta función se realiza el cálculo del vector K establecido en la función Interpolar
por motivos de que la función no se extendiera demasiado.

Recibiendo como parámetros las derivadas de (x,y), el tamaño de los vectores y el
puntero del vector K.

-fill_array

El objetivo de esta función es el de llenar un vector de forma sencilla Cuando se
requiere que sus valores sean incrementos de 1 en 1.  
Esta función recibe el vector, el inicio y el fin de los datos con los que se va a
rellenar.

-printArrI y printArrF

Estas dos funciones tienen el objetivo de imprimir los valores de un vector. la
diferencia es que una función imprime vectores con  
valores entero (int) y la otra de
valores flotantes (float),
Recibiendo como parámetros el vector y su tamaño.



►Desarrollo gráfico

Esta sección fue desarrollada para interactuar con el usuario, proveyendo una
interfaz gráfica para el ingreso y una mejor  
 visualización de los datos, desarrollado
en el lenguaje de C++ utilizando la librería graphics.h como herramienta para el  
desarrollo gráfico.

Dentro de esta parte gráfica se cuentan con las siguientes funciones:

● main  
● ginput  
● plano  
● trazar  
● trazar2

A continuación, se hará una descripción de cada una de estas funciones que forman
parte del proyecto en C++.

-main

Esta es la función que, como su nombre lo dice, es la principal del proyecto. Dentro
de esta se hacen los llamados de las  
 funciones realizadas en C++ y las
desarrolladas en C en la librería interpolacion.h.
En esta función se hace la inicialización   
de arreglos y variables que serán
necesarias en todo el proceso. Se utiliza una constante llamada MAX2, la cual tiene un  
 valor de 500; esto es para crear vectores grandes, ya que en C no se pueden crear
vectores con un tamaño dinámico.
