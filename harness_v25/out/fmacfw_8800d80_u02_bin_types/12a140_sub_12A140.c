// sub_12A140 @ 0x12a140, size 72 bytes
// Doc: sub_122A140 [unknown]: Wrapper checking global flag before operation
// sub_122A140 [unknown]: Wrapper checking global flag before operation
unsigned int  sub_12A140(int a1, uint32_t *a2, uint32_t *a3)
{
  int v6; // r3
  int v7; // r0

  if ( **(__int16 **)off_12A188 < 0 && !*(uint8_t *)(a1 + 1224) )
    sub_12F46C(dword_12A194, dword_12A190, 1311);
  v6 = dword_12A18C + 140 * *(unsigned __int8 *)(a1 + 1225);
  *a2 = *(uint32_t *)(v6 + 128);
  v7 = *(uint32_t *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}

