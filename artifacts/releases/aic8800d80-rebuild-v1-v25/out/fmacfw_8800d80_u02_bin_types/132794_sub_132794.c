// sub_132794 @ 0x132794, size 128 bytes
int  sub_132794(unsigned __int8 *a1, int a2)
{
  int v2; // r11
  __int16 **v3; // r8
  int v4; // r10
  int v5; // r9
  unsigned __int8 *v8; // r4
  int v9; // r7
  int v10; // r0

  v2 = *a1;
  if ( *a1 )
  {
    v3 = (__int16 **)off_132814;
    v4 = dword_132818;
    v5 = dword_13281C;
    v8 = a1;
    v9 = 0;
    while ( 1 )
    {
      if ( a2 && (v8[1] & 0x80u) == 0 )
        goto LABEL_6;
      sub_1326F4();
      if ( **v3 < 0 )
        break;
      if ( v10 <= 11 )
        goto LABEL_11;
LABEL_6:
      if ( ++v8 - a1 >= v2 )
        return v9;
    }
    if ( v10 > 11 )
    {
      sub_12F49C(v5, v4, 598);
      v2 = *a1;
      goto LABEL_6;
    }
LABEL_11:
    v9 = (unsigned __int16)(v9 | (1 << v10));
    goto LABEL_6;
  }
  return *a1;
}

