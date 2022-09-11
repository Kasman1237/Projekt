#pragma once
#include "statki.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
class plansza
{
public:
    plansza(int n);
    int T[12][12];

    int roz;
    int ilosc;
    void statek(int rozm, int ile);
    void zeruj();



};
