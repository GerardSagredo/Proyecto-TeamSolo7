#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



typedef struct{
  const char respuestas[100]; //Al momento de leer respuestas o preguntas
  int errores;                // se usara scanf("%s",respuestas[i])
  int aciertos;
  int contador;
}soluciones;

//const char arreglo[100]: arreglo de 100 casillas, cada casilla una oracion (string).

typedef struct{
  const char preguntas[100];
  soluciones soluciones; //Ambos deben tener el mismo tamaño y
                 // pregunta[i] y soluciones->respuestas[i] deben coincidir.
}Mazo;


int main(void) {
  printf("\n  --------------------------------\n");
  printf("    ** MENU DE APLICACION ANKI **      \n");
  printf("  --------------------------------\n");
  printf("   » Opcion 1: Crear mazo \n");
  printf("   » Opcion 2: Mostrar mazos guardados \n");
  printf("   » Opcion 3: Practicar \n");
  printf("   » Opcion 4: Revisar estadisticas \n");
  printf("   » Opcion 5: Eliminar un mazo \n");
  printf("   » Opcion 6: Modificar carta \n\n");

  int mazosHoy = 0; // Incluir y aumentar en 1 al empezar a usar un mazo

 //Cargar totalMazos (uso historico de mazos)

  int estadisticas[4]; //Este arreglo incluye: int_errores, int_aciertos, mazosHoy, totalMazos.

  while(1){
    int opcion; 
    scanf("%d",&opcion);
      switch (opcion){
        case 1: //Crear mazo
        printf("Creando mazo\n");
        break;

        case 2: //Mostrar mazos guardados
        printf("Mostrando mazo\n");
        break;

        case 3: //Practicar

        break;

        case 4: //Revisar estadisticas

        break;

        case 5: //Eliminar un mazo

        break;

        case 6: //Modificar carta

        break;
      }

  }

  return 0;
}

/*void CrearMazo(List * Mazos){
  List *listaMazos = createList();
  char contenido[20];
  scanf("%s",contenido);
  Mazo* mazo  = ( Mazo*) malloc(sizeof(Mazo));
  soluciones * mazo->soluciones = (soluciones *) malloc(sizeof(soluciones));
  while(strcmp(contenido,"NULL")==0){
   
    scanf("%s",contenido);
  }

}*/