


#include <iostream>
#include "ConsoleLog.h"



void* operator new(std::size_t s)                       { auto p = std::malloc(s); clog("( n", p, s, ")"); return p; }
void* operator new[](std::size_t s)                     { auto p = std::malloc(s); clog("( n[]", p, s, ")"); return p; }

void operator delete(void* p) noexcept                  { clog("( d", p, ")"); std::free(p); }
void operator delete[](void* p) noexcept                { clog("( d[]", p, ")"); std::free(p); }

void operator delete(void* p, std::size_t s) noexcept   { clog("( d", p, s, ")"); std::free(p); }
void operator delete[](void* p, std::size_t s) noexcept { clog("( d[]", p, s, ")"); std::free(p); }



int main(int argc, char* argv[])
{
    clog("{");
    int v;
    std::cout << "test " << &v << std::endl;
    std::cout << "test " << &v << std::endl;
    clog("}");
    return 0;
}
