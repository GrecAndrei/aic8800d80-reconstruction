// sub_1389D0 @ 0x1389d0, size 136 bytes
// Doc: sub_12389D0 [util]: Table-driven dispatch using index lookup with ldrsh from globals
// sub_12389D0 [util]: Table-driven dispatch using index lookup with ldrsh from globals
uint32_t * sub_1389D0(int a1, __int16 a2, int a3)
{
  uint8_t *v3; // r5
  int v4; // r4
  int v5; // r3
  uint32_t *v6; // r6
  int v7; // r7
  int v8; // r12
  int v9; // r3

  v3 = off_138A5C;
  v4 = *((unsigned __int8 *)off_138A5C + 68);
  v5 = dword_138A60;
  v6 = (uint32_t *)(dword_138A60 + 80 * v4);
  if ( **(__int16 **)off_138A58 < 0 )
  {
    v7 = 4 * v4;
    if ( *(uint16_t *)(dword_138A60 + 80 * v4 + 76) )
    {
      fmac_phy_op_handler(dword_138A70, dword_138A6C, 175);
      return nullptr;
    }
  }
  else
  {
    v7 = 4 * v4;
  }
  v8 = dword_138A60 + 16 * (v7 + v4);
  *(uint32_t *)(v8 + 12) = a1;
  if ( a1 )
    *(uint8_t *)(v8 + 16) = *(uint8_t *)(a1 + 16);
  v9 = v5 + 16 * (v4 + v7);
  *(uint32_t *)(v9 + 68) = a3;
  *(uint16_t *)(v9 + 76) = a2;
  list_push_tail(dword_138A64, v6);
  v3[68] = v3[68]
         + 1
         - -64
         * ((unsigned int)(((unsigned int)dword_138A68 * (unsigned uint64_t)((unsigned int)(unsigned __int8)v3[68] + 1)) >> 32) >> 7);
  return v6;
}

