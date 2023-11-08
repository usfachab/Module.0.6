#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data * data = new Data();
    data->i = 12;
    data->c = 48;

    uintptr_t uptr = Serializer::serialize( data );

    data = Serializer::deserialize( uptr );

    std::cout << data->i << std::endl;
    std::cout << data->c << std::endl;

    delete data;

    return 0;
}