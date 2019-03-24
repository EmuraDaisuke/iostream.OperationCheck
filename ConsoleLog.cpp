


#include <cstdio>
#include "./ConsoleLog.h"



ConsoleLog::~ConsoleLog() noexcept                  {}

ConsoleLog::ConsoleLog()                            :mp(ma){}

void ConsoleLog::Out() const noexcept               { std::puts(ma); std::fflush(stdout); }

void ConsoleLog::Put() noexcept                     { Tail(std::snprintf(Tail(), Size(), " ")); }
void ConsoleLog::Put(bool v) noexcept               { Tail(std::snprintf(Tail(), Size(), "%d", (v)? 1:0)); }
void ConsoleLog::Put(i8 v) noexcept                 { Tail(std::snprintf(Tail(), Size(), I8, v)); }
void ConsoleLog::Put(i16 v) noexcept                { Tail(std::snprintf(Tail(), Size(), I16, v)); }
void ConsoleLog::Put(i32 v) noexcept                { Tail(std::snprintf(Tail(), Size(), I32, v)); }
void ConsoleLog::Put(i64 v) noexcept                { Tail(std::snprintf(Tail(), Size(), I64, v)); }
void ConsoleLog::Put(u8 v) noexcept                 { Tail(std::snprintf(Tail(), Size(), U8, v)); }
void ConsoleLog::Put(u16 v) noexcept                { Tail(std::snprintf(Tail(), Size(), U16, v)); }
void ConsoleLog::Put(u32 v) noexcept                { Tail(std::snprintf(Tail(), Size(), U32, v)); }
void ConsoleLog::Put(u64 v) noexcept                { Tail(std::snprintf(Tail(), Size(), U64, v)); }
void ConsoleLog::Put(float v) noexcept              { Tail(std::snprintf(Tail(), Size(), F32, v)); }
void ConsoleLog::Put(double v) noexcept             { Tail(std::snprintf(Tail(), Size(), F64, v)); }
void ConsoleLog::Put(const char* v) noexcept        { Tail(std::snprintf(Tail(), Size(), "%s", (v)? v:"")); }
void ConsoleLog::Put(const void* v) noexcept        { Tail(std::snprintf(Tail(), Size(), "%p", v)); }
void ConsoleLog::Put(const std::string& v) noexcept { Tail(std::snprintf(Tail(), Size(), "%s", v.c_str())); }

void ConsoleLog::Tail(int s) noexcept               { mp += s; }
char* ConsoleLog::Tail() const noexcept             { return mp; }

std::size_t ConsoleLog::Size() const noexcept       { return (&ma[sizeof(ma)] - mp); }

void ConsoleLog::Log() noexcept                     {}
