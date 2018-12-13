#pragma once
// Copyright(c) 2018 Emura Daisuke
// Apache License 2.0



#include <string>



class ConsoleLog {
    public:
        ~ConsoleLog() noexcept;
        
        ConsoleLog();
        
        void Out() const noexcept;
        
        void Put() noexcept;
        void Put(bool v) noexcept;
        void Put(signed char v) noexcept;
        void Put(signed short v) noexcept;
        void Put(signed int v) noexcept;
        void Put(signed long long v) noexcept;
        void Put(unsigned char v) noexcept;
        void Put(unsigned short v) noexcept;
        void Put(unsigned int v) noexcept;
        void Put(unsigned long long v) noexcept;
        void Put(float v) noexcept;
        void Put(double v) noexcept;
        void Put(const char* v) noexcept;
        void Put(const void* v) noexcept;
        void Put(const std::string& v) noexcept;
        
        template <class Head, class... Tail>
        void Log(Head&& head, Tail&&... tail) noexcept
        {
            Put(head); Put();
            return Log(std::forward<Tail>(tail)...);
        }
    
    private:
        void Tail(int s) noexcept;
        char* Tail() const noexcept;
        
        std::size_t Size() const noexcept;
        
        void Log() noexcept;
    
    
    private:
        char ma[0x1000];
        char* mp;
};



template <class... Args>
void clog(Args... args) noexcept
{
    ConsoleLog v;
    v.Log(args...);
    v.Out();
}
