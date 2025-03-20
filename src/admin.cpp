#include "admin.h"
#include "exceptie.h"

client admin::find_client(uint id)
{
    for(int i = 0; i < (int)clients.size(); i++)
    {
        if(id == clients[i].get_id()) return clients[i];
    }
    throw(new exceptie("Client negasit"));
}

carte admin::find_book(uint id)
{
    for(int i = 0; i < (int)books.size(); i++)
    {
        if(id == books[i].get_id()) return books[i];
    }
    throw(new exceptie("Carte negasita"));
}