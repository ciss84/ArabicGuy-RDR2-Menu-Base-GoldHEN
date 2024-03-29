#include <Common.h>
#include "plugin_common.h"
#include "types.h"
#include "utilitie.h"

namespace Hooks {
extern uint64_t v_gameDir;
extern int64_t SUB_19E03E0_ADDR;
extern int64_t SUB_19E0200_ADDR;
typedef uint64_t(*registerNative_t)(int64_t pointer, uint64_t nativeCrossmap, int64_t nativeFuncAddr);
typedef char(*xml_omt_Loader_t)(long long a1,  char *path, char* ex, long long a4, long long a5);
typedef uint32_t(*main_t)(char a1);
typedef char*(*DataFunc_t)(char* a1, _BYTE* a2);
//typedef double(*fcxLoader_t)(long long Type, int32_t a2, __m128 _XMM0);
typedef u8(*contentIsExist_t)(long long a1, char *path, long long a3);
typedef char*(*omtLoader_t)(uint64_t a1, char* path, char* ex, uint64_t a4, uint8_t a5);
typedef char(*xmlLoader_t)(uint64_t a1, char* path, uint64_t a3, uint64_t a4, uint64_t a5, char a6, uint64_t a7);
extern registerNative_t registerNative_Stub;
extern main_t main_Stub;
extern DataFunc_t DataFunc_Stub;
//extern fcxLoader_t fcxLoader_Stub;
extern contentIsExist_t contentIsExist_Stub;
extern omtLoader_t omtLoader_Stub;
extern xml_omt_Loader_t xml_omt_Loader_Stub;
extern xmlLoader_t xmlLoader_Stub;
uint64_t registerNative_hook(int64_t pointer, uint64_t nativeCrossmap, int64_t nativeFuncAddr);
char xml_omt_Loader_hook(long long a1, char *path, char* ex, long long a4, long long a5);
uint32_t main_Hook(char a1);
char* DataFunc_hook(char* a1, _BYTE* a2);
//double fcxLoader_hook(long long Type, int32_t a2, __m128 _XMM0);
u8 contentIsExist_hook(long long a1, char *path, long long a3);
char* omtLoader_hook(uint64_t a1, char* path, char* ex, uint64_t a4, uint8_t a5);
char xmlLoader_hook(uint64_t a1,  char* path, uint64_t a3, uint64_t a4, uint64_t a5, char a6, uint64_t a7);
};
