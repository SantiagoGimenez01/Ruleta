#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int dosVScom();
int unoVScom();
void ruleta_muestra();
void SetColorAndBackground(int ForgC, int BackC);
void gotoxy(int x,int y);
int main()
{
    int opc, opc_jug;//Opciones del menu
    int cont=0;
    //Diseño del menu
    SetColorAndBackground(9,0);
    gotoxy(45,0);
    do
    {
    cont=0;
    printf("Menu Ruleta:\n");
    gotoxy(1,4);
    printf("1.Comenzar el juego");
    gotoxy(1,6);
    printf("2.Como jugar");
    gotoxy(1,8);
    printf("0.Salir");
    gotoxy(1,2);
    printf("Seleccione una opcion:");
    scanf("%d",&opc);
    //Elegimos que opcion queremos
    switch(opc)
    {

    //Termina el juego
    case 0:
        system("cls");
        gotoxy(40,1);
        printf("Juego Terminado");
        gotoxy(0,3);
        printf("Muchas gracias por jugar a nuestra ruleta, te esperamos para que te sigas divirtiendo cuando quieras!!");
        break;
    //Comenzamos el juego
    case 1:
        system("cls"),
        gotoxy(40,1);
        printf("Bienvenido a la ruleta!!");
        gotoxy(0,5);
        printf("1.Un jugador vs COM");
        gotoxy(0,7);
        printf("2.Dos jugadores vs COM");
        gotoxy(0,3);
        printf("Elija el modo de juego:");
        scanf("%d",&opc_jug);
    system("cls");
    switch(opc_jug)
    {
        //Un jugador vs COM
    case 1:
        unoVScom();
    break;
    case 2:
        dosVScom();
    break;
    default:
        printf("La opcion ingresada no es valida, intentelo de nuevo");
    break;
    }
    break;
    case 2:
        system("cls");
        printf("Cada jugador elige cinco numeros, ganara aquel jugador o jugadores que acierten mas cantidad de numeros luego de tres tiradas de la computadora. Si no tienen aciertos la que gana es la computadora.\n");
        break;
    default:
        system("cls");
        printf("Opcion Invalida\n");
    }
    if(opc!=0)
    {
        while(cont==0)
    {
        printf("Ingrese un 3 para volver al inicio:");
        scanf("%d",&cont);
        if(cont==3)
            break;

    }
    }
    system("cls");
    }
    while(opc!=0);
    gotoxy(0,50);
    return 0;
    }

void gotoxy(int x,int y)
{
     COORD coord={0,0};
     coord.X=x;
     coord.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void ruleta_muestra()
{
    int i=0, j=0, k=1;
     gotoxy(40,3);
        printf(".......................");
        gotoxy(40,4);
        printf("|          0          |");
        gotoxy(40,5);
        printf("|---------------------|");


    for (i=0; i<12; i++)
    {
        gotoxy(40,6+(i+i));
        for(j=0; j<3; j++)
        {
        if(k<10)
          printf("|   %d  ",k);
        else
          printf("|   %d ",k);
        k++;
        }
        printf(" |");
        gotoxy(40,7+(i+i));
        printf("|---------------------|");
    }
    gotoxy(40,5+(i+i));
    printf("-----------------------");


    return 0;
}

int unoVScom()
{
    SetColorAndBackground(7,0);
    int numeros[5];//Numeros elegidos por el jugador
    int i=0,j=0,k=0;//Contadores
    int espacios=0;//Separaciones
    int y=0,x=0,q=1;
    int e=0,a=0;
    int aciertos=0;//Aciertos
    int rondas=0;//Nro de rondas
    int num[2];//Numeros sacados por la maquina
    int d=0,p=0;
        gotoxy(40,1);
        printf("Preparado para jugar contra la computadora??");
        gotoxy(0,2);
        printf("Elija 5 numeros del siguiente tablero:");
        do
        {
            ruleta_muestra();
            gotoxy(0,3+espacios);
            printf("Ingrese su %d%c numero:",i+1,248);
            scanf("%d",&numeros[i]);
            while(numeros[i]>36||numeros[i]<0)
            {
                gotoxy(0,4+espacios);
                printf("(No esta agregado en la tabla!!)\n");
                printf("Ingrese el %d%c numero nuevamente:",i+1,248);
                scanf("%d",&numeros[i]);
                espacios++;
                espacios++;
            }
            espacios++;
            i++;
        }
        while(i<5);
        gotoxy(0,10+espacios);
        printf("Sus numeros elegidos son:");
        for(j;j<i;j++)
        {
            printf("%d",numeros[j]);
            if(j<4)
                printf("-");
        }
        Sleep(0);
        system("cls");
        gotoxy(40,1);
        printf("Ahora es el turno de la maquina");
    srand(time(NULL));
    do
    {
        d=0;
        a=0;
        num[a]=rand()%(36-0)+0;
        if(rondas==0)
            aciertos=0;
        while(d<5)
        {
            if(numeros[d]==num[a])
                {
                    aciertos++;
                }
            d++;
        }
        k=0;
        if(num[a]==0)
        {
         SetColorAndBackground(12,14);
        gotoxy(10+30*rondas,3);
        printf(".......................");
        gotoxy(10+30*rondas,4);
        printf("|          0          |");
        gotoxy(10+30*rondas,5);
        printf("|---------------------|");
        }
        else
        {
        gotoxy(10+30*rondas,3);
        printf(".......................");
        gotoxy(10+30*rondas,4);
        printf("|          0          |");
        gotoxy(10+30*rondas,5);
        printf("|---------------------|");
        }


        k=1;
        for (y=0; y<12; y++)
    {
        gotoxy(10+30*rondas,6+(y+y));
        for(x=0; x<3; x++)
        {
            if (num[a]==k)
        {


        if(k<10)
        {
        printf("| ");
        SetColorAndBackground(12,14);
        printf("  %d  ",k);
        }

        else
        {
        printf("|  ");
        SetColorAndBackground(12,14);
        printf(" %d ",k);
        }

        }
        else
        {
            SetColorAndBackground(15,0);
           if(k<10)
          printf("|   %d  ",k);
        else
          printf("|   %d ",k);
        }
        k++;
        }
        SetColorAndBackground(15,0);
        printf(" |");
        gotoxy(10+30*rondas,7+(y+y));
        printf("|---------------------|");
    }
    gotoxy(10+30*rondas,5+(y+y));
    printf("-----------------------");
    a++;
    rondas++;
    }
    while(rondas<3);
    gotoxy(0,32);
    printf("Tus numeros elegidos fueron:");
    for(p;p<i;p++)
        {
            printf("%d",numeros[p]);
            if(p<4)
                printf("-");
        }
    gotoxy(0,35);
    printf("El numero de aciertos es %d\n",aciertos);
    if(aciertos>0)
        printf("Felicidades, ganaste!!!\n");
    else
    {
        printf("Gano la computadora :(\n");
        printf("Pero no te desanimes, vuelvelo a intentar!!\n");
    }
    return 0;
}

int dosVScom()
{
    SetColorAndBackground(12,0);
    int numeros1[5],numeros2[5];//Numeros elegidos por el jugador
    int i=0,j=0,k=0,s=0;;//Contadores
    int espacios=0;//Separaciones
    int y=0,x=0,q=1;
    int e=0,a=0;
    int aciertos1=0,aciertos2=0;//Aciertos
    int rondas=0;//Nro de rondas
    int num[2];//Numeros sacados por la maquina
    int d=0,p=0,l=0,r=0;//Otros
    int jug;
    gotoxy(40,1);
        printf("Preparados para jugar contra la computadora??");
        do
        {
            gotoxy(0,2);
            printf("El jugador 1 tiene que elegir cuales seran sus numeros:");
            ruleta_muestra();
            gotoxy(0,3+espacios);
            printf("Ingrese su %d%c numero:",i+1,248);
            scanf("%d",&numeros1[i]);
            while(numeros1[i]>36||numeros1[i]<0)
            {
                gotoxy(0,4+espacios);
                printf("(No esta agregado en la tabla!!)\n");
                printf("Ingrese el %d%c numero nuevamente:",i+1,248);
                scanf("%d",&numeros1[i]);
                espacios++;
                espacios++;
            }
            espacios++;
            i++;
        }
        while(i<5);
        system("cls");
        espacios=0;
        do
        {
            gotoxy(0,2);
            printf("El jugador 2 tiene que elegir cuales seran sus numeros:");
            ruleta_muestra();
            gotoxy(0,3+espacios);
            printf("Ingrese su %d%c numero:",s+1,248);
            scanf("%d",&numeros2[s]);
            while(numeros2[s]>36||numeros2[s]<0)
            {
                gotoxy(0,4+espacios);
                printf("(No esta agregado en la tabla!!)\n");
                printf("Ingrese el %d%c numero nuevamente:",s+1,248);
                scanf("%d",&numeros2[s]);
                espacios++;
                espacios++;
            }
            espacios++;
            s++;
        }
        while(s<5);
        Sleep(0);
        system("cls");
        gotoxy(40,1);
    printf("Ahora es el turno de la maquina");
    srand(time(NULL));
    do
    {
        SetColorAndBackground(12,0);
        d=0;
        l=0;
        a=0;
        num[a]=rand()%(36-0)+0;
        if(rondas==0)
            {
                aciertos1=0;
                aciertos2=0;
            }
        while(d<5)
        {
            if(numeros1[d]==num[a])
                {
                    aciertos1++;
                }
            d++;
        }
        while(l<5)
        {
            if(numeros2[l]==num[a])
                {
                    aciertos2++;
                }
            l++;
        }
        k=0;
        SetColorAndBackground(12,0);
        if(num[a]==0)
        {
         SetColorAndBackground(12,14);
        gotoxy(10+30*rondas,3);
        printf(".......................");
        gotoxy(10+30*rondas,4);
        printf("|          0          |");
        gotoxy(10+30*rondas,5);
        printf("|---------------------|");
        }
        else
        {
        gotoxy(10+30*rondas,3);
        printf(".......................");
        gotoxy(10+30*rondas,4);
        printf("|          0          |");
        gotoxy(10+30*rondas,5);
        printf("|---------------------|");
        }


        k=1;

        for (y=0; y<12; y++)
    {
        gotoxy(10+30*rondas,6+(y+y));
        for(x=0; x<3; x++)
        {
            if (num[a]==k)
        {


        if(k<10)
        {
        printf("| ");
        SetColorAndBackground(12,14);
        printf("  %d  ",k);
        }

        else
        {
        printf("|  ");
        SetColorAndBackground(12,14);
        printf(" %d ",k);
        }

        }
        else
        {
            SetColorAndBackground(12,0);
           if(k<10)
          printf("|   %d  ",k);
        else
          printf("|   %d ",k);
        }
        k++;
        }
SetColorAndBackground(12,0);
        printf(" |");
        gotoxy(10+30*rondas,7+(y+y));
        printf("|---------------------|");
    }
    gotoxy(10+30*rondas,5+(y+y));
    printf("-----------------------");
    a++;
    rondas++;
    }
    while(rondas<3);
    gotoxy(0,32);
    printf("Los numeros elegidos por el jugador 1 son: : ");
    for(p;p<i;p++)
        {
            printf("%d",numeros1[p]);
            if(p<4)
                printf("-");
        }
    gotoxy(0,34);
    printf("Los numeros elegidos por el jugador 2 son: :");
    for(r;r<i;r++)
        {
            printf("%d",numeros2[r]);
            if(r<4)
                printf("-");
        }
    gotoxy(0,36);
    printf("El numero de aciertos del jugador 1 es %d\n",aciertos1);
    printf("El numero de aciertos del jugador 2 es %d\n",aciertos2);
    if(aciertos1>0||aciertos2>0)
       {
           if (aciertos1>aciertos2)
            printf("Felicidades jugador 1, ganaste!!\n");
           else
            {
                if(aciertos1==aciertos2)
                {
                    printf("Hay un empate!!!\n");
                }
                else
                    printf("Felicidades jugador 2, ganaste!!!\n");
            }
       }
    else
    {
        printf("Gano la computadora :(\n");
        printf("Pero no te desanimes, vuelvelo a intentar!!");
    }

    gotoxy(0,50);
    return 0;

    }

