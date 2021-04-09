#include <stdio.h>
#include <stdlib.h>

#define QUANTUM_UNITS 2


struct node {
    char nombre;
    int num;
    struct node * nextptr;
}*stnode;
 
// Prototipo de funciones
int crearLista(int n);
void mostrarLista(int x);
void cursorAyuda();
// -------------------------------------------------
int main()
{
  int n, x;
  stnode = NULL;
	printf("\n\n Simulacion Round Robin :\n");
	printf("--------------------------\n");

    printf("Ingresa la cantidad de nodos : ");
    scanf("%d", &n);

    x = crearLista(n); 
    //cursorAyuda();
    mostrarLista(x);
    return 0;
}
// -----------------------------------------------------

//---------------------------------------------------------
int crearLista(int n)
{
    int i, num;
    char nombre;
    struct node *preptr, *newnode;
    int arreglo[10]= {0};
    int a,b;
    int loop;
    int mayor;
    int posMayor =0;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));
        printf("\nIngresa la letra del proceso : ");
        scanf(" %c", &nombre);
        printf("Ingresa las unidades del proceso 1 : ");
        scanf("%d", &num);

        stnode -> nombre = nombre;
        stnode-> num = num;

        stnode->nextptr = NULL;
        preptr = stnode;

        a = num;
        arreglo[0]=num;


        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("\nIngresar informacion del nodo %d : ", i);
            printf("\nLetra del proceso: ");
            scanf(" %c", &nombre);
            printf("Unidades del proceso: ");
            scanf("%d", &num);

            b = num;
            arreglo[i-1]=num;
            
         
            newnode->nombre = nombre;
            newnode->num = num;
            newnode->nextptr = NULL;	// A la siguiente direccion del nuevo nodo se le coloca NULL

            preptr->nextptr = newnode;	//El nodo anterior se linkea con el nuevo nodo
            preptr = newnode;   		// El nodo anterior avanza


        }
        preptr->nextptr = stnode; 		//El ultimo nodo se linkea con el primer nodo
    }
    //Se selecciona el elemento mayor 
    mayor = arreglo[0];
    for(int i = 1; i < n; ++i)
    {
        if(arreglo[i] > mayor)
        {
            mayor = arreglo[i];
            posMayor = i;
        }
    }

    return mayor;



}
// ------------------------------------------------------

// ------------------------------------------------------
void mostrarLista(int x)
{
    //struct node *tmp;
    int n = 1, i, a;

    int num_giros = x / QUANTUM_UNITS;

    if(stnode == NULL)
    {
        printf("No hay informacion");
    }
    else
    {
        printf("\nRound Robin:\n");
        for(i = 1; i<= num_giros; i++){
          printf("\nGiro numero %d\n", i);
          cursorAyuda();
          printf("\n");
          

        }
    }
}
// ------------------------------------------------------------

void cursorAyuda(){
  struct node *tmp;
  int n =1, x;
  tmp = stnode;
  do {
            x = tmp->num;
            tmp -> num = tmp -> num - QUANTUM_UNITS;
            if(tmp->num >= 0){
              
              printf("\nProceso %c = Numero de procesos inicial: %d || Numero de procesos despues del giro : %d", tmp->nombre, x, tmp->num);
              
            }

            tmp = tmp->nextptr;
            n++;
        }while(tmp != stnode);
}