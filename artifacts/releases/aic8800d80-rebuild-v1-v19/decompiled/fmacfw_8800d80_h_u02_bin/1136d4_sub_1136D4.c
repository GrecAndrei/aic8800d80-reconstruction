// sub_1136D4 @ 0x1136d4, size 124 bytes
int sub_1136D4()
{
  void *v0; // r7
  int result; // r0
  _WORD *v2; // r9
  _WORD *v3; // r6
  int v4; // r8
  int v5; // r11
  __int16 **v6; // r10
  unsigned __int16 v7; // r5
  unsigned int v8; // r1
  int v9; // r2

  v0 = off_113750;
  result = sub_12D100(dword_113754);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = off_113764;
    v3 = off_113758;
    v4 = dword_113768;
    v5 = dword_11376C;
    v6 = (__int16 **)off_113770;
    v7 = 0;
    do
    {
      if ( !sub_10F9E8(v4, (unsigned __int16)(v2[153] - 4)) )
      {
        sub_12E948(v5, v7, v9);
        if ( **v6 < 0 )
          sub_12F32C(dword_113760, dword_11375C, 495);
      }
      result = sub_12D108(dword_113754);
      v8 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

