#include<bits/stdc++.h>
using namespace std;

#define INCEPATOR 1
#define INTERMEDIAR 2
#define AVANSAT 3
#define DIMENSIUNEMAXIMA 25
#define NUMARMAXIMMINE 99
#define DIMENSIUNEATABLEI 526

int DIMENSIUNE ;
int MINE ;


bool esteValid(int rand, int coloana)
{

    return (rand >= 0) && (rand < DIMENSIUNE) &&
           (coloana >= 0) && (coloana < DIMENSIUNE);
}


bool esteMina (int rand, int coloana, char tabla[][DIMENSIUNEMAXIMA])
{
    if (tabla[rand][coloana] == '*')
        return (true);
    else
        return (false);
}

void faMutare(int *x, int *y){
char c[100];

    printf("Introduceti coordonatele randului si a coloanei (rand coloana): " );
    scanf("%d",x);
    cin>>c;

if(strlen(c)!=1 || (*x<0 || *x> DIMENSIUNE)){while(strlen(c)!=1){
    printf("Introduceti coordonatele randului si a coloanei (rand coloana): " );
    scanf("%d",x);
    cin>>c;
}
}
*y=int(c[0])-97;
}


void afisareTabla(char tablaMea[][DIMENSIUNEMAXIMA])
{system("cls");

    int i, j;
printf ("Starea curenta a jocului: \n \n");
printf("  ");

    printf (" ");

    for (char i='a'; i<'a'+DIMENSIUNE; i++)
cout<<i<<" ";
    printf ("\n");
    printf("  ");
for(int i=0;i<DIMENSIUNE;i++) printf(" _");
printf("\n");
    for (i=0; i<DIMENSIUNE; i++)
    {
      if(i<10) cout<<" "<<i<<" ";
       else cout<<i<<" ";


        for (j=0; j<DIMENSIUNE; j++)
            printf ("%c ", tablaMea[i][j]);
        printf ("\n");
    }

    return;
}


int numarMineApropiate(int rand, int coloana, int mine[][2],
                      char tablaReala[][DIMENSIUNEMAXIMA])
{

    int count = 0;


        if (esteValid (rand-1, coloana) == true)
        {
               if (esteMina (rand-1, coloana, tablaReala) == true)
               count++;
        }


        if (esteValid (rand+1, coloana) == true)
        {
               if (esteMina (rand+1, coloana, tablaReala) == true)
               count++;
        }


        if (esteValid (rand, coloana+1) == true)
        {
            if (esteMina (rand, coloana+1, tablaReala) == true)
               count++;
        }


        if (esteValid (rand, coloana-1) == true)
        {
               if (esteMina (rand, coloana-1, tablaReala) == true)
               count++;
        }


        if (esteValid (rand-1, coloana+1) == true)
        {
            if (esteMina (rand-1, coloana+1, tablaReala) == true)
               count++;
        }


        if (esteValid (rand-1, coloana-1) == true)
        {
             if (esteMina (rand-1, coloana-1, tablaReala) == true)
               count++;
        }


        if (esteValid (rand+1, coloana+1) == true)
        {
               if (esteMina (rand+1, coloana+1, tablaReala) == true)
               count++;
        }


        if (esteValid (rand+1, coloana-1) == true)
        {
            if (esteMina (rand+1, coloana-1, tablaReala) == true)
               count++;
        }

    return (count);
}


bool continuaJocul(char tablaMea[][DIMENSIUNEMAXIMA], char tablaReala[][DIMENSIUNEMAXIMA],
            int mine[][2], int rand, int coloana, int *miscariRamase)
{

    if (tablaMea[rand][coloana] != '-')
        return (false);

    int i;

    if (tablaReala[rand][coloana] == '*')
    {
        tablaMea[rand][coloana]='*';

        for (i=0; i<MINE; i++)
            tablaMea[mine[i][0]][mine[i][1]]='*';

        afisareTabla (tablaMea);
        printf ("\nAti declansat o mina. Jocul a luat sfarsit!\n");
        return (true) ;
    }

    else
     {

        int count = numarMineApropiate(rand, coloana, mine, tablaReala);
        (*miscariRamase)--;

        tablaMea[rand][coloana] = count + '0';

        if (!count)
        {

            if (esteValid (rand-1, coloana) == true)
            {
                   if (esteMina (rand-1, coloana, tablaReala) == false)
                   continuaJocul(tablaMea, tablaReala, mine, rand-1, coloana, miscariRamase);
            }


            if (esteValid (rand+1, coloana) == true)
            {
                   if (esteMina (rand+1, coloana, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand+1, coloana, miscariRamase);
            }


            if (esteValid (rand, coloana+1) == true)
            {
                if (esteMina (rand, coloana+1, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand, coloana+1, miscariRamase);
            }


            if (esteValid (rand, coloana-1) == true)
            {
                   if (esteMina (rand, coloana-1, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand, coloana-1, miscariRamase);
            }


            if (esteValid (rand-1, coloana+1) == true)
            {
                if (esteMina (rand-1, coloana+1, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand-1, coloana+1, miscariRamase);
            }


            if (esteValid (rand-1, coloana-1) == true)
            {
                 if (esteMina (rand-1, coloana-1, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand-1, coloana-1, miscariRamase);
            }


            if (esteValid (rand+1, coloana+1) == true)
            {
                 if (esteMina (rand+1, coloana+1, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand+1, coloana+1, miscariRamase);
            }


            if (esteValid (rand+1, coloana-1) == true)
            {
                if (esteMina (rand+1, coloana-1, tablaReala) == false)
                    continuaJocul(tablaMea, tablaReala, mine, rand+1, coloana-1, miscariRamase);
            }
        }

        return (false);
    }
}

void plaseazaMine(int mine[][2], char tablaReala[][DIMENSIUNEMAXIMA])
{
    bool marcheaza[DIMENSIUNEMAXIMA*DIMENSIUNEMAXIMA];

    memset (marcheaza, false, sizeof (marcheaza));


    for (int i=0; i<MINE; )
     {
        int aleator = rand() % (DIMENSIUNE*DIMENSIUNE);
        int x = aleator / DIMENSIUNE;
        int y = aleator % DIMENSIUNE;


        if (marcheaza[aleator] == false)
        {

            mine[i][0]= x;

            mine[i][1] = y;


            tablaReala[mine[i][0]][mine[i][1]] = '*';
            marcheaza[aleator] = true;
            i++;
        }
    }

    return;
}


void initializeaza(char tablaReala[][DIMENSIUNEMAXIMA], char tablaMea[][DIMENSIUNEMAXIMA])
{

    srand(time (NULL));


    for (int i=0; i<DIMENSIUNE; i++)
    {
        for (int j=0; j<DIMENSIUNE; j++)
        {
            tablaMea[i][j] = tablaReala[i][j] = '-';
        }
    }

    return;
}



void inlocuiesteMine (int rand, int coloana, char tabla[][DIMENSIUNEMAXIMA])
{
    for (int i=0; i<DIMENSIUNE; i++)
    {
        for (int j=0; j<DIMENSIUNE; j++)
            {

                if (tabla[i][j] != '*')
                {
                    tabla[i][j] = '*';
                    tabla[rand][coloana] = '-';
                    return;
                }
            }
    }
    return;
}


void joacaJocul ()
{

    bool gameOver = false;


    char tablaReala[DIMENSIUNEMAXIMA][DIMENSIUNEMAXIMA], tablaMea[DIMENSIUNEMAXIMA][DIMENSIUNEMAXIMA];

    int miscariRamase = DIMENSIUNE * DIMENSIUNE - MINE, x, y;
    int mine[NUMARMAXIMMINE][2];

      initializeaza (tablaReala, tablaMea);


    plaseazaMine (mine, tablaReala);



    int miscari = 0;
    while (gameOver == false)
     {

        afisareTabla (tablaMea);
        faMutare (&x, &y);


        if (miscari == 0)
        {

            if (esteMina (x, y, tablaReala) == true)
                inlocuiesteMine (x, y, tablaReala);
        }

        miscari ++;

        gameOver = continuaJocul (tablaMea, tablaReala, mine, x, y, &miscariRamase);

        if ((gameOver == false) && (miscariRamase == 0))
         {
            printf ("\nFelicitari!\n");
            gameOver = true;
         }
    }
    return;
}
 int verificaInput()
 {bool valid=false;
 int x;
 while(!valid){
    printf ("Alegeti nivelul de dificultate:\n");
    printf ("*Introduceti 1 pentru INCEPATOR (9 * 9 Celule si 10 mine)\n");
    printf ("*Introduceti 2 pentru INTERMEDIAR (16 * 16 Celule si 40 mine)\n");
    printf ("*Introduceti 3 pentru AVANSAT (24 * 24 Celule si 99 mine)\n");
     cin>>x;
     if((cin.good())&&(x>=1&&x<=3))
        {
        valid=true;
        }

    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        printf("\n");
        cout<<"Ati introdus o valoare invalida, reincercati."<<endl;
         }
 }

  return x;
 }
void nivelulDeDificultate ()
{int nivel=verificaInput();

   if (nivel == INCEPATOR)

    {
        DIMENSIUNE = 9;
        MINE = 10;
    }

    if (nivel == INTERMEDIAR)
    {
        DIMENSIUNE = 16;
        MINE = 40;
    }

    if (nivel == AVANSAT)
    {
        DIMENSIUNE = 24;
        MINE = 99;
    }

    return;

}



int main()
{

    nivelulDeDificultate ();

    joacaJocul ();

    return (0);
}
