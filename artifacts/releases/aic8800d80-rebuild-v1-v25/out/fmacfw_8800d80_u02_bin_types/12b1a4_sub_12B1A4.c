// sub_12B1A4 @ 0x12b1a4, size 192 bytes
// Doc: sub_122B1A4 [unknown]: Unknown function at 0x122B1A4
// sub_122B1A4 [unknown]: Unknown function at 0x122B1A4
int sub_12B1A4()
{
  uint32_t *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  char v4; // r8
  int v5; // r1
  int v6; // r3
  int v7; // r2
  int v8; // r1
  int v10; // r1

  v0 = off_12B264;
  v1 = *(uint32_t *)off_12B264;
  v2 = *(uint32_t *)off_12B264 + 6 * *((unsigned __int8 *)off_12B264 + 10);
  v3 = 6 * *((unsigned __int8 *)off_12B264 + 10);
  v4 = *(uint8_t *)(v2 + 3);
  if ( (v4 & 5) != 0 )
  {
    v5 = *(uint32_t *)(*(uint32_t *)off_12B268 + 20);
    if ( !v5 )
    {
      v5 = dword_12B26C;
      goto LABEL_4;
    }
  }
  else
  {
    v5 = mac_check_msg_id_0x96c((unsigned __int16 *)(*(uint32_t *)off_12B264 + 6 * *((unsigned __int8 *)off_12B264 + 10)));
    if ( !v5 )
    {
      v5 = 30000;
      goto LABEL_4;
    }
  }
  if ( (v4 & 1) == 0 && *((uint8_t *)off_12B274 + 3850) == 1 )
    v5 += 170000;
LABEL_4:
  sub_127AD0((__int16 *)v2, v5, *(uint8_t *)(v1 + 366));
  v6 = v0[1];
  if ( v6 )
  {
    v7 = *(unsigned __int8 *)(v2 + 2);
    v8 = *(unsigned __int16 *)(v1 + v3);
    if ( *(uint8_t *)(v2 + 2) )
    {
      if ( v7 == 1 && (v10 = v8 - 4992, (unsigned __int16)(v10 - 13) <= 0x370u) )
        *(uint8_t *)(v6 + 2) = (unsigned int)(((unsigned int)dword_12B270 * (unsigned uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(uint8_t *)(v6 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v8 - 2412) <= 0x48 )
      {
        if ( v8 == 2484 )
        {
          *(uint8_t *)(v6 + 2) = 14;
          return sub_12CD34(2);
        }
        LOBYTE(v7) = (unsigned int)(((unsigned int)dword_12B270 * (unsigned uint64_t)(unsigned int)(v8 - 2407)) >> 32) >> 2;
      }
      *(uint8_t *)(v6 + 2) = v7;
    }
  }
  return sub_12CD34(2);
}

