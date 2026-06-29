// fwstruct annotate: 112ed0_sub_112ED0.c
// sub_112ED0 @ 0x112ed0, size 100 bytes
int __fastcall sub_112ED0(int a1, unsigned __int16 *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  sub_112E30();
  if ( *(_BYTE *)off_112F34 != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (unsigned __int8)(a1 - 1) > 5u )
    return 2;
  if ( (*((_DWORD *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_112F38 + 16 * v4;
  *(_DWORD *)(v6 + 4) = *a2;
  *(_BYTE *)(v6 + 11) = 1;
  *(_DWORD *)(v5 + 2099508) = a2;
  *((_DWORD *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}

