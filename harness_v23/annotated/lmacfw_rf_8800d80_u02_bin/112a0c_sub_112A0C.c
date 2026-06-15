// v23 annotated: sub_112A0C @ 0x112a0c
// Original: 112a0c_sub_112A0C.c
// Primary struct: <unclustered>
//
// sub_112A0C @ 0x112a0c, size 308 bytes
// Doc: rf_cmd_send_n16a [rf]: Enqueue and dispatch an N16A-type RF command to the upper MAC via IPC.
// rf_cmd_send_n16a [rf]: Enqueue and dispatch an N16A-type RF command to the upper MAC via IPC.
int __fastcall sub_112A0C(unsigned __int8 *a1, unsigned int a2, int a3)
{
  unsigned __int16 *v3; // r7
  unsigned __int8 *v4; // r6
  _BYTE *v5; // r4
  char v6; // r2
  unsigned __int8 *v7; // r4
  int v9; // r8
  int v10; // r3
  int v11; // r6
  _BYTE *v12; // r8
  char v13; // r5
  int v14; // r0
  unsigned int v15; // r3
  char *v16; // r3
  int v18; // r0

  v3 = (unsigned __int16 *)off_112B40;
  v4 = (unsigned __int8 *)off_112B44;
  v5 = off_112B48;
  ++*(_WORD *)off_112B40;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    sub_10DA6C(dword_112B58, *v3, *v4);
    sub_1136F4(dword_112B5C, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    sub_10DA6C(dword_112B60, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = (a1[1] << 8) & 0xF00;
    v11 = *a1 | v10;
    if ( *(_BYTE *)off_112B4C )
      a1 = (unsigned __int8 *)sub_11F74C(512, dword_112B6C, a2, v10);
    if ( v9 == 17 )
    {
      v12 = off_112B78;
      if ( *((unsigned __int8 *)off_112B78 + 2433) >= (unsigned int)*((unsigned __int8 *)off_112B78 + 2434) )
      {
        sub_10DA6C(dword_112B70);
      }
      else
      {
        if ( v11 + 4 == a2 || a2 == v11 + 5 )
        {
          sub_113630(a1);
          v13 = v12[2433];
          v14 = dword_112B54;
          v15 = (unsigned __int8)v12[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_112B50
                               * (unsigned __int64)((unsigned int)(unsigned __int8)v12[2432] + 1)) >> 32) >> 5);
          v12[2432] = v15;
          v16 = &v12[20 * v15];
          *((_DWORD *)v16 + 409) = v7 + 4;
          *((_DWORD *)v16 + 412) = v11;
          v12[2433] = v13 + 1;
          sub_11E724(v14);
          sub_11E5E0(0x1000000);
          return 1;
        }
        sub_10DA6C(dword_112B74, *v3, v11, a2);
      }
    }
    else
    {
      sub_10DA6C(dword_112B68, *v3, v9, v11, a2);
    }
  }
  v18 = sub_10FEF8(&v7[-*(_DWORD *)off_112B64]);
  sub_113630(v18);
  return 1;
}

