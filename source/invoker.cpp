#include "invoker.h"
#include "imports.h"
#include "nativesData.h"
int v_nt_counter;
void *nativesTableAddr;
NativeArg_s nativeArg;
u64 args[30];

void setVectors() {
	while (nativeArg.vectorCount) {
		nativeArg.vectorCount--;

		vector3* argVector = nativeArg.argVectors[nativeArg.vectorCount];
		vector4 tempVector = nativeArg.tempVectors[nativeArg.vectorCount];		
		argVector->x = tempVector.x;
		argVector->y = tempVector.y;
		argVector->z = tempVector.z;
	}
}
char buffer2[255];
void callHash(u64 hash) {
//((void(*)(NativeArg_s*))(hash + 0x400000))(&nativeArg);// native address + game base
	 for(int i = 0; i <= sizeof(nativesHashes_129) / sizeof(nativesHashes_129[0]); i++) {
		if(nativesHashes_129[i] == hash) {
			((void(*)(NativeArg_s*))nativesFunctions_129[i])(&nativeArg);
		}
	}
}

void resetArgs() {
	nativeArg.argCount = 0;
	nativeArg.vectorCount = 0;
	nativeArg.argValues = nativeArg.returnValue = args;
}
