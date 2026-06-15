// v23 annotated: sub_11BD88 @ 0x11bd88
// Original: 11bd88_sub_11BD88.c
// Primary struct: <unclustered>
//
// sub_11BD88 @ 0x11bd88, size 136 bytes
int *__fastcall sub_11BD88(int a1)
{
  __int16 **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r5
  int *result; // r0

  v1 = (__int16 **)off_11BE24;
  v2 = dword_11BE10;
  v4 = (int *)(dword_11BE10 + 28 * a1);
  if ( **(__int16 **)off_11BE24 < 0 )
  {
    v5 = 8 * a1;
    if ( *(unsigned __int8 *)(dword_11BE10 + 28 * a1 + 24) != 255
      || (sub_1219C4(dword_11BE20, dword_11BE18, 3044), **v1 < 0) )
    {
      if ( *(_BYTE *)(v2 + 4 * (v5 - a1) + 25) )
        sub_1219C4(dword_11BE1C, dword_11BE18, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  sub_11E724(dword_11BE14);
  v6 = v2 + 4 * (v5 - a1);
  result = sub_100200(v4, 0, 0x1Cu);
  *(_WORD *)(v6 + 14) = 255;
  *(_BYTE *)(v6 + 24) = -1;
  return result;
}

