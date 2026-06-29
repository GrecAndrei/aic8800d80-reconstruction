// sub_114A3C @ 0x114a3c, size 70 bytes
// Doc: rf_fault_dump_n328 [rf]: Alternate RF fault state dump routine
// rf_fault_dump_n328 [rf]: Alternate RF fault state dump routine
int  sub_114A3C(char a1, uint8_t *a2)
{
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0
  char v6; // r2

  v3 = (unsigned int)MEMORY[0x1FC](10) >> (8 * a1);
  v4 = (unsigned __int8)v3 >> 4;
  if ( (v3 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v3 )
    {
      *a2 = 0;
      return 2;
    }
    v4 = (unsigned __int8)v3;
    result = 1;
  }
  if ( (v4 & 1) != 0 )
    v6 = -1;
  else
    v6 = 1;
  *a2 = (v4 >> 1) * v6;
  return result;
}

