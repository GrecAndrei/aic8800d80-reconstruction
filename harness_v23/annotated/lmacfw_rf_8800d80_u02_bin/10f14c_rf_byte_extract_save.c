// v23 annotated: rf_byte_extract_save @ 0x10f14c
// Original: 10f14c_rf_byte_extract_save.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// rf_byte_extract_save @ 0x10f14c, size 12 bytes
// Doc: rf_byte_extract_save [rf]: Extracts high byte and saves to stack
// rf_byte_extract_save [rf]: Extracts high byte and saves to stack
int rf_byte_extract_save()
{
  return sub_10F064(dword_10F158, 0, 2, 1);
}

