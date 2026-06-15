// v23 annotated: sub_123F64 @ 0x123f64
// Original: 123f64_sub_123F64.c
// Primary struct: <unclustered>
//
// sub_123F64 @ 0x123f64, size 16 bytes
// Doc: sub_1223F64 [mmio]: Set bit 6 in MMIO register (read-modify-write)
// sub_1223F64 [mmio]: Set bit 6 in MMIO register (read-modify-write)
int __fastcall sub_123F64(int result)
{
  *(_DWORD *)off_123F74 = *(_DWORD *)off_123F74 & 0xFFFFFFBF | (result << 6);
  return result;
}

