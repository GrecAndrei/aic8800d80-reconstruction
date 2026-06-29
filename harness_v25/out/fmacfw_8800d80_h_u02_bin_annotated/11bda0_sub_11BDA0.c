// fwstruct annotate: 11bda0_sub_11BDA0.c
// sub_11BDA0 @ 0x11bda0, size 174 bytes
int sub_11BDA0()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r7
  int v3; // r5
  char v4; // r8
  char *v5; // r3
  _DWORD *v6; // r2
  int result; // r0
  char v8; // r1
  int v9; // r3
  int v10; // r1
  void *v11; // r0
  _DWORD v12[28]; // [sp+0h] [bp-90h] BYREF
  char v13; // [sp+70h] [bp-20h] BYREF

  v0 = off_11BE50;
  v1 = *((_DWORD *)off_11BE50 + 1);
  if ( v1 )
  {
    v2 = *((_DWORD *)off_11BE50 + 2);
    sub_124CF4(off_11BE50);
    v3 = v0[4];
    if ( v3 )
      goto LABEL_3;
  }
  else
  {
    v3 = *((_DWORD *)off_11BE50 + 4);
    v2 = 0;
    if ( v3 )
    {
LABEL_3:
      sub_143630(v12, dword_11BE54, 144);
      v4 = *((_BYTE *)v0 + 160);
      if ( v12[1] )
        sub_124CF4(dword_11BE54);
      if ( v12[8] )
        sub_124CF4(dword_11BE58);
      if ( v12[15] )
        sub_124CF4(dword_11BE5C);
      if ( v12[22] )
        sub_124CF4(dword_11BE60);
      sub_11BC48();
      v0[4] = v3;
      *((_BYTE *)v0 + 160) = v4;
      v0 = off_11BE50;
      v5 = (char *)v12;
      v6 = off_11BE50;
      do
      {
        result = *((_DWORD *)v5 + 5);
        v8 = v5[24];
        v6[10] = result;
        v5 += 28;
        *((_BYTE *)v6 + 44) = v8;
        v6 += 7;
      }
      while ( &v13 != v5 );
      if ( v1 )
        goto LABEL_14;
      return result;
    }
  }
  result = sub_11BC48();
  v0[4] = v3;
  if ( v1 )
  {
LABEL_14:
    v9 = dword_11BE68;
    v10 = *((_DWORD *)off_11BE64 + 4);
    v11 = off_11BE50;
    v0[2] = v2;
    v0[1] = v9;
    return sub_124BFC(v11, v10 + 5000);
  }
  return result;
}

