// v23 annotated: sub_138528 @ 0x138528
// Original: 138528_sub_138528.c
// Primary struct: <unclustered>
//
// sub_138528 @ 0x138528, size 316 bytes
_DWORD *sub_138528()
{
  _DWORD *v0; // r6
  _WORD *v1; // r4
  _DWORD *v2; // r5
  int v3; // r6
  char *v4; // r3
  char *v5; // r0
  _DWORD *v6; // r3
  _BYTE *v7; // r1
  BOOL v8; // r2
  BOOL v9; // r0
  int *v10; // r2
  _WORD *v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  int v15; // r1
  _DWORD *v16; // r2
  int v17; // r3
  int v18; // r2

  if ( *(_BYTE *)off_138664 )
    sub_102AD0(0xC2u);
  if ( **(_BYTE **)off_138668 == 1 )
    *(_DWORD *)off_13866C &= ~0x200000u;
  v0 = off_138670;
  v1 = off_138674;
  v2 = off_138678;
  if ( (*(_DWORD *)off_138670 & 4) != 0 )
  {
    v15 = *(unsigned __int16 *)(*(_DWORD *)off_13869C + 54);
    v16 = off_1386A4;
    v17 = dword_1386A0 + 1320 * *(unsigned __int8 *)(*(_DWORD *)off_138674 + 366);
    *((_BYTE *)off_138678 + 29) = 3;
    v18 = v16[4];
    v2[5] = v17;
    sub_124BFC((int)(v2 + 3), v15 + v18);
    *((_BYTE *)v2 + 28) = 1;
    *v0 &= ~4u;
  }
  v3 = *((unsigned __int8 *)v1 + 3850);
  if ( !*((_BYTE *)v1 + 3850) )
  {
    v4 = (char *)off_138674;
    v5 = (char *)off_138674 + 3840;
    do
    {
      v4[8] = v3;
      v4[64] = 0x80;
      v4 += 60;
    }
    while ( v5 != v4 );
    v6 = off_13867C;
    v1[2] = v3;
    v6[1] = v3;
  }
  v7 = *(_BYTE **)v1;
  if ( *(_BYTE *)(*(_DWORD *)v1 + 368) == 1 && v7[252] == 7 )
  {
    v9 = sub_1435D0(v7 + 253, dword_138698, 7) == 0;
    v7 = *(_BYTE **)v1;
    v3 = *((unsigned __int8 *)v1 + 3850);
    v8 = v9;
  }
  else
  {
    v8 = 0;
    LOBYTE(v9) = 0;
  }
  *((_BYTE *)v1 + 3898) = v9;
  sub_12EB90(8, dword_138684, dword_138680, (unsigned __int8)v7[366], v3, v8, (unsigned __int8)v7[367]);
  v10 = (int *)off_13868C;
  v11 = off_138690;
  *(_DWORD *)off_138688 |= 4u;
  *v11 = *v10;
  *v10 = (HIWORD(*v10) << 16) | 0x5DC;
  v2[1] |= 0x20u;
  sub_12CBF4(4u, 1);
  v12 = *(_DWORD *)(*(_DWORD *)v1 + 360);
  if ( v12 )
  {
    v13 = *(unsigned __int16 *)(*(_DWORD *)v1 + 364);
    if ( v13 <= 0xC8 )
      sub_143630(dword_138694, v12, v13);
  }
  return sub_13819C();
}

