// v23 annotated: sub_110320 @ 0x110320
// Original: 110320_sub_110320.c
// Primary struct: <unclustered>
//
// sub_110320 @ 0x110320, size 62 bytes
// Doc: sub_1210320 [rf]: Unidentified behavioral routine in lmacfw_rf firmware
// sub_1210320 [rf]: Unidentified behavioral routine in lmacfw_rf firmware
int sub_110320()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110360 = 1;
  }
  v0 = (int *)off_110364;
  v1 = dword_110368;
  ++*(_DWORD *)off_110364;
  result = list_push_tail(v1);
  v3 = *v0;
  ++*(_DWORD *)off_11036C;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_110360;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

