// fwstruct annotate: 1295b8_sub_1295B8.c
// sub_1295B8 @ 0x1295b8, size 254 bytes
// Doc: rf_mbox_mailbox_send [mmio]: Send command via RF mailbox MMIO registers
// rf_mbox_mailbox_send [mmio]: Send command via RF mailbox MMIO registers
int sub_1295B8()
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

  v0 = (unsigned int *)off_1296E8;
  v1 = (int *)off_1296BC;
  v2 = off_1296C0;
  v3 = off_1296C4;
  v4 = *((unsigned __int16 *)off_1296C0 + 93);
  v5 = (unsigned int *)off_1296C8;
  v6 = (unsigned __int8 **)off_1296CC;
  *(_DWORD *)off_1296B8 |= 0x40000000u;
  *v3 |= 0x10000000u;
  *v0 &= 0xFFF0FFFF;
  *v0 = *v0 & 0xFFFFFF00 | 0x10;
  *v5 = *v5 & 0xFFFFFF03 | 0x10;
  *v1 = *v1 & 0x3FFFFF | (((v4 >> 5) + 32) << 22);
  result = feature_guard_sdio(2, dword_1296D4);
  v8 = *v6;
  v9 = **v6;
  if ( v9 == 1 )
  {
    if ( v2[189] )
    {
      result = (int)off_1296D8;
      *(_DWORD *)off_1296DC &= ~0x2000000u;
      *v5 |= 0x200000u;
      *(_DWORD *)result = 36;
      if ( *v8 != 2 )
        goto LABEL_3;
      goto LABEL_6;
    }
    result = (int)off_1296DC;
    v13 = off_1296D8;
    v14 = off_1296E4;
    *(_DWORD *)off_1296DC |= 0x2000000u;
    *v13 = 4;
    *v14 = 1;
    *v3 &= 0xFFFBFFFE;
    v9 = (unsigned __int8)*v8;
  }
  if ( v9 != 2 )
  {
LABEL_3:
    *(_DWORD *)off_1296D8 &= ~0x20u;
    return result;
  }
LABEL_6:
  v10 = off_1296DC;
  v11 = off_1296D8;
  v12 = off_1296C8;
  *(_DWORD *)off_1296E0 |= 0x10000u;
  *v10 &= ~0x2000000u;
  *v11 = 63;
  *v12 &= ~1u;
  return 63;
}

