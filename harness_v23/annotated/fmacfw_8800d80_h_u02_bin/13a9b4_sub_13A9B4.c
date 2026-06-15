// v23 annotated: sub_13A9B4 @ 0x13a9b4
// Original: 13a9b4_sub_13A9B4.c
// Primary struct: <unclustered>
//
// sub_13A9B4 @ 0x13a9b4, size 106 bytes
int __fastcall sub_13A9B4(int a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r1
  int *v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2

  sub_12EB90(
    32,
    dword_13AA20,
    *(unsigned __int16 *)(a1 + 32),
    *(unsigned __int16 *)(a1 + 30),
    *(unsigned __int8 *)(a1 + 27));
  v6 = *(unsigned __int16 *)(a1 + 30);
  v7 = v6 << 31;
  if ( (v6 & 1) != 0 || (sub_11754C(), (*(_WORD *)(a1 + 30) & 1) != 0) )
    sub_12E948(dword_13AA24, v7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_13AA28 = 1;
  }
  v8 = (int *)off_13AA2C;
  ++*(_DWORD *)off_13AA2C;
  result = sub_117DD8(a1, a3, a2);
  if ( *v8 )
  {
    v10 = *v8 - 1;
    v11 = *(_DWORD *)off_13AA28;
    *v8 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

