// sub_1346C0 @ 0x1346c0, size 256 bytes
int  sub_1346C0(int a1)
{
  int v1; // lr
  int v3; // r7
  uint8_t *v4; // r6
  int v5; // r0
  unsigned int *v6; // r3
  uint8_t *v7; // r5
  int v8; // r0
  uint8_t *v9; // r0
  uint8_t *v10; // r0
  int v12; // r0

  v3 = v1;
  v4 = (uint8_t *)sub_12C7EC(5145, 5, 6, 2u);
  v5 = sub_12C7EC(5143, 5, 6, 2u);
  v6 = (unsigned int *)off_1347C0;
  v7 = (uint8_t *)v5;
  if ( (*(uint32_t *)off_1347C0 & 0x4000000) != 0 )
  {
    *(uint32_t *)off_1347C0 &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  v8 = dword_1347CC;
  *((uint8_t *)off_1347C8 + 73) = *(uint8_t *)off_1347C4;
  sub_12E948(v8, v3);
  sub_1342AC();
  sub_1173F4(a1);
  sub_13BCD4(*(unsigned __int8 *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  sub_12D108(dword_1347D0, (uint32_t *)v4 - 3);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v12 = sub_12C7EC(30, 0, 6, 4u);
    *(uint8_t *)(v12 + 2) = 0;
    *(uint8_t *)(v12 + 3) = *(uint8_t *)(a1 + 107);
    sub_12D108(dword_1347D0, (uint32_t *)(v12 - 12));
  }
  if ( *(unsigned __int8 *)(a1 + 116) != 255 )
  {
    v9 = (uint8_t *)sub_12C7EC(12, 0, 6, 1u);
    *v9 = *(uint8_t *)(a1 + 116);
    sub_12D108(dword_1347D0, (uint32_t *)v9 - 3);
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v10 = (uint8_t *)sub_12C7EC(57, 0, 6, 1u);
    *v10 = *(uint8_t *)(a1 + 107);
    sub_12D108(dword_1347D0, (uint32_t *)v10 - 3);
  }
  *v7 = 0;
  v7[1] = *(uint8_t *)(a1 + 107);
  sub_12D108(dword_1347D0, (uint32_t *)v7 - 3);
  return sub_13467C();
}

