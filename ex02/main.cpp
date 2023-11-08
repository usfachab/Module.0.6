#include <iostream>
#include <typeinfo>
#include <stdexcept>

class Base
{
public:
    virtual ~Base();
};

Base::~Base() {}

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate( void )
{
    srand( time( 0 ) );

    int r( rand() % 3 );

    switch ( r )
    {
        case 0: return ( new A() ); break;

        case 1: return ( new B() ); break;

        case 2: return ( new C() ); break;

        default: break;
    }
    return ( NULL );
}

void identify( Base *p )
{
    if ( dynamic_cast<A *>( p ) )
        std::cout << "A" << std::endl;
    else if ( dynamic_cast<B *>( p ) )
        std::cout << "B" << std::endl;
    else if ( dynamic_cast<C *>( p ) )
        std::cout << "C" << std::endl;
    else
        std::cout << "Base casting" << std::endl;
}

void identify( Base &p )
{
    {
        try
        {
            A a = dynamic_cast<A &>( p ); (void)a;
            std::cout << "A" << std::endl;
            return;
        }
        catch ( const std::exception &e ) {}
    }

    {
        try
        {
            B b = dynamic_cast<B &>( p ); (void)b;
            std::cout << "B" << std::endl;
            return;
        }
        catch ( const std::exception &e ) {}
    }

    {
        try
        {
            C c = dynamic_cast<C &>( p ); (void)c;
            std::cout << "C" << std::endl;
            return;
        }
        catch ( const std::exception &e ) {}
    }
}

int main()
{
    Base* base = generate();

    // Base *base = new Base();

    identify( base );
    identify( *base );

    return 0;
}