# PID_DC_Motor
controlador PID diseñado para el control de motor de corriente directa
<img src="https://user-images.githubusercontent.com/47931397/145720033-59937e55-6ef9-49b0-88d2-090763eee9a4.png">

### 1 DISEÑO PID ANTI WIND-UP

<img src="https://user-images.githubusercontent.com/47931397/145720072-b3c49229-fc95-431c-aa67-2e31862c6ad1.png">
<img src="https://user-images.githubusercontent.com/47931397/145720107-39bd5b06-2b15-47b6-b243-a08ab51fe9d5.png">

#### Simulacion 

<img src="https://user-images.githubusercontent.com/47931397/145720471-27cf6a51-3e29-41a9-9333-cf2d3e474288.png">

#### Resultados

<img src="https://user-images.githubusercontent.com/47931397/144941089-ef4cbd89-67ce-449c-99c4-52c3104033fe.png">

### 2 IMPLEMENTACION 

En el diagrama siguiente se puede observar las conexiones necesarias para poder implementar el algoritmo de control. Para la lectura de pulsos del encoder se configura un pin como interrupción externa y para la salida del controlador se configura la salida PWM por un pin.

<img src="https://user-images.githubusercontent.com/47931397/145720194-6c68e197-bf31-45dc-bfb3-1dcc425cf1fd.png">
El control se realiza en esta rutina de servicio de interrupción, esta ISR se ejecuta cada 10ms (Periodo de muestreo)
<img src="https://user-images.githubusercontent.com/47931397/145720511-437c3cc2-a96c-4d9e-8936-4048df453cef.png">


### 2.2 EMBEDDED CODER - SIMULINK
El siguiente modelo Simulink es el usado para Embedded coder para la generación de código y aplicar el algoritmo de control implementado. Se puede observar que dentro del bloque “ALGORITMO DE CONTROL” el subsistema MRAC que en este caso sería el algoritmo de control elegido y el cual será programado en el microcontrolador STM32L412KBU. En este caso todo el programa será ejecutado por el MCU, otra opción sería realizar una implementación conjunta con simulink donde la referencia y la salida sea establecido y visualizado respectivamente por el simulink.

<img src="https://user-images.githubusercontent.com/47931397/144938440-4a7c0afc-1527-4dab-a31d-a6493553fc05.png">

### 2.1 IMPLEMENTACION PID USANDO EMBEDDED CODER - SIMULINK
En este caso Embedded coder generará un código optimizado que podrá ser compilado y cargado al microcontrolador con un entorno de desarrollo, para este propósito usaremos Arm Keil uVision. Adicionalmente se hace uso del entorno gráfico STM32CubeMx el cual nos permitirá configurar el MCU de manera gráfica. Este entorno es proporcionado por el fabricante y nos ahorra el tiempo para poder centrarnos mas en la aplicación y no mucho en la inicialización de los periféricos del MCU, ahorrándonos tiempo.
El subsistema mostrado a continuación es el controlador PID implementado en MCU, para este caso se diseñó un PID Anti Wind-UP. Embedded coder generará el código optimizado la para poder ser compilado y cargado al MCU.
<img src="https://user-images.githubusercontent.com/47931397/144938727-2f7a1a9d-e63f-4bab-b591-1277291ed1c2.png">
<img src="https://user-images.githubusercontent.com/47931397/144938841-07790a11-af89-424d-b966-d6f19d4cc8e5.png">

#### Resultado

<img src="https://user-images.githubusercontent.com/47931397/144939379-78c8121e-d710-44cf-84cc-6cb67e7fefd3.png">

A continuación, se muestra la salida PWM del microcontrolador. El PWM generado es de 40KHz y el ancho de pulso variará de acuerdo con la entrada de referencia

<img src="https://user-images.githubusercontent.com/47931397/144939444-66532b47-efb0-4835-b4d2-eb618e93f271.png">

## AUTOR 
### - Quino B. Jeffry
  - dowhile98@gmail.com
  - WhatsApp: +51 955207709
