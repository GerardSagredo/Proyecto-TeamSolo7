#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



/*
  //Al momento de leer respuestas o preguntas
  // se usara scanf("%s",respuestas[i])
*/


//const char arreglo[100]: arreglo de 100 casillas, cada casilla un struct
//incorporar arreglo de structs*
void CrearMazo();
void mostrarEstadisticas();
void practicar(List *listaMazos);

typedef struct{
  char* preguntas;
  char* respuestas;
  int aciertos;
  int errores;                
  int contador;

}Preguntas;


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
        CrearMazo();
        break;

        case 2: //Mostrar mazos guardados
        printf("Mostrando mazo\n");
        break;

        case 3: //Practicar
        //practicar(listaMazos);

        break;

        case 4: //Revisar estadisticas
        mostrarEstadisticas();
        break;

        case 5: //Eliminar un mazo

        break;

        case 6: //Modificar carta

        break;
      }

  }

  return 0;
}

void CrearMazo(){
  printf("ENTRA\n");
  List *listaMazos = createList();
  int cont=0,i=0;
  int numpreguntas=6;
  Preguntas* arregloPreguntas = calloc(numpreguntas, sizeof(arregloPreguntas));
  //FILE *f = fopen ( "nmazos.txt", "r");
 // char copia[1024];
 // char* Nummazo = (char*) malloc (sizeof(char));
  //Nummazo = strtok(copia, " ");
  //printf("nombre %s",Nummazo);

  //while(fgets(copia,1024,f) != NULL){
    
    FILE *fp = fopen ( "mazo1.txt", "r");
    char texto[1024];
   
    while(fgets(texto,1024,fp) != NULL){
    
    //printf("texto que entra: %s", texto);
      if(cont==0){
        cont++;
        arregloPreguntas[i].preguntas=texto;
        printf("pregunta %d: %s",i,arregloPreguntas[i].preguntas);
        printf("pregunta [%d]: %s\n",i-1,arregloPreguntas[i-1].preguntas);
      
      }else{
        cont--;
        arregloPreguntas[i].respuestas=texto;
        printf("respuesta%d: %s\n",i,arregloPreguntas[i].respuestas);
        i++;
      }
    }

  //}

  
    printf("-------- \n");
    i=0;
    printf("%d\n",numpreguntas);
    while(i!=numpreguntas){
      
      printf("pregunta %d: %s\n",i,arregloPreguntas[i].preguntas);
      printf("respuesta %d: %s\n",i,arregloPreguntas[i].respuestas);
      i++;
  }






  printf("SALE\n");
}












void mostrarEstadisticas(){

  //Considerar guardar solo numeros en el txt para facilitar su reemplazo al guardar los datos. (referencia: https://www.cs.utah.edu/~germain/PPS/Topics/C_Language/file_IO.html)


  char *filename = "datosGuardados.txt";
  FILE *fp = fopen(filename, "r");

  if (fp == NULL)
  {
    printf("Error: no se pudo abrir %s", filename);
  }
  else
  {
    // Se lee linea por linea, con un maximo de 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp))
        printf("%s", buffer);

    // Cerrar documento
    fclose(fp);

  }
  
}

/*void sobreescribir(){

  
}*/

/*

void practicar(List *listaMazos){
  char mazo[20];
  scanf("%s",mazo);
  char *lmazos = firstList(listaMazos);

  while(strcmp(mazo)){

  }



}
*/