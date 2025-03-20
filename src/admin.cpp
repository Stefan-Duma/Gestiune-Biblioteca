#include "admin.h"
#include "exceptie.h"

client admin::find_client(uint id)
{
    for(int i = 0; i < (int)clienti.size(); i++)
    {
        if(id == clienti[i].get_id()) return clienti[i];
    }
    throw(new exceptie("Client negasit"));
}

carte admin::find_book(uint id)
{
    for(int i = 0; i < (int)carti.size(); i++)
    {
        if(id == carti[i].get_id()) return carti[i];
    }
    throw(new exceptie("Carte negasita"));
}