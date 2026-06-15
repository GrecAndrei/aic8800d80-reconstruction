// sub_1246F0 @ 0x1246f0, size 152 bytes
int __fastcall sub_1246F0(int a1, int a2)
{
  _BYTE *v3; // r6
  int *v4; // r5
  int v5; // r3
  int v6; // r2
  _DWORD *v7; // r5
  int v8; // r4

  if ( (*(_DWORD *)off_124788 & 2) != 0 && (*(_BYTE *)a2 == 1 || *(unsigned __int16 *)(a2 + 4) > 0x1387u) )
  {
    sub_11F504(dword_1247A0);
    return -1;
  }
  else
  {
    v3 = off_12478C;
    if ( !*(_BYTE *)off_12478C )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_124790 = 1;
      }
      v4 = (int *)off_124794;
      ++*(_DWORD *)off_124794;
      sub_11D348();
      sub_115E98();
      if ( *v4 )
      {
        v5 = *v4 - 1;
        v6 = *(_DWORD *)off_124790;
        *v4 = v5;
        if ( !v5 )
        {
          if ( v6 )
            __enable_irq();
        }
      }
    }
    v7 = off_12479C;
    ++*(_BYTE *)off_124798;
    *v7 |= 0x500000u;
    sub_102908((unsigned __int8 *)a2, 0);
    *v7 &= 0xFF87FFFF;
    v8 = (unsigned __int8)*v3;
    if ( *v3 )
    {
      return 0;
    }
    else
    {
      sub_1188F4();
      sub_12466C();
      return v8;
    }
  }
}

