/*
 -- shellcode injection for PVZ writted by: pxcvbe
 -- This Shellcode only works for plants vs. zombies (steam edition)
 -- thanks for guided hacking, and WN95 for example code
*/
#pragma once

/// <SHELLCODE INJECTION VARS>(RapidFire)
unsigned char ShellCodeRapidFire[] =
{
	0xC7, 0x46, 0x58, 0x25, 0x00, 0x00, 0x00, //mov [esi+58],00000025 { 37 in decimals }
	0x83, 0xF8, 0x12,                         //cmp eax,12
	0x68, 0x12, 0x5C, 0x46, 0x00,             //push 00465C12
	0xC3                                      //ret
};
/// </END>

/// <SHELLCODE INJECTION VARS>(Generate Sun Faster)
unsigned char ShellCodeGenerateSunFaster[] =
{
	0xC7, 0x47, 0x58, 0x20, 0x00, 0x00, 0x00, //mov [edi+58],00000020 { 32 in decimals }
	0x8B, 0x07,                               //mov eax,[edi]
	0x68, 0x4B, 0x5E, 0x46, 0x00,             //push 00465E4B
	0xC3                                      //ret
};
/// </END>

/// <SHELLCODE INJECTION VARS>(FastKill Zombie)
unsigned char ShellCodeZombie1[] = //  Normal & Stick Zombie
{
	0xC7, 0x87, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov [edi+000000C8],00000000
	0x68, 0x0A, 0x5E, 0x54, 0x00,                               //push 00545E0A
	0xC3                                                        //ret
};
unsigned char ShellCodeZombie2[] = // Conehat Zombie
{
	0xC7, 0x85, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov [ebp+000000D0],00000000
	0x68, 0x20, 0x5B, 0x54, 0x00,                               //push 00545B20
	0xC3                                                        //ret 
};
unsigned char ShellCodeZombie3[] = // Door Zombie
{
	0x81, 0xAE, 0xDC, 0x00, 0x00, 0x00, 0x88, 0x13, 0x00, 0x00, //sub [esi+000000DC],00001388
	0x68, 0x77, 0x57, 0x54, 0x00,                               //push 00545777
	0xC3                                                        //ret 
};
/// </END>

/// <SHELLCODE INJECTION VARS>(Planting Anywhere)
unsigned char ShellCodePlantsAnywhere[] =
{
	0x0F, 0x8D, 0x6F, 0x3C, 0x95, 0xF1,  //jnl 00413C75
    0x68, 0x55, 0x33, 0x41, 0x00,        //push 00413355
    0xC3                                 //ret 
};
/// </END>
