#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer( const Serializer& obj ) { *this = obj; }

Serializer& Serializer::operator=( const Serializer& rhs )
{
    static_cast<void>( rhs );
    return ( *this );
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize( Data* data )
{
    return ( reinterpret_cast<uintptr_t>( data ) );
}

Data* Serializer::deserialize( uintptr_t uptr)
{
    return ( reinterpret_cast<Data *>( uptr ) );
}