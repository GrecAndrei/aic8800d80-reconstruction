// v23 annotated: bitfield_pack_n_214 @ 0x117e64
// Original: 117e64_bitfield_pack_n_214.c
// Primary struct: <unclustered>
//
// bitfield_pack_n_214 @ 0x117e64, size 130 bytes
// Doc: bitfield_pack_n_214 [util]: Pack/shift bits into a 32-bit field with sign extension
// bitfield_pack_n_214 [util]: Pack/shift bits into a 32-bit field with sign extension
void bitfield_pack_n_214()
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
    *(_DWORD *)off_117EE8 = 1;
  }
  v0 = (int *)off_117EF0;
  v1 = off_117EEC;
  v2 = off_117EF4;
  ++*(_DWORD *)off_117EF0;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((_BYTE *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((unsigned __int8 *)v1 + 190) != (unsigned __int8)i)
      && *((_DWORD *)v4 + 84) )
    {
      patch_sub_1217374((unsigned __int8)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  v6 = *v0;
  v2[511] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(_DWORD *)off_117EE8;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
}

