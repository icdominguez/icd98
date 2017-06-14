#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct nodo {
	
	int valor;
	struct nodo *sig;
	
};

void Inicializar (struct nodo **);
int EsVacia (struct nodo *);
void insertar_orden(struct nodo* *,int);
void Insertar (struct nodo **, int);
void Eliminar_pila(struct nodo * *);
void Eliminar_cola(struct nodo * *);
void Listar (struct nodo *);
void Pintar (struct nodo *);
int Cima(struct nodo *);


int main(){
	
	struct nodo *lista;
	int numero, cima, op;

	Inicializar(&lista); //Llamada a función Inicializar (solo pone el primer puntero apuntando a NULL, realmente no hay nodos
	
	do{
	
		system("cls");
		printf("\n");
		puts("     ----------------MENU---------------");
		puts("     -----------------------------------");
		puts("     1.Comprobar si la lista esta vacia.");
		puts("     2.Insertar nodo.                   ");
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
			
			//Llamada insertar orden
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




void Pintar(struct nodo *p){
	
	while((*p).sig!=NULL){
	 /*En caso de que haya solo un elemento el siguiente ya es NULL,
	 por eso hay que hacerlo al menos una vez para que imprima el único elemento si solo hubiese un único elemento*/
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
	getch();
}
	
	if((*p).sig==NULL){
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
		getch();
	}
	
}


void Listar(struct nodo *p){
	
	while((*p).sig!=NULL){
	 /*En caso de que haya solo un elemento el siguiente ya es NULL,
	 por eso hay que hacerlo al menos una vez para que imprima el único elemento si solo hubiese un único elemento*/
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
	getch();
}
	
	if((*p).sig==NULL){
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
		getch();
	}
	
}

int Cima(struct nodo *p){
	
	return((*p).valor); //Devolvemos el valor
	
}

void Insertar(struct nodo* *q, int N){
	
	struct nodo *aux; //Creamos el puntero auxiliar
	aux = (struct nodo *)malloc(sizeof(struct nodo)); //Reservamos el espacio de memoria para el nodo nuevo
	
	(*aux).valor = N; //Guardado del valor en el nodo nuevo
	(*aux).sig = *q; //Nodo nuevo apuntando al siguiente
	*q = aux; //Guardo la dirección el nuevo nodo que tenia en aux en el puntero que apunta a "lista"
	Pintar(*q);
	
}

int EsVacia(struct nodo *p){
	
	return(p==NULL); //Si se cumple, devuelve 1
	
}

void Inicializar(struct nodo* *q){
	
	*q = NULL; //Primer puntero apuntando a NULL
	
}

void Eliminar_pila(struct nodo* *q)
{
	struct nodo *aux;
	if(EsVacia(*q)==1)
		printf("Lista vacia");
	else
	{
		aux=*q;
		*q=(*aux).sig;
		free(aux);
	}
}
void Eliminar_cola(struct nodo* *q)
{
	struct nodo *aux;
	struct nodo *aux2;
	
	if(EsVacia(*q)==1||(*(*q)).sig==NULL)
		Eliminar_pila(q);
	else{
	
		aux2=*q;
		aux=(*aux2).sig;
		
	
		while((*aux).sig!=NULL)
		{
			aux2=aux;
			aux=(*aux).sig;
		
		}
		(*aux2).sig=NULL;
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
	/*else if((*(*q)).sig==NULL) //Unico elemento insertas en cola
	{
	
		(*aux).sig=NULL;
		(*(*q)).sig=aux;
		Pintar(*q);
	}*/
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
		Pintar(*q);
	}
}
