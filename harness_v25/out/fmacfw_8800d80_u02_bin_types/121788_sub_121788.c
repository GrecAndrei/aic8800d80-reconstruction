// sub_121788 @ 0x121788, size 118 bytes
unsigned int  sub_121788(int *a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r7
  uint32_t *v3; // r4
  uint32_t *v4; // r1
  uint32_t *v5; // r6
  uint32_t *v6; // r5
  int v7; // r7
  int v8; // r0
  __int16 **v9; // r0
  int *v10; // r4
  int v11; // r2
  __int16 *v12; // r3

  v1 = off_121800;
  v2 = off_121804;
  v3 = off_121808;
  v4 = off_12180C;
  v5 = off_121810;
  v6 = off_121814;
  *(uint32_t *)off_121800 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((unsigned __int16 *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (__int16 **)off_121818;
  v10 = (int *)off_12181C;
  v11 = dword_121820;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(uint32_t *)off_121828 << 28 )
  {
    sub_12F49C(dword_121830, dword_12182C, 472);
    v11 = *v10;
  }
  *(uint32_t *)off_121824 = v11 | v10[1];
  return sub_11E080(0);
}

