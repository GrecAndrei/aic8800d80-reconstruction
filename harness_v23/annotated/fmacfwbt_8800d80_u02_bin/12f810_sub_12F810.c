// v23 annotated: sub_12F810 @ 0x12f810
// Original: 12f810_sub_12F810.c
// Primary struct: ipc_shared_buf (cluster 13, 4 funcs)
// Fields: ptr=0x0, state=0x1f8
//
// sub_12F810 @ 0x12f810, size 78 bytes
int __fastcall sub_12F810(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F860 = 1;
  }
  v2 = (int *)off_12F864;
  ++*(_DWORD *)off_12F864;
  result = sub_116484();
  if ( a1 <= 4 )
    --*(_BYTE *)(dword_12F868 + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(_DWORD *)off_12F860;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  --*((_DWORD *)off_12F86C + 126);
  return result;
}

