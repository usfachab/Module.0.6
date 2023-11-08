#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
   int i;
   char c;
};

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer( const Serializer & );
    Serializer &operator=( const Serializer & );

public:
    static uintptr_t    serialize( Data * );
    static Data         *deserialize( uintptr_t );
};

#endif