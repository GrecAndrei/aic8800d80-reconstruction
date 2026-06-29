// sub_12205C @ 0x12205c, size 168 bytes
// Doc: sub_1222060 [util]: Unknown utility helper at 0x1222060
// sub_1222060 [util]: Unknown utility helper at 0x1222060
int  sub_12205C(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  uint16_t *v5; // r3
  int result; // r0
  uint32_t *v7; // r3
  int v8; // r1
  uint8_t *v9; // r3
  char *v10; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    v7 = off_122118;
    *(uint8_t *)(a1 + 128) = 0;
    v8 = v7[4];
    v9 = off_122110;
    v10 = (char *)off_122110 + 12;
    *((uint16_t *)off_122110 + 14) = 1793;
    v9[36] = 0;
    *((uint32_t *)v9 + 5) = a1;
    result = timestamp_update(v10, v8 + 10000);
    *(uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (unsigned __int8)(*(uint8_t *)(a1 + 115) + 1);
    v4 = *(uint32_t *)off_122104;
    *(uint8_t *)(a1 + 115) = v3;
    if ( *(unsigned __int8 *)(v4 + 1) == v3 )
    {
      *(uint8_t *)(a1 + 115) = 0;
      feature_guard_check(1024, dword_122120);
      return send_msg_to_host_c43(a1);
    }
    else if ( *(uint8_t *)(a1 + 108) )
    {
      return sub_12B2B0(*(unsigned __int8 *)(a1 + 107), off_12211C, a1);
    }
    else
    {
      if ( *((uint8_t *)off_122108 + 2) )
        *(uint32_t *)off_12210C &= ~0x80000000;
      v5 = off_122110;
      if ( *((uint8_t *)off_122110 + 8) )
        --*((uint8_t *)off_122110 + 8);
      v5[14] = 1;
      result = timestamp_remove(dword_122114);
      *(uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}

