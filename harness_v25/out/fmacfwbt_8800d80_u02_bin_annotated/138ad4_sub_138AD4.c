// fwstruct annotate: 138ad4_sub_138AD4.c
// sub_138AD4 @ 0x138ad4, size 136 bytes
_DWORD *__fastcall sub_138AD4(int a1, __int16 a2, int a3)
{
  _BYTE *v3; // r5
  int v4; // r4
  int v5; // r3
  _DWORD *v6; // r6
  int v7; // r7
  int v8; // r12
  int v9; // r3

  v3 = off_138B60;
  v4 = *((unsigned __int8 *)off_138B60 + 68);
  v5 = dword_138B64;
  v6 = (_DWORD *)(dword_138B64 + 80 * v4);
  if ( **(__int16 **)off_138B5C < 0 )
  {
    v7 = 4 * v4;
    if ( *(_WORD *)(dword_138B64 + 80 * v4 + 76) )
    {
      sub_12F630(dword_138B74, dword_138B70, 175);
      return nullptr;
    }
  }
  else
  {
    v7 = 4 * v4;
  }
  v8 = dword_138B64 + 16 * (v7 + v4);
  *(_DWORD *)(v8 + 12) = a1;
  if ( a1 )
    *(_BYTE *)(v8 + 16) = *(_BYTE *)(a1 + 16);
  v9 = v5 + 16 * (v4 + v7);
  *(_DWORD *)(v9 + 68) = a3;
  *(_WORD *)(v9 + 76) = a2;
  list_push_tail(dword_138B68, v6);
  v3[68] = v3[68]
         + 1
         - -64
         * ((unsigned int)(((unsigned int)dword_138B6C * (unsigned __int64)((unsigned int)(unsigned __int8)v3[68] + 1)) >> 32) >> 7);
  return v6;
}

