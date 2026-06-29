// fwstruct annotate: 12a3bc_sub_12A3BC.c
// sub_12A3BC @ 0x12a3bc, size 214 bytes
// Doc: sub_122A3BC [util]: Check shared flag word and branch on signed halfword
// sub_122A3BC [util]: Check shared flag word and branch on signed halfword
int __fastcall sub_12A3BC(int a1, unsigned int a2)
{
  __int16 **v2; // r6
  int v5; // r2
  int v6; // r0
  int v7; // r3
  int v8; // r1
  int v9; // r3
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r3

  v2 = (__int16 **)off_12A494;
  if ( **(__int16 **)off_12A494 >= 0 )
  {
    v5 = *(unsigned __int8 *)(a1 + 1225);
    v6 = dword_12A498;
    v7 = 140 * v5 + 48 * a2 + dword_12A498;
    v8 = 2 * a2;
    v9 = *(unsigned __int8 *)(v7 + 16);
    if ( v9 != 1 )
    {
      if ( v9 != 2 )
        return 0;
      return *(_DWORD *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
    }
    goto LABEL_10;
  }
  if ( *(_BYTE *)(a1 + 1224) && a2 <= 1 )
  {
    v5 = *(unsigned __int8 *)(a1 + 1225);
    v6 = dword_12A498;
    v13 = 140 * v5 + 48 * a2 + dword_12A498;
    v8 = 2 * a2;
    v14 = *(unsigned __int8 *)(v13 + 16);
    if ( v14 != 1 )
    {
      if ( v14 == 2 )
        return *(_DWORD *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
      goto LABEL_15;
    }
LABEL_10:
    v12 = v6 + 140 * v5 + 16 * (a2 + v8);
    return *(_DWORD *)(v12 + 12) + *(_DWORD *)(v12 + 24);
  }
  sub_12F694(dword_12A4A0, dword_12A49C, 1325);
  v5 = *(unsigned __int8 *)(a1 + 1225);
  v6 = dword_12A498;
  v8 = 2 * a2;
  v11 = *(unsigned __int8 *)(140 * v5 + 48 * a2 + dword_12A498 + 16);
  if ( v11 == 1 )
    goto LABEL_10;
  if ( v11 == 2 )
    return *(_DWORD *)(140 * v5 + 16 * (a2 + v8) + v6 + 12);
  if ( **v2 >= 0 )
    return 0;
LABEL_15:
  sub_12F6C4(dword_12A4A4, dword_12A49C, 1337);
  return 0;
}

