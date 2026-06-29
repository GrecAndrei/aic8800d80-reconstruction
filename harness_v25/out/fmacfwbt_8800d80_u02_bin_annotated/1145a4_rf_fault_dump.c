// fwstruct annotate: 1145a4_rf_fault_dump.c
// rf_fault_dump @ 0x1145a4, size 190 bytes
// Doc: rf_fault_dump [util]: Dumps RF fault context from global fault/info pointers for diagnostics
// rf_fault_dump [util]: Dumps RF fault context from global fault/info pointers for diagnostics
void __noreturn rf_fault_dump()
{
  void *v0; // r5
  int v1; // r4
  unsigned int CPSR; // r1
  unsigned int v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // r4
  int v6; // r1
  int v7; // r2
  int v8; // r1
  int v9; // r2
  int v10; // r1
  int v11; // r2
  int ed40; // r0
  unsigned int v13; // r4
  unsigned int v14; // r5
  int v15; // r1

  v0 = off_114664;
  v1 = *(_DWORD *)(*(_DWORD *)off_114664 + 16);
  sub_12ECB0(dword_114670, v1, *(_DWORD *)off_11466C);
  if ( (v1 & 1) != 0 )
    *(_DWORD *)(*(_DWORD *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v3 = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  __get_CPSR();
  sub_12ECB0(dword_114674, CPSR, v3);
  if ( v4 )
  {
    sub_12ECB0(dword_114690, v6, v7);
    if ( !v5 )
      goto LABEL_5;
  }
  else if ( !v5 )
  {
    goto LABEL_5;
  }
  v13 = v5 & 0xFFFFFFF0;
  v14 = (dword_114694 - v13) >> 2;
  sub_12ECB0(dword_114698, v6, v7);
  v15 = v14;
  if ( v14 >= 0x100 )
    v15 = 256;
  rf_mem_read_ed40(v13, v15, 4, 0);
LABEL_5:
  sub_12ECB0(dword_114678, v6, v7);
  rf_mem_read_ed40(dword_11467C, 8, 4, 0);
  sub_12ECB0(dword_114680, v8, v9);
  rf_mem_read_ed40(dword_114684, 8, 4, 0);
  sub_12ECB0(dword_114688, v10, v11);
  ed40 = rf_mem_read_ed40(dword_11468C, 16, 4, 0);
  patch_apply_n4a8_5990(ed40);
}

