// v23 annotated: sub_111804 @ 0x111804
// Original: 111804_sub_111804.c
// Primary struct: <unclustered>
//
// sub_111804 @ 0x111804, size 316 bytes
// Doc: rf_mbx_init [rf]: Initialize the N30 RFIC mailbox bus: program control regs, clear pending IRQ, and drain 10-entry status doorbell array.
// rf_mbx_init [rf]: Initialize the N30 RFIC mailbox bus: program control regs, clear pending IRQ, and drain 10-entry status doorbell array.
int *__fastcall sub_111804(int *result, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r6
  unsigned int v7; // r11
  int v8; // r7
  int v9; // r10
  int v10; // r9
  int v11; // r2
  _WORD *v12; // r4
  int v13; // r1
  _DWORD *v14; // r2
  int v15; // r5
  int v16; // r6
  _DWORD *v17; // r2
  unsigned int v18; // r3
  bool v19; // cf

  v4 = a2 - 1;
  if ( (unsigned __int8)(a2 - 1) <= 4u )
  {
    v7 = a4;
    if ( result )
    {
      if ( (a3 & 0xFD) == 1 )
      {
        if ( a4 > 0x320 )
        {
          v9 = 400;
          LOWORD(v8) = 400;
          v10 = 26214400;
        }
        else
        {
          v8 = (unsigned __int16)(2 * ((int)(a4 + 3) >> 2));
          v9 = v8;
          v10 = (unsigned __int16)v8 << 16;
        }
        if ( a4 > 0x400 )
        {
          v18 = -1025;
          v19 = v7 - 1025 >= 0x400;
          if ( v7 - 1025 < 0x400 )
            v7 >>= 1;
          else
            v18 = ((unsigned int)dword_111948 * (unsigned __int64)v7) >> 32;
          if ( v19 )
            LOWORD(v7) = v18 >> 1;
        }
      }
      else
      {
        v8 = (unsigned __int16)(2 * ((int)(a4 + 3) >> 2));
        v9 = v8;
        v10 = (unsigned __int16)v8 << 16;
      }
      if ( (*((_DWORD *)&REG_4020_0900 + 8 * a2) & 0x80008000) != 0 )
        result = sub_11164C(result, a2);
      v11 = (a3 << 18) & 0xC0000;
      v12 = off_111940;
      v13 = *(unsigned __int16 *)off_111940;
      *((_DWORD *)&REG_4020_0900 + 8 * a2) = v7 & 0x7FF | v11 | (a2 << 22) | 0x18008000;
      if ( v13 + v9 > 2048 )
      {
        result = (int *)sub_10DA6C(dword_11194C, v13, v9, 2048);
        v13 = (unsigned __int16)*v12;
      }
      v14 = off_111944;
      *((_DWORD *)off_111944 + v4 + 65) = v13 | v10;
      v15 = (1 << a2) | v14[519];
      *v12 = v8 + v13;
      v14[519] = v15;
    }
    else
    {
      v16 = 32 * a2 + 1075838976;
      if ( (*((_DWORD *)&REG_4020_0b00 + 8 * a2) & 0x80008000) != 0 )
        result = sub_11164C(nullptr, a2);
      v17 = off_111944;
      *(_DWORD *)(v16 + 2816) = v7 & 0x7FF | (a3 << 18) & 0xC0000 | 0x18008000;
      v17[519] |= 0x10000 << a2;
    }
  }
  return result;
}

