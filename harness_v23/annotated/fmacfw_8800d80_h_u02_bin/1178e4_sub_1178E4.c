// v23 annotated: sub_1178E4 @ 0x1178e4
// Original: 1178e4_sub_1178E4.c
// Primary struct: <unclustered>
//
// sub_1178E4 @ 0x1178e4, size 130 bytes
void sub_1178E4()
{
  int *v0; // r9
  _DWORD *v1; // r7
  _BYTE *v2; // r8
  _DWORD *v3; // r5
  _BYTE *v4; // r6
  int i; // r4
  int v6; // r3
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117968 = 1;
  }
  v0 = (int *)off_117970;
  v1 = off_11796C;
  v2 = off_117974;
  ++*(_DWORD *)off_117970;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((_BYTE *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((unsigned __int8 *)v1 + 190) != (unsigned __int8)i)
      && *((_DWORD *)v4 + 84) )
    {
      sub_116DF4((unsigned __int8)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  v6 = *v0;
  v2[511] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(_DWORD *)off_117968;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
}

