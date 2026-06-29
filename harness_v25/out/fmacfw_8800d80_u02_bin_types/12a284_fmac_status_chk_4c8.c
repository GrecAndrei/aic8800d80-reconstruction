// fmac_status_chk_4c8 @ 0x12a284, size 144 bytes
// Doc: fmac_status_chk_4c8 [mac]: Read status byte at firmware ctx+0x4c8 and branch
// fmac_status_chk_4c8 [mac]: Read status byte at firmware ctx+0x4c8 and branch
unsigned __int8 * fmac_status_chk_4c8(unsigned __int8 *result, int a2)
{
  int v2; // r2
  int v3; // r7
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // lr
  unsigned __int8 *v8; // r5
  int v9; // r3
  int v10; // r1

  if ( result[1224] )
  {
    v2 = result[1225];
    v3 = dword_12A314;
    v4 = dword_12A314 + 140 * v2;
    v5 = *(unsigned __int8 *)(v4 + 115);
    v6 = *((uint32_t *)result + 1) & 0xFFFFFFBF;
    *(uint8_t *)(v4 + 134) = 1;
    v7 = 140 * v2;
    v8 = (unsigned __int8 *)(v3 + 140 * v2);
    *((uint32_t *)result + 1) = v6;
    if ( !v5 )
      return sub_129804(v8);
    v9 = a2 + (v5 << 10);
    if ( *(uint8_t *)(v4 + 112) || (v10 = a2 + 300, *((uint32_t *)off_12A318 + 4) - v10 + 50 >= 0) )
    {
      *(uint8_t *)(v3 + 140 * v2 + 114) = 1;
      timestamp_update(v7 + 96 + v3, v9);
      return sub_129804(v8);
    }
    *(uint32_t *)(v4 + 116) = v9;
    *(uint8_t *)(v4 + 114) = 2;
    return (unsigned __int8 *)timestamp_update(v7 + 96 + v3, v10);
  }
  return result;
}

