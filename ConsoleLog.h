#pragma once



#include <string>
#include "./Type.h"



class ConsoleLog {
    public:
        ~ConsoleLog() noexcept;
        
        ConsoleLog();
        
        void Out() const noexcept;
        
        void Put() noexcept;
        void Put(bool v) noexcept;
        void Put(i8 v) noexcept;
        void Put(i16 v) noexcept;
        void Put(i32 v) noexcept;
        void Put(i64 v) noexcept;
        void Put(u8 v) noexcept;
        void Put(u16 v) noexcept;
        void Put(u32 v) noexcept;
        void Put(u64 v) noexcept;
        void Put(f32 v) noexcept;
        void Put(f64 v) noexcept;
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
