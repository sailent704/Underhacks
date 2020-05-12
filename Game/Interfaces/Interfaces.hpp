#pragma once
#include "../SDK/SDK.hpp"

//spook953 - today at 8:41PM:
//why is GMFuncs a pointer
//Pin - today at 8:42PM:
//because I felt like it

struct CGMFunctions
{
	void room_goto(int nRoomNumber);
	void room_goto_meme(int nRoomNumber);
	void audio_stop_all();
	void room_goto_previous();
	void room_goto_next();
	void window_set_fullscreen(bool bFullscreen);
	void room_restart();
	void window_set_size(int x, int y);

private:
	void CallGMLFunc(const char* szFuncName, DWORD dwFunction, int nParams, PVOID arg1, PVOID arg2, PVOID arg3);
};

struct CPlayerData
{
public:
	double m_nIsInFight; //Set to 0 if we are not fighting, 1 if we are.
private:
	UCHAR pad0[0x16];
public:
	double m_Interact; //global.interact?
private:
	UCHAR pad1[0xA2];
public:
	double m_nKills; //Current amount of monsters killed
private:
	UCHAR pad2[0x238];
public:
	double m_nRoom; //Backup Room, used to return the player to a valid room after a fight.
private:
	UCHAR pad3[0xF8];
public:
	double m_nLOVE; //Level of Violence
private:
	UCHAR pad4[0x4];
public:
	double m_nEXP; //Execution Points
private:
	UCHAR pad5[0x4];
public:
	double m_nGold; //Gold
private:
	UCHAR pad6[0xB8];
public:
	double m_nMaxHealth; //Maximum Health
private:
	UCHAR pad7[0x8];
public:
	double m_nHealth; //Current Health
};

static struct COffsets
{
	DWORD dwBase;
	DWORD dwUserCmd;
	DWORD audio_stop_all;
	DWORD room_goto_previous;
	DWORD room_goto_next;
	DWORD room_restart;
	DWORD room_goto;
	DWORD window_set_fullscreen;
	DWORD window_set_size;

	void Initialize();
};

struct CDirectX
{

};

struct CUndertale
{
private:
	CDirectX Direct3D					= CDirectX();
public:
	CGMFunctions* GMFuncs		= new CGMFunctions;
	CPlayerData* PlayerData		= new CPlayerData;
	COffsets Offsets						= COffsets();

	void Init(); //Execute this function to map the CUserCmds, get the correct D3DDevice, run the hooks
	void Destroy(); //Called on DLL_PROCESS_DETACH
};

static CUndertale IGame = CUndertale();