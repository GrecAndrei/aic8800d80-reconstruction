// v23 annotated: sub_12D658 @ 0x12d658
// Original: 12d658_sub_12D658.c
// Primary struct: mmio_clock_gate (cluster 1, 23 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_12D658 @ 0x12d658, size 48 bytes
_DWORD *__fastcall sub_12D658(_DWORD *result, _DWORD *a2)
{
  _DWORD *v3; // r1
  _DWORD *v4; // r2
  int v5; // r1

  v3 = (_DWORD *)*a2;
  if ( v3 )
  {
    v4 = result;
    if ( *result )
    {
      result = (_DWORD *)a2[1];
      *(_DWORD *)v4[1] = v3;
      v4[1] = result;
    }
    else
    {
      result = (_DWORD *)*a2;
      v5 = a2[1];
      *v4 = *a2;
      v4[1] = v5;
    }
    *a2 = 0;
  }
  return result;
}

