#include <stdio.h>
#include <stdlib.h>

#define QUANTUM_UNITS 2


struct node {
    char nombre;
    int num;
    struct node * nextptr;
}*stnode;
 
// Prototipo de funciones
void crearLista(int n);
void mostrarLista();
// -------------------------------------------------
int main()
{
  int n;
  stnode = NULL;
	printf("\n\n Lista Circular Ligada :\n");
	printf("----------------------------------------\n");

    printf("Ingresa la cantidad de nodos : ");
    scanf("%d", &n);

    crearLista(n); 
    mostrarLista();
    return 0;
}
// -----------------------------------------------------

//---------------------------------------------------------
void crearLista(int n)
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
        //for(loop = 0; loop < 10; loop++)
         //printf("%d ", arreglo[loop]);

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
            
            //for(loop = 0; loop < 10; loop++)
            //printf("%d ", arreglo[loop]);
         
            newnode->nombre = nombre;
            newnode->num = num;
            newnode->nextptr = NULL;	// A la siguiente direccion del nuevo nodo se le coloca NULL

            preptr->nextptr = newnode;	//El nodo anterior se linkea con el nuevo nodo
            preptr = newnode;   		// El nodo anterior avanza


        }
        preptr->nextptr = stnode; 		//El ultimo nodo se linkea con el primer nodo
    }
    mayor = arreglo[0];
    for(int i = 1; i < n; ++i)
    {
        if(arreglo[i] > mayor)
        {
            mayor = arreglo[i];
            posMayor = i;
        }
    }
    printf("El numero mayor fue: %d (indice: %d)\n", mayor, posMayor);
    



}
// ------------------------------------------------------

// ------------------------------------------------------
void mostrarLista()
{
    struct node *tmp;
    int n = 1;

    if(stnode == NULL)
    {
        printf("No hay informacion");
    }
    else
    {
        tmp = stnode;
        printf("\nValores ingresados son :\n");

        do {
            printf("Informacion nodo %d = %c %d\n", n, tmp->nombre, tmp->num);

            tmp = tmp->nextptr;
            n++;
        }while(tmp != stnode);
    }
}
// ------------------------------------------------------------
