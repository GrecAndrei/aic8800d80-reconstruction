// v23 annotated: sub_12D6EC @ 0x12d6ec
// Original: 12d6ec_sub_12D6EC.c
// Primary struct: bt_hci_cmd (cluster 4, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12D6EC @ 0x12d6ec, size 100 bytes
unsigned __int8 *__fastcall sub_12D6EC(unsigned __int8 *a1, int a2, int a3, _WORD *a4)
{
  unsigned int v4; // r7
  unsigned int v5; // r12
  int v6; // r6
  int v7; // r4
  unsigned __int8 *v8; // r5

  v4 = (unsigned int)&a1[a2];
  v5 = (unsigned int)&a1[a2];
  if ( a1 < &a1[a2] )
  {
    while ( 1 )
    {
      v8 = a1;
      if ( v4 <= (unsigned int)(a1 + 1) )
        break;
      v6 = *a1;
      v7 = a1[1] + 2;
      a1 += v7;
      if ( v6 == 255 )
      {
        if ( v4 < (unsigned int)a1 )
          return nullptr;
        *a4 = v7;
        if ( !v8 || (unsigned int)(v8 + 3) > v5 )
          return nullptr;
        if ( v8[2] == a3 )
          return v8;
        a2 = (unsigned __int16)(a2 - v7);
        if ( v5 <= (unsigned int)a1 )
          goto LABEL_13;
        v4 = (unsigned int)&a1[a2];
      }
    }
  }
  else
  {
LABEL_13:
    if ( **(__int16 **)off_12D750 < 0 && (unsigned __int8 *)v5 != a1 )
      sub_12F35C(dword_12D758, dword_12D754, 127);
  }
  return nullptr;
}

