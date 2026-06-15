// v23 annotated: sub_1141C8 @ 0x1141c8
// Original: 1141c8_sub_1141C8.c
// Primary struct: <unclustered>
//
// sub_1141C8 @ 0x1141c8, size 82 bytes
int __fastcall sub_1141C8(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a1 == *(_DWORD *)off_11421C )
  {
    v5 = 0;
  }
  else
  {
    if ( a1 != *((_DWORD *)off_11421C + 1) )
    {
      result = sub_12EA88(dword_114220, a1, *(_DWORD *)off_11421C);
      goto LABEL_4;
    }
    v5 = 1;
  }
  result = sub_12EA88(dword_114230, dword_11422C, *(_DWORD *)(dword_114228 + 4 * v5));
LABEL_4:
  if ( *((_BYTE *)off_114224 + 353) )
    return sub_12C5E4(1068, 1, 1000 * *((unsigned __int8 *)off_114224 + 354), a4);
  return result;
}

