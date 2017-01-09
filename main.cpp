#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

int contor_bombe, verificax, verificay;
const int dimensiunex = 16, dimensiuney = 16;
bool pierdere;

class Grila{;
public:
    bool areBomba, marcat;
     Grila(void) {
        areBomba = false;
         marcat = false;
                 }
};
int c=25-dimensiunex;
void desenareChenar( Grila chenar[dimensiunex][dimensiuney])
{ system("cls");
   cout<<"  _";
    for(int i=97;i<122-c;i++)
    {
    cout<<char(i)<<"_";
    }
    cout<<endl;

for(int y=0;y<dimensiuney;y++)
{   if(y<=9){
    cout<<" "<<y<<"|";
             }
             else cout<<y<<"|";
for(int x=0;x<dimensiunex;x++)
{
if(chenar[x][y].areBomba&&chenar[x][y].marcat)
{
   cout<<"!|" ;
}
if(chenar[x][y].areBomba)
{
    cout<<"*|";
}
 else if(chenar[x][y].marcat)
 {
     cout<<"x|";
 }
else
{
    cout<<"_|";
}
     }
    cout<<endl;
   }
}






int main()
{int numar=1;
char d;
  pierdere=false;
  contor_bombe=2*dimensiunex;
    verificax=0;
    verificay=0;
    Grila tablaDeJoc[dimensiunex][dimensiuney];
    for(int i=0;i<contor_bombe;i++)
    {
        int pozitiex=rand() % dimensiunex;
        int pozitiey=rand() % dimensiuney;
        if(tablaDeJoc[pozitiex][pozitiey].areBomba==false){
            tablaDeJoc[pozitiex][pozitiey].areBomba=true;
        }
        else
        {
            i--;
        }
    }
    desenareChenar(tablaDeJoc);
     cout<<endl;

while(pierdere!=true)
    {
        cout<<endl;
        cout<<"Numar total de mine:"<<contor_bombe<<endl;
        cout<<"Numar mine marcate:"<<numar<<endl;
        cout<<endl;
        cout<<"Introduceti coordonata lui X."<<endl;
        cin>>d;
        cout<<"Introduceti coordonata lui Y."<<endl;
        cin>>verificay;

        if(tablaDeJoc[verificax][verificay].marcat==true)
        {
            cout<<"Boom!"<<endl;
            pierdere=true;
        }
       else
       {
           cout<<"Mai incercati."<<endl;
       }
       tablaDeJoc[verificax][verificay].marcat=true;
       cout<<endl;
       desenareChenar(tablaDeJoc);
       cout<<endl;
    }

return 0;
}
