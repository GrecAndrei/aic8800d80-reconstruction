// v23 annotated: rf_fault_dump_n_1ec @ 0x11455c
// Original: 11455c_rf_fault_dump_n_1ec.c
// Primary struct: <unclustered>
//
// rf_fault_dump_n_1ec @ 0x11455c, size 6 bytes
// Doc: rf_fault_dump_n_1ec [rf]: RF fault dump entry referencing fault table
// rf_fault_dump_n_1ec [rf]: RF fault dump entry referencing fault table
int __fastcall rf_fault_dump_n_1ec(int a1, int a2, int a3)
{
  return msg_parse(rf_fault_dump_564, a2, a3);
}

