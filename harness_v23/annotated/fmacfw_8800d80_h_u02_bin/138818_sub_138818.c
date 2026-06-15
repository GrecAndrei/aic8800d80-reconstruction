// v23 annotated: sub_138818 @ 0x138818
// Original: 138818_sub_138818.c
// Primary struct: <unclustered>
//
// sub_138818 @ 0x138818, size 100 bytes
int __fastcall sub_138818(int result)
{
  int v1; // r1
  __int16 **v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  int v6; // r3
  __int16 v7; // r2
  int v8; // r0
  int v9; // r3

  if ( *(_DWORD *)(result + 4 * (*(unsigned __int8 *)(result + 10) + 4)) )
  {
    v1 = *(unsigned __int8 *)(result + 11);
    v2 = (__int16 **)off_13887C;
    v3 = dword_138880;
    v4 = dword_138884;
    v5 = result;
    do
    {
      if ( **v2 < 0 && !v1 )
      {
        sub_12F32C(v4, v3, 1537);
        LOBYTE(v1) = *(_BYTE *)(v5 + 11);
      }
      v6 = *(unsigned __int8 *)(v5 + 10);
      v7 = *(_WORD *)(v5 + 8);
      v8 = v6 + 4;
      v9 = ((_BYTE)v6 + 1) & 0x3F;
      *(_DWORD *)(v5 + 4 * v8) = 0;
      v1 = (unsigned __int8)(v1 - 1);
      *(_BYTE *)(v5 + 10) = v9;
      *(_BYTE *)(v5 + 11) = v1;
      result = *(_DWORD *)(v5 + 4 * (v9 + 4));
      *(_WORD *)(v5 + 8) = (v7 + 1) & 0xFFF;
    }
    while ( result );
  }
  return result;
}

