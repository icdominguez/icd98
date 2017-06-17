#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (void)
{
		
    FILE*ar;
    char cad[50];
	int opcion;
	char pass[50],passb[50];
	do{
		
	printf("\n------------------FICHERO--------------------");
	printf("\n1-.Crear Contraseña");
	printf("\n2-.Entrar");
	printf("\n3-.Modificar");
	printf("\n0-.Salir");
	printf("\nElija opcion: ");
	scanf("%d",&opcion);
    fflush(stdin);
	
		switch(opcion)
		{
	                  case 1:
	                       {                         	
	                        	ar=fopen("fichero.txt","w");
	                        	//Comprobar si el archivo se creo de forma correcta
	                        	if ( ar!= NULL)
	                        	{
	                        		printf("Introduzca contraseña: ");
	                                fflush(stdin);
	                            	gets(cad);
	                        		
	                        		fputs(cad,ar);
	                        		fclose(ar);
	                        		system("cls");
	                        	}
	                        	else
	                        		printf("El archivo no se abrio correctamente");
	                        		system("cls");
	                        		
	                        	getch();	
	                       		break;
	                       }
	                  case 2:
	                       {
	                           ar=fopen("fichero.txt","r");
	                           printf("Introduzca contraseña: ");
	                           scanf("%s",&pass);
	                           fflush(stdin);
	                           fscanf(ar,"%s",passb);
	                           if(strcmp(pass,passb)==0)
	                           //Comparar cadena introducida con lo que hay en el fichero
	                           {
	                           		printf("Contraseña correcta");
	                           		getch();
	                           		fclose(ar);
	                           		system("cls");
							   }
							   break;
							}
	                  case 3:
	                       {
	                            ar=fopen("fichero.txt","r");
	                            fseek(ar,0,SEEK_END);
	                        	if (ftell( ar ) == 0 )
	                        	{
	                                system("cls");
	                          		printf("Fichero vacio");
	                          		getch();
	                          		system("cls");
	                        	}
	                        	else
	                        	//Comprobar si el archivo se creo de forma correcta
		                        if ( ar!= NULL)
	                        	{
	                        		printf("La contraseña que usted introdujo fue : ");
	                        		fgets(cad,50,ar);
	                        		puts(cad);
	                        		
	                        		fclose(ar);
	                        		
	                        		ar=fopen("fichero.txt","w");
	                        		printf("Introduzca contraseña nueva: ");
	                                fflush(stdin);
	                        		gets(cad);
	                        		
	                        		fputs(cad,ar);
	                        		fclose(ar);
	                        		system("cls");
	                        		
	                        	}
	                        	else
	                        		printf("El archivo no se abrio correctamente");
	                        		system("cls");
	                            break;                            
	                       }
	          	case 0:
	          		{
						printf("     Saliendo...");
						getch();
					}
					break;
				default:
					printf("     Opcion incorrecta.");
					getch();
					system("cls");
					break;
	   }
	}while(opcion!=0);
}
	
	
