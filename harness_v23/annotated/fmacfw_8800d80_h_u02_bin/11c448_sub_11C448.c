// v23 annotated: sub_11C448 @ 0x11c448
// Original: 11c448_sub_11C448.c
// Primary struct: <unclustered>
//
// sub_11C448 @ 0x11c448, size 70 bytes
unsigned int *__fastcall sub_11C448(unsigned int *result)
{
  int v1; // r2
  int v2; // r5
  unsigned int *v3; // r4
  __int64 v4; // r6
  unsigned int *v5; // r0

  v1 = *(unsigned __int16 *)(dword_11C490 + 1320 * *((unsigned __int8 *)result + 28) + 1222);
  if ( v1 != 1023 && *((_BYTE *)off_11C494 + 361) != 2 )
  {
    v4 = *((_QWORD *)result + 9);
    v2 = dword_11C490 + 1320 * *((unsigned __int8 *)result + 28);
    v3 = (unsigned int *)(v4 + 64);
    LODWORD(v4) = v4 + 80;
    while ( 1 )
    {
      v5 = v3++;
      result = sub_11AF90(v5, *(_DWORD *)(HIDWORD(v4) + 36), v1);
      if ( v3 == (unsigned int *)v4 )
        break;
      v1 = *(unsigned __int16 *)(v2 + 1222);
    }
  }
  return result;
}

