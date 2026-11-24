// rf_bus_reset2_0 @ 0x111304, size 242 bytes
// Doc: rf_bus_write_n_100 [rf]: RF bus write clearing/setting control bits
// rf_bus_write_n_100 [rf]: RF bus write clearing/setting control bits
int rf_bus_reset2_0()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  _DWORD *v3; // r2
  _DWORD *v4; // r1
  int v5; // r3
  _DWORD *v6; // r2
  int v7; // r0

  v0 = rf_bus_setup_3f8;
  *((_DWORD *)rf_bus_setup_3f8 + 4) |= 1u;
  while ( (*(_DWORD *)(v0 + 0x10) & 1) != 0 )
    ;
  v1 = rf_bus_setup_3f8;
  while ( *((int *)rf_bus_setup_3f8 + 4) >= 0 )
    ;
  v2 = rf_bus_setup_3f8;
  *((_DWORD *)rf_bus_setup_3f8 + 3) |= 0x40000007u;
  *(_DWORD *)(v1 + 0xc) = *(_DWORD *)(v1 + 0xc) & 0xFFFFC0FF | 0x2700;
  *(_DWORD *)(v1 + 0x10) |= 1u;
  while ( (*(_DWORD *)(v2 + 0x10) & 1) != 0 )
    ;
  v3 = rf_bus_setup_3f8;
  while ( *((int *)rf_bus_setup_3f8 + 4) >= 0 )
    ;
  v4 = rf_bus_setup_3f8;
  *((_DWORD *)rf_bus_setup_3f8 + 3) |= 0x40000007u;
  *(_DWORD *)(v3 + 0xc) = *(_DWORD *)(v3 + 0xc) & 0xFFFFC0FF | 0x2700;
  *(_DWORD *)(v3 + 0x800) &= 0xFFFFE7FC;
  *(_DWORD *)(v3 + 0x800) |= 0x800004u;
  *(_DWORD *)(v3 + 0x18) = 0;
  v5 = 1;
  *(_DWORD *)(v3 + 0x14) = -1;
  *(_DWORD *)(v3 + 0x81c) = 0;
  *(_DWORD *)(v3 + 0x814) = 0;
  *(_DWORD *)(v3 + 0x810) = 0;
  while ( 1 )
  {
    v6 = &v4[8 * v5 - 16];
    if ( v5 != 1 )
      break;
    *(_DWORD *)(v4 + 0xb08) = -1;
    *(_DWORD *)(v4 + 0x908) = -1;
LABEL_11:
    ++v5;
  }
  *(_DWORD *)(v6 + 0xb28) = -1;
  *(_DWORD *)(v6 + 0x928) = -1;
  if ( v5 != 6 )
    goto LABEL_11;
  *(_DWORD *)(v4 + 0x18) = rf_bus_write2_n_127;
  v7 = rf_bus_write_n_6b;
  *(_DWORD *)(v4 + 0x804) &= ~2u;
  *(_DWORD *)(v4 + 0x804) |= 0x8000u;
  *(_DWORD *)(v4 + 0x8) = 46;
  *(_DWORD *)(v4 + 0x8) |= 1u;
  return msg_parse(v7, v4);
}

