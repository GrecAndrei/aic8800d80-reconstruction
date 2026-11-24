// start @ 0x100100, size 236 bytes
int __fastcall start(int a1, int a2, _DWORD *a3)
{
  int v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r2
  int v8; // r3

  do
  {
    *(_BYTE *)(a1 + 30) = v4;
    *(_BYTE *)(a1 + 30) = v4;
    *(_BYTE *)(a1 + 30) = v4;
    *(_BYTE *)(a1 + 30) = v4;
    *(_BYTE *)(a1 + 30) = v4;
  }
  while ( _VF );
  *a3 = a1;
  *(_DWORD *)(a3 + 0x4) = a3;
  *(_DWORD *)(a3 + 0x8) = v4;
  *(_DWORD *)(a3 + 0xc) = v5;
  *(_DWORD *)(a3 + 0x10) = v6;
  *a3 = a1;
  *(_DWORD *)(a3 + 0x4) = a3 + 5;
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

