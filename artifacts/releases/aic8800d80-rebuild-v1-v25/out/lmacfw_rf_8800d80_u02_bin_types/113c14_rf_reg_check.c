// rf_reg_check @ 0x113c14, size 50 bytes
// Doc: rf_reg_check [rf]: Invoke RF helper with opcode 6 and check 0xff0000 result
// rf_reg_check [rf]: Invoke RF helper with opcode 6 and check 0xff0000 result
int  rf_reg_check(int a1)
{
  unsigned int v2; // r0
  char v3; // r1
  int v4; // r4

  v2 = sub_113A44(6u);
  if ( (v2 & 0xFF0000) == 0 )
  {
    v3 = 16;
    v4 = 1;
LABEL_3:
    host_reg_wait_set(6u, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( !HIBYTE(v2) )
  {
    v3 = 24;
    goto LABEL_3;
  }
  return -1;
}

