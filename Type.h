#pragma once



#if _WIN64//[
using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;
#define I8  "%hhd"
#define I16 "%hd"
#define I32 "%d"
#define I64 "%lld"

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
#define U8  "%hhu"
#define U16 "%hu"
#define U32 "%u"
#define U64 "%llu"

using f32 = float;
using f64 = double;
#define F32 "%f"
#define F64 "%f"
#endif//]



#if _LP64//[
using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long int;
#define I8  "%hhd"
#define I16 "%hd"
#define I32 "%d"
#define I64 "%ld"

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long int;
#define U8  "%hhu"
#define U16 "%hu"
#define U32 "%u"
#define U64 "%lu"

using f32 = float;
using f64 = double;
#define F32 "%f"
#define F64 "%f"
#endif//]
