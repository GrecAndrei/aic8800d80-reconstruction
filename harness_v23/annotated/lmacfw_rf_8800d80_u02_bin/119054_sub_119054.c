// v23 annotated: sub_119054 @ 0x119054
// Original: 119054_sub_119054.c
// Primary struct: <unclustered>
//
// sub_119054 @ 0x119054, size 260 bytes
int __fastcall sub_119054(int a1)
{
  int v1; // r7
  int v2; // r9
  int v4; // r5
  int v5; // r4
  int v6; // r8
  int v7; // r10
  int v8; // r3
  int v9; // r1
  int v10; // r9
  _DWORD *v11; // r1
  char *v12; // r0
  _DWORD *v13; // r5
  _DWORD *v14; // r4
  int *v15; // r1
  int *v16; // r2
  int v17; // r1
  char *v18; // r4
  _DWORD *v19; // r5
  unsigned __int8 v20; // r0
  _DWORD *v21; // r1
  _DWORD *v22; // r1

  v1 = dword_119158;
  v2 = *(unsigned __int8 *)(dword_119158 + 152 * a1 + 32);
  v4 = dword_119158 + 152 * a1;
  v5 = dword_119158 + 8 * (19 * (__int16)a1 + 11);
  v6 = 0;
  do
  {
    v7 = (unsigned __int8)v6++;
    if ( *(_DWORD *)(v4 + 56) )
      rf_bus_write_60fc(v7, v5 - 32);
    v8 = *(_DWORD *)(v4 + 88);
    v9 = v5;
    v4 += 8;
    v5 += 8;
    if ( v8 )
      rf_bus_write_60fc(v7, v9);
  }
  while ( v6 != 4 );
  v10 = dword_11915C + 224 * v2;
  if ( *(_BYTE *)(v10 + 94) )
  {
    if ( *(_BYTE *)(v10 + 94) == 2 )
      return sub_117CB4(a1);
  }
  else
  {
    *(_BYTE *)(v10 + 102) = -1;
  }
  v11 = off_119160;
  v12 = (char *)off_119164;
  v13 = off_119168;
  v14 = off_11916C;
  *(_DWORD *)off_119164 = -1;
  *v11 = -1;
  *v13 = 0;
  v15 = v11 + 1;
  *v14 = 0;
  *(int *)((char *)v15 + 0xFFFFFFF0) = 0;
  *(_DWORD *)&v12[-4] = 0;
  v16 = v15;
  *v15 = ((unsigned __int8)(a1 + 16) << 16) | 0x40000000;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  v17 = *(_DWORD *)(v1 + 152 * a1 + 44);
  if ( v17 )
  {
    v18 = (char *)off_119164;
    v19 = off_119160;
    v20 = *(_BYTE *)(v17 + 33) + 16;
    *(_DWORD *)off_119164 = -1;
    *v19 = -1;
    v21 = off_11916C;
    *(_DWORD *)&v18[-16] = 0;
    *v21 = 0;
    *(_DWORD *)((char *)v19 + 0xFFFFFFF4) = 0;
    v22 = v21 + 5;
    *(_DWORD *)&v18[-4] = 0;
    *v16 = (v20 << 16) | 0x40000000;
    while ( (*v22 & 0x40000000) != 0 )
      ;
  }
  return sub_117CB4(a1);
}

