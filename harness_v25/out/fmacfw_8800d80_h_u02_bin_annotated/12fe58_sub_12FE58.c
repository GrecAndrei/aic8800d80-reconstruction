// fwstruct annotate: 12fe58_sub_12FE58.c
// sub_12FE58 @ 0x12fe58, size 94 bytes
int sub_12FE58()
{
  int *v0; // r4
  _DWORD *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  sub_10D634();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12FEB8 = 1;
  }
  v0 = (int *)off_12FEBC;
  v1 = (_DWORD *)dword_12FEC0;
  ++*(_DWORD *)off_12FEBC;
  sub_12D100(v1);
  sub_12D100((_DWORD *)dword_12FEC4);
  sub_12D108(dword_12FEC0, (_DWORD *)dword_12FEC8);
  sub_12D108(dword_12FEC0, (_DWORD *)dword_12FECC);
  sub_12D108(dword_12FEC0, (_DWORD *)dword_12FED0);
  result = sub_12D108(dword_12FEC0, (_DWORD *)dword_12FED4);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_12FEB8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

