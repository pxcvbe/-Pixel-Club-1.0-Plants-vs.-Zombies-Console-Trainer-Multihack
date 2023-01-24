// All Variable Here!
// This simple variable defined
// You can add Class or namespace for clean code :)
#pragma once

/// <GAME WINDOW VARS>
LPCSTR LGameWindow = "Plants vs. Zombies";
std::string GameStatus;
HANDLE hProcHandle;
DWORD dwProcID = NULL;

/// <BOOLEAN VARS>
bool isGameAvailable;
bool updateOnNextRun;

/// <VIRTUAL ALLOC MEMORY VARS>
void* pVirtualMemRapidFire;
void* pVirtualMemZombie1;
void* pVirtualMemZombie2;
void* pVirtualMemZombie3;

// SUN VARS
bool SunStatus;
int SunValue = 9999; // give 9999 to pointer address of sun
uintptr_t SunBaseAddress = { 0x00731C50 }; // base address of sun
uintptr_t SunOffsets[] = { 0x868, 0x178, 0x4, 0x5578 }; // pointer address of sun

// MONEY VARS
bool MoneyStatus;
int MoneyValue = 1000000/10; // give $1.000.000 numbers to pointer address of money | 337 is money before modified status!
uintptr_t MoneyBaseAddress = { 0x00731C50 }; // base address of money
uintptr_t MoneyOffsets[] = { 0x94C, 0x54 }; // pointer address of money

// NO DURATION CARD VARS
bool NoDurationStatus;
int lenNoDuration = 2; // size byte is 2
uintptr_t NoDurationCardBaseAddress = { 0x004958C5 }; // base address of plants duration recharge
char NoDurationDefaultOpCode[] = "\x7E\x14"; // this original op-code
char NoDurationNOPs[] = "\x90\x90"; // this is NOP operation that give no duration effect

// AUTO COLLECT SUN VARS
bool autoCollectSunStatus;
int lenAutoCollectSun = 2; // size byte is 2
uintptr_t AutoCollectSunBaseAddress = { 0x004352F2 }; // base address of collect sun function
char autoCollectSunDefaultOpCode[] = "\x75\x09"; // this is original op-code
char autoCollectSunJMP[] = "\xEB\x09"; // this  is JUMP Instruction (\xEB) we gonna do "JMP" Instead "Jump not Equal" to run collect sun function in the game structure!

// RAPID FIRE VARS
bool rapidFireStatus;
int lenRapidFireBytes = 6;
uintptr_t rapidFireBaseAddress = { 0x00465C0C };
char rapidFireDefaultOpCode[] = "\x89\x4E\x58\x83\xF8\x12"; // size default is 6

// BURST FIRE VARS
bool burstFireStatus;
int lenBurstFireBytes = 6;
uintptr_t burstFireBaseAddress = { 0x0046AEC4 };
char burstFireDefaultOpCode[] = "\x0F\x85\x98\xFE\xFF\xFF"; // size default is 6
char burstFireJumpBelow[] = "\x0F\x82\x98\xFE\xFF\xFF"; // this is JUMP if below Instruction we gonna do "JB" Instead "Jump not Equal" to run Burst Fire Rates for Plants

// BRUTAL BURST GENERATE SUN VARS
bool burstGenerateSun;
int lenBurstBurstGenerateSun = 6;
uintptr_t burstGenerateSunBaseAddress = { 0x00465E2C };
char burstGenerateSunNOPs[] = "\x90\x90\x90\x90\x90\x90";
char burstGenerateSunDefaultOpCode[] = "\x0F\x8F\xE5\x00\x00\x00";

// FAST GENERATE SUN VARS
bool fastGenerateSun;
int lenGenerateSun = 5; // size len is 5 { same as byte }
uintptr_t fastGenerateSunBaseAddress = { 0x00465E46 };
char fastGenerateSunDefaultOpCode[] = "\x89\x47\x58\x8B\x07"; // size byte default is 5

/// Fast Kill All Zombies VARS
bool fast_kill_all_zombies;
int len_opcode_fastkill = 6;
uintptr_t fast_kill_zb_normalbaseAddress = { 0x00545E04 };
char fast_kill_zbnormal_defaultOpcode[]  = "\x89\xAF\xC8\x00\x00\x00";   // size byte default is 6
// Fast Kill Zombie Conehat
uintptr_t fast_kill_zb_conehatbaseAddress = { 0x00545B1A };
char fast_kill_zbconehat_defaultOpcode[]   = "\x89\x8D\xD0\x00\x00\x00"; // size byte default is 6
// Fast Kill Door Zombies
uintptr_t fast_kill_zb_doorbaseAddress  = { 0x00545771 };
char fast_kill_zbdoor_defaultOpcode[] = "\x29\x86\xDC\x00\x00\x00";      // size byte default is 6

// Planting Anywhere VARS
bool plants_anywhere;
int len_opcode_planting = 6;
uintptr_t plants_anywhere_baseAddress = { 0x0041334F };
char plants_anywhere_defaultOpCode[] = "\x0F\x84\x20\x09\x00\x00"; // size byte default is 6
char plants_anywhere_JNL[] = "\x0F\x8D\x20\x09\x00\x00"; // this is JUMP if not Less, we gonna do "JNL" Instead "Jump Equal" to run Planting anywhere

// Multi Planting VARS
bool multi_plants;
int len_opcode_multi_plants = 6;
uintptr_t multi_plants_baseAddress = { 0x00414007 };
char multi_plants_defaultOpCode[] = "\x0F\x85\xE3\x00\x00\x00"; // size byte default is 6
char multi_plants_JMPEqual[]      = "\x0F\x84\xE3\x00\x00\x00"; // this is JUMP Equal we gonna do "JE" Instead "Jump not Equal" to run Multi Planting