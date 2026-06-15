// v23 annotated: sub_126104 @ 0x126104
// Original: 126104_sub_126104.c
// Primary struct: <unclustered>
//
// sub_126104 @ 0x126104, size 94 bytes
// Doc: patch_apply_nc4 [patch]: Applies RF register patch (sets 0xf00000 bit mask and writes value)
// patch_apply_nc4 [patch]: Applies RF register patch (sets 0xf00000 bit mask and writes value)
int sub_126104()
{
  int v1; // r4
  int v2; // [sp+Ch] [bp-14h] BYREF
  unsigned __int16 v3; // [sp+10h] [bp-10h]
  unsigned __int16 v4; // [sp+12h] [bp-Eh]
  unsigned __int8 v5; // [sp+14h] [bp-Ch]

  if ( (*(_DWORD *)off_126164 & 0x2000000) != 0 )
    return 0;
  sub_100200(&v2, 0, 0xAu);
  v1 = sub_114880((int)&v2);
  msg_parse(dword_126168, v1);
  if ( v1 )
    msg_parse(dword_12616C);
  else
    msg_parse(dword_126170, (unsigned __int16)v2, HIWORD(v2), v3, v4, v5);
  return 0;
}

