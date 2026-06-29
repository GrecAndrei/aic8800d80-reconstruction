// fwstruct annotate: 13bb64_sub_13BB64.c
// sub_13BB64 @ 0x13bb64, size 334 bytes
int __fastcall sub_13BB64(int a1, unsigned __int16 *a2, int a3)
{
  int v4; // r4
  unsigned int v6; // r3
  unsigned int v7; // r8
  unsigned int v8; // r5
  int v9; // r6
  char v10; // r7
  int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r2

  if ( a3 != 1 )
  {
    if ( a3 == 2 )
    {
      v12 = a2[1];
      v13 = v12 >> 12;
      if ( v12 < 0x9000 && a1 != 255 )
      {
        if ( (v12 & 0x800) != 0 )
          return *(unsigned __int8 *)(696 * (unsigned __int8)a1 + 12 * v13 + dword_13BCB4 + 452);
        else
          return *(unsigned __int8 *)(696 * (unsigned __int8)a1 + 12 * v13 + dword_13BCB4 + 453);
      }
    }
    else if ( !a3 )
    {
      v7 = *(unsigned __int16 *)((char *)a2 + 3);
      v8 = (v7 >> 2) & 0xF;
      if ( v8 <= 8 )
      {
        v9 = (unsigned __int8)a1;
        v10 = *((_BYTE *)a2 + 2);
        if ( sub_121BC0((unsigned __int8)a1, (v7 >> 2) & 0xF) )
          return *(unsigned __int8 *)(696 * v9 + 12 * v8 + dword_13BCB4 + 452);
        if ( *((_DWORD *)off_13BCB8 + 4) - 500000 - *(_DWORD *)(696 * v9 + 12 * v8 + dword_13BCB4 + 448) >= 0 )
        {
          if ( *(_BYTE *)(dword_13BCB4 + 696 * a1 + 36) == 1 )
            goto LABEL_22;
          if ( *(_DWORD *)off_13BCBC )
          {
            v4 = *((unsigned __int8 *)sub_12D4F8((int)off_13BCBC) + 26);
            if ( v4 != 33 )
              return v4;
          }
          v11 = sub_13BB14((int **)dword_13BCC0);
          if ( v11 == 33 )
          {
LABEL_22:
            sub_13B734(v9, 0, 1, v10, v7, 37, 0);
            return 33;
          }
          else
          {
            v4 = v11;
            sub_12CC38(8193, ((_WORD)v11 << 8) | 8, 255);
          }
          return v4;
        }
      }
    }
    return 33;
  }
  v6 = (*(unsigned __int16 *)((char *)a2 + 5) >> 2) & 0xF;
  if ( v6 > 8 )
    return 33;
  return *(unsigned __int8 *)(696 * (unsigned __int8)a1 + 12 * v6 + dword_13BCB4 + 453);
}

