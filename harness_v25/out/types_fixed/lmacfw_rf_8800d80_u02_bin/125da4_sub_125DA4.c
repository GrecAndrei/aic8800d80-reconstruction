// sub_125DA4 @ 0x125da4, size 86 bytes
int sub_125DA4()
{
  int v1; // r4
  int *(_DWORD *)(v2 + 0xc); // [sp+4h] [bp-Ch] BYREF

  if ( (*(_DWORD *)off_125DFC & 0x2000000) != 0 )
    return 0;
  sub_100200(v2, 0, 4u);
  v1 = sub_114850((int)v2);
  msg_parse(dword_125E00, v1);
  if ( v1 || HIWORD(*(_DWORD *)(v2 + 0x0)) == 0xFFFF || LOWORD(*(_DWORD *)(v2 + 0x0)) == 0xFFFF )
    msg_parse(dword_125E08);
  else
    msg_parse(dword_125E04);
  return 0;
}

