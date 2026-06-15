// v23 annotated: sub_117F4C @ 0x117f4c
// Original: 117f4c_sub_117F4C.c
// Primary struct: <unclustered>
//
// sub_117F4C @ 0x117f4c, size 234 bytes
int __fastcall sub_117F4C(int a1, int a2, int a3, int a4)
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

  if ( *(_BYTE *)off_118038 )
    return sub_12EA88(dword_118048, a2, a3);
  LOWORD(v4) = *((unsigned __int8 *)off_11803C + 190);
  if ( (*((_DWORD *)off_11803C + 52) & 1) == 0 )
    v4 = (*(_DWORD *)(a1 + 84) >> 11) & 3;
  v6 = sub_12D2D0(dword_118040 + 84 * (__int16)v4 + 28);
  v7 = *(__int16 **)off_118044;
  v8 = v6;
  if ( **(__int16 **)off_118044 < 0 && !v6 )
    return sub_12F408(dword_118058, dword_118054, 369, a4);
  v9 = *(_DWORD *)(a1 + 84);
  result = v9 << 6;
  *(_WORD *)(v8 + 8) |= 0x20u;
  if ( (v9 & 0x2000000) != 0 )
  {
    result = (unsigned __int16)(v9 >> 15);
    if ( *v7 < 0 && (result & 0x3F0) == 0 )
      return sub_12F408(dword_118050, dword_11804C, 217, a4);
    if ( ((v9 >> 15) & 0x3FF) - 16 == *(unsigned __int8 *)(v8 + 12) )
    {
      v11 = *(_DWORD *)(*(_DWORD *)(a1 + 28) + 8);
      v12 = *(unsigned __int16 *)(v11 + 16);
      result = v12 & 0x1E;
      if ( result == 22 )
      {
        result = sub_11BFAC(a1, v8);
        if ( result )
          goto LABEL_17;
      }
      else if ( (v9 & 0x200) == 0 )
      {
        v13 = *(unsigned __int16 *)(a1 + 48);
        if ( (v13 == 52 || v13 == 28) && *(unsigned __int8 *)(v8 + 13) == v12 >> 12 )
        {
          result = sub_143770(v8 + 228, v11 + 18, 34);
          *(_DWORD *)(v8 + 224) = v8 + 228;
LABEL_17:
          *(_WORD *)(v8 + 8) |= 0x40u;
        }
      }
    }
  }
  return result;
}

