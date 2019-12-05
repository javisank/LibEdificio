/*
  LibEdificio.h - Libreria para el manejo de la 
  estacion de las luces del Edificio.
  Javier Sankowicz.
*/

#include "Arduino.h"
#include "LibEdificio.h"

/* ************ Funciones de la clase Luz Piso ************ */

LuzPiso::LuzPiso(int pin)
{
	pinMode(pin,OUTPUT);
	_pin = pin;
	digitalWrite(_pin,LOW);
}

void LuzPiso::encender()
{
	digitalWrite(_pin,HIGH);
}

void LuzPiso::apagar()
{
	digitalWrite(_pin,LOW);
}

/* ********************************************************** */


/* ************ Funciones de la clase Sensor ************ */

Sensor::Sensor(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Sensor::leer()
{
	return(digitalRead(_pin));
}

void Sensor::esperar(int estado)
{
	while(leer()!=estado);
} 

/* ********************************************************** */

/* ************ Funciones de la clase Pulsador ************** */

Pulsador::Pulsador(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Pulsador::leer()
{
	return(digitalRead(_pin));
}

void Pulsador::esperar(int estado)
{
	while(leer()!=estado);
}

/* ********************************************************* */

/* ************Ingresar numero por puerto serie************** */

int ingresar_numero()   //devuelve un entero que va de -32768 a 32767
{
  String readString;
  
  while(!(Serial.available()>0));

  while(Serial.available()>0)
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  int number = readString.toInt();

  return number;
}

/* ********************************************************* */

/* ************Funciones imprimir texto********************* */

void mostrar_cartel(String text)
{
	Serial.print(text);
	Serial.print(" ");
}

void mostrar_numero(int num)
{
	Serial.println(num);
}

/* ********************************************************* */

/* *****************Inicializacion************************** */
void inicializar_sistema()
{
	Serial.begin(9600);
	
}
/* ********************************************************* */

/* ******************Finalizacion*************************** */
void finalizar()
{
	while(1);
}
/* ********************************************************* */

//Variables para manejo de sensores y pulsadores
int estado_sensor_luz=DIA;
int estado_pulsador=NO_PRESIONADO;
int numero_ingresado=0;

//Variable para contador
int contador=0;

//Variables elementos del sistema
LuzPiso piso1(pin_piso1);
LuzPiso piso2(pin_piso2);
LuzPiso piso3(pin_piso3);
LuzPiso piso4(pin_piso4);
LuzPiso piso5(pin_piso5);
LuzPiso piso6(pin_piso6);
LuzPiso piso7(pin_piso7);
LuzPiso piso8(pin_piso8);

Sensor sensor_luz(pin_sensor_ldr);

Pulsador pulsador(pin_pulsador);