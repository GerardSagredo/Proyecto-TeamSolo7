#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



/*
  //cabros me robaron el celular y me quede sin whatsapp, si necesitan algo o el profe avisa algo porfa mandenlo al ds o escribanlo por aca //dale
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
  Preguntas* arregloPreguntas = malloc(1* sizeof(arregloPreguntas));
  FILE *fp = fopen ( "mazo1.txt", "r");
  
    char texto[1024];
    int cont=1;
    int i;
    int contpreguntas=0;
    while(fgets(texto,1024,fp) != NULL){
      if(strlen(texto)==0) break;
    
      
      if(strcmp(texto,"\n")!=0){
        
        if(cont==1){
       contpreguntas++;
       arregloPreguntas = realloc(arregloPreguntas,contpreguntas* sizeof(arregloPreguntas));
        cont--;
        strcpy(arregloPreguntas[i].preguntas,texto);
        printf("pregunta %d: %s",i,arregloPreguntas[contpreguntas].preguntas);
      }else{
        cont++;
        strcpy(arregloPreguntas[i].respuestas,texto);
        printf("respuesta %d: %s\n",i,arregloPreguntas[contpreguntas].respuestas);
        i++;
      }


      }
   
      
      
  
    }
    
    
printf("++++++++++++++++++++++++++++\n");
 for(i=1;i<contpreguntas+1;i++){
  printf("pregunta %d: %s",i,arregloPreguntas[i].preguntas);
  printf("respuesta %d: %s\n",i,arregloPreguntas[i].respuestas);
 }

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

void sobreescribir(Preguntas arregloPreguntas){//Esta funcion se encargara de actualizar los datos.

//Se abre el mismo documento pero ahora para escribir.
  char *filename = "datosGuardados.txt";
  FILE *fptr;
  fptr = fopen(filename, "w");
  //Se introducen los nuevos valores en el mismo documento de texto
  fprintf(fptr, "Aciertos: %d\n", arregloPreguntas.aciertos);
  fprintf(fptr, "Errores: %d\n", arregloPreguntas.errores);
  fprintf(fptr, "Mazos usados hoy: %d\n", arregloPreguntas.aciertos);
  fprintf(fptr, "Total de mazos usados: %d\n", arregloPreguntas.aciertos);

  fclose(fptr);
}

/*

void practicar(List *listaMazos){
  char mazo[20];
  scanf("%s",mazo);
  char *lmazos = firstList(listaMazos);

  while(strcmp(mazo)){

  }



}
*/