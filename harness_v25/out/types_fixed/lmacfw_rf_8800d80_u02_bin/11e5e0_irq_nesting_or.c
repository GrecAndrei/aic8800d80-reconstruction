// irq_nesting_or @ 0x11e5e0, size 52 bytes
// Doc: irq_nesting_or [util]: Set/clear IRQ nesting bit via OR mask
// irq_nesting_or [util]: Set/clear IRQ nesting bit via OR mask
int __fastcall irq_nesting_or(int a1)
{
  _DWORD *v1; // r2
  int *v2; // r5
  int v3; // r1
  int v4; // r4
  int result; // r0
  int *v6; // r3
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11E614 = 1;
  }
  v1 = off_11E618;
  v2 = (int *)off_11E61C;
  v3 = *(_DWORD *)off_11E618;
  v4 = *(_DWORD *)off_11E618 + 1;
  result = a1 | *(_DWORD *)off_11E61C;
  *(_DWORD *)off_11E618 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (int *)off_11E614;
    *v1 = v3;
    v7 = *v6;
    if ( !v3 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

