#include <LibEdificio.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  helipuerto.encender();
  
  delay(1000);

  helipuerto.apagar();
  
  delay(1000);
}
