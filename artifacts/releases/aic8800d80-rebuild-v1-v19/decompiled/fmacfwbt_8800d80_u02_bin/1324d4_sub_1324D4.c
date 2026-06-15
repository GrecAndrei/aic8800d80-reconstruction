// sub_1324D4 @ 0x1324d4, size 92 bytes
int __fastcall sub_1324D4(unsigned __int8 *a1)
{
  int v1; // r3
  int result; // r0
  int v4; // r1
  char *v5; // r3
  char *v6; // r1

  v1 = *a1;
  result = *((unsigned __int16 *)a1 + 1);
  if ( v1 )
  {
    v4 = *((unsigned __int8 *)off_132530 + 371);
    v5 = (char *)off_132530 + 202;
  }
  else
  {
    v4 = *((unsigned __int8 *)off_132530 + 370);
    v5 = (char *)off_132530 + 118;
  }
  if ( v4 )
  {
    v6 = &v5[6 * v4];
    while ( *(unsigned __int16 *)v5 != result )
    {
      v5 += 6;
      if ( v5 == v6 )
        goto LABEL_9;
    }
    a1[8] = v5[4];
    a1[9] = v5[3];
  }
  else
  {
LABEL_9:
    if ( **(__int16 **)off_132534 < 0 )
      result = sub_12F6C4(dword_13253C, dword_132538, 141);
    *((_WORD *)a1 + 4) = 15;
  }
  return result;
}

