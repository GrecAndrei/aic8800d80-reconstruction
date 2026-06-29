// fwstruct annotate: 13aaf4_sub_13AAF4.c
// sub_13AAF4 @ 0x13aaf4, size 106 bytes
// Doc: sub_123AAF4 [mac]: Process descriptor fields and prepare output buffers
// sub_123AAF4 [mac]: Process descriptor fields and prepare output buffers
int __fastcall sub_13AAF4(int a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r1
  int *v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2

  feature_guard_check(
    32,
    dword_13AB60,
    *(unsigned __int16 *)(a1 + 32),
    *(unsigned __int16 *)(a1 + 30),
    *(unsigned __int8 *)(a1 + 27));
  v6 = *(unsigned __int16 *)(a1 + 30);
  v7 = v6 << 31;
  if ( (v6 & 1) != 0 || (counter_increment_n1f8(), (*(_WORD *)(a1 + 30) & 1) != 0) )
    msg_parse(dword_13AB64, v7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_13AB68 = 1;
  }
  v8 = (int *)off_13AB6C;
  ++*(_DWORD *)off_13AB6C;
  result = sub_117F18(a1, a3, a2);
  if ( *v8 )
  {
    v10 = *v8 - 1;
    v11 = *(_DWORD *)off_13AB68;
    *v8 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

