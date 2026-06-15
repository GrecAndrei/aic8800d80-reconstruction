// v23 annotated: sub_1329B0 @ 0x1329b0
// Original: 1329b0_sub_1329B0.c
// Primary struct: <unclustered>
//
// sub_1329B0 @ 0x1329b0, size 128 bytes
int __fastcall sub_1329B0(unsigned __int8 *a1, int a2)
{
  int v2; // r11
  __int16 **v3; // r8
  int v4; // r10
  int v5; // r9
  unsigned __int8 *v8; // r4
  int v9; // r7
  char v10; // r0
  int v11; // r0

  v2 = *a1;
  if ( *a1 )
  {
    v3 = (__int16 **)off_132A30;
    v4 = dword_132A34;
    v5 = dword_132A38;
    v8 = a1;
    v9 = 0;
    while ( 1 )
    {
      if ( a2 )
      {
        v10 = v8[1];
        if ( v10 >= 0 )
          goto LABEL_7;
      }
      else
      {
        v10 = v8[1];
      }
      v11 = sub_132910(v10);
      if ( **v3 < 0 )
        break;
      if ( v11 <= 11 )
        goto LABEL_12;
LABEL_7:
      if ( ++v8 - a1 >= v2 )
        return v9;
    }
    if ( v11 > 11 )
    {
      sub_12F6C4(v5, v4, 598);
      v2 = *a1;
      goto LABEL_7;
    }
LABEL_12:
    v9 = (unsigned __int16)(v9 | (1 << v11));
    goto LABEL_7;
  }
  return *a1;
}

