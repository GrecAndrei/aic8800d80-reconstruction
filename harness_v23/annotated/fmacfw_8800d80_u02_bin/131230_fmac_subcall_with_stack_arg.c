// v23 annotated: fmac_subcall_with_stack_arg @ 0x131230
// Original: 131230_fmac_subcall_with_stack_arg.c
// Primary struct: <unclustered>
//
// fmac_subcall_with_stack_arg @ 0x131230, size 40 bytes
// Doc: fmac_subcall_with_stack_arg [mac]: Prepare stack argument and call helper at 0x12df38
// fmac_subcall_with_stack_arg [mac]: Prepare stack argument and call helper at 0x12df38
unsigned __int8 *__fastcall fmac_subcall_with_stack_arg(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = sdio_buffer_prepare_n_1e4(a1, a2, &v5);
  if ( result )
    *(_DWORD *)(a3 + 220) = *(_DWORD *)(result + 3);
  else
    *(_DWORD *)(a3 + 220) = 0x80000000;
  return result;
}

