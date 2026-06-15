// v23 annotated: rf_bus_write_n144 @ 0x11f4b4
// Original: 11f4b4_rf_bus_write_n144.c
// Primary struct: <unclustered>
//
// rf_bus_write_n144 @ 0x11f4b4, size 6 bytes
// Doc: rf_bus_write_n144 [rf]: Writes to RF bus with shifted index
// rf_bus_write_n144 [rf]: Writes to RF bus with shifted index
int __fastcall rf_bus_write_n144(int result)
{
  *((_DWORD *)rf_mem_read_n_d8 + 1) = result;
  return result;
}

