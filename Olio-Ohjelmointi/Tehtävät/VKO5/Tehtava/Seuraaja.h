#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
#include <string>
using namespace std;

class Seuraaja {
public:
    Seuraaja(string nimi);
    void paivitys(const string& viesti);
    string getNimi();
    Seuraaja* next;

private:
    string nimi;
};

#endif // SEURAAJA_H
