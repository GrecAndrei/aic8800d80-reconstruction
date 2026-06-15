// v23 annotated: sub_13B438 @ 0x13b438
// Original: 13b438_sub_13B438.c
// Primary struct: <unclustered>
//
// sub_13B438 @ 0x13b438, size 414 bytes
int __fastcall sub_13B438(int a1, char *a2, unsigned int a3)
{
  char *v6; // r8
  char v7; // r10
  char v8; // r5
  unsigned __int8 v9; // r6
  _BYTE *v10; // r0
  unsigned __int16 v11; // r3
  char *v12; // r5
  int v13; // r0
  int v14; // r2
  _DWORD *v15; // r6

  if ( sub_12D0B0(a3) == 3 )
  {
    v6 = (char *)off_13B5DC + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          sub_13BAC0(a3 >> 8);
          sub_12D470(dword_13B5F8, v6);
          sub_12CF5C(a3, 0);
        }
        else
        {
          v7 = v6[20];
          sub_13C448((char *)off_13B5DC + 32 * (a3 >> 8));
          *((_DWORD *)v6 + 2) = *((_DWORD *)off_13B5E0 + 4);
          v8 = *a2;
          v9 = a2[1];
          v10 = (_BYTE *)sub_12CB54(5131, 13, 5, 3u);
          v10[2] = v7 - 4;
          *v10 = v8;
          v10[1] = v9;
          sub_12CBB4((int)v10);
          sub_13BAA8(a3 >> 8);
          sub_12CF5C(a3, 1);
        }
      }
      else if ( **(__int16 **)off_13B5D8 < 0 )
      {
        sub_12F6C4(dword_13B5E8, dword_13B5E4, 218);
      }
    }
    else
    {
      v11 = *((unsigned __int8 *)off_13B5EC + 371);
      if ( *((_BYTE *)off_13B5EC + 371) )
        v11 = *(unsigned __int8 *)(dword_13B5F4
                                 + 1320
                                 * *(unsigned __int8 *)(dword_13B5F0 + 696 * *((unsigned __int8 *)off_13B5DC + 16) + 34)
                                 + 106) == 0;
      v12 = (char *)off_13B5DC + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        sub_13B734(
          (unsigned __int8)v12[16],
          v12,
          1,
          (unsigned __int8)v12[23],
          v11
        | (unsigned __int16)((4 * (unsigned __int8)v12[22])
                           | (2 * (unsigned __int8)v12[18])
                           | (*((_WORD *)v12 + 10) << 6)),
          37,
          0);
        sub_12D470(dword_13B5FC, v12);
        sub_12CF5C(a3, 0);
      }
      else
      {
        sub_13B734(
          (unsigned __int8)v12[16],
          v12,
          1,
          (unsigned __int8)v12[23],
          v11
        | (unsigned __int16)((4 * (unsigned __int8)v12[22])
                           | (2 * (unsigned __int8)v12[18])
                           | (*((_WORD *)v12 + 10) << 6)),
          (unsigned __int8)a2[2],
          (unsigned __int8)a2[2]);
        v13 = (unsigned __int8)*a2;
        v14 = (unsigned __int8)a2[1];
        v15 = off_13B5E0;
        *(_BYTE *)(696 * v13 + 12 * v14 + dword_13B5F0 + 452) = BYTE1(a3);
        *((_DWORD *)v12 + 2) = v15[4];
        sub_13BAA8(a3 >> 8);
        sub_12CF5C(a3, 1);
      }
    }
    return 0;
  }
  if ( **(__int16 **)off_13B5D8 >= 0 )
    return 0;
  sub_12F6C4(dword_13B5E8, dword_13B5E4, 109);
  return 0;
}

