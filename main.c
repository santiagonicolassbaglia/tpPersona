#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20


typedef struct
{

    int dni;
    char nombre[50];
    int flagEstado;
    int edad;

}ePersona;


void agregarPersona(ePersona [], int);
void borrarPersona(ePersona [], int);
void mostrarGraficoEdades(ePersona []);
int buscarLibre(ePersona [], int);
void ordenarLista(ePersona [], int);
void mostrarTodasLasPersonas(ePersona lista[],int);


int main()
{
    ePersona listaPersonas[TAM];
    int i;
    int indice= 0;
    int opcion;
    char seguir='s';


    for(i=0; i<TAM; i++)
    {
        listaPersonas[i].flagEstado=0;
    }


    while(seguir=='s')
    {
    printf("Elija la opcion que desee: \n");
    printf("1. Agregar una persona\n");
    printf("2. Borrar una persona\n");
    printf("3. Imprimir lista ordenada por nombre\n");
    printf("4. Imprimir gráfico de edades\n");
    printf("5. Salir\n\n");

    scanf("%d",&opcion);
    fflush(stdin);

    switch(opcion)
    {
        case 1:
            printf("USTED HA SELECCIONADO: INGRESAR PERSONA \n");
            agregarPersona(listaPersonas, TAM);

            break;

        case 2:
            printf("Escoja el numero de la lista el cual desea eliminar: \n");
            scanf("%d",&indice);
            fflush(stdin);

            borrarPersona(listaPersonas, indice);
            break;
        case 3:
            ordenarLista(listaPersonas, TAM);
            break;

        case 4:


            break;

    }


    printf("Quiere elegir otra opcion? S/N\n");
    scanf("%c",&seguir);
    fflush(stdin);
   }
}





void agregarPersona(ePersona lista[], int tamanio)
    {
        int libre = buscarLibre(lista,tamanio);


        if(libre==0)
        {
            printf("Ingrese dni: \n");
            scanf("%d",&lista[libre].dni);
            fflush(stdin);

            printf("Ingrese nombre: \n");
            fflush(stdin);
            gets(lista[libre].nombre);

            printf("Ingrese edad: \n ");
            scanf("%d",&lista[libre].edad);
            fflush(stdin);

            lista[libre].flagEstado=1;
        }

    }



    void borrarPersona(ePersona lista[], int lugarBorrarLista)
    {

        int i=0;
        if ( lista[lugarBorrarLista].flagEstado==1)
            {
                for (i=0; i < sizeof(lista[lugarBorrarLista].nombre)-1; i++)
                {
                //lista[lugarBorrarLista].nombre[i] = '';
                }
                lista[lugarBorrarLista].edad=0;
                lista[lugarBorrarLista].dni=0;
                lista[lugarBorrarLista].flagEstado=0;

                printf("la persona se ha eliminado correctamente..");
            }
        else
            {
                printf("Hubo un error al querer eliminar.. por favor intentelo de nuevo");
            }
    }


    void ordenarLista(ePersona lista[], int tamanio )
    {
        int i,j;

        for(i=0; i<tamanio-1; i++)
        {
            for(j=i+1; j<tamanio; j++)
            {

                ePersona auxPersona;

                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxPersona=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxPersona;
                }
            }
        }
    }

    void mostrarGraficoDeEdades(ePersona lista[])
    {

    }


    void mostrarPersona(ePersona persona)
    {
        printf("%s----%d----%d\n",persona.nombre,persona.dni,persona.edad);
    }

   void mostrarTodasLasPersonas(ePersona lista[],int tam)
   {

    int i;

    for(i=0; i<tam; i++)
    {

        if(lista[i].flagEstado==1)
        {
            mostrarPersona(lista[i]);
        }
    }
   }




    int buscarLibre(ePersona lista[],int tamanio)
    {
        int i;
        int libre=0;
        for(i=0; i<tamanio; i++)
        {

            if(lista[i].flagEstado==0)
            {

                libre=i;
                break;
            }
            else if(lista[i].flagEstado==1)
            {
                libre=-1;
            }

        }

        return libre;

    }





/*int valor[] = {1, 3, 9, 7, 5};

   int max;

   max = 0;
   for (i = 0; i < 5; i++)
      if (valor[i] > max)
         max = valor[i];

   for (i = max; i > 0; i--){
      for (j = 0; j < 5; j++)
         if (valor[j] >= i)
            printf(" *");
         else
            printf("  ");

      putchar('\n');
   }

   return EXIT_SUCCESS;*/





