// v23 annotated: sub_11ECB8 @ 0x11ecb8
// Original: 11ecb8_sub_11ECB8.c
// Primary struct: <unclustered>
//
// sub_11ECB8 @ 0x11ecb8, size 134 bytes
// Doc: sub_121ECB8 [ipc]: Initializes shared buffer pointers and calls allocator
// sub_121ECB8 [ipc]: Initializes shared buffer pointers and calls allocator
int sub_11ECB8()
{
  _DWORD *v0; // r4
  int *v1; // r5
  int v2; // r1
  int v3; // r2
  _DWORD *v4; // r3
  int v5; // r1
  int result; // r0
  int v7; // r2
  _DWORD *v8; // r2
  _DWORD *v9; // r3
  _DWORD _0[10]; // [sp+0h] [bp-18h] BYREF

  clear_flags(16);
  v0 = off_11ED40;
  v1 = (int *)off_11ED44;
  v2 = 0;
  while ( (*v0 & 8) == 0 )
  {
    v3 = *v1;
    *v0 |= 1u;
    if ( v3 )
    {
      v9 = &_0[v2 + 6];
      v2 = (unsigned __int8)(v2 + 1);
      *(v9 - 6) = v3;
      if ( v2 == 4 || (*v0 & 8) != 0 )
      {
        _0[4] = 0;
        _0[5] = v2;
        sub_11EC94((int)_0);
        v2 = 0;
      }
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11ED48 = 1;
  }
  v4 = off_11ED4C;
  v5 = *(_DWORD *)off_11ED4C;
  result = *(unsigned __int8 *)off_11ED50;
  v7 = *(_DWORD *)off_11ED4C + 1;
  *(_DWORD *)off_11ED4C = v7;
  if ( result )
  {
    result = *(_DWORD *)off_11ED54 | 0x1000;
    *(_DWORD *)off_11ED54 = result;
  }
  if ( v7 )
  {
    v8 = off_11ED48;
    *v4 = v5;
    if ( !v5 )
    {
      if ( *v8 )
        __enable_irq();
    }
  }
  return result;
}

