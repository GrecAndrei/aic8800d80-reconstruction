// fwstruct annotate: 113104_sub_113104.c
// sub_113104 @ 0x113104, size 360 bytes
int __fastcall sub_113104(unsigned __int8 *a1, unsigned int a2, int a3)
{
  unsigned __int16 *v3; // r7
  unsigned __int8 *v4; // r6
  _BYTE *v5; // r4
  char v6; // r2
  unsigned __int8 *v7; // r4
  int v9; // r8
  int v10; // r6
  _BYTE *v11; // r8
  char v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  char *v15; // r3
  int v17; // r0

  v3 = (unsigned __int16 *)off_11326C;
  v4 = (unsigned __int8 *)off_113270;
  v5 = off_113274;
  ++*(_WORD *)off_11326C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    sub_10DC24(dword_113284, *v3, *v4);
    sub_1141C8(dword_113288, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    sub_10DC24(dword_11328C, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(_BYTE *)off_113278 )
      a1 = (unsigned __int8 *)sub_12ECD0(512, dword_113298);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        ((void (*)(void))sub_114104)();
        sub_113C48(v7 + 4);
        sub_12D104(512);
        return 1;
      }
      sub_10DC24(dword_11329C, *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = off_1132A8;
      if ( *((unsigned __int8 *)off_1132A8 + 2433) >= (unsigned int)*((unsigned __int8 *)off_1132A8 + 2434) )
      {
        sub_10DC24(dword_1132A4);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          sub_114104(a1);
          v12 = v11[2433];
          v13 = dword_113280;
          v14 = (unsigned __int8)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_11327C
                               * (unsigned __int64)((unsigned int)(unsigned __int8)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          *((_DWORD *)v15 + 409) = v7 + 4;
          *((_DWORD *)v15 + 412) = v10;
          v11[2433] = v12 + 1;
          sub_12D248(v13);
          sub_12D104(0x400000);
          return 1;
        }
        sub_10DC24(dword_1132A0, *v3, v10, a2);
      }
    }
    else
    {
      sub_10DC24(dword_113294, *v3, v9, v10, a2);
    }
  }
  v17 = sub_110008(&v7[-*(_DWORD *)off_113290]);
  sub_114104(v17);
  return 1;
}

