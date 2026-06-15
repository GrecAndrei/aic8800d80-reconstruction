// v23 annotated: sub_1017E0 @ 0x1017e0
// Original: 1017e0_sub_1017E0.c
// Primary struct: <unclustered>
//
// sub_1017E0 @ 0x1017e0, size 24 bytes
int __fastcall sub_1017E0(int result, int a2, int a3)
{
  if ( (*(_DWORD *)off_1017F8 & 8) != 0 )
  {
    result = mmio_reg_read_pair(result, a2, a3, *(_DWORD *)off_1017F8 << 28);
    *(_DWORD *)off_1017FC = 8;
  }
  return result;
}

