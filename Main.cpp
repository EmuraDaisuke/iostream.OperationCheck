


#include <iostream>
#include <vector>
#include <thread>
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
    std::vector<std::thread> at(std::thread::hardware_concurrency());
    for (auto& t : at) t = std::thread([]{ int v; std::cout << "test " << &v << std::endl; });
    for (auto& t : at) t.join();
    clog("}");
    return 0;
}
