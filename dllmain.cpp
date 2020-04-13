// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
BOOL APIENTRY Lab2DLL( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


