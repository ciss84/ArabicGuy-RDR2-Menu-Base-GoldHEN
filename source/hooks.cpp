#include "hooks.h"
#include "imports.h"
#include "utilitie.h"
#include "invoker.h"
#include "crossmaping.h"
#include "enums.h"
#include "vars.h"
#include "natives.h"
#include "extraNatives.h"
#include "functions.h"
#include "drawing.h"
#include "utils.h"
#include "detour.h"
#define TEXT_INFO_POINTER 0x886A00C

namespace Hooks {

registerNative_t registerNative_Stub;
//fcxLoader_t fcxLoader_Stub;
contentIsExist_t contentIsExist_Stub;
omtLoader_t omtLoader_Stub;
xml_omt_Loader_t xml_omt_Loader_Stub;
main_t main_Stub;
DataFunc_t DataFunc_Stub;
xmlLoader_t xmlLoader_Stub;
uint64_t v_gameDir;
int64_t SUB_19E03E0_ADDR;
int64_t SUB_19E0200_ADDR;
char nr_buffer[255];
bool natives_init;
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4
#define MAP_ANONYMOUS 0x20
#define MAP_PRIVATE 0x02
#define MAP_FIXED 0x10
//#define PAGE_EXECUTE_READWRITE = 0x40

uint64_t registerNative_hook(int64_t pointer, uint64_t nativeCrossmap, int64_t nativeFuncAddr) {
if(!natives_init) {
	nativesTableAddr = (void*)0x270000000;
	//sprintf(nr_buffer, "nativesTableAddr: %p", nativesTableAddr);
	// sceSysUtilSendSystemNotificationWithText(222, nr_buffer);
	natives_init = 1;
	}
	twoQwords *p2q;
	 //for(int i = 0; i < 36; i++) {
	 p2q = reinterpret_cast<twoQwords*>(__HASHMAPDATA);
	 while(p2q->p0) {
	  if(p2q->p1 == nativeCrossmap) { //crossmap comparation
	 // sprintf(buffer2, "NativeFunction: 0x%llx", p2q->p1);
	  
	
	
	*(uint64_t*)((uint64_t)nativesTableAddr + v_nt_counter) = p2q->p0;
	*(uint32_t*)(((uint64_t)nativesTableAddr + v_nt_counter + 0xC)) = nativeFuncAddr;
	v_nt_counter += 0x10;
	break;
	}
	p2q++;
	}
	return registerNative_Stub(pointer, nativeCrossmap, nativeFuncAddr);
}
//Hash PLAYER_ZERO = 0xD7114C9;Hash PLAYER_ONE = 0x9B22DBAF;Hash PLAYER_TWO = 0x9B810FA2;Hash SP0_TOTAL_CASH = 0x324C31D;Hash SP1_TOTAL_CASH = 0x44BD6982;Hash SP2_TOTAL_CASH = 0x8D75047D;
//int GET_PLAYER_NUMBER() {switch (GET_ENTITY_MODEL(PLAYER_PED_ID())){case 225514697: return 0;case -1692214353: return 1;case -1686040670: return 2;}return -1;};
//int GET_PLAYER_CASH() {int plyCash = -1;switch (GET_PLAYER_NUMBER()){case 0: STAT_GET_INT(SP0_TOTAL_CASH, &plyCash, -1); break;case 1: STAT_GET_INT(SP1_TOTAL_CASH, &plyCash, -1); break;case 2: STAT_GET_INT(SP2_TOTAL_CASH, &plyCash, -1); break;}return plyCash;};
//bool SET_PLAYER_CASH(int amount) {switch (GET_PLAYER_NUMBER()){case 0: STAT_SET_INT(SP0_TOTAL_CASH, amount, true); break;case 1: STAT_SET_INT(SP1_TOTAL_CASH, amount, true); break;case 2: STAT_SET_INT(SP2_TOTAL_CASH, amount, true); break;default:return false;}return true;};

void monitorButtons() {
	Static_67 = GET_FRAME_COUNT();
	if ( !( GET_FRAME_COUNT() - Static_67 >= 2 ) ) {
		testT = true;
	} else testT = false;
	Static_67 = GET_FRAME_COUNT();
	if (NumMenu == Closed) {
		if (IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_LB) && IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_X)) {
			NumMenu = Main_Menu;
			NumMenuLevel = 0;
			currentOption = 1;
			playSound("HUD_DRAW", "HUD_DUEL_SOUNDSET");
		}
	}
	else {
		if(testT) {
			if (check_button(FrontendCancel, 0)) {
				if (NumMenu == Main_Menu) {
					NumMenu = Closed;
				}
				else {
					NumMenu = lastNumMenu[NumMenuLevel - 1];
					currentOption = lastOption[NumMenuLevel - 1];
					NumMenuLevel--;
				}
				playSound("BACK", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(FrontendAccept, 0)) {
				PressX = true;
				playSound("ACCEPT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(FrontendUp, 1)) {
				currentOption--;
				if (currentOption < 1) {
					currentOption = optionCount;
				}
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(FrontendDown, 1)) {
				currentOption++;
				if (currentOption > optionCount) {
					currentOption = 1;
				}
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(FrontendRight, 1)) {
				rightPress = true;
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(FrontendLeft, 1)) {
				leftPress = true;
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
		}
	}
}
void actionsController() {
	DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	DISABLE_CONTROL_ACTION(2, INPUT_VEH_SELECT_NEXT_WEAPON, true);
	DISABLE_CONTROL_ACTION(2, INPUT_HUD_SPECIAL, true);
	DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, true);
	DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_CANCEL, true);
	DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_LEFT, true);
	DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RIGHT, true);
	DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_DOWN, true);
	DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_UP, true);
	DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SPRINT, true);
	DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	DISABLE_CONTROL_ACTION(2, MeleeHorseAttackPrimary, true);
	DISABLE_CONTROL_ACTION(2, MeleeHorseAttackSecondary, true);
	DISABLE_CONTROL_ACTION(2, MeleeGrappleAttack, true);
	DISABLE_CONTROL_ACTION(2, MeleeAttack, true);
	DISABLE_CONTROL_ACTION(2, INPUT_MAP, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SELECT_WEAPON_UNARMED, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SELECT_WEAPON_MELEE, true);
	DISABLE_CONTROL_ACTION(2, INPUT_ATTACK2, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_UP, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_DOWN, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_LEFT, true);
	DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_RIGHT, true);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_CANCEL);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_DOWN);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_UP);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_LEFT);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_RIGHT);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_X);
	DRAW_RECT(Menu_X, 0.1177f, CenterDraw, 0.080f,BannerR, BannerG, BannerB, 150, 0, 0);
	if (NumMenu != Closed) {
		if (InfoText != NULL) {
			if (optionCount > maxOptions) {
				DRAW_TEXT(InfoText, 0, 0.758 - 0.125, ((maxOptions + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
				DRAW_RECT(Menu_X, (((maxOptions + 2.2080) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150, 0, 0); //Info Box
			}
			else {
				DRAW_TEXT(InfoText, 0, 0.758- 0.125, ((optionCount + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
				DRAW_RECT(Menu_X, (((optionCount + 2.2080) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150, 0, 0); //Info Box
			}
		}
		if (optionCount > maxOptions) {
			DRAW_TEXT("Ver: 1.0", 0, 0.758 - 0.125, ((maxOptions + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 255, false, false, 0, 0, 0);
			char buffer[30];
			snprintf(buffer, sizeof(buffer), "~bold~%i/%i", currentOption, optionCount);
			drawTextCounter(buffer, 0, 0.758 + 0.102, ((maxOptions + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 200); //option count
			DRAW_RECT(Menu_X, (((maxOptions + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150, 0, 0); //Info Box
		}
		else {
			DRAW_TEXT("Ver: 1.0", 0, 0.758- 0.125, ((optionCount + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 255, false, false, 0, 0, 0);
			char buffer[30];
			snprintf(buffer, sizeof(buffer), "~bold~%i/%i", currentOption, optionCount);
			drawTextCounter(buffer, 0, 0.758 + 0.102, ((optionCount + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 200); //option count
			DRAW_RECT(Menu_X, (((optionCount + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150, 0, 0); //Info Box
		}
	}
}
void looping()
{
	if(Invinsibility){ SET_PLAYER_INVINCIBLE(PLAYER_ID(), true); }
	if(NeverWanted){ CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID()); }
	if(Invisibility) { SET_ENTITY_VISIBLE(PLAYER_PED_ID(), false); } else { SET_ENTITY_VISIBLE(PLAYER_PED_ID(), true); }
	if(SuperRun) {
	if (IS_CONTROL_PRESSED(0, FrontendAccept) && NumMenu == Closed) {
			APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), true, 0, 15, 0, 0, 0, 0, false, true, true, true, 0, true);
			APPLY_FORCE_TO_ENTITY(PLAYER_PED_ID(), true, 0, 0, 0, 0, 0, 0, false, true, true, true, 0, true);
		}
	}
	if(SuperJump){ SET_SUPER_JUMP_THIS_FRAME(PLAYER_ID()); }
}
void menu(void) {
	drawScroller();
	optionCount = 0;
	if(NumMenu == Main_Menu) {
		AddTitle("ArabicGuy Menu Base");
		addOption("Player",  1, "");
		addOption("Credits",  0, "");
    if(GET() == 1) { ChangeMenu(PlayerMenu); }
    if(GET() == 2) { ChangeMenu(Credits); }
	}
	else if(NumMenu == PlayerMenu) {
		AddTitle("Player");
		CheckBox("GodMode", Invinsibility, 1, "");
	  CheckBox("Never Wanted", NeverWanted, 0, "");
		CheckBox("Super Run", SuperRun, 1, "Press X to use super run.");
		CheckBox("Super Jump", SuperJump, 0, "Press square to use super Jump.");		
		CheckBox("Invisibility", Invisibility, 1, "");
		CheckBox("Freeze Position", FreezePos, 0, "");
		if(GET() == 1) { Invinsibility = !Invinsibility; }
		if(GET() == 2) { NeverWanted = !NeverWanted; }			
		if(GET() == 3) { SuperRun = !SuperRun; }
		if(GET() == 4) { SuperJump = !SuperJump; }	
		if(GET() == 5) { Invisibility = !Invisibility; }			
		if(GET() == 6) { FreezePos =! FreezePos; FREEZE_ENTITY_POSITION(PLAYER_PED_ID(), FreezePos); }		
	}
	else if(NumMenu == Credits) {
		AddTitle("Credits");
		addOption("84Ciss", 1, "");		
		addOption("rfoodxmodz", 1, "");
		addOption("2much4u", 0, "");
	}
	if(NumMenu != Closed)
	actionsController();
}
uint32_t main_Hook(char a1) {
setTextData = reinterpret_cast<text_info*>(TEXT_INFO_POINTER);
int FrameCount = GET_FRAME_COUNT();
		if (FrameCount > frameCount) {
			frameCount = FrameCount;
      looping();
	    monitorButtons();				  			
			if(NumMenu != Closed) {
				menu();
				resetVars();
			}
	}
	return 1;
}

};
