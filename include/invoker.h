#include <Common.h>
#include "plugin_common.h"
#include "rage_types.h"
//#include <utility>

extern int v_nt_counter;
extern void *nativesTableAddr;
// struct Native_s {
	// struct Native_s *lastNativeTable;
	// u64 nativeFunctions[7];
	// u64 nativeCount;
	// u64 nativeHashes[7];
// };
struct twoQwords {
	uint64_t p0;
	uint64_t p1;
};


struct NativeArg_s {
	u64* returnValue;
	u32 argCount;
	u8 padding1[4];
	u64* argValues;
	u32 vectorCount;
	u8 padding2[4];
	vector3* argVectors[4];
	vector4 tempVectors[4];
};

extern NativeArg_s nativeArg;

void callHash(u64 hash);
void resetArgs();
void setVectors();

template<typename T>
inline void pushArg(T value) {
	*(T*)&nativeArg.argValues[nativeArg.argCount] = value;
	nativeArg.argCount++;
}

template<typename R>
inline R getReturn() {
	return *(R*)&nativeArg.returnValue[0];
}

/*template<typename N, typename... A>
N invoke(u64 hash, A &&... args)
{
	resetArgs();
	int dummy[] = { 0, ((void)pushArg(std::forward<A>(args)), 0) ... };
	callHash(hash);
	setVectors();
	return getReturn<N>();
}*/

template<typename T>
T invoke(uint64_t hash)
{
	resetArgs();
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1>
T invoke(uint64_t hash, P1 p0)
{
	resetArgs();
	pushArg(p0);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2>
T invoke(uint64_t hash, P1 p0, P2 p1)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26, typename P27>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25, P27 p26)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	pushArg(p26);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26, typename P27, typename P28>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25, P27 p26, P28 p27)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	pushArg(p26);
	pushArg(p27);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26, typename P27, typename P28, typename P29>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25, P27 p26, P28 p27, P29 p28)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	pushArg(p26);
	pushArg(p27);
	pushArg(p28);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26, typename P27, typename P28, typename P29, typename P30>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25, P27 p26, P28 p27, P29 p28, P30 p29)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	pushArg(p26);
	pushArg(p27);
	pushArg(p28);
	pushArg(p29);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26, typename P27, typename P28, typename P29, typename P30, typename P31>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25, P27 p26, P28 p27, P29 p28, P30 p29, P31 p30)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	pushArg(p26);
	pushArg(p27);
	pushArg(p28);
	pushArg(p29);
	pushArg(p30);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}

template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15, typename P16, typename P17, typename P18, typename P19, typename P20, typename P21, typename P22, typename P23, typename P24, typename P25, typename P26, typename P27, typename P28, typename P29, typename P30, typename P31, typename P32>
T invoke(uint64_t hash, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9, P11 p10, P12 p11, P13 p12, P14 p13, P15 p14, P16 p15, P17 p16, P18 p17, P19 p18, P20 p19, P21 p20, P22 p21, P23 p22, P24 p23, P25 p24, P26 p25, P27 p26, P28 p27, P29 p28, P30 p29, P31 p30, P32 p31)
{
	resetArgs();
	pushArg(p0);
	pushArg(p1);
	pushArg(p2);
	pushArg(p3);
	pushArg(p4);
	pushArg(p5);
	pushArg(p6);
	pushArg(p7);
	pushArg(p8);
	pushArg(p9);
	pushArg(p10);
	pushArg(p11);
	pushArg(p12);
	pushArg(p13);
	pushArg(p14);
	pushArg(p15);
	pushArg(p16);
	pushArg(p17);
	pushArg(p18);
	pushArg(p19);
	pushArg(p20);
	pushArg(p21);
	pushArg(p22);
	pushArg(p23);
	pushArg(p24);
	pushArg(p25);
	pushArg(p26);
	pushArg(p27);
	pushArg(p28);
	pushArg(p29);
	pushArg(p30);
	pushArg(p31);
	callHash(hash);
	setVectors();
	return getReturn<T>();
}
