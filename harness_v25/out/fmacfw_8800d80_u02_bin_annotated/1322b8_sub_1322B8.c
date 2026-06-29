// fwstruct annotate: 1322b8_sub_1322B8.c
// sub_1322B8 @ 0x1322b8, size 92 bytes
int __fastcall sub_1322B8(unsigned __int8 *a1)
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
    v4 = *((unsigned __int8 *)off_132314 + 371);
    v5 = (char *)off_132314 + 202;
  }
  else
  {
    v4 = *((unsigned __int8 *)off_132314 + 370);
    v5 = (char *)off_132314 + 118;
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
    if ( **(__int16 **)off_132318 < 0 )
      result = sub_12F49C(dword_132320, dword_13231C, 141);
    *((_WORD *)a1 + 4) = 15;
  }
  return result;
}

