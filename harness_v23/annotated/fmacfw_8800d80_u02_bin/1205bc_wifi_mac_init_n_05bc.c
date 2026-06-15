// v23 annotated: wifi_mac_init_n_05bc @ 0x1205bc
// Original: 1205bc_wifi_mac_init_n_05bc.c
// Primary struct: <unclustered>
//
// wifi_mac_init_n_05bc @ 0x1205bc, size 284 bytes
// Doc: wifi_mac_init_n_05bc [mac]: Initialize WiFi MAC MMIO registers block
// wifi_mac_init_n_05bc [mac]: Initialize WiFi MAC MMIO registers block
_DWORD *wifi_mac_init_n_05bc()
{
  int *v0; // r4
  int *v1; // r5
  int *v2; // r6
  int v3; // r0
  int v4; // r0
  _DWORD *v5; // r0
  unsigned int *v6; // r1
  unsigned int *v7; // r3
  int v8; // r4
  int v9; // r3
  char v10; // r2
  bool v11; // zf
  int v12; // r2
  unsigned int v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r6
  _DWORD *v16; // r5
  _DWORD *v17; // r4
  _DWORD *result; // r0
  unsigned __int8 **v19; // r1
  int v20; // r3

  v0 = (int *)off_1206D8;
  v1 = (int *)off_1206DC;
  v2 = (int *)off_1206E0;
  v3 = nullsub_1();
  v4 = nullsub_2(v3);
  nullsub_3(v4);
  v5 = off_1206E4;
  v6 = (unsigned int *)off_1206E8;
  v7 = (unsigned int *)off_1206EC;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1206F0;
  *v5 |= 0x8000000u;
  *v6 = *v6 & 0xFF0FFFFF | 0x200000;
  *v7 = *v7 & 0xFFFFF8FF | 0x600;
  *v7 = *v7 & 0xFFFFC7FF | 0x2000;
  *v7 = *v7 & 0xFFFE3FFF | 0xC000;
  *v7 |= 0xE0000u;
  *v1 = *v1 & v8 | 0x5DC;
  v5[1] = v5[1] & v8 | 0xBB8;
  *(v6 - 205) = *(v6 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v2;
  v10 = *(_BYTE *)(*v2 + 2);
  if ( (v10 & 0x10) != 0 )
    v5[16] &= ~0x80000000;
  else
    *(_DWORD *)off_12071C |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(_DWORD *)off_1206F4;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(_DWORD *)off_1206F4 = v13;
  v14 = off_1206F8;
  *(_DWORD *)off_1206F8 = dword_1206FC;
  if ( *(_BYTE *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = off_120704;
  v16 = off_120708;
  v17 = off_12070C;
  result = off_120710;
  v19 = (unsigned __int8 **)off_120714;
  *(_DWORD *)off_120700 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(_DWORD *)off_120718 |= 0x80000000;
  return result;
}

