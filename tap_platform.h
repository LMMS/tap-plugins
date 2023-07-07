/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef TAP_PLATFORM_H
#define TAP_PLATFORM_H


#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

#ifdef _MSC_VER

#include <Windows.h>
#define __CONSTRUCTOR
#define __DESTRUCTOR
#define __INIT_FINI(initfn, finifn)                                          \
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ulReason, LPVOID lpReserved)   \
{                                                                            \
    switch (ulReason)                                                        \
    {                                                                        \
    case DLL_PROCESS_ATTACH:                                                 \
        initfn();                                                            \
        break;                                                               \
    case DLL_PROCESS_DETACH:                                                 \
        finifn();                                                            \
        break;                                                               \
    }                                                                        \
    return TRUE;                                                             \
}

#else /* ! _MSC_VER */

#define __CONSTRUCTOR __attribute__((constructor))
#define __DESTRUCTOR __attribute__((destructor))
#define __INIT_FINI(init, fini)

#endif /* _MSC_VER */

#endif
