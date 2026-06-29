// fwstruct annotate: 117e0c_sub_117E0C.c
// sub_117E0C @ 0x117e0c, size 234 bytes
int __fastcall sub_117E0C(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v6; // r0
  __int16 *v7; // r1
  int v8; // r4
  unsigned int v9; // r2
  int result; // r0
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r2

  if ( *(_BYTE *)off_117EF8 )
    return sub_12E948(dword_117F08, a2, a3);
  LOWORD(v4) = *((unsigned __int8 *)off_117EFC + 190);
  if ( (*((_DWORD *)off_117EFC + 52) & 1) == 0 )
    v4 = (*(_DWORD *)(a1 + 84) >> 11) & 3;
  v6 = sub_12D190(dword_117F00 + 84 * (__int16)v4 + 28);
  v7 = *(__int16 **)off_117F04;
  v8 = v6;
  if ( **(__int16 **)off_117F04 < 0 && !v6 )
    return sub_12F2C8(dword_117F18, dword_117F14, 369, a4);
  v9 = *(_DWORD *)(a1 + 84);
  result = v9 << 6;
  *(_WORD *)(v8 + 8) |= 0x20u;
  if ( (v9 & 0x2000000) != 0 )
  {
    result = (unsigned __int16)(v9 >> 15);
    if ( *v7 < 0 && (result & 0x3F0) == 0 )
      return sub_12F2C8(dword_117F10, dword_117F0C, 217, a4);
    if ( ((v9 >> 15) & 0x3FF) - 16 == *(unsigned __int8 *)(v8 + 12) )
    {
      v11 = *(_DWORD *)(*(_DWORD *)(a1 + 28) + 8);
      v12 = *(unsigned __int16 *)(v11 + 16);
      result = v12 & 0x1E;
      if ( result == 22 )
      {
        result = sub_11BE6C(a1, v8);
        if ( result )
          goto LABEL_17;
      }
      else if ( (v9 & 0x200) == 0 )
      {
        v13 = *(unsigned __int16 *)(a1 + 48);
        if ( (v13 == 52 || v13 == 28) && *(unsigned __int8 *)(v8 + 13) == v12 >> 12 )
        {
          result = sub_143630(v8 + 228, v11 + 18, 34);
          *(_DWORD *)(v8 + 224) = v8 + 228;
LABEL_17:
          *(_WORD *)(v8 + 8) |= 0x40u;
        }
      }
    }
  }
  return result;
}

