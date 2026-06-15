// sub_11EABC @ 0x11eabc, size 132 bytes
void sub_11EABC()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r6
  int v2; // r3
  int v3; // r7
  int v4; // r3
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r2

  v0 = off_11EB40;
  v1 = off_11EB44;
  v2 = *((_DWORD *)off_11EB40 + 5);
  if ( v2 != *(_DWORD *)off_11EB44 )
  {
    v3 = dword_11EB48;
    do
    {
      v7 = v2 & 0x7FFFFFFF;
      v8 = v0[4] - (v2 & 0x7FFFFFFF);
      v9 = v2 & 0x80000000;
      if ( v8 > 0x9F )
      {
        v4 = v0[5];
      }
      else
      {
        v10 = v0[3];
        if ( v7 > v10 )
          v9 += 0x80000000;
        v4 = v9 | v10;
        v0[5] = v4;
      }
      v5 = v4 & 0x7FFFFFFF;
      v6 = *(_DWORD *)((v4 & 0x7FFFFFFF) + 0x14);
      if ( v6 != v3 )
        sub_12E948(dword_11EB4C, v4 & 0x7FFFFFFF, v6);
      sub_11E9F4(v5);
      *(_BYTE *)(v5 + 156) = 1;
      sub_11DFC0(v5);
      v2 = v0[5];
    }
    while ( v2 != *v1 );
  }
}

