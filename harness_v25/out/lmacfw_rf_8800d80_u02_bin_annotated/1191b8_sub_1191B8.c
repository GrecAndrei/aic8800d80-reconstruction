// fwstruct annotate: 1191b8_sub_1191B8.c
// sub_1191B8 @ 0x1191b8, size 94 bytes
int __fastcall sub_1191B8(_BYTE *a1, int a2)
{
  int v2; // r3
  int result; // r0
  char v5; // r2
  int v6; // r6
  char v7; // r5
  _BYTE *v8; // r0

  v2 = (char)a1[118];
  result = (char)a1[117];
  v5 = a1[119];
  v6 = (unsigned __int8)a1[120];
  a1[117] = a2;
  if ( v2 )
  {
    v7 = a2;
    if ( v6 )
    {
      if ( v6 != 1 || result >= a2 || a2 <= v2 + v5 )
        goto LABEL_7;
      LOBYTE(v6) = 0;
    }
    else
    {
      if ( result <= a2 || a2 >= v2 - v5 )
        goto LABEL_7;
      LOBYTE(v6) = 1;
    }
    v8 = (_BYTE *)sub_11DDF0(87, 4, 0, 3);
    *v8 = a1[95];
    v8[1] = v6;
    v8[2] = v7;
    result = sub_11DE50(v8);
LABEL_7:
    a1[120] = v6;
  }
  return result;
}

