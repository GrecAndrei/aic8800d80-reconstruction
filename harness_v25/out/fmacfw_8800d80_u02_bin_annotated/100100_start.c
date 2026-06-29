// fwstruct annotate: 100100_start.c
// start @ 0x100100, size 236 bytes
int __fastcall start(int a1, int a2, _DWORD *a3)
{
  _DWORD *v4; // r4
  int v5; // r6
  int (__fastcall *v6)(int); // r9
  int v7; // r5
  int v9; // r0
  int v10; // r2
  int v11; // r3

  v7 = *(unsigned __int8 *)(a1 + 3);
  if ( (a3 != nullptr) & _CF )
  {
    v9 = a1 + 220;
    if ( (unsigned __int16)*(_DWORD *)off_1001EC == 49729
      || (*((_DWORD *)off_1001F0 + 23) & 3) != 2
      || (v10 = *((_DWORD *)off_1001F4 + 92), v11 = *((_DWORD *)off_1001F4 + 93), v10 >= 0)
      || v11 >= 0 )
    {
      _R0 = dword_1001F8;
      __asm { MSR.W           MSP, R0 }
      return off_1001FC();
    }
    else
    {
      _R2 = v10 & 0xFFFFFFF;
      __asm { MSR.W           MSP, R2 }
      return ((int (__fastcall *)(int))(v11 & 0xFFFFFFF))(v9);
    }
  }
  else
  {
    *v4 = a1;
    v4[1] = a3;
    v4[2] = v7;
    *a3 = a1;
    a3[1] = a3;
    a3[2] = v5;
    return v6(a1);
  }
}

