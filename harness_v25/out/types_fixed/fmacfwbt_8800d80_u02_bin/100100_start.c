// start @ 0x100100, size 236 bytes
int __fastcall start(int a1, int a2, int a3)
{
  int v4; // r4
  _DWORD *v5; // r6
  int v6; // r5
  int v7; // r2
  int v8; // r3

  v6 = *(unsigned __int8 *)(a1 + 20);
  if ( !((a3 < 0) ^ _VF | (a3 == 0)) )
    JUMPOUT(0x1201F2);
  *v5 = a1;
  *(_DWORD *)(v5 + 0x4) = v4;
  *(_DWORD *)(v5 + 0x8) = v5;
  *v5 = a1;
  *(_DWORD *)(v5 + 0x4) = a3;
  *(_DWORD *)(v5 + 0x8) = a3;
  *(_DWORD *)(v5 + 0xc) = v6;
  *(_DWORD *)(v5 + 0x10) = v5;
  if ( (unsigned __int16)*(_DWORD *)off_1001EC == 49729
    || (*((_DWORD *)off_1001F0 + 23) & 3) != 2
    || (v7 = *((_DWORD *)off_1001F4 + 92), v8 = *((_DWORD *)off_1001F4 + 93), v7 >= 0)
    || v8 >= 0 )
  {
    _R0 = dword_1001F8;
    __asm { MSR.W           MSP, R0 }
    return off_1001FC();
  }
  else
  {
    _R2 = v7 & 0xFFFFFFF;
    __asm { MSR.W           MSP, R2 }
    return ((int (*)(void))(v8 & 0xFFFFFFF))();
  }
}

