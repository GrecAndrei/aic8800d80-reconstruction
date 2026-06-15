// v23 annotated: sub_12F2C8 @ 0x12f2c8
// Original: 12f2c8_sub_12F2C8.c
// Primary struct: <unclustered>
//
// sub_12F2C8 @ 0x12f2c8, size 82 bytes
int __fastcall sub_12F2C8(int a1, int a2, int a3)
{
  int *v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F31C = 1;
  }
  v4 = (int *)off_12F320;
  v5 = dword_12F324;
  ++*(_DWORD *)off_12F320;
  result = sub_12E948(v5, a1, a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F328 >= 0 )
  {
    sub_12B9E0();
    result = sub_12CFC4(0x80000000);
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_12F31C;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

