#include<fstream>
#include<iostream>
using namespace std;
typedef struct {float greutate;
                float profit;
                float eficienta;} obiect;
obiect M[100];
float profit_total;
float G,Gs=0,P=0;
int n,h,aux,x=99,y;

int read_data()
{fstream f;
f.open("inputks.dat",ios::in);
f>>n;
f>>G;
for(int i=1;i<=n;i++)
{f>>M[i].greutate;
f>>M[i].profit;}
f.close();}

int sort_data()
{for(int i=1;i<=n;i++)
M[i].eficienta=M[i].profit/M[i].greutate;
do{h=0;
   for(int i=1;i<=n-1;i++)
       if(M[i].eficienta>M[i+1].eficienta)
         {aux=M[i].eficienta;
          M[i].eficienta=M[i+1].eficienta;
          M[i+1].eficienta=aux;h=1;}}
    while(h!=0);}

float sweet_greedy()
{for(int i=1;i<=n;i++)
{if(Gs<=G)
{Gs=Gs+M[i].greutate;
P=P+M[i].profit;y=i;}}
if(Gs>G)
{Gs=Gs-M[y].greutate;
P=P-M[y].profit;
while(Gs+M[y].greutate>G)
{M[y].greutate=(x*M[y].greutate)/100;
M[y].profit=(x*M[y].profit)/100;
x--;}
Gs=Gs+M[y].greutate;
P=P+M[y].profit;}
return P;}

int main()
{read_data();
sort_data();
profit_total=sweet_greedy();
cout<<profit_total;}
