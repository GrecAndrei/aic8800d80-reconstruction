// v23 annotated: sub_132178 @ 0x132178
// Original: 132178_sub_132178.c
// Primary struct: <unclustered>
//
// sub_132178 @ 0x132178, size 92 bytes
int __fastcall sub_132178(unsigned __int8 *a1)
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
    v4 = *((unsigned __int8 *)off_1321D4 + 371);
    v5 = (char *)off_1321D4 + 202;
  }
  else
  {
    v4 = *((unsigned __int8 *)off_1321D4 + 370);
    v5 = (char *)off_1321D4 + 118;
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
    if ( **(__int16 **)off_1321D8 < 0 )
      result = sub_12F35C(dword_1321E0, dword_1321DC, 141);
    *((_WORD *)a1 + 4) = 15;
  }
  return result;
}

