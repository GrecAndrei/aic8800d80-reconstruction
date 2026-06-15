// v23 annotated: sub_113374 @ 0x113374
// Original: 113374_sub_113374.c
// Primary struct: <unclustered>
//
// sub_113374 @ 0x113374, size 148 bytes
int __fastcall sub_113374(int a1, int a2)
{
  _BYTE *v2; // r6
  int **v3; // r4
  char v4; // r0
  _BYTE *v5; // r12
  int *v6; // r7
  int *v7; // r5
  unsigned int v8; // r4
  int *v9; // r1
  char v10; // r3
  char v11; // r2
  unsigned __int16 *v12; // r1
  int v13; // r2
  char v14; // r3

  v2 = off_113408;
  if ( *(_BYTE *)off_113408 )
    return -99;
  v3 = (int **)off_11340C;
  v4 = sub_12D22C(off_11340C, a2);
  v5 = off_113414;
  *(_BYTE *)off_113414 = v4;
  if ( v4 )
  {
    v6 = *v3;
    v7 = *(int **)(dword_113410 + 8240);
    if ( v4 != 1 )
    {
      v8 = *((unsigned __int16 *)v6 + 6);
      if ( *((unsigned __int16 *)v7 + 6) < v8 )
      {
        v9 = v6;
        v10 = v4;
        while ( 1 )
        {
          v11 = v4 - v10--;
          if ( !v8 )
            break;
          if ( !*v9 || !v10 )
          {
            *v5 = v10;
            v7 = v9;
            goto LABEL_11;
          }
          v8 = *(unsigned __int16 *)(*v9 + 12);
          v7 = v9;
          v9 = (int *)*v9;
        }
        *v5 = v11;
      }
      goto LABEL_11;
    }
    if ( v7 )
    {
LABEL_11:
      v12 = (unsigned __int16 *)v6[1];
      v13 = v7[1] + 8 * (*((unsigned __int8 *)v7 + 14) - 1);
      v14 = *(_BYTE *)(v13 + 3);
      *v2 = 1;
      *(_BYTE *)(v13 + 3) = v14 & 0xF5 | 0xA;
      return sub_112ED0(1, v12);
    }
  }
  return -98;
}

