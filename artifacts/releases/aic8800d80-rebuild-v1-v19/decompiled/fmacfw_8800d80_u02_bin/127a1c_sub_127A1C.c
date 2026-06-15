// sub_127A1C @ 0x127a1c, size 140 bytes
int sub_127A1C()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  _DWORD *v5; // r3
  void *v6; // r1

  v0 = (int *)off_127AAC;
  v1 = off_127AA8;
  sub_100200((int *)off_127AA8, 0, 0x60u);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    sub_100200(i, 0, 0x1Cu);
    *((_WORD *)i + 7) = 255;
    *((_BYTE *)i + 24) = -1;
    *((_BYTE *)i + 27) = -1;
    if ( v2 <= 2 )
    {
      sub_12D248(v1);
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((_WORD *)v0 + 47) = 0;
    *((_BYTE *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  sub_12D240(dword_127AB0);
  sub_12D240(dword_127AB4);
  sub_12D248(dword_127AB0);
  sub_12D248(dword_127AB0);
  sub_12D248(dword_127AB0);
  result = sub_12D248(dword_127AB0);
  v5 = off_127AA8;
  v6 = off_127ACC;
  *((_DWORD *)off_127AA8 + 13) = off_127AC8;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

