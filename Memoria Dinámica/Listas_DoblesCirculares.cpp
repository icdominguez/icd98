#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct nodo
{
       int valor;
       struct nodo *sig;
       struct nodo *ant;
};

void Inicializar (struct nodo **);
int EsVacia (struct nodo *);
int Cima(struct nodo *);
void Insertar (struct nodo **, int);
void Eliminar_pila(struct nodo * *);
void Eliminar_cola(struct nodo * *);
void Listar (struct nodo *);
void Pintar (struct nodo *);
void insertar_orden(struct nodo* *,int);

int main(void){
	
	struct nodo *lista;
	int numero, cima, op;

	Inicializar(&lista); //Llamada a función Inicializar (solo pone el primer puntero apuntando a NULL, realmente no hay nodos
	
	do{
	
		system("cls");
		printf("\n");
		puts("     ----------------MENU---------------");
		puts("     -----------------------------------");
		puts("     1.Comprobar si la lista esta vacia.");
		puts("     2.Insertar.                        ");
		puts("     3.Listar nodos.                    ");
		puts("     4.Cima de la pila.                 ");
		puts("     5.Eliminar pila.                   ");
		puts("     6.Eliminar Cola.                   ");
		puts("     7.Insertar en orden.               ");
		puts("     0.Salir.                           ");
		puts("     -----------------------------------");
		printf("     Introduzca opcion: ");
		scanf("%d", &op);
	
		switch(op) {
		
    		case 1:
    			if (EsVacia(lista)==1){ //Llamada a función EsVacia. Si el primer puntero apunta a NULL es que no hay nodos y está vacía.
    				puts("     La lista esta vacia");
    				getch();
    			}else{
    				printf("     No esta vacia");
    				getch();
    			}
    				break;
    		case 2:
				printf("     Insertar numero: ");
				scanf("%d", &numero);
				Insertar(&lista, numero); //Llamada a la función Insertar.
				break;
				
			case 3:
				if(EsVacia(lista)!=1){
					Listar(lista); //Llamada a la función Listar solo si la lista no está vacía
				}else{
					printf("     La lista esta vacia");
					getch();
				}
				break;
				
           	case 4:
				if(EsVacia(lista)!=1){
					printf("     %d", Cima(lista)); //Llamada a la función Cima solo si la lista no está vacía
					getch();
				}else{
					
					printf("     La lista esta vacia");
					getch();
				}
				break;
				
			case 5:
				Eliminar_pila(&lista);
			break;
				
			
			case 6:
					Eliminar_cola(&lista);
			break;
			
			case 7:
				printf("     Insertar numero: ");
				scanf("%d", &numero);
				insertar_orden(&lista,numero);
			break;
				
			case 0:
				printf("     Saliendo...");
				getch();
				break;
				
			default:
				printf("     Opcion incorrecta.");
				getch();
				break;
		}
	}while(op!=0);
}

void Inicializar(struct nodo* *q)
{
	*q = NULL; //Primer puntero apuntando a NULL	
}
int Cima(struct nodo *p)
{
	return((*p).valor); //Devolvemos el valor	
}

int EsVacia(struct nodo *p)
{	
	return(p==NULL); //Si se cumple, devuelve 1	
}

void Listar(struct nodo *p)
{
	struct nodo *ultimo;
	ultimo = p;
	
	
		while((*ultimo).sig!=p)
		{
		 /*En caso de que haya solo un elemento el siguiente ya es NULL,
		 por eso hay que hacerlo al menos una vez para que imprima el único elemento si solo hubiese un único elemento*/
			
			printf("%d     ", (*ultimo).valor);
			ultimo = (*ultimo).sig;
		}
		
		if ((*ultimo).sig==p)
		{
			printf("%d     ",(*ultimo).valor);
		}
	
	getch();
}

void Insertar(struct nodo* *q,int N)
{
	struct nodo *aux;
	aux=(struct nodo *)malloc(sizeof(struct nodo));
	(*aux).valor=N;
	
	if(EsVacia(*q)==1)
	{
		(*aux).sig=aux;
		(*aux).ant=aux;
		*q=aux;
	}
	else
	{
		(*aux).sig=*q;
		(*aux).ant=(*(*q)).ant;
		(*(*(*q)).ant).sig=aux;
		(*(*q)).ant=aux;
		*q=aux;
	}
}

void Eliminar_pila(struct nodo* *q)
{
	struct nodo *aux;
	aux=*q;
	
	if(EsVacia(*q)==1)
	{
		printf("Lista vacia");
	}
	else if((*(*q)).sig==aux)
	{
		free(*q);
		*q=NULL;
	}
	else
	{
		(*(*(*q)).ant).sig=(*(*q)).sig;
		*q=(*(*q)).sig;
		free(aux);
	}
}
void Eliminar_cola(struct nodo* *q)
{
	struct nodo *aux;
	
	if(EsVacia(*q)==1 || (*(*q)).sig==*q)
		Eliminar_pila(q);
	else
	{
		aux=(*(*q)).ant;
		(*(*q)).ant=(*(*(*q)).ant).ant;
		(*(*(*(*q)).ant).ant).sig = *q;
		free(aux);
	}
}

void insertar_orden(struct nodo * *q,int N)
{
	struct nodo *aux,*aux1,*aux2;
	aux=(struct nodo*)malloc(sizeof(struct nodo));
	(*aux).valor=N;
	
	if(EsVacia(*q)==1 || (*(*q)).valor>N)
	{
		free(aux); //aux se va  a volver a crear en insertar
		Insertar(q,N);
	}
	else if((*(*q)).sig==NULL) //Unico elemento insertas en cola
	{
	
		(*aux).sig=NULL;
		(*(*q)).sig=aux;
	}
	else // mas de 1
	{
	
		aux2=*q;
		aux1=(*aux2).sig;
		while(aux1!=NULL && (*aux1).valor<N) //mayor a menor (los ultimos en entrar son los mayores)
		{
			aux2=aux1;
			aux1=(*aux2).sig;
		}
		
		(*aux).sig=aux1;
		(*aux2).sig=aux;
		(*aux).ant=aux2;
		
		if(aux1!=NULL)//Si insertamos en cola no hay que arreglar ningun anterior
			(*aux1).ant=aux;
			
	}
}

