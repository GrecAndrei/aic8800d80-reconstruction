// fwstruct annotate: 10ca3c_sub_10CA3C.c
// sub_10CA3C @ 0x10ca3c, size 86 bytes
// Doc: sub_120CA3C [util]: Loads fw state struct and reads field at offset 0x224
// sub_120CA3C [util]: Loads fw state struct and reads field at offset 0x224
int sub_10CA3C()
{
  _DWORD *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = off_10CA94;
  while ( !*(_DWORD *)off_10CA94 )
    ;
  if ( *(_DWORD *)(*(_DWORD *)off_10CA98 + 548) )
  {
    v1 = sub_12D4F8(*(_DWORD *)off_10CA98 + 548);
    v2 = **(__int16 **)off_10CA9C;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(__int16 **)off_10CA9C;
    *(_DWORD *)off_10CA94 = 1;
    if ( v4 >= 0 )
      return 20;
  }
  sub_12F694(dword_10CAA4, dword_10CAA0, 1101);
  return 20;
}

