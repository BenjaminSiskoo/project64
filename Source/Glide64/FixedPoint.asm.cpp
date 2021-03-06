/*
* Glide64 - Glide video plugin for Nintendo 64 emulators.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/****************************************************************
;
; Glide64 - Glide Plugin for Nintendo 64 emulators
; Project started on December 29th, 2001
;
; Authors:
; Dave2001, original author, founded the project in 2001, left it in 2002
; Gugaman, joined the project in 2002, left it in 2002
; Sergey 'Gonetz' Lipski, joined the project in 2002, main author since fall of 2002
; Hiroshi 'KoolSmoky' Morii, joined the project in 2007
;
;****************************************************************
;
; To modify Glide64:
; * Write your name and (optional)email, commented by your work, so I know who did it, and so that you can find which parts you modified when it comes time to send it to me.
; * Do NOT send me the whole project or file that you modified.  Take out your modified code sections, and tell me where to put them.  If people sent the whole thing, I would have many different versions, but no idea how to combine them all.
;
;****************************************************************/

#if defined(_MSC_VER) && !defined(_STDINT)
typedef signed __int64          int64_t;
#else
#include <stdint.h>
#endif

// (x * y) >> 16
extern "C" int __declspec(naked) imul16(int x, int y)
{
	_asm {
		push ebp
		mov ebp,esp
		mov   eax, [x]
		mov   edx, [y]
		imul  edx        
		shrd  eax,edx,16
		leave
		ret
	}
}

//(x * y) >> 14
extern "C" int  __declspec(naked) imul14(int x, int y)
{
	_asm {
		push ebp
		mov ebp,esp
		mov   eax, [x]
		mov   edx, [y]
		imul  edx        
		shrd  eax,edx,14
		leave
		ret
	}
}

int idiv16(int x, int y)
{
    int64_t result;
    const int64_t m = (int64_t)(x);
    const int64_t n = (int64_t)(y);

    result = (m << 16) / n;
    return (int)(result);
}
