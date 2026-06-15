// sub_102970 @ 0x102970, size 152 bytes
int __fastcall sub_102970(unsigned __int16 *a1, int a2)
{
  unsigned __int8 *v3; // r0
  int v4; // r1
  int v5; // r1
  int v6; // r2
  int v7; // r2
  int v8; // r0
  int v9; // r1

  if ( a2 )
  {
    v7 = a2;
    v8 = dword_102A18;
    v9 = dword_102A1C;
  }
  else
  {
    if ( *(_BYTE *)off_102A08 )
      goto LABEL_4;
    v3 = (unsigned __int8 *)off_102A10;
    v4 = *((unsigned __int16 *)off_102A10 + 18);
    *(_DWORD *)off_102A0C &= ~0x200u;
    if ( v4 != *a1 )
      goto LABEL_4;
    v5 = a1[1];
    if ( v3[45] != *((unsigned __int8 *)a1 + 9) )
    {
      v6 = a1[2];
      goto LABEL_5;
    }
    v6 = a1[2];
    if ( *((unsigned __int16 *)v3 + 19) != v5
      || *((unsigned __int16 *)v3 + 20) != v6
      || *((unsigned __int16 *)v3 + 21) != a1[3] )
    {
LABEL_5:
      sub_101EC0(*(unsigned __int8 *)a1, v5, v6, *((unsigned __int8 *)a1 + 1));
    }
    if ( sub_12CD48(7) == 1 || sub_12CD48(6) == 3 )
    {
LABEL_4:
      v5 = a1[1];
      v6 = a1[2];
      goto LABEL_5;
    }
    v9 = dword_102A1C;
    v8 = dword_102A20;
  }
  return sub_12E948(v8, v9, v7);
}

