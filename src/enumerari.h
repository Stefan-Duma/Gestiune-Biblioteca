#ifndef ENUMERARI_H
#define ENUMERARI_H

#include <iostream>
#include <string>
#include <stdexcept>

enum Judet {
    Alba = 1, Arad, Arges, Bacau, Bihor, BistritaNasaud, Botosani, Brasov,
    Braila, Buzau, CarasSeverin, Calarasi, Cluj, Constanta, Covasna, Dambovita,
    Dolj, Galati, Giurgiu, Gorj, Harghita, Hunedoara, Ialomita, Iasi, Ilfov,
    Maramures, Mehedinti, Mures, Neamt, Olt, Prahova, Salaj, SatuMare, Sibiu,
    Suceava, Teleorman, Timis, Tulcea, Valcea, Vaslui, Vrancea, Necunoscut = 100
};

enum Luna{
    Ianuarie = 1, Februarie, Martie, Aprilie, Mai, Iunie,
    Iulie, August, Septembrie, Octombrie, Noiembrie, Decembrie
};
std::string judetToString(Judet judet);
Judet stringToJudet(const std::string& str);
#endif //ENUMERARI_H