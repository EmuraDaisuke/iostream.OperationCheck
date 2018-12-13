// Copyright(c) 2018 Emura Daisuke
// Apache License 2.0



#include <cstdio>
#include "./ConsoleLog.h"



ConsoleLog::~ConsoleLog() noexcept                  {}

ConsoleLog::ConsoleLog()                            :mp(ma){}

void ConsoleLog::Out() const noexcept               { std::puts(ma); std::fflush(stdout); }

void ConsoleLog::Put() noexcept                     { Tail(std::snprintf(Tail(), Size(), " ")); }
void ConsoleLog::Put(bool v) noexcept               { Tail(std::snprintf(Tail(), Size(), "%hhd", (v)? 1:0)); }
void ConsoleLog::Put(signed char v) noexcept        { Tail(std::snprintf(Tail(), Size(), "%hhd", v)); }
void ConsoleLog::Put(signed short v) noexcept       { Tail(std::snprintf(Tail(), Size(), "%hd", v)); }
void ConsoleLog::Put(signed int v) noexcept         { Tail(std::snprintf(Tail(), Size(), "%d", v)); }
void ConsoleLog::Put(signed long long v) noexcept   { Tail(std::snprintf(Tail(), Size(), "%lld", v)); }
void ConsoleLog::Put(unsigned char v) noexcept      { Tail(std::snprintf(Tail(), Size(), "%hhu", v)); }
void ConsoleLog::Put(unsigned short v) noexcept     { Tail(std::snprintf(Tail(), Size(), "%hu", v)); }
void ConsoleLog::Put(unsigned int v) noexcept       { Tail(std::snprintf(Tail(), Size(), "%u", v)); }
void ConsoleLog::Put(unsigned long long v) noexcept { Tail(std::snprintf(Tail(), Size(), "%llu", v)); }
void ConsoleLog::Put(float v) noexcept              { Tail(std::snprintf(Tail(), Size(), "%f", v)); }
void ConsoleLog::Put(double v) noexcept             { Tail(std::snprintf(Tail(), Size(), "%f", v)); }
void ConsoleLog::Put(const char* v) noexcept        { Tail(std::snprintf(Tail(), Size(), "%s", (v)? v:"")); }
void ConsoleLog::Put(const void* v) noexcept        { Tail(std::snprintf(Tail(), Size(), "%p", v)); }
void ConsoleLog::Put(const std::string& v) noexcept { Tail(std::snprintf(Tail(), Size(), "%s", v.c_str())); }

void ConsoleLog::Tail(int s) noexcept               { mp += s; }
char* ConsoleLog::Tail() const noexcept             { return mp; }

std::size_t ConsoleLog::Size() const noexcept       { return (&ma[sizeof(ma)] - mp); }

void ConsoleLog::Log() noexcept                     {}
