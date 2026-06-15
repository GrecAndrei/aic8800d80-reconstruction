// v23 annotated: sub_124E34 @ 0x124e34
// Original: 124e34_sub_124E34.c
// Primary struct: <unclustered>
//
// sub_124E34 @ 0x124e34, size 96 bytes
int __fastcall sub_124E34(int a1)
{
  int *v1; // r4
  void *v2; // r5
  bool v3; // zf
  int result; // r0
  int v5; // r3
  int v6; // r2
  _DWORD *v7; // r3
  int v8; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_124E94 = 1;
  }
  v1 = (int *)off_124E98;
  v2 = off_124E9C;
  v3 = *(_DWORD *)off_124E9C == a1;
  ++*(_DWORD *)off_124E98;
  if ( v3 )
  {
    result = sub_12D2D0(v2);
    v7 = off_124EA0;
    if ( *(_DWORD *)v2 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)v2 + 12);
      result = 0x40000;
      *((_DWORD *)off_124EA0 + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((_DWORD *)off_124EA0 + 2) = 1024;
    }
  }
  else
  {
    result = sub_12D2E8(v2, a1);
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(_DWORD *)off_124E94;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

