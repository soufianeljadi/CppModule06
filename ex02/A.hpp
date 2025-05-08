#ifndef A_HPP
#define A_HPP

#include "Base.hpp"
#include "C.hpp"
#include "B.hpp"

class A : public Base
{
    public:
        A();
        ~A();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif