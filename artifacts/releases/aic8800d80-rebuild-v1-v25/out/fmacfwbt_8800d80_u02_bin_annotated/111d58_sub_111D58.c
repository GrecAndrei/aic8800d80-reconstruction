// fwstruct annotate: 111d58_sub_111D58.c
// sub_111D58 @ 0x111d58, size 316 bytes
int *__fastcall sub_111D58(int *result, unsigned int a2, int a3, unsigned int a4)
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
            v18 = ((unsigned int)dword_111E9C * (unsigned __int64)v7) >> 32;
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
        result = sub_111BA0(result, a2);
      v11 = (a3 << 18) & 0xC0000;
      v12 = off_111E94;
      v13 = *(unsigned __int16 *)off_111E94;
      *((_DWORD *)&REG_4020_0900 + 8 * a2) = v7 & 0x7FF | v11 | (a2 << 22) | 0x18008000;
      if ( v13 + v9 > 2048 )
      {
        result = (int *)sub_10DA7C(dword_111EA0, v13, v9, 2048);
        v13 = (unsigned __int16)*v12;
      }
      v14 = off_111E98;
      *((_DWORD *)off_111E98 + v4 + 65) = v13 | v10;
      v15 = (1 << a2) | v14[519];
      *v12 = v8 + v13;
      v14[519] = v15;
    }
    else
    {
      v16 = 32 * a2 + 1075838976;
      if ( (*((_DWORD *)&REG_4020_0b00 + 8 * a2) & 0x80008000) != 0 )
        result = sub_111BA0(nullptr, a2);
      v17 = off_111E98;
      *(_DWORD *)(v16 + 2816) = v7 & 0x7FF | (a3 << 18) & 0xC0000 | 0x18008000;
      v17[519] |= 0x10000 << a2;
    }
  }
  return result;
}

