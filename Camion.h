#pragma once
#include "Voiture.h"

class Camion :
    public Voiture
{
    Camion(const std::string&, const std::string&, const std::string&, int, std::string);
};

