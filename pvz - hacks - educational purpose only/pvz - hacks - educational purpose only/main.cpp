/*
 _____ _______   ________ _         _____ _    _ ____  ______            _______      ________   _    _          _____ _  __ _____
|  __ \_   _\ \ / /  ____| |       / ____| |  | |  _ \|  ____|          |  __ \ \    / /___  /  | |  | |   /\   / ____| |/ // ____|
| |__) || |  \ V /| |__  | |      | |    | |  | | |_) | |__     ______  | |__) \ \  / /   / /   | |__| |  /  \ | |    | ' /| (___
|  ___/ | |   > < |  __| | |      | |    | |  | |  _ <|  __|   |______| |  ___/ \ \/ /   / /    |  __  | / /\ \| |    |  <  \___ \
| |    _| |_ / . \| |____| |____  | |____| |__| | |_) | |____           | |      \  /   / /__   | |  | |/ ____ \ |____| . \ ____) |
|_|   |_____/_/ \_\______|______|  \_____|\____/|____/|______|          |_|       \/   /_____|  |_|  |_/_/    \_\_____|_|\_\_____/
*/

// EXAMPLE SOURCE CODE HACKS FOR PLANTS VS ZOMBIES "STEAM EDITION" [EXTERNAL TRAINER]
// THIS CODE WRITTED & MODIFIED BY : PXCVBE / IVAN.K [https://github.com/pxcvbe]
// THIS CODE WAS ORIGINALLY FROM https://github.com/WN59

// basic library include
#include <iostream> 
#include <vector>
#include <Windows.h>
#include <ctime>
#include <string>
// color library include
#include <algorithm>
#include <cctype>
#include <iterator>
#include <set>
#include <sstream>
#include "include/color/color.hpp"
#include "include/variable/variable.h"
#include "include/shellcode/shellcode.c"

#pragma warning(disable:4129)

// Function Caller Global
uintptr_t FindMYAddy(int pointerlevel, HANDLE hProcHandle, uintptr_t offsets[], uintptr_t baseaddress);
bool WriteToMemory(HANDLE hProcHandle);

int main()
{
	HWND hGameWindow = NULL;
	int timeSinceLastUpdate = clock();
	int gameAvailTMR = clock();
	int onePressTMR = clock();
	updateOnNextRun = true;
	// OFF VARS
	std::string sSunStatus = "\033[31m OFF \033[0m";
	std::string sMoneyStatus = "\033[31m OFF \033[0m";
	std::string sNoDurationStatus = "\033[31m OFF \033[0m";
	std::string sAutoCollectionStatus = "\033[31m OFF \033[0m";
	std::string sRapidFireStatus = "\033[31m OFF \033[0m";
	std::string sBurstFireStatus = "\033[31m OFF \033[0m";
	std::string sBurstGenerateSun = "\033[31m OFF \033[0m";
	std::string sFastGenerateSun = "\033[31m OFF \033[0m";
	std::string sFastKillZB = "\033[31m OFF \033[0m";
	std::string sFastKillZB2 = "\033[31m OFF \033[0m";
	std::string sFastKillZB3 = "\033[31m OFF \033[0m";
	std::string sPlantsAnywhere = "\033[31m OFF \033[0m";
	std::string sMultiPlants = "\033[31m OFF \033[0m";

	while (!GetAsyncKeyState(VK_INSERT))
	{
		SetConsoleTitleA("Plants vs. Zombies Trainer [pIxel-Club 1.0] by: pxcvbe");
		if (clock() - gameAvailTMR > 100)
		{
			gameAvailTMR = clock();
			isGameAvailable = false;

			hGameWindow = FindWindowA(NULL, LGameWindow);
			if (hGameWindow) {
				GetWindowThreadProcessId(hGameWindow, &dwProcID); // find processid
				if (dwProcID != 0)
				{
					hProcHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
					if (hProcHandle == INVALID_HANDLE_VALUE || hProcHandle == NULL)
					{
						GameStatus = "Fail to open process for valid handle";
					}
					else
					{
						GameStatus = " Plants vs. Zombie "  "[ \033[32m Ready to Hacks! \033[0m]"; // "\033[32m (your text) \033[0m]" is green colors
						isGameAvailable = true;
					}
				}
				else
				{
					GameStatus = " Failed to get processID ";
				}
			}
			else
			{
				GameStatus = " Plants vs Zombies " "[ \033[31mNot Found . . . ! \033[0m ]"; // "\033[31m (your text) \033[0m]" is red colors

				/*  -- why i'm not using "dye" or "hue" namespace in header cause it's very hardcoded which is cause pain in the ass haha --  */
			}

			if (updateOnNextRun || clock() - timeSinceLastUpdate > 5000)
			{ 
				system("CLS");
				std::cout << dye::green_on_light_green("=") << dye::green_on_light_green("=") << dye::green_on_light_green("==============================================================================================================") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("         d888                     888         .d8888b.  888          888            d888        .d8888b. ") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("        d8888                     888        d88P  Y88b 888          888           d8888       d88P  Y88b") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::red      ("          888                     888        888    888 888          888             888       888    888") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::red      ("88888b.   888   888  888  .d88b.  888        888        888 888  888 88888b.         888       888    888") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::red      ("888 '88b  888   `Y8bd8P' d8P  Y8b 888        888        888 888  888 888 '88b        888       888    888") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::red      ("888  888  888     X88K   88888888 888 888888 888    888 888 888  888 888  888        888       888    888") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("888 d88P  888   .d8''8b. Y8b.     888        Y88b  d88P 888 Y88b 888 888 d88P        888   d8b Y88b  d88P") << "     " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("88888P' 8888888 888  888  'Y8888  888         'Y8888P'  888  'Y88888 88888P'       8888888 Y8P  'Y8888P'")  << "      "<< dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("888") << "                                                                                                           " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("888") << "                                                                                                           " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("=") << dye::light_red("888") << "                                                                                                           " << dye::green_on_light_green("=") << std::endl;
				std::cout << dye::green_on_light_green("================================================================================================================\n") << std::endl;
				std::cout << "GAME-STATUS: " << GameStatus << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F1]") << " Unlimited Sun(9999) -> ["     << sSunStatus << "] <-" << std::endl << std::endl;
				std::cout << " PRESS " << dye::red("[ENTER]") << " Give $1 Millions of Money(Freeze) -> [" << sMoneyStatus << "] <-" << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F2]") << " No Duration -> ["             << sNoDurationStatus << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F3]") << " Auto-Collect Sun -> ["        << sAutoCollectionStatus << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F4]") << " Rapid Fire -> ["              << sRapidFireStatus << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F5]") << " Burst Fire -> ["              << sBurstFireStatus << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F6]") << " Burst Generate Sun" << dye::yellow(" (Caution: Lagging!)") << " -> [" << sBurstGenerateSun << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F7]") << " Fast Generate Sun -> ["       << sFastGenerateSun << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F8]") << " Fast Kill Zombie -> ["        << sFastKillZB << "] <- " << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F9]") << " Planting Anywhere -> ["       << sPlantsAnywhere << "] <-" << std::endl << std::endl;
				std::cout << " PRESS " << dye::light_green("[F10]") << " Multi Planting -> ["         << sMultiPlants << "] <-" << std::endl << std::endl;
				std::cout << " PRESS " << hue::light_red << "[INSERT]" << hue::reset << " To Exit " << std::endl;
				updateOnNextRun = false;
				timeSinceLastUpdate = clock();
			}
			 
			if (isGameAvailable)
			{
				WriteToMemory(hProcHandle);
			}
		}
		// ON OFF FUNCTION
		if (clock() - onePressTMR > 400)
		{
			if (isGameAvailable)
			{
				if (GetAsyncKeyState(VK_F1))
				{
					onePressTMR = clock();
					SunStatus = !SunStatus;
					updateOnNextRun = true;
					if (SunStatus) sSunStatus = "\033[32m ON \033[0m";
					else sSunStatus = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F2))
				{
					onePressTMR = clock();
					NoDurationStatus = !NoDurationStatus;
					updateOnNextRun = true;
					if (NoDurationStatus) sNoDurationStatus = "\033[32m ON \033[0m";
					else sNoDurationStatus = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_RETURN)) // ENTER
				{
					onePressTMR = clock();
					MoneyStatus = !MoneyStatus;
					updateOnNextRun = true;
					if (MoneyStatus) sMoneyStatus = "\033[32m ON \033[0m";
					else sMoneyStatus = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F3))
				{
					onePressTMR = clock();
					autoCollectSunStatus = !autoCollectSunStatus;
					updateOnNextRun = true;
					if (autoCollectSunStatus) sAutoCollectionStatus = "\033[32m ON \033[0m";
					else sAutoCollectionStatus = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F4))
				{
					onePressTMR = clock();
					rapidFireStatus = !rapidFireStatus;
					updateOnNextRun = true;
					if (rapidFireStatus) sRapidFireStatus = "\033[32m ON \033[0m";
					else sRapidFireStatus = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F5))
				{
					onePressTMR = clock();
					burstFireStatus = !burstFireStatus;
					updateOnNextRun = true;
					if (burstFireStatus) sBurstFireStatus = "\033[32m ON \033[0m";
					else sBurstFireStatus = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F6))
				{
					onePressTMR = clock();
					burstGenerateSun = !burstGenerateSun;
					updateOnNextRun = true;
					if (burstGenerateSun) sBurstGenerateSun = "\033[32m ON \033[0m";
					else sBurstGenerateSun = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F7))
				{
					onePressTMR = clock();
					fastGenerateSun = !fastGenerateSun;
					updateOnNextRun = true;
					if (fastGenerateSun) sFastGenerateSun = "\033[32m ON \033[0m";
					else sFastGenerateSun = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F8))
				{
					onePressTMR = clock();
					fast_kill_all_zombies = !fast_kill_all_zombies;
					updateOnNextRun = true;
					if (fast_kill_all_zombies) sFastKillZB = "\033[32m ON \033[0m";
					else sFastKillZB = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F9))
				{
					onePressTMR = clock();
					plants_anywhere = !plants_anywhere;
					updateOnNextRun = true;
					if (plants_anywhere) sPlantsAnywhere = "\033[32m ON \033[0m";
					else sPlantsAnywhere = "\033[31m OFF \033[0m";
				}

				if (GetAsyncKeyState(VK_F10))
				{
					onePressTMR = clock();
					multi_plants = !multi_plants;
					updateOnNextRun = true;
					if (multi_plants) sMultiPlants = "\033[32m ON \033[0m";
					else sMultiPlants = "\033[31m OFF \033[0m";
				}
			}
		}
	}
	CloseHandle(hProcHandle);
	CloseHandle(hGameWindow);

	return ERROR_SUCCESS;
}

// VARS FUNCTION HERE!
uintptr_t FindMYAddy(int pointerlevel, HANDLE hProcHandle, uintptr_t offsets[], uintptr_t baseaddress) // find pointer or multilevel pointer
{
	uintptr_t pointer = baseaddress;
	uintptr_t pTemp;

	uintptr_t pointerAddr;
	for (int c = 0; c < pointerlevel; c++) {

		if (c == 0)
		{
			ReadProcessMemory(hProcHandle, (LPCVOID)pointer, &pTemp, sizeof(pTemp), NULL);
		}

		pointerAddr = pTemp + offsets[c]; // THIS IS THE ERROR LOL, WE CHANGE = TO +
		ReadProcessMemory(hProcHandle, (LPCVOID)pointerAddr, &pTemp, sizeof(pTemp), NULL);
	}
	return pointerAddr;
}

// Func ShellCode Detours Injection (With JMP Instruction)
bool is_injected = false;
void* pVirtualMem = nullptr;
void ShellCode_Injections(HANDLE hProc, uintptr_t* baseaddress, unsigned char* shellcode, size_t shellcode_size)
{ 
	if (!is_injected) // keep track of whether the jump instruction has already been written to the memory location or not, Before writing the jump instruction, it.
	{
		void* virtualMem = VirtualAllocEx(hProc, nullptr, shellcode_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

		BYTE JmpOpcode[] = { 0xE9, 0x00, 0x00, 0x00, 0x00 }; // 0xE9 is JMP Instruction with 5 Bytes Patched
		*(DWORD*)&JmpOpcode[1] = (DWORD)((char*)virtualMem - (char*)baseaddress - 5);

		WriteProcessMemory(hProc, (void*)baseaddress, &JmpOpcode, sizeof(JmpOpcode), nullptr);
		WriteProcessMemory(hProc, virtualMem, shellcode, shellcode_size, nullptr);

		is_injected = true;
	}
	CloseHandle(hProc);
}
// Func ShellCode Detours Injection (With PUSH & RET (at the end) Instruction)
void ShellCode_InjectionsWithRET(HANDLE hProc, uintptr_t* baseaddress, unsigned char* shellcode, size_t shellcode_size)
{
	if (pVirtualMem == nullptr) // check if the memory already allocated and only allocate memory if memory is not allocated before to the stack memory!
		pVirtualMem = VirtualAllocEx(hProcHandle, nullptr, shellcode_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE); //Alokasi memory

	BYTE JmpOpcode[] = { 0x68, 0x00,0x00,0x00,0x00,0xC3 }; // The instruction 0x68 is a push instruction and it takes a 4-byte immediate value as an operand.

	*(DWORD*)&JmpOpcode[1] = (DWORD)pVirtualMem;

	WriteProcessMemory(hProcHandle, (void*)baseaddress, &JmpOpcode, sizeof(JmpOpcode), nullptr);
	WriteProcessMemory(hProcHandle, (void*)pVirtualMem, shellcode, shellcode_size, nullptr);
}
// Function to turn off injection and free alloc memory to prevent unexpected errors
void turn_off_injection() {
	is_injected = false;
}

// Very HardCoded this function is not recommend!
void ShellCodeFastKillZombieCall()
{
	if (pVirtualMemZombie1 == nullptr)
		pVirtualMemZombie1 = VirtualAllocEx(hProcHandle, nullptr, sizeof(ShellCodeZombie1), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (pVirtualMemZombie2 == nullptr)
		pVirtualMemZombie2 = VirtualAllocEx(hProcHandle, nullptr, sizeof(ShellCodeZombie2), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (pVirtualMemZombie3 == nullptr)
		pVirtualMemZombie3 = VirtualAllocEx(hProcHandle, nullptr, sizeof(ShellCodeZombie3), MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	BYTE JmpOpcode1[] = { 0x68, 0x00,0x00,0x00,0x00,0xC3 };
	BYTE JmpOpcode2[] = { 0x68, 0x00,0x00,0x00,0x00,0xC3 };
	BYTE JmpOpcode3[] = { 0x68, 0x00,0x00,0x00,0x00,0xC3 };

	*(DWORD*)&JmpOpcode1[1] = (DWORD)pVirtualMemZombie1;
	*(DWORD*)&JmpOpcode2[1] = (DWORD)pVirtualMemZombie2;
	*(DWORD*)&JmpOpcode3[1] = (DWORD)pVirtualMemZombie3;

	// Fast Kill Zombie Normal & Stick
	WriteProcessMemory(hProcHandle, (void*)fast_kill_zb_normalbaseAddress, &JmpOpcode1, sizeof(JmpOpcode1), nullptr);
	WriteProcessMemory(hProcHandle, (void*)pVirtualMemZombie1, &ShellCodeZombie1, sizeof(ShellCodeZombie1), nullptr);
	// Fast Kill Zombie Conehat
	WriteProcessMemory(hProcHandle, (void*)fast_kill_zb_conehatbaseAddress, &JmpOpcode2, sizeof(JmpOpcode2), nullptr);
	WriteProcessMemory(hProcHandle, (void*)pVirtualMemZombie2, &ShellCodeZombie2, sizeof(ShellCodeZombie2), nullptr);
	// Fast Kill Zombie Door
	WriteProcessMemory(hProcHandle, (void*)fast_kill_zb_doorbaseAddress, &JmpOpcode3, sizeof(JmpOpcode3), nullptr);
	WriteProcessMemory(hProcHandle, (void*)pVirtualMemZombie3, &ShellCodeZombie3, sizeof(ShellCodeZombie3), nullptr);
}

// Function to perform Write the memory
bool WriteToMemory(HANDLE hProcHandle)
{
	uintptr_t AddressToWrite;
	// Sun Status
	if (SunStatus) {
		AddressToWrite = FindMYAddy(4, hProcHandle, SunOffsets, SunBaseAddress);
		WriteProcessMemory(hProcHandle, (uintptr_t*)AddressToWrite, &SunValue, sizeof(SunValue), NULL);
	}
	// Money Status
	if (MoneyStatus) {
		AddressToWrite = FindMYAddy(2, hProcHandle, MoneyOffsets, MoneyBaseAddress);
		WriteProcessMemory(hProcHandle, (uintptr_t*)AddressToWrite, &MoneyValue, sizeof(MoneyValue), NULL);
	}
	// No Duration
	if (NoDurationStatus) {
		WriteProcessMemory(hProcHandle, (uintptr_t*)NoDurationCardBaseAddress, NoDurationNOPs, lenNoDuration, NULL);
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)NoDurationCardBaseAddress, NoDurationDefaultOpCode, lenNoDuration, NULL);
	}
	// Auto-Collect
	if (autoCollectSunStatus) {
		WriteProcessMemory(hProcHandle, (uintptr_t*)AutoCollectSunBaseAddress, autoCollectSunJMP, lenAutoCollectSun, NULL);
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)AutoCollectSunBaseAddress, autoCollectSunDefaultOpCode, lenAutoCollectSun, NULL);
	}
	// Rapid-Fire
	if (rapidFireStatus) {
		ShellCode_InjectionsWithRET(hProcHandle, (uintptr_t*)rapidFireBaseAddress, ShellCodeRapidFire, sizeof(ShellCodeRapidFire));
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)rapidFireBaseAddress, rapidFireDefaultOpCode, 6, NULL);
	}
	// Burst-Fire
	if (burstFireStatus) {
		WriteProcessMemory(hProcHandle, (uintptr_t*)burstFireBaseAddress, burstFireJumpBelow, sizeof(lenBurstFireBytes), NULL);
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)burstFireBaseAddress, burstFireDefaultOpCode, sizeof(lenBurstFireBytes), NULL);
	}
	// Burst Generate Sun
	if (burstGenerateSun) {
		WriteProcessMemory(hProcHandle, (uintptr_t*)burstGenerateSunBaseAddress, burstGenerateSunNOPs, lenBurstBurstGenerateSun, NULL);
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)burstGenerateSunBaseAddress, burstGenerateSunDefaultOpCode, lenBurstBurstGenerateSun, NULL);
	}
	// Fast Generate Sun
	if (fastGenerateSun) {
		ShellCode_Injections(hProcHandle, (uintptr_t*)fastGenerateSunBaseAddress, (BYTE*)ShellCodeGenerateSunFaster, sizeof(ShellCodeGenerateSunFaster));
	} else {
		turn_off_injection();
		WriteProcessMemory(hProcHandle, (uintptr_t*)fastGenerateSunBaseAddress, fastGenerateSunDefaultOpCode, lenGenerateSun, NULL);
	}
	// Fast Kill Zombie
	if (fast_kill_all_zombies) {
		ShellCodeFastKillZombieCall();
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)fast_kill_zb_normalbaseAddress, fast_kill_zbnormal_defaultOpcode, len_opcode_fastkill, NULL);
		WriteProcessMemory(hProcHandle, (uintptr_t*)fast_kill_zb_conehatbaseAddress, fast_kill_zbconehat_defaultOpcode, len_opcode_fastkill, NULL);
		WriteProcessMemory(hProcHandle, (uintptr_t*)fast_kill_zb_doorbaseAddress, fast_kill_zbdoor_defaultOpcode, len_opcode_fastkill, NULL);
	}
	// Planting Anywhere
	if (plants_anywhere) {
		WriteProcessMemory(hProcHandle, (uintptr_t*)plants_anywhere_baseAddress, plants_anywhere_JNL, len_opcode_planting, NULL);
	}
	else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)plants_anywhere_baseAddress, plants_anywhere_defaultOpCode, len_opcode_planting, NULL);
	}
	// Multi Planting
	if (multi_plants) {
		WriteProcessMemory(hProcHandle, (uintptr_t*)multi_plants_baseAddress, multi_plants_JMPEqual, len_opcode_multi_plants, NULL);
	} else {
		WriteProcessMemory(hProcHandle, (uintptr_t*)multi_plants_baseAddress, multi_plants_defaultOpCode, len_opcode_multi_plants, NULL);
	}


	return true;
}

/******************************************************************************************
$$$$$$$$\       $$\   $$\       $$$$$$$\
$$  _____|      $$$\  $$ |      $$  __$$\
$$ |            $$$$\ $$ |      $$ |  $$ |
$$$$$\          $$ $$\$$ |      $$ |  $$ |
$$  __|         $$ \$$$$ |      $$ |  $$ |
$$ |            $$ |\$$$ |      $$ |  $$ |
$$$$$$$$\       $$ | \$$ |      $$$$$$$  |
\________|      \__|  \__|      \_______/
******************************************************************************************/
