#ifndef EXCEPTIE_H
#define EXCEPTIE_H

#include <string>

class exceptie{
    public:
        std::string mesaj;
        exceptie(std::string exc) : mesaj(exc) {}
};

#endif //EXCEPTIE_H