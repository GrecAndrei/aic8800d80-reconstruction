// sub_126F8C @ 0x126f8c, size 144 bytes
int __fastcall sub_126F8C(int result)
{
  _DWORD *v1; // r5
  int v2; // r4
  int v3; // r6
  _BYTE *v4; // r0
  int *v5; // r6
  int v6; // r3
  int v7; // r2
  _DWORD *v8; // r0

  v1 = off_12701C;
  v2 = result;
  if ( *((_DWORD *)off_12701C + 11) )
  {
    *((_DWORD *)off_12701C + 11) = result;
  }
  else
  {
    v3 = *((_DWORD *)off_12701C + 10);
    if ( v3 == result )
    {
      *(_BYTE *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(_BYTE *)(v3 + 24) != 3 )
      {
        v4 = (_BYTE *)sub_12C7EC(69, 13, 0, 1);
        *v4 = *(_BYTE *)(v3 + 24);
        sub_12C84C(v4);
      }
      if ( *((int *)off_127020 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(_DWORD *)off_127024 = 1;
        }
        v5 = (int *)off_127028;
        ++*(_DWORD *)off_127028;
        sub_116DF4(4);
        sub_11735C(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(_DWORD *)off_127024;
          *v5 = v6;
          if ( !v6 )
          {
            if ( v7 )
              __enable_irq();
          }
        }
      }
      v1[11] = v2;
      *(_BYTE *)(v2 + 16) = 2;
      v8 = (_DWORD *)sub_12C7EC(140, 0, 255, 4);
      *v8 = dword_12702C;
      return sub_12C84C(v8);
    }
  }
  return result;
}

