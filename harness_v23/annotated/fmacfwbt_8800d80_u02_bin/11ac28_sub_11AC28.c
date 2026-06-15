// v23 annotated: sub_11AC28 @ 0x11ac28
// Original: 11ac28_sub_11AC28.c
// Primary struct: <unclustered>
//
// sub_11AC28 @ 0x11ac28, size 68 bytes
// Doc: sub_121ac28 [unknown]: Unknown helper with push and shifted value setup
// sub_121ac28 [unknown]: Unknown helper with push and shifted value setup
int __fastcall sub_11AC28(int result)
{
  int *v1; // r4
  int v2; // r2
  int v3; // r1
  int v4; // r3
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11AC6C = 1;
  }
  v1 = (int *)off_11AC74;
  v2 = dword_11AC70 + 84 * result;
  v3 = *(unsigned __int8 *)(v2 + 80);
  v4 = *(_DWORD *)off_11AC74 + 1;
  *(_DWORD *)off_11AC74 = v4;
  if ( !v3 && *(_DWORD *)(v2 + 44) )
  {
    result = sub_11A308(result);
    v4 = *v1;
  }
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = *(_DWORD *)off_11AC6C;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

