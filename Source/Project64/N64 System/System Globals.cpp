/****************************************************************************
*                                                                           *
* Project 64 - A Nintendo 64 emulator.                                      *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2012 Project64. All rights reserved.                        *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#include "stdafx.h"

CN64System    * g_System = NULL;
CN64System    * g_BaseSystem = NULL;
CN64System    * g_SyncSystem = NULL;
CRecompiler   * g_Recompiler = NULL;
CMipsMemory   * g_MMU = NULL; //Memory of the n64 
CTLB          * g_TLB = NULL; //TLB Unit
CRegisters    * g_Reg = NULL; //Current Register Set attacted to the g_MMU
CNotification * g_Notify = NULL;   
CPlugins      * g_Plugins = NULL;
CN64Rom       * g_Rom = NULL;      //The current rom that this system is executing.. it can only execute one file at the time
CAudio        * g_Audio = NULL;
CSystemTimer  * g_SystemTimer = NULL;
CTransVaddr   * g_TransVaddr = NULL;
CSystemEvents * g_SystemEvents = NULL;
DWORD         * g_TLBLoadAddress = NULL;
DWORD         * g_TLBStoreAddress = NULL;

int * g_NextTimer;


