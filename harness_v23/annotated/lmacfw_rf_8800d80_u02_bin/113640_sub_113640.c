// v23 annotated: sub_113640 @ 0x113640
// Original: 113640_sub_113640.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_113640 @ 0x113640, size 64 bytes
int sub_113640()
{
  int v0; // r0
  _DWORD *v1; // r4
  int result; // r0

  v0 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_113680 + 2) + 16))(*((_DWORD *)off_113680 + 1));
  if ( !v0 )
    return sub_10DA6C(dword_11368C);
  v1 = (_DWORD *)v0;
  result = sub_112C20(*(_DWORD *)off_113684 + v0, *(_DWORD *)off_113688);
  if ( result < 0 )
  {
    sub_10FEF8(v1);
    return sub_10DA6C(dword_113690);
  }
  return result;
}

