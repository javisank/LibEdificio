/*
  LibEdificio.h - Libreria para el manejo de la 
  estacion del cruce de calles con semaforos.
  Javier Sankowicz.
*/

#ifndef LibEdificio_h
#define LibEdificio_h

#include "Arduino.h"

#define ACTIVADO HIGH
#define DESACTIVADO LOW

#define PRESIONADO HIGH
#define NO_PRESIONADO LOW

#define DIA HIGH
#define NOCHE LOW


#define REPETIR(X) for(int i=0;i<X;i++)

const int pin_piso1 = 2;
const int pin_piso2 = 3;
const int pin_piso3 = 4;
const int pin_piso4 = 5;
const int pin_piso5 = 6;
const int pin_piso6 = 7;
const int pin_piso7 = 8;
const int pin_piso8 = 9;

const int pin_sensor_ldr = 10;
//const int sensor_pir = 11;
const int pin_pulsador = 11;

class LuzPiso {
	public:
		LuzPiso(int pin);
		void encender();
		void apagar();
	private:
		int _pin;
};

class Sensor
{
	public:
		Sensor(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
	
};

class Pulsador
{
	public:
		Pulsador(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
};


extern void mostrar_cartel(String);
extern void mostrar_numero(int num);
extern int ingresar_numero();
extern void inicializar_sistema();
extern void finalizar();

//Variables para manejo de sensores y pulsadores
extern int estado_sensor_luz;
extern int estado_pulsador;
extern int numero_ingresado;

//Variable Contador
extern int contador;

//Variables elementos del sistema
extern LuzPiso piso1;
extern LuzPiso piso2;
extern LuzPiso piso3;
extern LuzPiso piso4;
extern LuzPiso piso5;
extern LuzPiso piso6;
extern LuzPiso piso7;
extern LuzPiso piso8;

extern Sensor sensor_luz;

extern Pulsador pulsador;


#endif

