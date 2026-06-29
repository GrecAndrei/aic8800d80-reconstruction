// fwstruct annotate: 127aec_buf_release_and_dispatch.c
// buf_release_and_dispatch @ 0x127aec, size 38 bytes
// Doc: buf_release_and_dispatch [util]: Releases object at offset 0x58 then dispatches a task via outer call
// buf_release_and_dispatch [util]: Releases object at offset 0x58 then dispatches a task via outer call
int __fastcall buf_release_and_dispatch(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = sub_121BE4(*(_DWORD *)(a1 + 88));
  *(_DWORD *)(a1 + 88) = v2;
  result = rf_bus_reset_n_1b2_acf8(a1, v2);
  *(_BYTE *)(a1 + 85) = *(_BYTE *)(a1 + 85) & 0x9F | 0x20;
  return result;
}

