//Incluyo la libreria de manejo de la estacion Interseccion de Calles.
#include <LibEdificio.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  piso1.encender();
  piso2.encender();
  piso3.encender();
  piso4.encender();
  
  piso5.apagar();
  piso6.apagar();
  piso7.apagar();
  piso8.apagar();
  
  delay(1000);

  piso1.apagar();
  piso2.apagar();
  piso3.apagar();
  piso4.apagar();
  
  piso5.encender();
  piso6.encender();
  piso7.encender();
  piso8.encender();
  
  delay(1000);

}

