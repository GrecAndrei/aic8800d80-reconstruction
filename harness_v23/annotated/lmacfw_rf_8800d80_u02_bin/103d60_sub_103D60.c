// v23 annotated: sub_103D60 @ 0x103d60
// Original: 103d60_sub_103D60.c
// Primary struct: <unclustered>
//
// sub_103D60 @ 0x103d60, size 66 bytes
int __fastcall sub_103D60(int a1, int a2, _DWORD *a3)
{
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (unsigned __int16)*(_DWORD *)off_103DA4;
  v4 = 0x3FFF;
  if ( v3 == 0x3FFF )
    a3 = (_DWORD *)*a3;
  else
    v4 = v3 + 1;
  if ( v3 != 0x3FFF )
    a3 = (_DWORD *)a3[v4];
  if ( ((unsigned __int8)a3 & 1) != 0 )
  {
    if ( a2 )
      goto LABEL_8;
  }
  else if ( a2 != 1 )
  {
LABEL_8:
    result = v3 + 2 + 2 * a1;
    goto LABEL_9;
  }
  result = v3 + 1 + 2 * a1;
LABEL_9:
  if ( result >= 0x4000 )
    result -= 0x4000;
  return result;
}

