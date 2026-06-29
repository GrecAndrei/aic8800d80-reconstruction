// rf_calib_init_loader @ 0x10ee7c, size 256 bytes
// Doc: rf_calib_init_loader [rf]: Load calibration constants from ROM tables into RF MMIO block at 0x40100000
// rf_calib_init_loader [rf]: Load calibration constants from ROM tables into RF MMIO block at 0x40100000
int rf_calib_init_loader()
{
  unsigned int *v0; // r4
  uint32_t *v1; // r2
  int v2; // r0
  int v3; // r3
  uint32_t *v4; // r9
  uint32_t *v5; // r6
  uint32_t *v6; // r10
  int v7; // r5
  int *v8; // r2
  int v9; // r1
  unsigned int v10; // r8
  unsigned int v11; // r7
  unsigned int v12; // r6
  unsigned int v13; // r5
  int result; // r0
  uint32_t v15[2]; // [sp+4h] [bp-Ch] BYREF
  __int16 v16; // [sp+Ch] [bp-4h]

  v0 = (unsigned int *)off_10EF7C;
  v1 = off_10EF80;
  v2 = dword_10EF84;
  v3 = dword_10EF88;
  v4 = off_10EF9C;
  v5 = off_10EF8C;
  v6 = off_10EFA0;
  v7 = dword_10EF90;
  v16 = 0;
  *((uint32_t *)off_10EF7C + 14) = 296;
  v1[3] = v2 | v1[3] & 0xE0000000;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  v15[0] = v7;
  v15[1] = 2442;
  sub_102908((unsigned __int8 *)v15, 0);
  v8 = (int *)off_10EF94;
  v9 = dword_10EF98;
  v0 += 593954;
  *v6 |= 0x80000000;
  *v8 = v9;
  v10 = *v0;
  v11 = *v0;
  v12 = *v0;
  v13 = *v0;
  *v0 &= ~0x80000u;
  *v0 |= 0x100000u;
  *v0 |= 0x200000u;
  *v0 |= 0x400000u;
  result = sub_10EC2C(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}

