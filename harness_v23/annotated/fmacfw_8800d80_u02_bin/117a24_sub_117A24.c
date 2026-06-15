// v23 annotated: sub_117A24 @ 0x117a24
// Original: 117a24_sub_117A24.c
// Primary struct: <unclustered>
//
// sub_117A24 @ 0x117a24, size 130 bytes
// Doc: sub_1217A24 [util]: Utility/state helper (prologue, shifts and transforms 3 args, 0x10 bytes)
// sub_1217A24 [util]: Utility/state helper (prologue, shifts and transforms 3 args, 0x10 bytes)
void sub_117A24()
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
    *(_DWORD *)off_117AA8 = 1;
  }
  v0 = (int *)off_117AB0;
  v1 = off_117AAC;
  v2 = off_117AB4;
  ++*(_DWORD *)off_117AB0;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((_BYTE *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((unsigned __int8 *)v1 + 190) != (unsigned __int8)i)
      && *((_DWORD *)v4 + 84) )
    {
      rf_set_bit_flag((unsigned __int8)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  v6 = *v0;
  v2[511] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(_DWORD *)off_117AA8;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
}

