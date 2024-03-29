#include "plugin_common.h"
#include <orbis/libkernel.h>

#include <stdint.h>
#include <stdarg.h>
#include "detour.h"
#include "utilitie.h"
#include "hooks.h"
#include "imports.h"
#include "types.h"
//#include "ImgCache.h"
#define GOLDHEN_PATH_ (const char*) GOLDHEN_PATH
#define BASE_PATH_PATCH (const char*) GOLDHEN_PATH_ "/patches"
#define BASE_PATH_PATCH_SETTINGS (const char*) BASE_PATH_PATCH "/settings"
#define PLUGIN_NAME (const char*) "Sheriff"
#define PLUGIN_DESC (const char*) "Rdr2 Sheriff Menu"
#define PLUGIN_AUTH (const char*) "84Ciss"
#define PLUGIN_VER 0x129 // 1.29

#define NO_ASLR_ADDR 0x00400000
#define TEX_ICON "/user/data/icon0.png"

attr_public const char *g_pluginName = PLUGIN_NAME;
attr_public const char *g_pluginDesc = PLUGIN_DESC;
attr_public const char *g_pluginAuth = PLUGIN_AUTH;
attr_public u32 g_pluginVersion = PLUGIN_VER;

char titleid[16] = {0};
char game_elf[32] = {0};
char game_prx[MAX_PATH_] = {0};
char game_ver[8] = {0};

u64 module_base = 0;
u32 module_size = 0;
// unused for now
u64 PRX_module_base = 0;
u32 PRX_module_size = 0;
struct proc_info procInfo;
long APP_BASE = 0x400000;

int get_module_info(OrbisKernelModuleInfo moduleInfo, const char* name, uint64_t *base, uint32_t *size)
{
    OrbisKernelModule handles[256];
    size_t numModules;
    int ret = 0;
    ret = sceKernelGetModuleList(handles, sizeof(handles), &numModules);
    if (ret)
    {
        final_printf("sceKernelGetModuleList (0x%08x)\n", ret);
        return ret;
    }
    final_printf("numModules: %li\n", numModules);
    for (size_t i = 0; i < numModules; ++i)
    {
        ret = sceKernelGetModuleInfo(handles[i], &moduleInfo);
        final_printf("ret 0x%x\n", ret);
        final_printf("module %li\n", i);
        final_printf("name: %s\n", moduleInfo.name);
        final_printf("start: 0x%lx\n", (uint64_t)moduleInfo.segmentInfo[0].address);
        final_printf("size: %u (0x%x)\n", moduleInfo.segmentInfo[0].size, moduleInfo.segmentInfo[0].size);
        if (ret)
        {
            final_printf("sceKernelGetModuleInfo (%X)\n", ret);
            return ret;
        }

        if (strcmp(moduleInfo.name, name) == 0 || name[0] == '0')
        {
            if (base)
                *base = (uint64_t)moduleInfo.segmentInfo[0].address;

            if (size)
                *size = moduleInfo.segmentInfo[0].size;
            return 1;
        }
    }
    return 0;
}

void* my_thread(void* args) {
    u64 isonline_addr = (uint64_t)0x5106F20 + APP_BASE; //0x5BA55F0 0x5BA56A0
    WriteJump(isonline_addr, (uint64_t)Hooks::main_Hook);

    uint32_t boot_wait = 10;
    final_printf("Sleeping for %u seconds...\n", boot_wait);
    sleep(boot_wait);
    scePthreadExit(NULL);
    return NULL;
}
unsigned int CRC32(const char* str) {
	size_t textLen = strlen(str);
	//int i = 0;
	unsigned int retHash = 0;
	//
	for (int i = 0; i < textLen; i++)
	{
		if (str[0] == '"')
		i = 1;
		char ctext = str[i];
		if (ctext == '"')
		break;
		if (ctext - 65 > 25)
		{
			if (ctext == '\\')
			ctext = '/';
		}
		else ctext += 32;
		retHash = (1032 * (retHash + ctext) >> 8) ^ 1032 * (retHash + ctext);
	}
	return 32769 * (9 * retHash ^ (10 * retHash >> 11));
}
extern "C" {
s32 attr_module_hidden module_start(size_t argc, const void *args) {
    final_printf("[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    final_printf("[GoldHEN] Plugin Author(s): %s\n", g_pluginAuth);
    boot_ver();
    struct proc_info procInfo;
    OrbisKernelModuleInfo CurrentModuleInfo;
    CurrentModuleInfo.size = sizeof(OrbisKernelModuleInfo);
    if(!get_module_info(CurrentModuleInfo, "0", &module_base, &module_size) && module_base && module_size)
    {
        final_printf("Could not find module info for current process\n");
        return -1;
    }
    if (sys_sdk_proc_info(&procInfo) == 0) {
    initImports();
    //writeCacheImg();
    sceSysUtilSendSystemNotificationWithText(222, "Plugin Rdr2 1.29\n ");
    sceSysUtilSendSystemNotificationWithText(222, "Sheriff Menu V1.0 By @84Ciss\n ");   
    print_proc_info();
    OrbisPthread thread;
    scePthreadCreate(&thread, NULL, my_thread, NULL, "my_thread");
    scePthreadJoin(thread, NULL);
    sceSysUtilSendSystemNotificationWithText(222, "Open Menu With  + , \nEnjoy!");
    return 0;
    }
    NotifyStatic(TEX_ICON, "Unable to get process info from " STRINGIFY(sys_sdk_proc_info));    
    return -1;
}
}
extern "C" {
s32 attr_module_hidden module_stop(s64 argc, const void *args) {
    final_printf("[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    return 0;
}
}