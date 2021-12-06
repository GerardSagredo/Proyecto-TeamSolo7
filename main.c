#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


void CrearMazo();
void mostrarEstadisticas();
void practicar(List *listaMazos);
//void sobreescribir(Preguntas,int,int);

typedef struct{
  char preguntas[20];
  char respuestas[20];
  int aciertos;
  int errores;                
  int contador;

}Preguntas;


int main(void) {//Interfaz de la app
  printf("\n  --------------------------------\n");
  printf("    ** MENU DE APLICACION ANKI **      \n");
  printf("  --------------------------------\n");
  printf("   » Opcion 1: Crear mazo \n");
  printf("   » Opcion 2: Mostrar mazos guardados \n");
  printf("   » Opcion 3: Practicar \n");
  printf("   » Opcion 4: Revisar estadisticas \n");
  printf("   » Opcion 5: Eliminar un mazo \n");
  printf("   » Opcion 6: Modificar carta \n");
  printf("   » Opcion 7: Salir \n\n");

  int mazosHoy = 0; // Incluir y aumentar en 1 al empezar a usar un mazo

 //Cargar las variables a partir de los datosGuardados.txt(pendiente)

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

        case 7: //Salir - Se debe guardar datos antes de salir
        //sobreescribir(arregloPreguntas,mazosHoy,totalMazos);
        return 0;
      }

  }

  return 0;
}





void CrearMazo(){
  printf("ENTRA\n");
  FILE *fp = fopen ( "mazo1.txt", "r");
  char texto[20];
  int cantpreg,i=0,cont=0;
  fscanf(fp,"%d", &cantpreg);   //lee y almacena en variable la cantidad de preguntas indicada.

  printf("%d\n", cantpreg);
  Preguntas* arregloPreguntas = malloc(cantpreg * sizeof(arregloPreguntas));
  fgets(texto,1024,fp);

  while(i!=cantpreg){
   ;
    strcpy(arregloPreguntas[i].preguntas,fgets(texto,20,fp));
    strcpy(arregloPreguntas[i].respuestas,fgets(texto,20,fp));
    i++;

  }
  
  for(i=0;i<cantpreg;i++){
    
    printf("p[%d]:%s\n",i,arregloPreguntas[i].preguntas);
    printf("r[%d]:%s\n",i,arregloPreguntas[i].respuestas);
    printf("----------------------------\n");
  }
}

void mostrarEstadisticas(){
  //Se abre el documento en busqueda de datos guardados
  char *filename = "datosGuardados.txt";
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) //Si algo falla
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

void sobreescribir(Preguntas arregloPreguntas, int mazosHoy, int totalMazos){//Esta funcion se encargara de actualizar los datos.
//Debe ser ejecutada al salir de la app.

//Se abre el mismo documento pero ahora para escribir.
  char *filename = "datosGuardados.txt";
  FILE *fptr;
  fptr = fopen(filename, "w");
  //Se introducen los nuevos valores en el mismo documento de texto
  fprintf(fptr, "Aciertos: %d\n", arregloPreguntas.aciertos);
  fprintf(fptr, "Errores: %d\n", arregloPreguntas.errores);
  fprintf(fptr, "Mazos usados hoy: %d\n", mazosHoy);
  fprintf(fptr, "Total de mazos usados: %d\n", totalMazos);

  fclose(fptr);
}/*

void practicar(List *listaMazos){
  char mazo[20];
  scanf("%s",mazo);
  char *lmazos = firstList(listaMazos);

  while(strcmp(mazo)){

  }



}
*/