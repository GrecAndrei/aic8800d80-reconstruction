// v23 annotated: sub_123490 @ 0x123490
// Original: 123490_sub_123490.c
// Primary struct: <unclustered>
//
// sub_123490 @ 0x123490, size 70 bytes
unsigned __int8 *__fastcall sub_123490(unsigned __int8 *result)
{
  int v1; // r4
  _DWORD *v2; // r3
  char v3; // r2

  if ( result[1] == 192 && result[2] == 181 && result[3] == 122 )
  {
    v1 = result[4];
    if ( (unsigned __int8)(v1 + 106) <= 1u )
    {
      v2 = off_1234DC;
      *(_BYTE *)off_1234D8 = result[5];
      result = (unsigned __int8 *)sub_1264DC(*v2 + 20000);
      if ( v1 == 150 )
        v3 = 2;
      else
        v3 = 0;
      *(_BYTE *)off_1234E0 = v3;
    }
  }
  return result;
}

