// sub_129394 @ 0x129394, size 254 bytes
// Doc: mmio_reg_init_n_39c [mmio]: Initialize MMIO control registers at 0x4032xxxx with status read
// mmio_reg_init_n_39c [mmio]: Initialize MMIO control registers at 0x4032xxxx with status read
int sub_129394()
{
  unsigned int *v0; // r12
  int *v1; // r1
  _BYTE *v2; // r7
  _DWORD *v3; // r4
  unsigned int v4; // r0
  unsigned int *v5; // r5
  unsigned __int8 **v6; // r6
  int result; // r0
  _BYTE *v8; // r2
  int v9; // r3
  _DWORD *v10; // r1
  _DWORD *v11; // r4
  _DWORD *v12; // r2
  _DWORD *v13; // r6
  _DWORD *v14; // r5

  v0 = (unsigned int *)off_1294C4;
  v1 = (int *)off_129498;
  v2 = off_12949C;
  v3 = off_1294A0;
  v4 = *((unsigned __int16 *)off_12949C + 93);
  v5 = (unsigned int *)off_1294A4;
  v6 = (unsigned __int8 **)off_1294A8;
  *(_DWORD *)off_129494 |= 0x40000000u;
  *v3 |= 0x10000000u;
  *v0 &= 0xFFF0FFFF;
  *v0 = *v0 & 0xFFFFFF00 | 0x10;
  *v5 = *v5 & 0xFFFFFF03 | 0x10;
  *v1 = *v1 & 0x3FFFFF | (((v4 >> 5) + 32) << 22);
  result = feature_guard_check(2, dword_1294B0);
  v8 = *v6;
  v9 = **v6;
  if ( v9 == 1 )
  {
    if ( v2[189] )
    {
      result = (int)off_1294B4;
      *(_DWORD *)off_1294B8 &= ~0x2000000u;
      *v5 |= 0x200000u;
      *(_DWORD *)result = 36;
      if ( *v8 != 2 )
        goto LABEL_3;
      goto LABEL_6;
    }
    result = (int)off_1294B8;
    v13 = off_1294B4;
    v14 = off_1294C0;
    *(_DWORD *)off_1294B8 |= 0x2000000u;
    *v13 = 4;
    *v14 = 1;
    *v3 &= 0xFFFBFFFE;
    v9 = (unsigned __int8)*v8;
  }
  if ( v9 != 2 )
  {
LABEL_3:
    *(_DWORD *)off_1294B4 &= ~0x20u;
    return result;
  }
LABEL_6:
  v10 = off_1294B8;
  v11 = off_1294B4;
  v12 = off_1294A4;
  *(_DWORD *)off_1294BC |= 0x10000u;
  *v10 &= ~0x2000000u;
  *v11 = 63;
  *v12 &= ~1u;
  return 63;
}

