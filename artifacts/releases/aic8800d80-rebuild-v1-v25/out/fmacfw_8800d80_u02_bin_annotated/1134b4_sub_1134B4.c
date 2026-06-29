// fwstruct annotate: 1134b4_sub_1134B4.c
// sub_1134B4 @ 0x1134b4, size 148 bytes
int __fastcall sub_1134B4(int a1, int a2)
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

  v2 = off_113548;
  if ( *(_BYTE *)off_113548 )
    return -99;
  v3 = (int **)off_11354C;
  v4 = sub_12D36C(off_11354C, a2);
  v5 = off_113554;
  *(_BYTE *)off_113554 = v4;
  if ( v4 )
  {
    v6 = *v3;
    v7 = *(int **)(dword_113550 + 8240);
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
      return sub_113010(1, v12);
    }
  }
  return -98;
}

