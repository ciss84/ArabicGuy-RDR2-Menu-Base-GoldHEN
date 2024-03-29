#include <Common.h>
#include "plugin_common.h"

#include <stdint.h>

typedef long suseconds_t;

typedef void *PVOID;
typedef unsigned long DWORD;
typedef unsigned long _DWORD;
typedef char CHAR;
typedef unsigned char BYTE;
typedef unsigned char byte;
typedef int BOOL;
typedef float FLOAT;
typedef CHAR *PCHAR;
typedef unsigned short WORD;
typedef DWORD *PDWORD;
typedef void* Void;
typedef int Any;
typedef unsigned int uint;
typedef int Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

struct Vect3
{
	float x;
	float unk1001;
	float y;
	float unk1002;
	float z;
	float c;
	float d;
	float e;
	float f;
};

typedef struct {
	float x, y;
} vector2;

typedef struct {
	float x, _padX, y, _padY, z, _padZ;
} vector3;

typedef struct {
	float x, y, z, w;
} vector4;

typedef struct {
	int r, g, b, a;
} Color;