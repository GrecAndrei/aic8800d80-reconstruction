// sub_100FAC @ 0x100fac, size 612 bytes
int  sub_100FAC(unsigned int a1, int a2)
{
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  uint32_t *v4; // r5
  uint32_t *v5; // r6
  uint32_t *v6; // r4
  int v7; // r1
  uint32_t *v8; // r1
  uint32_t *v9; // r2
  int v11; // r4
  unsigned int *v12; // r0
  int v13; // r2
  unsigned int *v14; // r3
  int v15; // r4
  unsigned int *v16; // r5
  int v17; // r1
  uint32_t *v18; // r4
  unsigned int *v19; // r1
  uint8_t *v20; // r0
  unsigned int *v21; // r2
  char *v22; // r2
  unsigned int *v23; // r1
  uint32_t *v24; // r5
  uint32_t *v25; // r0
  uint32_t *v26; // r4
  uint32_t *v27; // r2
  int result; // r0

  v2 = off_101210;
  v3 = off_101214;
  v4 = off_101218;
  v5 = off_10121C;
  *(uint32_t *)off_101210 |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = off_101220;
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(uint32_t *)((char *)v4 + 0xFFFFFFEC) = *(uint32_t *)((char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = off_101224;
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = off_101228;
  *(uint32_t *)((char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  sub_102E08(1, 0, 16, *v9);
  sub_102E08(1, 16, 16, *(uint32_t *)off_10122C);
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
  v12 = (unsigned int *)off_101230;
  v13 = dword_101234;
  v14 = (unsigned int *)off_101238;
  *(uint32_t *)off_101230 = *(uint32_t *)off_101230 & 0xFE01FFFF | (*(unsigned __int8 *)(dword_101234 + v11) << 17);
  v15 = v11 + v13;
  v16 = (unsigned int *)off_10123C;
  *v12 = *v12 & 0xFFFFFF00 | *(unsigned __int8 *)(v15 + 1);
  v17 = *(unsigned __int8 *)(v15 + 2);
  v18 = off_101240;
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v19 = (unsigned int *)off_10121C;
  v12 -= 64;
  *v16 = *v16 & 0xFF00FFFF | 0x2F0000;
  *v12 |= 8u;
  *v12 |= 4u;
  v20 = off_101244;
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  *v18 &= 0xFFFFC7FF;
  *v19 = *v19 & 0xFFFFE3FF | 0x1000;
  v16[19966] = v16[19966] & 0xFFFFF83F | 0x400;
  if ( !v20[1] )
  {
    v21 = (unsigned int *)off_101248;
    *v19 = *v19 & 0xFFFFFC7F | 0x100;
    *v21 = *v21 & 0x16000 | 0x8000 | *v21 & 0xFFFE1FFF;
  }
  v22 = (char *)off_10124C;
  v23 = (unsigned int *)off_10121C;
  v24 = off_101250;
  v25 = off_101224;
  v26 = off_101254;
  *(uint32_t *)off_10124C |= 0xC00u;
  *v23 = *v23 & 0xFFFFFF87 | 0x48;
  *v24 |= 4u;
  *v25 &= ~2u;
  *v26 |= 0x20000u;
  *(uint32_t *)&v22[-12] = *(uint32_t *)&v22[-12] & 0xFFF8FFFF | 0x20000;
  *(uint32_t *)&v22[-12] = *(uint32_t *)&v22[-12] & 0xFFFFFFF0 | 8;
  v27 = off_101258;
  v24[1905] = v24[1905] & 0xFFFFE3FF | 0x800;
  *(uint32_t *)((char *)v26 + 0xFFFFFFE8) = *(uint32_t *)((char *)v26 + 0xFFFFFFE8) & 0xFC7FFFFF | 0x1000000;
  *v25 &= ~0x20u;
  *v23 |= 0xE0000u;
  while ( !*v27 )
    ;
  result = *(uint32_t *)off_10125C & 1;
  if ( !result )
    result = sub_100E24(0);
  *(uint32_t *)off_101258 = 1;
  return result;
}

