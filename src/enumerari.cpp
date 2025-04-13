#include "enumerari.h"


std::string judetToString(Judet judet) {
    switch (judet) {
        case Judet::Alba: return "Alba";
        case Judet::Arad: return "Arad";
        case Judet::Arges: return "Arges";
        case Judet::Bacau: return "Bacau";
        case Judet::Bihor: return "Bihor";
        case Judet::BistritaNasaud: return "BistritaNasaud";
        case Judet::Botosani: return "Botosani";
        case Judet::Brasov: return "Brasov";
        case Judet::Braila: return "Braila";
        case Judet::Buzau: return "Buzau";
        case Judet::CarasSeverin: return "CarasSeverin";
        case Judet::Calarasi: return "Calarasi";
        case Judet::Cluj: return "Cluj";
        case Judet::Constanta: return "Constanta";
        case Judet::Covasna: return "Covasna";
        case Judet::Dambovita: return "Dambovita";
        case Judet::Dolj: return "Dolj";
        case Judet::Galati: return "Galati";
        case Judet::Giurgiu: return "Giurgiu";
        case Judet::Gorj: return "Gorj";
        case Judet::Harghita: return "Harghita";
        case Judet::Hunedoara: return "Hunedoara";
        case Judet::Ialomita: return "Ialomita";
        case Judet::Iasi: return "Iasi";
        case Judet::Ilfov: return "Ilfov";
        case Judet::Maramures: return "Maramures";
        case Judet::Mehedinti: return "Mehedinti";
        case Judet::Mures: return "Mures";
        case Judet::Neamt: return "Neamt";
        case Judet::Olt: return "Olt";
        case Judet::Prahova: return "Prahova";
        case Judet::Salaj: return "Salaj";
        case Judet::SatuMare: return "SatuMare";
        case Judet::Sibiu: return "Sibiu";
        case Judet::Suceava: return "Suceava";
        case Judet::Teleorman: return "Teleorman";
        case Judet::Timis: return "Timis";
        case Judet::Tulcea: return "Tulcea";
        case Judet::Valcea: return "Valcea";
        case Judet::Vaslui: return "Vaslui";
        case Judet::Vrancea: return "Vrancea";
        default: return "Necunoscut";
    }
}

Judet stringToJudet(const std::string& str) {
    if (str == "Alba") return Judet::Alba;
    if (str == "Arad") return Judet::Arad;
    if (str == "Arges") return Judet::Arges;
    if (str == "Bacau") return Judet::Bacau;
    if (str == "Bihor") return Judet::Bihor;
    if (str == "BistritaNasaud") return Judet::BistritaNasaud;
    if (str == "Botosani") return Judet::Botosani;
    if (str == "Brasov") return Judet::Brasov;
    if (str == "Braila") return Judet::Braila;
    if (str == "Buzau") return Judet::Buzau;
    if (str == "CarasSeverin") return Judet::CarasSeverin;
    if (str == "Calarasi") return Judet::Calarasi;
    if (str == "Cluj") return Judet::Cluj;
    if (str == "Constanta") return Judet::Constanta;
    if (str == "Covasna") return Judet::Covasna;
    if (str == "Dambovita") return Judet::Dambovita;
    if (str == "Dolj") return Judet::Dolj;
    if (str == "Galati") return Judet::Galati;
    if (str == "Giurgiu") return Judet::Giurgiu;
    if (str == "Gorj") return Judet::Gorj;
    if (str == "Harghita") return Judet::Harghita;
    if (str == "Hunedoara") return Judet::Hunedoara;
    if (str == "Ialomita") return Judet::Ialomita;
    if (str == "Iasi") return Judet::Iasi;
    if (str == "Ilfov") return Judet::Ilfov;
    if (str == "Maramures") return Judet::Maramures;
    if (str == "Mehedinti") return Judet::Mehedinti;
    if (str == "Mures") return Judet::Mures;
    if (str == "Neamt") return Judet::Neamt;
    if (str == "Olt") return Judet::Olt;
    if (str == "Prahova") return Judet::Prahova;
    if (str == "Salaj") return Judet::Salaj;
    if (str == "SatuMare") return Judet::SatuMare;
    if (str == "Sibiu") return Judet::Sibiu;
    if (str == "Suceava") return Judet::Suceava;
    if (str == "Teleorman") return Judet::Teleorman;
    if (str == "Timis") return Judet::Timis;
    if (str == "Tulcea") return Judet::Tulcea;
    if (str == "Valcea") return Judet::Valcea;
    if (str == "Vaslui") return Judet::Vaslui;
    if (str == "Vrancea") return Judet::Vrancea;

    return Judet::Necunoscut;
}
