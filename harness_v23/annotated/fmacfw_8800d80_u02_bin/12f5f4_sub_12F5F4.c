// v23 annotated: sub_12F5F4 @ 0x12f5f4
// Original: 12f5f4_sub_12F5F4.c
// Primary struct: <unclustered>
//
// sub_12F5F4 @ 0x12f5f4, size 78 bytes
int __fastcall sub_12F5F4(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F644 = 1;
  }
  v2 = (int *)off_12F648;
  ++*(_DWORD *)off_12F648;
  result = sub_116044();
  if ( a1 <= 4 )
    --*(_BYTE *)(dword_12F64C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(_DWORD *)off_12F644;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  --*((_DWORD *)off_12F650 + 126);
  return result;
}

