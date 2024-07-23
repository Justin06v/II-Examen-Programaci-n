#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
	
/***********************************************************************************************/
int a, cp = 0,ci = 0, ap = 0, ai = 0;
char condi[20];
float pp = 0, pi = 0;
float pv[30];
int gan;
int g, emp;
int voto, votoc[30], cc, c;
char nombre[30][30];
char apellido[30][30];
char apellido1[30][30];
char pap[10][30];
int codigo[30];
int i = 0;
int ctv = 0;
char nombrep[100][30];
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

/***********************************************************************************************/


void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void ingresar_candidatos();
void votar();
void resultados();
void votaciones();

/***********************************************************************************************/



void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


/***********************************************************************************************/
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

/***********************************************************************************************/



void ingresar_candidatos()
{
	char sigue;
	
	do{
		system("cls");
		
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
		cuadro(10,7,105,25);
		cuadro(41,3,78,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(47,04); printf("**** INGRESANDO DATOS ****");
		
		i = i + 1;
		codigo[i] = i + 10;
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
		gotoxy(13,9); printf("Ingrese el primer nombre del candidato: ");
		scanf("%s",&nombre[i]);
		gotoxy(13,10); printf("Ingrese el primer apellido del candidato: ");
		scanf("%s",&apellido[i]);
		gotoxy(13,11); printf("Ingrese el segundo apellido del candidato: ");
		scanf("%s",&apellido1[i]);
		gotoxy(13,12); printf("Ingrese  el nombre del partido (todo junto) ej: PartidoAccionEstudiantil \n ");
		gotoxy(13,13); printf("Nombre: ");
		scanf("%s",&nombrep[i]);
		gotoxy(13,14); printf("Ingrese las siglas del partido politico: ");
		scanf("%s",&pap[i]);
		gotoxy(13,15); printf("El codigo de candidato es: %i ",codigo[i]);
		cc = cc + 1;
		
		
		SetConsoleTextAttribute (hConsoleHandle, 15);
		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(11,27);printf("Desea ingresar otro candidato S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	}while (tolower(sigue)=='s');
	
}




/***********************************************************************************************/

void resultados()
{    
    int j = 1;
    int a = 2;
    int c = 1;
	system("cls");
	
			if(cc == 0){
		
		         system("cls");
	             SetConsoleTextAttribute (hConsoleHandle, 15);
             	 cuadro(45,3,72,5);
                 cuadro(10,7,105,25);
	
	
	             SetConsoleTextAttribute (hConsoleHandle, 10);
               	 gotoxy(48,4); printf("***** RESULTADOS *****"); 
	 
                 SetConsoleTextAttribute (hConsoleHandle, 15);
	             gotoxy(13,8); printf("Aun no hay candidatos registrados");
	             SetConsoleTextAttribute (hConsoleHandle, 10);
                 cuadro(13,26,52,28);
	
                 gotoxy(15,27); printf("<PRESIONE TECLA PARA VOLVER AL MENU>");
                 getch();
                 menu();
	}
	SetConsoleTextAttribute (hConsoleHandle, 15);
	cuadro(45,3,72,5);
	cuadro(10,7,105,25);
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(48,4); printf("***** RESULTADOS *****"); 
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	
	
	for(i = i; i >= j; j++){
		
		if(votoc[j] == 0){
			pv[j] = 0;
		}else{
			pv[j] = (votoc[j] * 100) / ctv ;
		}
		
		gotoxy(13,7 + c); printf("Candidato: %s %s %s ",nombre[j],apellido[j],apellido1[j]);
		gotoxy(13,8 + c); printf("Partido: %s (%s)",nombrep[j],pap[j]);
		gotoxy(13,9 + c); printf("Votos totales: %i ",votoc[j]);
		gotoxy(13,10 + c); printf("Porcentaje de votos: %.2f ", pv[j]);
		gotoxy(13,11 + c); printf("----------------------------------------------------------------");
		c = c + 5; 
	}
	
	
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
			
	cuadro(13,26,52,28);
	
    gotoxy(15,27); printf("<PRESIONE TECLA PARA VOLVER AL MENU>");
    getch();
    menu();
}



/***********************************************************************************************/
void votar(){
	char nombrevot[30];
	char apellidovot[30];
	int cedulavot[100];
	int i = 0;
	int j = 0;
	int a = 0;
	system("cls");
	
		if(cc == 0){
		
		    system("cls");
		    SetConsoleTextAttribute (hConsoleHandle, 15);
		
        	cuadro(45,3,70,5);
	        cuadro(10,7,105,25);
	
	        SetConsoleTextAttribute (hConsoleHandle, 10);
	
        	gotoxy(50,4); printf("**** VOTANDO ****");
	
        	SetConsoleTextAttribute (hConsoleHandle, 15);
			gotoxy(13,8); printf("Aun no hay candidatos registrados");
		    SetConsoleTextAttribute (hConsoleHandle, 10);
            cuadro(13,26,52,28);
	
            gotoxy(15,27); printf("<PRESIONE TECLA PARA VOLVER AL MENU>");
            getch();
            menu();
	}
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
		
	cuadro(45,3,70,5);
	cuadro(10,7,105,25);
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	
	gotoxy(50,4); printf("**** VOTANDO ****");
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	
	i = i + 1;
	
	gotoxy(13,8); printf("Ingrese su primer nombre: ");
	scanf("%s",&nombrevot);
	gotoxy(13,9); printf("Ingrese su primer apellido: ");
	scanf("%s",&apellidovot);
	gotoxy(13,10); printf("Ingrese su numero de cedula: ");
	scanf("%i",&cedulavot[i]);
	
	for(i = i; i > j; j++){
		if(cedulavot[j] == cedulavot[i]){
			a = 1;
		}else{
			a = 2;
		}
	}
	
	if(a == 1){
			system("cls");
				
	        SetConsoleTextAttribute (hConsoleHandle, 15);
		
        	cuadro(45,3,70,5);
        	cuadro(10,7,105,25);
	
        	SetConsoleTextAttribute (hConsoleHandle, 10);
	
        	gotoxy(50,4); printf("**** VOTANDO ****");
        	
        	gotoxy(13,8); printf("Usted ya voto");
        		SetConsoleTextAttribute (hConsoleHandle, 10);
            	cuadro(13,26,52,28);
	
            	gotoxy(15,27); printf("<PRESIONE TECLA PARA VOLVER AL MENU>");
            	getch();
            	menu();
	}else{
			gotoxy(13,11); printf("Ingrese el codigo de candidato por el cual desea votar: ");
			do{
			    scanf("%i",&voto);
				if((voto - 10 ) > cc || (voto - 10) <= 0 ){
					gotoxy(13,12); printf("El codigo no es correcto, intente de nuevo: ");
					a = 0;
				}else{
					a = 1;
				}
			}while(a == 0);
			
        	c = voto - 10;
        	votoc[c] = votoc[c] + 1;
        	
			SetConsoleTextAttribute (hConsoleHandle, 10);
			gotoxy(13,13); printf("Su voto a sido registrado!!");
			ctv = ctv + 1;
			
			SetConsoleTextAttribute (hConsoleHandle, 10);
            cuadro(13,26,52,28);
	
           	gotoxy(15,27); printf("<PRESIONE TECLA PARA VOLVER AL MENU>");
           	getch();
           	menu();
	}
	
}

/***********************************************************************************************/
void candidatos(){
	
int j = 1;
int a = 2;
int c = 1;
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 15);
	cuadro(45,3,70,5);
	cuadro(10,7,105,25);
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	gotoxy(50,4); printf("**** VOTANDO ****");
	SetConsoleTextAttribute (hConsoleHandle, 15);
	
	for(i = i; i >= j; j++){
		gotoxy(13,7 + c); printf("Candidato: %s %s %s ",nombre[j],apellido[j],apellido1[j]);
		gotoxy(13,8 + c); printf("Partido: %s (%s)",nombrep[j],pap[j]);
		gotoxy(13,9 + c); printf("Codigo: %i ",codigo[j]);
		gotoxy(13,10 + c); printf("----------------------------------------------------------------");
		c = c + 4; 
	}
	
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(13,26,51,28);
	
	gotoxy(15,27); printf("<PRESIONE TECLA PARA PASAR A VOTAR>");
	getch();
	votar();
}





/***********************************************************************************************/

void menu()

{
	char opc,conti;
	
	do{
		

		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 7);
		cuadro(34,2,82,6); 
		cuadro(8,8,105,22);
		cuadro(8,23,105,25); 
	

		SetConsoleTextAttribute (hConsoleHandle, 10);
	    gotoxy(43,4);printf("***** CENTRO DE VOTACIONES *****");
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(14,10);printf("[1]  INGRESAR CANDIDATOS");
		gotoxy(14,12);printf("[2]  VOTACIONES");
		gotoxy(14,14);printf("[3]  RESULTADOS");
		gotoxy(90,20);printf("<<[4] SALIR>>");
		
		SetConsoleTextAttribute(hConsoleHandle,15);
		gotoxy(14,24);printf("INGRESE SU OPCION: ");
		opc=getch();

		switch(opc)
		{
		case '1': ingresar_candidatos();break;
		case '2': candidatos(); break;
		case '3': resultados(); break;
		case '4': 
				
			system("cls");
			
			SetConsoleTextAttribute (hConsoleHandle, 2);
			cuadro(18,8,63,14);
			
			gotoxy(20,10);printf("Estas seguro que quieres cerrar la votacion");
			
			gotoxy(20,12);printf("Desea salir del programa S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
				menu();
				
			else if (conti=='S' || conti=='s')
			    break;
			     
	
		}
			

		}while(opc!='4');

	}


/********************************************************************************************/

int main() {
	menu();
	return 0;
}
