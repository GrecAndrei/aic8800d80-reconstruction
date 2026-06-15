// v23 annotated: sub_123BF8 @ 0x123bf8
// Original: 123bf8_sub_123BF8.c
// Primary struct: <unclustered>
//
// sub_123BF8 @ 0x123bf8, size 192 bytes
int __fastcall sub_123BF8(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  _DWORD *v5; // r5
  _DWORD *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = rf_bus_setup_n3a8(5, a4, a3, 28);
  v5 = off_123CB8;
  *(_DWORD *)v4 = dword_123CBC;
  v6 = off_123CC0;
  *(_DWORD *)(v4 + 4) = *v5;
  *(_DWORD *)(v4 + 8) = *v6;
  *(_BYTE *)(v4 + 26) = 4;
  *(_WORD *)(v4 + 24) = 32;
  v7 = v4;
  mmio_pair_read_n1800((_DWORD *)(v4 + 12), (_DWORD *)(v4 + 16));
  *(_DWORD *)(v7 + 20) = dword_123CC4;
  if ( (*v5 & 0x20000) != 0 && sdio_buffer_prepare_n_2e2() )
  {
    *(_DWORD *)(v7 + 20) |= 0x400u;
    if ( (*(_DWORD *)off_123CB8 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(_DWORD *)off_123CB8 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( sysctl_chip_id_get() )
    *(_DWORD *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(_DWORD *)off_123CB8 & 0x2000) != 0 )
    *(_DWORD *)(v7 + 20) |= 0x1000u;
  if ( sub_101874() )
    *(_DWORD *)(v7 + 20) |= 0x200u;
  if ( (*(_DWORD *)off_123CB8 & 0x8000) != 0 && chip_feature_check() )
    *(_DWORD *)(v7 + 20) |= 0x800000u;
  v8 = sub_101888();
  v9 = *(_DWORD *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(_DWORD *)(v7 + 20) = v9 | 0x600000;
  sub_12CBB4(v7);
  return 0;
}

