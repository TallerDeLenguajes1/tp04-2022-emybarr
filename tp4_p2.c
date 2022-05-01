#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Tarea{
              int TareaID;
              char *Descripcion;
              int Duracion;
}; typedef struct Tarea tarea;

void cargarTarea(tarea **tareas, int cantidad );
void mostrarTarea(tarea *tarea);
void Todo(tarea **tareas,tarea **tareasrealizadas,int n );
void busquedaporId(tarea **tarea, int n);
void buscarPalabra(tarea **t, int n);
int main(){
            int ntareas;
            tarea **tareas, **trealizadas ;

            printf("Ingrese la cantidad de tareas :\n");
            scanf("%d",&ntareas);
             fflush(stdin);

            tareas = (tarea**)malloc(sizeof(tarea*)*ntareas);
            trealizadas=(tarea**)malloc(sizeof(tarea*)*ntareas);
          
           

printf("Ingrese la descripcion de las tareas ;  \n");
cargarTarea(tareas,ntareas);
printf(" \n");
printf("Mostrar todas las tareas cargadas \n");
for(int i =0; i < ntareas;i++){
    if(tareas[i] !=NULL){
        mostrarTarea(tareas[i]);
    }
}
printf(" \n");

busquedaporId(tareas,ntareas);
buscarPalabra(tareas, ntareas);

Todo(tareas,trealizadas,ntareas);

printf(" \n");
printf("Tareas realizadas \n");
for(int i =0; i < ntareas;i++){
    if(trealizadas[i] !=NULL){
        mostrarTarea(trealizadas[i]);
    }
}
printf(" \n");
printf("Tareas no realizadas \n");
for(int i =0; i < ntareas;i++){
    if(tareas[i] !=NULL){
        mostrarTarea(tareas[i]);
    }
}
printf(" \n");


free(trealizadas);
free(tareas);

getchar();

return 0;

}


void cargarTarea(tarea **tareas, int cantidad ){

    for(int i = 0; i < cantidad; i++){
        printf("-------TAREA [%d]-------- \n" , i + 1 );
        tareas[i]=(tarea*)malloc(sizeof(tarea));
        tareas[i]->TareaID= i + 1 ;
        tareas[i]->Duracion = 1 + rand() % 10;
        tareas[i]->Descripcion= (char*)malloc(50*sizeof(char));
        printf("Descripcion ");
        gets(tareas[i]->Descripcion);
        fflush(stdin);
        printf(" \n");

    }
}


void mostrarTarea(tarea *tarea){
    printf("----------Tarea [%d]---------- \n" , tarea->TareaID);
    printf("Duracion:  %d  \n", tarea->Duracion);
    printf("Descripcion : %s \n", tarea->Descripcion);
    printf("-------------------------------------------");
    fflush(stdin);
    printf(" \n");

}

void Todo(tarea **tareas,tarea **tareasrealizadas, int n ){
    int numero;
    for(int i = 0; i < n; i++){
        printf("SELECCION \n");
        mostrarTarea(tareas[i]);
        fflush(stdin);
        printf("La tarea fue realizada ? SI = 1 || NO = 0 \n ");
        scanf("%d",&numero);
        fflush(stdin);

        if(numero == 1){
            tareasrealizadas[i]=tareas[i];
            tareas[i]=NULL;
        }else{
            tareasrealizadas[i]=NULL;

        }
    }

}


void busquedaporId(tarea **t, int n){
    int id;
    printf("Ingrese el ID ");
    scanf("%d",&id);
     fflush(stdin);

    if( id > n ){
        printf("El id no pertenece");
           printf(" \n");
    }else{
        printf("Tarea encontrada");
           printf(" \n");
    }
}

   void buscarPalabra(tarea **t, int n){
        char palabra[50];
        char *palabraencontrada;
        int igual= 0;

        printf("Ingrese una palabra \n");
        gets(palabra);
         fflush(stdin);

        for(int i = 0;i< n;i++){

            palabraencontrada=strstr(t[i]->Descripcion,palabra);

            if(palabraencontrada !=NULL){
                mostrarTarea(t[i]);
                igual++;
            }
        }
        if( igual == 0){
            printf("no hay coicidencia");
        }

    }

