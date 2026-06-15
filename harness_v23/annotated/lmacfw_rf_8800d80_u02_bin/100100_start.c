// v23 annotated: start @ 0x100100
// Original: 100100_start.c
// Primary struct: <unclustered>
//
// start @ 0x100100, size 236 bytes
int __fastcall start(int a1, int a2, unsigned int a3)
{
  int v3; // r6
  int *v4; // r5
  int v5; // r2
  int v6; // r3

  do
  {
    while ( 1 )
    {
      v4 = *(int **)(a3 + 76);
      if ( a1 != 0 && a3 >= 0x1D )
        break;
      v3 += 8;
      a1 = *v4;
      a3 = v4[1];
    }
  }
  while ( a3 == 0 || a3 < 0x1D );
  *(_WORD *)(a1 + 14) = a1;
  if ( (unsigned __int16)*(_DWORD *)off_1001EC == 49729
    || (*((_DWORD *)off_1001F0 + 23) & 3) != 2
    || (v5 = *((_DWORD *)off_1001F4 + 92), v6 = *((_DWORD *)off_1001F4 + 93), v5 >= 0)
    || v6 >= 0 )
  {
    _R0 = dword_1001F8;
    __asm { MSR.W           MSP, R0 }
    return off_1001FC();
  }
  else
  {
    _R2 = v5 & 0xFFFFFFF;
    __asm { MSR.W           MSP, R2 }
    return ((int (*)(void))(v6 & 0xFFFFFFF))();
  }
}

