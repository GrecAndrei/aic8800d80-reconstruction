// v23 annotated: sub_11394C @ 0x11394c
// Original: 11394c_sub_11394C.c
// Primary struct: <unclustered>
//
// sub_11394C @ 0x11394c, size 190 bytes
void __noreturn sub_11394C()
{
  void *v0; // r5
  int v1; // r4
  unsigned int CPSR; // r1
  unsigned int v3; // r5
  unsigned int v4; // r4
  int v5; // r1
  int v6; // r1
  int v7; // r1
  int f594; // r0
  unsigned int v9; // r4
  unsigned int v10; // r5
  int v11; // r1

  v0 = off_113A0C;
  v1 = *(_DWORD *)(*(_DWORD *)off_113A0C + 16);
  msg_parse(dword_113A18, v1);
  if ( (v1 & 1) != 0 )
    *(_DWORD *)(*(_DWORD *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  __get_CPSR();
  v3 = __get_CPSR();
  v4 = __get_CPSR();
  __get_CPSR();
  msg_parse(dword_113A1C, CPSR);
  if ( v3 )
  {
    msg_parse(dword_113A38, v5);
    if ( !v4 )
      goto LABEL_5;
  }
  else if ( !v4 )
  {
    goto LABEL_5;
  }
  v9 = v4 & 0xFFFFFFF0;
  v10 = (dword_113A3C - v9) >> 2;
  msg_parse(dword_113A40, v5);
  v11 = v10;
  if ( v10 >= 0x100 )
    v11 = 256;
  rf_mem_read_f594(v9, v11, 4, 0);
LABEL_5:
  msg_parse(dword_113A20, v5);
  rf_mem_read_f594(dword_113A24, 8, 4, 0);
  msg_parse(dword_113A28, v6);
  rf_mem_read_f594(dword_113A2C, 8, 4, 0);
  msg_parse(dword_113A30, v7);
  f594 = rf_mem_read_f594(dword_113A34, 16, 4, 0);
  rf_state_check_n_e90(f594);
}

