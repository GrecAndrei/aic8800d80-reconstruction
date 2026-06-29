// rf_level_apply_n200 @ 0x126fd8, size 104 bytes
// Doc: rf_level_apply_n262 [rf]: Apply RF TX level/amplitude settings to registers
// rf_level_apply_n262 [rf]: Apply RF TX level/amplitude settings to registers
int  rf_level_apply_n200(char a1)
{
  uint8_t *v1; // r4
  int v3; // r0
  int v4; // r2
  signed int v5; // r3

  v1 = rf_level_apply_n268;
  if ( *((uint8_t *)rf_level_apply_n268 + 1) )
  {
    v3 = *((char *)rf_level_apply_n268 + 3);
    v4 = v3;
  }
  else
  {
    sub_10DE98();
    v4 = (int)COERCE_FLOAT(sub_10DEF0());
    v3 = (char)v4;
  }
  v1[4] = a1;
  v1[6] = a1;
  if ( v4 > 29 )
    v5 = (unsigned int)(((unsigned int)rf_level_apply_n270 * (unsigned uint64_t)(unsigned int)(v4 - 30)) >> 32) >> 3;
  else
    v5 = ((int)((unsigned uint64_t)(rf_level_apply_n26c * (uint64_t)(v4 - 40)) >> 32) >> 2) - ((v4 - 40) >> 31);
  if ( v5 >= 8 )
    v5 = 8;
  if ( v5 < -7 )
    LOBYTE(v5) = -7;
  v1[2] = v5;
  return rf_level_compute(v3);
}

