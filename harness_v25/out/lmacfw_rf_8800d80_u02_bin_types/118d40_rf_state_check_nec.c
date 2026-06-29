// rf_state_check_nec @ 0x118d40, size 118 bytes
// Doc: rf_state_check_nec [rf]: Check RF state and clear bits 0x10 in control regs 0x810/0x814
// rf_state_check_nec [rf]: Check RF state and clear bits 0x10 in control regs 0x810/0x814
unsigned int  rf_state_check_nec(int *a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r7
  uint32_t *v3; // r4
  uint32_t *v4; // r1
  uint32_t *v5; // r6
  uint32_t *v6; // r5
  int v7; // r7
  int v8; // r0
  __int16 **v9; // r0
  int *v10; // r4
  int v11; // r2
  __int16 *v12; // r3

  v1 = off_118DB8;
  v2 = off_118DBC;
  v3 = off_118DC0;
  v4 = off_118DC4;
  v5 = off_118DC8;
  v6 = off_118DCC;
  *(uint32_t *)off_118DB8 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((unsigned __int16 *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (__int16 **)off_118DD0;
  v10 = (int *)off_118DD4;
  v11 = dword_118DD8;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(uint32_t *)off_118DE0 << 28 )
  {
    sub_1219F4(dword_118DE8, dword_118DE4, 472);
    v11 = *v10;
  }
  *(uint32_t *)off_118DDC = v11 | v10[1];
  return sub_1174B8(0);
}

