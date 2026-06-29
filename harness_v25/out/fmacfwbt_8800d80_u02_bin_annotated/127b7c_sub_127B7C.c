// fwstruct annotate: 127b7c_sub_127B7C.c
// sub_127B7C @ 0x127b7c, size 186 bytes
int __fastcall sub_127B7C(int result, __int16 a2)
{
  int v2; // r8
  int v3; // r7
  int v4; // r5
  int v5; // r9
  int v6; // r4
  int v8; // r2
  unsigned __int16 v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r7
  char v13; // r2

  v2 = dword_127C3C;
  v3 = *(unsigned __int8 *)(result + 86);
  v4 = dword_127C3C + 1320 * v3;
  v5 = *(_BYTE *)(v4 + 85) & 0x60;
  if ( (*(_BYTE *)(v4 + 85) & 0x60) == 0 )
  {
    v6 = result;
    result = sub_12A3BC(dword_127C3C + 1320 * v3, *(unsigned __int8 *)(result + 87));
    v8 = *(_DWORD *)(v6 + 92);
    v9 = abs16(v8 - (result - a2));
    *(_WORD *)(v6 + 96) = v8 - (result - a2);
    if ( v9 > 0x7D0u )
    {
      *(_BYTE *)(v4 + 85) = *(_BYTE *)(v4 + 85) & 0xAF | 0x10;
      return result;
    }
    if ( v9 > 0xC8u )
    {
      v10 = *((_DWORD *)off_127C38 + 2);
      if ( !v10 )
      {
LABEL_16:
        v12 = v2 + 1320 * v3;
        v13 = *(_BYTE *)(v12 + 85);
        *(_DWORD *)(v12 + 88) = v10;
        *(_BYTE *)(v12 + 85) = v13 | 0x40;
        return result;
      }
      result = 0;
      do
      {
        if ( *(unsigned __int8 *)(v10 + 86) == *(unsigned __int8 *)(v4 + 107) )
        {
          v11 = *(__int16 *)(v10 + 96);
          if ( result >= v11 )
            result = *(__int16 *)(v10 + 96);
          if ( v5 < v11 )
            v5 = *(__int16 *)(v10 + 96);
        }
        v10 = *(_DWORD *)v10;
      }
      while ( v10 );
      if ( !result )
      {
        v10 = v5 >> 1;
        goto LABEL_16;
      }
      if ( !v5 )
      {
        v10 = result / 2;
        goto LABEL_16;
      }
    }
  }
  return result;
}

