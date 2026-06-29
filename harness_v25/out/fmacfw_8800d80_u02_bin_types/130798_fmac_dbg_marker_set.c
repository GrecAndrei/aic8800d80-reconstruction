// fmac_dbg_marker_set @ 0x130798, size 56 bytes
// Doc: fmac_dbg_marker_set [util]: Write debug marker bytes (0xbf, 0xc) to control word
// fmac_dbg_marker_set [util]: Write debug marker bytes (0xbf, 0xc) to control word
int  fmac_dbg_marker_set(int a1)
{
  uint32_t *v2; // r1
  uint16_t *v3; // r2
  __int16 v4; // r6
  __int16 v5; // r5
  __int16 v6; // r4

  v2 = off_1307D0;
  **(uint8_t **)a1 = -65;
  *(uint8_t *)(*(uint32_t *)a1 + 1) = 12;
  *(uint32_t *)(*(uint32_t *)a1 + 2) = v2[12];
  v3 = *(uint16_t **)a1;
  v4 = *((uint16_t *)v2 + 26);
  v5 = *((uint16_t *)v2 + 27);
  v6 = *((uint16_t *)v2 + 28);
  v3[6] = *((uint16_t *)v2 + 29);
  v3[3] = v4;
  v3[4] = v5;
  v3[5] = v6;
  *(uint32_t *)a1 = v3 + 7;
  return 14;
}

