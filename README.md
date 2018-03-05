#include<iostream>
#include<fstream>
using namespace std;
typedef struct{float greutate;
               float profit;
               float eficienta;}
               obiect;
obiect M[100];
float profit_total;
float G;
int n;
fstream f("input.dat");

int read_data()
{f>>n;f>>G;
    for (int i=1;i<=n;i++)
        {f>>M[i].greutate;
        f>>M[i].profit;
        M[i].eficienta=M[i].profit/M[i].greutate;}}

int sort_data()
{int i,g,aux;
    do{g=0;
        for(i=0;i<n-1;i++)
            if(M[i].eficienta<M[i+1].eficienta)
            {aux=M[i].eficienta;
            M[i].eficienta=M[i+1].eficienta;
            M[i+1].eficienta=aux;
            g=1;}}
            while(g);}

float sweet_greedy()
{
    float P=0;
    float Ga=0,Gd;
    for(int i=1;i<=n;i++)
    {if(M[i].greutate+Ga<=G)
        {P=P+M[i].profit;
        Ga=Ga+M[i].greutate;}
    else
        {Gd=G-Ga;
        while(Ga+Gd>G)
        {M[i].greutate=M[i].greutate*99/100;
        M[i].profit=M[i].profit*99/100;
        Gd=M[i].greutate;}
        P=P+M[i].profit;}}
        return P;}

        int main()
        {
            read_data();
            sort_data();
            profit_total=sweet_greedy();
            cout<<profit_total;
        }



