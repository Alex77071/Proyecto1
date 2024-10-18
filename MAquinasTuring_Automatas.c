#include <stdio.h>
#include<windows.h>
#define VERDE_T        "\x1b[32m"
#define RESET_COLOR    "\x1b[0m"
#define ROJO_F   "\x1b[41m"
#define VERDE_F  "\x1b[42m"
#define ROJO_T     "\x1b[31m"

#define MAX 5

void gotoxy(int x, int y);
void deco1();
void deco2();
void deco3();
void tope();
void arrG ();
void q1();
void q2();
void q3();
void q4();

struct nodo {
    int dato;
    struct nodo *liga;
};
struct nodo *crea() {
    struct nodo *paux;
    paux = (struct nodo *)malloc(sizeof(struct nodo));
    return paux;
}

int PILA_VACIA(struct nodo *TOPE) {
    int BAND;
    if (TOPE == NULL) {
        BAND = 1;
    } else {
        BAND = 0;
    }

    return BAND;
}
struct nodo *push(struct nodo *TOPE, int DATO) {
    struct nodo *q;
        q = crea();
        q->dato = DATO;
        q->liga = TOPE;
    return q;
}
struct nodo *pop(struct nodo *TOPE) {
	struct nodo *q;
    if (PILA_VACIA(TOPE)) {
        gotoxy (10,16);printf(ROJO_F"Subdesbordamiento - Pila vacia"RESET_COLOR);
    } else {
        q= TOPE;
        TOPE = TOPE->liga;
        free(q);
        return TOPE;
    }
   
}

void Duplicado(struct nodo *TOPE){
    struct nodo *p;
    int i=0;
        p= TOPE;
        gotoxy(30, 15);printf("%c",24);
        gotoxy(27, 16);printf("CADENA A DUPLICAR");

        while(p!=NULL){
        	gotoxy(28,17+(i*2));printf("%d", p->dato);
            i++;
            p= p->liga;
		}
		Sleep(500);
        gotoxy(30+(i*4), 13);printf("  ");

}

void Sig (int cabezal){
	gotoxy(30+(cabezal*4),11);printf("%c",24);
}
void Sig2 (int cabezal){
    gotoxy(30+(cabezal*4),11);printf(" ");
}

void circulo (int c,int f){
	int i;

	gotoxy (c,f); printf ("%c%c%c%c",218,196,196,196);
	gotoxy (c,f+1); printf ("%c",179);
	gotoxy (c,f+2); printf ("%c%c%c",192,196,196);

	
	gotoxy(c+4,f);printf ("%c%c",196,191);
	gotoxy(c+4,f+1); printf(" %c",179);
	gotoxy (c+3,f+2); printf("%c%c%c",196,196,217);
	
}

main()
{
int res;
int i,j,cabezal,estado,valor,Vector[13];	

do{
struct nodo *TOPE = NULL, *p;	
	deco1();	
	gotoxy(58,24);system("pause");
	system("cls");
	deco2();
	gotoxy(73,28);system("pause");
	system("cls");
	deco3();
	
	for (i=0; i<13; i++){
	    Vector[i]=100;
	}
	gotoxy(30,9);printf("b");
    i=1;
	arrG();

	tope();
int z;

	do{
    	gotoxy(30+(i*4),9);scanf("%d", &valor);
    	if(valor>3) z=1;
		Vector[i]= valor;
		i++;
	}while ((valor>=0 && valor <=1)&& i<=5);
	

    for (i=0; i<13; i++){
	    if (Vector[i]!= 0 && Vector[i]!=1){
	    	Vector[i]=100;
	    	gotoxy(30+(i*4),9);printf("b");
	    }
	}
	cabezal=1;
	estado=0;
	do{
		Duplicado(TOPE);
		Sleep(500);
		if (estado==0){	
	        if (Vector[cabezal]!=100){
			   Sig(cabezal);Sleep(500);Sig2(cabezal);
	           cabezal++;
		    } else if (Vector[cabezal]==100){
			  Vector[cabezal]=3;
			  TOPE = push(TOPE,3);
			  gotoxy(30+(cabezal*4),9);printf("X");
			  Sig(cabezal);Sleep(500);Sig2(cabezal);
			  Duplicado(TOPE);
			  cabezal--;
              estado=1;
		   }
		}
        if (estado==1){			
		    if (Vector[cabezal]!=100){
		    	Sig(cabezal);Sleep(500);Sig2(cabezal);
			    TOPE = push(TOPE,Vector[cabezal]);
			    Duplicado(TOPE);
			    cabezal--;

		    }
			if (Vector[cabezal]==100){
                estado=2;
                Sig(cabezal);Sleep(500);Sig2(cabezal);
			    cabezal++;

		    }

		}

		if (estado==2){
			if ( Vector[cabezal]!=3 ){
			   Sig(cabezal);Sleep(500);Sig2(cabezal);
			   cabezal++;

	     	}
			if (Vector[cabezal]==3 ){
                estado=3;
                Sig(cabezal);Sleep(500);Sig2(cabezal);
			    cabezal++;
	    	}

	   }
	   if(estado==3){
	   	 if (((Vector[cabezal]==100)) &&  !(PILA_VACIA(TOPE))){
         	Sig(cabezal);Sleep(500);Sig2(cabezal);
            p=TOPE;
			Vector[cabezal]=p->dato;
		    gotoxy(30+(cabezal*4),9);printf(ROJO_F"%d"RESET_COLOR, Vector[cabezal]);
		    TOPE = pop(TOPE);
		    Duplicado(TOPE);
		    cabezal++;

		  }
		  if (PILA_VACIA(TOPE)){
			estado=4;
		   }

	    }
	}while(estado != 4);
    if (z !=1){
    	gotoxy(70,20);printf(VERDE_T"CADENA ACEPTADA"RESET_COLOR);
    	gotoxy(87,20);printf(VERDE_F" X "RESET_COLOR);
	}
	else{
		gotoxy(70,20);printf(VERDE_T"CADENA  NO ACEPTADA"RESET_COLOR);
    	gotoxy(89,20);printf(VERDE_F" X "RESET_COLOR);	
	}	
	
sleep(1);
gotoxy(80,27);printf("Cargar otro ejemplo, Si[1] / No[0]: ");
scanf("%d",&res);
sleep(1);
system("cls");
}while(res !=0);
	
	gotoxy(50,15);printf(ROJO_F"     FINALIZADO     "RESET_COLOR);
		
}

//FUNCION DECORACION BIENVENIDA
void deco1(){
	int i;
	//Cuadro 1
//Horizontal	
for (i=15; i<100; i++)
	{
		gotoxy(i+1,5);printf("%c",219);
	}
	
for (i=15; i<100; i++)
	{
		gotoxy(i+1,20);printf("%c",219);
	}
//Vertical
for(i=4; i<20; i++)
	{
		gotoxy(15,i+1);printf("%c",219);
	}
for(i=4; i<20; i++)
	{
		gotoxy(100,i+1);printf("%c",219);
	}
//--------------------------------------------------------//
	//Cuadro 2
//Horizontal
for (i=17; i<97; i++)
	{
		gotoxy(i+1,6);printf("%c",205);
	}

for (i=17; i<97; i++)
	{
		gotoxy(i+1,19);printf("%c",205);
	}	
//Vertical					

for(i=6; i<18; i++)
	{
		gotoxy(17,i+1);printf("%c",186);
	}
	
for(i=6; i<18; i++)
	{
		gotoxy(98,i+1);printf("%c",186);
	}
	
char mensaje[]=VERDE_T"MAQUINA DE TURING SIMPLE"RESET_COLOR;
char mensaje2[]="Teoria de Automatas";
int longitud = sizeof(mensaje) - 1;
int longitud2 = sizeof(mensaje2) - 1;

for (i = 0; i < longitud; ++i) {
        gotoxy(45+i,12);printf("%c", mensaje[i]);
        fflush(stdout);
        usleep(30000);
    }
sleep(1);    
for (i = 0; i < longitud; ++i) {
        gotoxy(69+i,17);printf("%c", mensaje2[i]);
        usleep(30000);
    }		
    
 gotoxy(90,17);printf("X");
			
}


// FUNCION DECORACION
void deco2(){
	int i;
	//Cuadro 1
//Horizontal	
for (i=1; i<115; i++)
	{
		gotoxy(i+1,1);printf("%c",219);
	}
	
for (i=1; i<115; i++)
	{
		gotoxy(i+1,26);printf("%c",219);
	}
//Vertical
for(i=0; i<26; i++)
	{
		gotoxy(1,i+1);printf("%c",219);
	}
for(i=1; i<25; i++)
	{
		gotoxy(115,i+1);printf("%c",219);
	}
	
//--------------------------------------------------------//
	//Cuadro 2
//Horizontal
for (i=3; i<112; i++)
	{
		gotoxy(i+1,2);printf("%c",205);
	}

for (i=3; i<112; i++)
	{
		gotoxy(i+1,25);printf("%c",205);
	}	
//Vertical					

for(i=2; i<24; i++)
	{
		gotoxy(3,i+1);printf("%c",186);
	}
	
for(i=2; i<24; i++)
	{
		gotoxy(113,i+1);printf("%c",186);
	}
	
gotoxy(43,4);printf("INFORMACION DE LA MAQUINA DE TURING");

//INFORMACION DE LA MAQUINA DE TURING

gotoxy(30,6);printf("DEFINCION FORMAL DE LA MAQUINA DE TURING [DUPLICA CINTAS]");
gotoxy(30,9);printf("Q = {q0, q1, q2, q3, q4}");
gotoxy(30,10);printf("E = {0, 1}");
gotoxy(30,11);printf("T = {0, 1, X}");
gotoxy(30,12);printf("F = {q4}");
gotoxy(30,13);printf("S = {q0}");
gotoxy(35,15);printf(VERDE_T"DIAGRAMA DE TRANSICION: "RESET_COLOR);
	
q1();	
q2();
q3();
q4();		
}

void deco3()
{
	//PANTALLA DE SOLUCION
int i;

//Cuadro 1
	//Horizontal
for(i=36; i<82; i++)
{
	gotoxy(i+1,0);printf("%c",219);	
}
for(i=37; i<82; i++)
{
	gotoxy(i+1,4);printf("%c",219);	
}
 //Vertical
 for(i=0; i<4; i++)
 {
 	gotoxy(37,i+1);printf("%c",219);
 }
 
 for(i=0; i<4; i++)
 {
 	gotoxy(82,i+1);printf("%c",219);
 }
//------------- Cuadro 2 -------------//
	//Horizontal
for(i=38; i<80; i++)
{
	gotoxy(i+1,1);printf("%c",205);	
}	

for(i=38; i<80; i++)
{
	gotoxy(i+1,3);printf("%c",205);
}
	//Vertical
for(i=1; i<2; i++)
{
	gotoxy(38,i+1);printf("%c",186);	
}	

for(i=1; i<2; i++)
{
	gotoxy(81,i+1);printf("%c",186);
}

gotoxy(47,2);printf(VERDE_T"MAQUINA DE TURING SIMPLE"RESET_COLOR);
	
}

void tope()
{
	int i;
	char mensaje[]=ROJO_F" TOPE 5 NUMEROS BINARIOS "RESET_COLOR;
	int longitud = sizeof(mensaje) - 1;
	for (i = 0; i < longitud; ++i) {
        gotoxy(80+i,7);printf("%c", mensaje[i]);
        usleep(30000);
    }	
	gotoxy(90,8);printf(ROJO_T"2 o 3 = b"RESET_COLOR);
	gotoxy(90,9);printf(ROJO_T">3 NO valido"RESET_COLOR);
	
}	
		
void arrG (){
    int i;
    int c=29,f=8;
	gotoxy (c,f); printf ("%c%c%c",218,196,196);
	gotoxy (c,f+1); printf ("%c",179);
	gotoxy (c,f+2); printf ("%c%c%c",192,196,196);
	for (i=0; i<12; i++){
	    gotoxy(c+(i*4)+3,f); printf ("%c%c%c%c",196,194,196,196);
		gotoxy(c+(i*4)+3,f+1);printf (" %c",179);
		gotoxy(c+(i*4)+3,f+2);printf ("%c%c%c%c",196,193,196,196);
	}
	gotoxy(c+(i*4)+3,f);printf ("%c%c",196,191);
	gotoxy(c+(i*4)+3,f+1); printf(" %c",179);
	gotoxy (c+(i*4)+3,f+2); printf ("%c%c",196,217);
}


void q1(){
	int i;
    circulo(4,19);
    gotoxy(6,20);printf("q0");

    gotoxy(13,18);printf("0,0,R");
	gotoxy(13,19);printf("1,1,R");

    gotoxy(6,20);printf("q0");
    for(i=0; i<10; i++){
    	gotoxy(10+i,20);printf("_");
	}
	circulo(20,19);
    gotoxy(22,20);printf("q1");
    gotoxy(11,21);printf("100,3,L");	
}

void q2(){
	int i;
	circulo(20,19);
    gotoxy(22,20);printf("q1");

    gotoxy(28,18);printf("0,0->E,R");
	gotoxy(28,19);printf("1,1->E,R");
		
    gotoxy(22,20);printf("q1");
        for(i=0; i<10; i++){
    	gotoxy(26+i,20);printf("_");
	}
	circulo(36,19);
    gotoxy(38,20);printf("q2");
    gotoxy(26,21);printf("100,100,R");
}

void q3(){
	int i;
    circulo(36,19);
    gotoxy(38,20);printf("q2");
    gotoxy(45,18);printf("0,0,R");
	gotoxy(45,19);printf("1,1,R");
		
    gotoxy(38,20);printf("q2");
    for(i=0; i<10; i++){
    	gotoxy(42+i,20);printf("_");
	}
	circulo(52,19);
    gotoxy(54,20);printf("q3");
    gotoxy(43,21);printf("3,3,R");	
}

void q4(){
	int i;
    circulo(52,19);
    gotoxy(54,20);printf("q3");
    gotoxy(61,18);printf("100,E->0,R");
	gotoxy(61,19);printf("100,1->1,R");
	
    circulo(52,19);
    gotoxy(54,20);printf("q3");
    for(i=0; i<10; i++){
    	gotoxy(58+i,20);printf("_");
	}
	circulo(68,19);
    gotoxy(70,20);printf("q4");
    gotoxy(58,21);printf("100,3->E,-");
	
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
