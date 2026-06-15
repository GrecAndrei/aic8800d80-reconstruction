// v23 annotated: sub_12B18C @ 0x12b18c
// Original: 12b18c_sub_12B18C.c
// Primary struct: <unclustered>
//
// sub_12B18C @ 0x12b18c, size 138 bytes
int sub_12B18C()
{
  int v0; // r0
  int v1; // r2
  _BYTE *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( sub_12D0B0(2) != 3 )
  {
    v0 = sub_12D0B0(2);
    sub_12ECB0(dword_12B218, v0, v1);
  }
  if ( **(__int16 **)off_12B21C < 0 && sub_12D0B0(2) != 3 )
    sub_12F694(dword_12B228, dword_12B224, 201);
  v2 = off_12B220;
  v3 = *(_DWORD *)off_12B220;
  v4 = *(unsigned __int8 *)(*(_DWORD *)off_12B220 + 367);
  v5 = (unsigned __int8)(*((_BYTE *)off_12B220 + 10) + 1);
  *((_BYTE *)off_12B220 + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    sub_12CC60(v3 - 12);
    v6 = *((unsigned __int16 *)v2 + 4);
    if ( v2[11] )
    {
      sub_12B708(0, v6);
      v2[11] = 0;
    }
    else
    {
      sub_12CC38(2050, v6, 2, (unsigned __int8)v2[11]);
    }
    sub_12CF5C(2);
    return 0;
  }
  else
  {
    sub_12B3C8();
    return 0;
  }
}

