// sub_11C26C @ 0x11c26c, size 158 bytes
int  sub_11C26C(int result)
{
  int v1; // r7
  int v2; // r5
  uint8_t *v3; // r6
  int v4; // r8
  int v5; // r0
  __int16 v6; // r5
  __int16 v7; // r4
  int v8; // r2

  v1 = *(uint32_t *)(result + 72);
  v2 = result;
  if ( **(__int16 **)off_11C30C < 0 && !v1 )
    result = sub_1219C4(dword_11C320, dword_11C31C, 3591);
  v3 = off_11C310;
  if ( (*((uint8_t *)off_11C310 + 88) & 0x20) == 0 && *((unsigned __int8 *)off_11C310 + 90) > 1u )
  {
    v4 = *(unsigned __int8 *)(v2 + 102);
    v5 = sub_11DDF0(70, *((uint8_t *)off_11C310 + 88) & 0x20, *((uint8_t *)off_11C310 + 88) & 0x20, 20);
    *(uint8_t *)v5 = 0;
    *(uint8_t *)(v5 + 1) = *(uint8_t *)(v2 + 95);
    *(uint8_t *)(v5 + 2) = *(uint8_t *)(v1 + 4);
    *(uint8_t *)(v5 + 3) = *(uint8_t *)(v1 + 5);
    v6 = *(uint16_t *)(v1 + 8);
    v7 = *(uint16_t *)(v1 + 10);
    v8 = dword_11C314;
    *(uint16_t *)(v5 + 4) = *(uint16_t *)(v1 + 6);
    *(uint16_t *)(v5 + 6) = v6;
    *(uint16_t *)(v5 + 8) = v7;
    *(uint8_t *)(v5 + 16) = *(uint8_t *)(v1 + 12);
    *(uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_11C318
                                         * (unsigned uint64_t)(unsigned int)(*(uint32_t *)(v8 + 152 * v4 + 8) - 5000)) >> 32) >> 6;
    result = sub_11DE50(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

