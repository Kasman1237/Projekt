#include "planszaa.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace std;



//Tworzenie statkow o danym rozmiarze i ilosci i dodawanie na plansze

void plansza::statek(int rozm, int ile)
{
    srand(time(NULL));
    int x = 0, y = 0;

    for (int o = 0; ile > o; o++)
    {
        int k = rand() % (2);
        y = 0;
        x = 0;

        if (k == 0)
        {
            if (rozm == 3)
            {
                do {

                    x = 1 + rand() % (11 - rozm - 1 + 1);
                    y = 1 + rand() % (10 - 1 + 1);
                } while (!(T[x][y] == 0 && T[x + rozm - 1][y] == 0 && T[x + rozm - 2][y] == 0));
            }
            if (rozm == 2)
            {
                do {

                    x = 1 + rand() % (11 - rozm - 1 + 1);
                    y = 1 + rand() % (10 - 1 + 1);
                } while (!(T[x][y] == 0 && T[x + rozm - 1][y] == 0));
            }if (rozm == 1)
            {
                do {

                    x = 1 + rand() % (11 - rozm - 1 + 1);
                    y = 1 + rand() % (10 - 1 + 1);
                } while (!(T[x][y] == 0));
            }if (rozm == 4)
            {
                do {

                    x = 1 + rand() % (11 - rozm - 1 + 1);
                    y = 1 + rand() % (10 - 1 + 1);
                } while (!(T[x][y] == 0 && T[x + rozm - 1][y] == 0 && T[x + rozm - 2][y] == 0 && T[x + rozm - 3][y] == 0));
            }for (int i = x - 1; i <= x + rozm; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                    T[i][j] = 5;
            }
            for (int l = x; l <= x + rozm - 1; l++)
            {
                T[l][y] = rozm;
            }
        }
        if (k == 1)
        {
            if (rozm == 2)
            {
                do {
                    x = 1 + rand() % (10);
                    y = 1 + rand() % (11 - rozm);
                } while (!(T[x][y] == 0 && T[x][y + rozm - 1] == 0));
            }
            if (rozm == 3)
            {


                do {
                    x = 1 + rand() % (10);
                    y = 1 + rand() % (11 - rozm);
                } while (!(T[x][y] == 0 && T[x][y + rozm - 1] == 0 && T[x][y + rozm - 2] == 0));
            }
            if (rozm == 4)
            {


                do {
                    x = 1 + rand() % (10);
                    y = 1 + rand() % (11 - rozm);
                } while (!(T[x][y] == 0 && T[x][y + rozm - 1] == 0 && T[x][y + rozm - 2] == 0 && T[x][y + rozm - 3] == 0));
            }
            if (rozm == 1)
            {


                do {
                    x = 1 + rand() % (10);
                    y = 1 + rand() % (11 - rozm);
                } while (!(T[x][y] == 0));
            }
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + rozm; j++)
                {
                    T[i][j] = 5;
                }
            }
            for (int l = y; l <= y + rozm - 1; l++)
            {
                T[x][l] = rozm;
            }
        }
    }
}

//Tworzenie planszy wype³nionej zerami
void plansza::zeruj()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            T[i][j] = 0;
        }
    }


}




//Tworzenie planszy ze statkami dla gracza i komputera
plansza::plansza(int n)
{
    if (n == 1)
    {
        zeruj();
        statek(4, 1);
        statek(1, 4);
        statek(2, 3);
        statek(3, 2);
    }
    if (n == 2)
    {
        zeruj();
        statek(1, 4);
        statek(2, 3);
        statek(4, 1);
        statek(3, 2);
    }
}


