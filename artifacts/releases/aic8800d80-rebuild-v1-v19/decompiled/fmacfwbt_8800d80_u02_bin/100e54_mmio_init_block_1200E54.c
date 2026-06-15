// mmio_init_block_1200E54 @ 0x100e54, size 616 bytes
// Doc: mmio_init_block_1200E54 [mmio]: Initialize MMIO block at 0x40344000 with bit OR 0x400 patch
// mmio_init_block_1200E54 [mmio]: Initialize MMIO block at 0x40344000 with bit OR 0x400 patch
int __fastcall mmio_init_block_1200E54(unsigned int a1, int a2)
{
  _DWORD *v2; // r3
  _DWORD *v3; // r2
  _DWORD *v4; // r5
  _DWORD *v5; // r6
  _DWORD *v6; // r4
  int v7; // r1
  _DWORD *v8; // r1
  _DWORD *v9; // r2
  int v11; // r4
  unsigned int *v12; // r0
  int v13; // r2
  unsigned int *v14; // r3
  int v15; // r4
  unsigned int *v16; // r5
  int v17; // r1
  _DWORD *v18; // r4
  unsigned int *v19; // r1
  _BYTE *v20; // r0
  unsigned int *v21; // r2
  char *v22; // r2
  unsigned int *v23; // r1
  _DWORD *v24; // r5
  _DWORD *v25; // r0
  _DWORD *v26; // r4
  _DWORD *v27; // r2
  int result; // r0

  v2 = off_1010BC;
  v3 = off_1010C0;
  v4 = off_1010C4;
  v5 = off_1010C8;
  *(_DWORD *)off_1010BC |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = off_1010CC;
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(_DWORD *)((char *)v4 + 0xFFFFFFEC) = *(_DWORD *)((char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = off_1010D0;
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = off_1010D4;
  *(_DWORD *)((char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  sub_102D10(1, 0, 16, *v9);
  sub_102D10(1, 16, 16, *(_DWORD *)off_1010D8);
  sub_1009A0(0, a1);
  if ( a1 > 0x98A )
  {
    v11 = 6;
  }
  else if ( a1 <= 0x97B )
  {
    v11 = 0;
  }
  else
  {
    v11 = 3;
  }
  v12 = (unsigned int *)off_1010DC;
  v13 = dword_1010E0;
  v14 = (unsigned int *)off_1010E4;
  *(_DWORD *)off_1010DC = *(_DWORD *)off_1010DC & 0xFE01FFFF | (*(unsigned __int8 *)(dword_1010E0 + v11) << 17);
  v15 = v11 + v13;
  v16 = (unsigned int *)off_1010E8;
  *v12 = *v12 & 0xFFFFFF00 | *(unsigned __int8 *)(v15 + 1);
  v17 = *(unsigned __int8 *)(v15 + 2);
  v18 = off_1010EC;
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v19 = (unsigned int *)off_1010C8;
  v12 -= 64;
  *v16 = *v16 & 0xFF00FFFF | 0x2F0000;
  *v12 |= 8u;
  *v12 |= 4u;
  v20 = off_1010F0;
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  *v18 &= 0xFFFFC7FF;
  *v19 = *v19 & 0xFFFFE3FF | 0x1000;
  v16[19966] = v16[19966] & 0xFFFFF83F | 0x400;
  if ( !v20[1] )
  {
    v21 = (unsigned int *)off_1010F4;
    *v19 = *v19 & 0xFFFFFC7F | 0x100;
    *v21 = *v21 & 0x16000 | 0x8000 | *v21 & 0xFFFE1FFF;
  }
  v22 = (char *)off_1010F8;
  v23 = (unsigned int *)off_1010C8;
  v24 = off_1010FC;
  v25 = off_1010D0;
  v26 = off_101100;
  *(_DWORD *)off_1010F8 |= 0xC00u;
  *v23 = *v23 & 0xFFFFFF87 | 0x48;
  *v24 |= 4u;
  *v25 &= ~2u;
  *v26 |= 0x20000u;
  *(_DWORD *)&v22[-12] = *(_DWORD *)&v22[-12] & 0xFFF8FFFF | 0x20000;
  *(_DWORD *)&v22[-12] = *(_DWORD *)&v22[-12] & 0xFFFFFFF0 | 8;
  v27 = off_101104;
  v24[1905] = v24[1905] & 0xFFFFE3FF | 0x800;
  *(_DWORD *)((char *)v26 + 0xFFFFFFE8) = *(_DWORD *)((char *)v26 + 0xFFFFFFE8) & 0xFC7FFFFF | 0x1000000;
  *v25 &= ~0x20u;
  *v23 = *v23 & 0xFFF1FFFF | 0x60000;
  while ( !*v27 )
    ;
  result = *(_DWORD *)off_101108 & 1;
  if ( !result )
    result = sub_100CD0(0);
  *(_DWORD *)off_101104 = 1;
  return result;
}

