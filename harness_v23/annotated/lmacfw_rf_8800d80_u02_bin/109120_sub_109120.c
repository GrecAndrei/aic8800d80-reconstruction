// v23 annotated: sub_109120 @ 0x109120
// Original: 109120_sub_109120.c
// Primary struct: group_17 (cluster 17)
//
// sub_109120 @ 0x109120, size 98 bytes
int __fastcall sub_109120(__int64 a1, int a2, _DWORD *a3)
{
  unsigned __int8 v3; // r5
  _DWORD *v4; // r6
  int v5; // r4
  _DWORD *v6; // r3

  if ( a1 )
  {
    LODWORD(a1) = HIDWORD(a1) + a1;
    if ( (_DWORD)a1 )
    {
      HIDWORD(a1) = 0;
      while ( 1 )
      {
        v3 = BYTE4(a1) + 1;
        v4 = &a3[HIDWORD(a1)];
        if ( *v4 <= a2 )
          break;
        HIDWORD(a1) = v3;
        if ( v3 >= (int)a1 )
          goto LABEL_12;
      }
      LODWORD(a1) = (unsigned __int8)a1;
      if ( (unsigned int)(unsigned __int8)a1 > HIDWORD(a1) )
      {
        v5 = (int)&a3[(unsigned __int8)a1 - 1 - (unsigned __int8)(a1 - 1 - BYTE4(a1))];
        v6 = &a3[(unsigned __int8)a1];
        do
        {
          *v6 = *(v6 - 1);
          --v6;
        }
        while ( v6 != (_DWORD *)v5 );
      }
      *v4 = a2;
    }
    else
    {
LABEL_12:
      a3[(_DWORD)a1] = a2;
    }
  }
  else
  {
    *a3 = a2;
  }
  return a1;
}

