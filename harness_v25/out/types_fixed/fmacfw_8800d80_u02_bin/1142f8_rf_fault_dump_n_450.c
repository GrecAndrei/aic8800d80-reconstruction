// rf_fault_dump_n_450 @ 0x1142f8, size 24 bytes
// Doc: rf_fault_dump_n_450 [rf]: RF fault dump handler clearing fault structure fields
// rf_fault_dump_n_450 [rf]: RF fault dump handler clearing fault structure fields
int __fastcall rf_fault_dump_n_450(int a1)
{
  _DWORD *v1; // r2
  _WORD *v2; // r1

  v1 = rf_fault_dump_n_438;
  v2 = rf_fault_dump_n_434;
  *((_DWORD *)rf_fault_dump_n_438 + 2) = a1;
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *v1 = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v2 + 0x18) = 0;
  return 1;
}

