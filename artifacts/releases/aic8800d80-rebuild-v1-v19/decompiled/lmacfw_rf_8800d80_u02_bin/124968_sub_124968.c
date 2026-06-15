// sub_124968 @ 0x124968, size 128 bytes
int sub_124968()
{
  int *v0; // r6
  _DWORD *v1; // r4
  _DWORD *v2; // r5
  int v3; // r7
  void *v4; // r1
  int v5; // r3
  int v6; // r2

  if ( *(_DWORD *)off_1249E8 << 28 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_124A00 = 1;
    }
    v0 = (int *)off_1249EC;
    v1 = off_1249E8;
    v2 = off_1249F0;
    ++*(_DWORD *)off_1249EC;
    *v1 = 0;
    v3 = v2[4];
    while ( *v1 << 28 )
    {
      if ( (unsigned int)(v2[4] - v3) > 0x7530 )
        sub_11F504(dword_124A0C, *v1 << 28, 30000);
    }
    v4 = off_1249F8;
    while ( (*(_DWORD *)off_1249F8 & *(_DWORD *)off_1249F4 & 4) == 0 )
      ;
    *(_DWORD *)off_1249FC = 4;
    if ( *v0 )
    {
      v5 = *v0 - 1;
      v6 = *(_DWORD *)off_124A00;
      *v0 = v5;
      if ( !v5 )
      {
        if ( v6 )
          __enable_irq();
      }
    }
    sub_11F504(dword_124A04, v4);
  }
  sub_11F504(dword_124A08);
  return 0;
}

