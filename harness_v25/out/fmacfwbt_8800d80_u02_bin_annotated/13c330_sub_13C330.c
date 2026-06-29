// fwstruct annotate: 13c330_sub_13C330.c
// sub_13C330 @ 0x13c330, size 264 bytes
int __fastcall sub_13C330(int a1, int a2, int a3)
{
  int v4; // r3
  int v5; // r3
  int i; // r4
  int v8; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r2
  int v15; // r3
  int (__fastcall *v16)(int, int); // r2
  unsigned __int8 v17; // r0

  v4 = 696 * *(unsigned __int8 *)(a1 + 29);
  if ( (*(_DWORD *)(dword_13C438 + v4 + 4) & 2) == 0 )
    return 1;
  v5 = v4 + 12 * *(unsigned __int8 *)(a1 + 27) + dword_13C438;
  --*(_BYTE *)(v5 + 455);
  if ( (*(_WORD *)(a1 + 30) & 2) == 0 )
    return 1;
  v8 = *(unsigned __int8 *)(v5 + 453);
  if ( v8 == 33 || msg_get_value((v8 << 8) | 8) != 1 )
    return 1;
  v11 = dword_13C43C + 32 * v8;
  v12 = *(_DWORD *)(a1 + 36) << 10;
  v13 = *(_DWORD *)(v11 + 28);
  --*(_DWORD *)(v11 + 4);
  if ( v12 < 0 )
  {
    if ( a3 )
    {
      if ( !a2 )
      {
        v14 = *(unsigned __int16 *)(a1 + 64);
        if ( ((v14 - (*((_DWORD *)off_13C440 + 4) >> 10)) & 0x8000) == 0 )
          sub_12ECB0(dword_13C444, 0, ((unsigned int)(v14 - (*((_DWORD *)off_13C440 + 4) >> 10)) >> 15) & 1);
      }
    }
    else if ( !a2 && ((*(unsigned __int16 *)(a1 + 64) - (*((_DWORD *)off_13C440 + 4) >> 10)) & 0x8000) == 0 )
    {
      i = 0;
      *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4) |= 2u;
      return i;
    }
  }
  *(_BYTE *)((*(int (__fastcall **)(int, int))v13)(v13, (*(_WORD *)(a1 + 32) - *(_WORD *)(v13 + 4)) & 0xFFF) + v13 + 6) = 2;
  v15 = *(unsigned __int8 *)(v13 + 262) + v13;
  for ( i = 0; *(_BYTE *)(v15 + 6) == 2; i = (char)(i + 1) )
  {
    *(_BYTE *)(v15 + 6) = 0;
    v16 = *(int (__fastcall **)(int, int))v13;
    *(_WORD *)(v13 + 4) = (*(_WORD *)(v13 + 4) + 1) & 0xFFF;
    v17 = v16(v13, 1);
    v15 = v13 + v17;
    *(_BYTE *)(v13 + 262) = v17;
  }
  return i;
}

