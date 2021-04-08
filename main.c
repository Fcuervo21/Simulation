#include <stdio.h>
#include <stdlib.h>

#define QUANTUM_UNITS 2

struct node {
    char nombre;
    int num;
    struct node * nextptr;
}*stnode;
 
// Prototipo de funciones
void ClListcreation(int n);
void displayClList();

int main()
{
  int n;
  stnode = NULL;
	printf("\n\n Circular Linked List :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf("Ingresa la cantidad de nodos : ");
    scanf("%d", &n);
 
    ClListcreation(n); 
    displayClList();
    return 0;
}

void ClListcreation(int n)
{
    int i, num;
    char nombre;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));
        printf("\nIngresa la letra del proceso : ");
        scanf("%c", &nombre);
        printf("\nIngresa las unidades del proceso 1 : ");
        scanf("%d", &num);

        stnode -> nombre = nombre;
        stnode->num = num;

        stnode->nextptr = NULL;
        preptr = stnode;
        
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("\nIngresar informacion del nodo %d : ", i);
            printf("\nLetra del proceso: ");
            scanf("%c", &nombre);
            printf("\nUnidades del proceso: ");
            scanf("%d", &num);

            newnode->nombre = nombre;
            newnode->num = num;
            newnode->nextptr = NULL;	// next address of new node set as NULL

            preptr->nextptr = newnode;	// previous node is linking with new node
            preptr = newnode;   		// previous node is advanced
        }
        preptr->nextptr = stnode; 		//last node is linking with first node
    }
}

void displayClList()
{
    struct node *tmp;
    int n = 1;

    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
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