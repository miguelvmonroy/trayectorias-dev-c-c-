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

Se crearon dos vectores de tipo entero con un tamaño de la constante MAXP para
contener las coordenadas X, Y que el usuario ingrese:

● X[MAXP]  
● Y[MAXP]

Se definen los arreglos que contienen los valores de las derivadas de la
interpolación:

● dx[MAX2]  
● ddx[MAX2]  
● dy[MAX2]  
● ddy[MAX2]   

Se definen también los arreglos resultado de la interpolación de la ruta “X” y “Y” .
Debido al problema de los vectores con  
 tamaño dinámico en C, se definen también
unas variables de tipo entero que indican el número de datos que almacena el
vector:

● int_x[MAX2]  
● int_y[MAX2]  
● size_x  
● size_y  

Dentro de la función (cuando comienza a funcionar después de realizar la creación
de las variables locales) se abre la  
 ventana gráfica con una dimensión de 600x600
pixeles.

Después se llama a la función plano para trazar los ejes del plano X, Y y se ingresan
los puntos con el ratón (mouse) en   
el plano por el usuario.

Después de haber ingresado los puntos se realiza la interpolación, haciendo el
llamado a la función Interpolar de la librería interpolacion .h

Una vez calculado esto dentro del programa, se tiene una función getch() para
generar una pausa antes de mostrar el   
resultado, por lo que se tendrá que presionar
cualquier tecla en el teclado para continuar y visualizar el resultado de la  
interpolación. Para esto se vuelve a trazar el plano y se llama a la función trazar2
para graficar el resultado.

Y por último, se cierra la ventana gráfica con la función closegraph() y termina el
programa.

►ginput

Esta función tiene como objetivo el guardar los puntos en el plano capturados por el
usuario, Almacenando estos valores   
en los vectores que recibe como parámetros X[
], Y[ ], con un límite de puntos definido por el parámetro num_points.

Dentro de esta función se utiliza un tipo de dato llamado POINT de la librería
graphics.h. Los objetos que son de este tipo   
son capaces de almacenar valores X y
Y. Utilizando la función GetCursorPos() obtenemos las coordenadas (x,y) de la  
posición del puntero (ratón) y las almacenamos en el objeto de tipo POINT.
Finalmente, con la función  
 GetAsyncKeyState(VK_LBUTTON), detectamos si ocurre
el evento en el que el usuario realiza click derecho con el ratón;   
para de esta forma
almacenar esas coordenadas en los vectores X, Y y se dibuja un punto en la
posición.

►plano

Esta es una función muy sencilla y tiene como único objetivo el trazar las líneas de
los ejes que marcan los cuadrantes en   
un plano (X,Y). Para trazar una línea se utilizan las funciones moveto() que se encarga de mover el origen del trazado de   
la línea y la función lineto() que dibuja la línea a la posición marcada.
Para trazar el eje Y se movió el origen a la mitad del  
 plano en el eje X y se trazó la
línea hasta el máximo del eje Y. Teniendo en cuenta que la pantalla es de 600x600
pixeles la,  
mitad es de 300 pixeles y el máximo es de 600 pixeles.

Para el eje X se usó la misma dinámica, pero al revés. Moviendo el origen a la mitad
del eje Y (300 pixeles) y trazando la línea  
 hasta el máximo del eje X (600 píxeles).

 ►trazar
 La función trazar fue creada para unir los puntos marcados por el usuario, y de esta
 forma poder visualizar la ruta  
  y el orden de una mejor manera; Recibiendo de
 parámetros los vectores con las coordenadas X, Y y el número de puntos.

 La función recibe las coordenadas y el número de puntos; y por medio de un ciclo va
 dibujando líneas del punto uno al   
 punto dos y así sucesivamente. Para una mejor
 visualización del orden se mostró el número del punto haciendo una   
 conversión de
 un número de entero (int) a una cadena (char) para poder imprimirlo en la pantalla de
 la siguiente manera:

 La función sprintf() guarda el valor de i en la variable n que es de tipo cadena (char)
 y con la función outtextxy() se  
  imprime en la pantalla gráfica en las coordenadas que
 le corresponde a ese punto, sumándole 10 pixeles para que no   
 se encima en el
 trazado de la línea.

►trazar2

El funcionamiento de la función trazar2() es igual al de trazar(). Recibiendo vectores
con las coordenadas X y Y, y el  
 número de puntos que son. Pero en este caso
recibe vectores de tipo flotante que son el resultado de la interpolación.

En este caso la función solamente graficara los puntos sin marcar el número del
punto, ya que aquí crecen demasiado,  
 trazando las líneas de un punto al siguiente y
mostrando una gráfica con curvas más suaves.
