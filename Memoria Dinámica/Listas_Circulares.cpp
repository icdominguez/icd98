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
void Insertar_pila (struct nodo **, int);
void Insertar_cola (struct nodo **, int);
void Eliminar_pila(struct nodo * *);
void Eliminar_cola(struct nodo * *);
void Listar (struct nodo *);
void Pintar (struct nodo *);
int Cima(struct nodo *);


int main(){
	
	struct nodo *lista;
	int numero, cima, op;

	Inicializar(&lista); //Llamada a funci�n Inicializar (solo pone el primer puntero apuntando a NULL, realmente no hay nodos
	
	do{
	
		system("cls");
		printf("\n");
		puts("     ----------------MENU---------------");
		puts("     -----------------------------------");
		puts("     1.Comprobar si la lista esta vacia.");
		puts("     2.Insertar pila.                   ");
		puts("     8.Insertar cola.                   ");
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
				if (EsVacia(lista)==1){ //Llamada a funci�n EsVacia. Si el primer puntero apunta a NULL es que no hay nodos y est� vac�a.
		
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
				Insertar_pila(&lista, numero); //Llamada a la funci�n Insertar.
				break;
				
			case 3:
				if(EsVacia(lista)!=1){
					Listar(lista); //Llamada a la funci�n Listar solo si la lista no est� vac�a
				}else{
					printf("     La lista esta vacia");
					getch();
				}
				break;
				
			case 4:
				if(EsVacia(lista)!=1){
					printf("     %d", Cima(lista)); //Llamada a la funci�n Cima solo si la lista no est� vac�a
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
			
			case 8:
				printf("     Insertar numero: ");
				scanf("%d", &numero);
				Insertar_cola(&lista,numero);
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
	
	struct nodo *ultimo;
	ultimo = p;
	
	while((*p).sig!=ultimo){ //(*ultimo).sig!=*q
	 /*En caso de que haya solo un elemento el siguiente ya es NULL,
	 por eso hay que hacerlo al menos una vez para que imprima el �nico elemento si solo hubiese un �nico elemento*/
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
	getch();
}
	
	if((*p).sig==ultimo){
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
		getch();
	}
	
}


void Listar(struct nodo *p){
	
	struct nodo *ultimo;
	ultimo = p;
	
	while((*p).sig!=ultimo){ //(*ultimo).sig!=*q
	 /*En caso de que haya solo un elemento el siguiente ya es NULL,
	 por eso hay que hacerlo al menos una vez para que imprima el �nico elemento si solo hubiese un �nico elemento*/
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
	getch();
}
	
	if((*p).sig==ultimo){
		
		printf("     %d", (*p).valor);
		p = (*p).sig;
	
		getch();
	}
	
}

int Cima(struct nodo *p){
	
	return((*p).valor); //Devolvemos el valor
	
}

void Insertar_pila(struct nodo* *q, int N){
	
	struct nodo *ultimo;
	ultimo=*q;
	
	struct nodo *aux; //Creamos el puntero auxiliar
	aux = (struct nodo *)malloc(sizeof(struct nodo)); //Reservamos el espacio de memoria para el nodo nuevo
	
	(*aux).valor = N; //Guardado del valor en el nodo nuevo
	
	if(EsVacia(*q) == 1 ){
		(*aux).sig=aux;
		*q=aux;
	}
	else
	{
		(*aux).sig = *q; //Nodo nuevo apuntando al siguiente
		//Nos movemos al elemento final de la lista para que apunte al primero
		while((*ultimo).sig!=*q){
			ultimo=(*ultimo).sig;
		}
		(*ultimo).sig=aux;
		*q = aux; //Guardo la direcci�n el nuevo nodo que tenia en aux en el puntero que apunta a "lista"
	}
	
	Pintar(*q);
}

void Insertar_cola(struct nodo* *q, int N){
	
	struct nodo *ultimo;
	ultimo=*q;
	
	struct nodo *aux; //Creamos el puntero auxiliar
	aux = (struct nodo *)malloc(sizeof(struct nodo)); //Reservamos el espacio de memoria para el nodo nuevo
	
	(*aux).valor = N; //Guardado del valor en el nodo nuevo
	
	if(EsVacia(*q) == 1 ){
		(*aux).sig=aux;
		*q=aux;
	}
	else
	{
		//Nos movemos al elemento final de la lista para que apunte al primero
		while((*ultimo).sig!=*q){
			ultimo=(*ultimo).sig;
		}
		(*ultimo).sig=aux;
		(*aux).sig = *q; //Nodo nuevo apuntando al primero
	}
	
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
	struct nodo *ultimo;
	ultimo=*q;
	
	struct nodo *aux;
	aux=*q;
	
	if(EsVacia(*q)==1)
		printf("Lista vacia");
	else
	{
		while((*ultimo).sig!=*q){
			ultimo=(*ultimo).sig;
		}
		(*ultimo).sig=(*aux).sig;

		*q=(*aux).sig;
		free(aux);
	}
}
void Eliminar_cola(struct nodo* *q)
{
	struct nodo *ultimo;
	ultimo=*q;
	
	struct nodo *aux;
	
	if(EsVacia(*q)==1||(*(*q)).sig==*q)
		Eliminar_pila(q);
	else{
	
		aux=(*ultimo).sig;
		
	
		while((*aux).sig!=*q)
		{
			ultimo=aux;
			aux=(*aux).sig;		
		}
		
		(*ultimo).sig=*q;
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
		Insertar_pila(q,N);
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
		while(aux1!=*q && (*aux1).valor<N) //mayor a menor (los ultimos en entrar son los mayores)
		{
			aux2=aux1;
			aux1=(*aux2).sig;
		}
		(*aux).sig=aux1;
		(*aux2).sig=aux;
		Pintar(*q);
	}
}
