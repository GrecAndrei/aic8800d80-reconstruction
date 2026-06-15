// v23 annotated: sub_123FDC @ 0x123fdc
// Original: 123fdc_sub_123FDC.c
// Primary struct: <unclustered>
//
// sub_123FDC @ 0x123fdc, size 16 bytes
int __fastcall sub_123FDC(int result)
{
  *(_DWORD *)off_123FEC = *(_DWORD *)off_123FEC & 0xFC0FFFFF | (result << 20);
  return result;
}

