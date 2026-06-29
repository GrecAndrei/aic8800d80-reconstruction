// fwstruct annotate: 11a6a8_sub_11A6A8.c
// sub_11A6A8 @ 0x11a6a8, size 68 bytes
int __fastcall sub_11A6A8(int result)
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
    *(_DWORD *)off_11A6EC = 1;
  }
  v1 = (int *)off_11A6F4;
  v2 = dword_11A6F0 + 84 * result;
  v3 = *(unsigned __int8 *)(v2 + 80);
  v4 = *(_DWORD *)off_11A6F4 + 1;
  *(_DWORD *)off_11A6F4 = v4;
  if ( !v3 && *(_DWORD *)(v2 + 44) )
  {
    result = sub_119D88(result);
    v4 = *v1;
  }
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = *(_DWORD *)off_11A6EC;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

