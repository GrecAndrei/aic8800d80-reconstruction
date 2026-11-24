// sub_13B25C @ 0x13b25c, size 414 bytes
int __fastcall sub_13B25C(int a1, char *a2, unsigned int a3)
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

  if ( sub_12CD48(a3) == 3 )
  {
    v6 = (char *)off_13B400 + 32 * (a3 >> 8);
    if ( *(_DWORD *)(v6 + 0x44) )
    {
      if ( *(_DWORD *)(v6 + 0x44) == 1 )
      {
        if ( *(_DWORD *)(a2 + 0x8) )
        {
          sub_13B8E4(a3 >> 8);
          sub_12D108(dword_13B41C, v6);
          sub_12CBF4(a3, 0);
        }
        else
        {
          v7 = *(_DWORD *)(v6 + 0x50);
          sub_13C26C((char *)off_13B400 + 32 * (a3 >> 8));
          *((_DWORD *)v6 + 2) = *((_DWORD *)off_13B404 + 4);
          v8 = *a2;
          v9 = *(_DWORD *)(a2 + 0x4);
          v10 = (_BYTE *)sub_12C7EC(5131, 13, 5, 3u);
          *(_DWORD *)(v10 + 0x8) = v7 - 4;
          *v10 = v8;
          *(_DWORD *)(v10 + 0x4) = v9;
          sub_12C84C((int)v10);
          sub_13B8CC(a3 >> 8);
          sub_12CBF4(a3, 1);
        }
      }
      else if ( **(__int16 **)off_13B3FC < 0 )
      {
        sub_12F35C(dword_13B40C, dword_13B408, 218);
      }
    }
    else
    {
      v11 = *((unsigned __int8 *)off_13B410 + 371);
      if ( *((_BYTE *)off_13B410 + 371) )
        v11 = *(unsigned __int8 *)(dword_13B418
                                 + 1320
                                 * *(unsigned __int8 *)(dword_13B414 + 696 * *((unsigned __int8 *)off_13B400 + 16) + 34)
                                 + 106) == 0;
      v12 = (char *)off_13B400 + 32 * (a3 >> 8);
      if ( *(_DWORD *)(a2 + 0x8) )
      {
        sub_13B558(
          (unsigned __int8)*(_DWORD *)(v12 + 0x40),
          v12,
          1,
          (unsigned __int8)*(_DWORD *)(v12 + 0x5c),
          v11
        | (unsigned __int16)((4 * (unsigned __int8)*(_DWORD *)(v12 + 0x58))
                           | (2 * (unsigned __int8)*(_DWORD *)(v12 + 0x48))
                           | (*((_WORD *)v12 + 10) << 6)),
          37,
          0);
        sub_12D108(dword_13B420, v12);
        sub_12CBF4(a3, 0);
      }
      else
      {
        sub_13B558(
          (unsigned __int8)*(_DWORD *)(v12 + 0x40),
          v12,
          1,
          (unsigned __int8)*(_DWORD *)(v12 + 0x5c),
          v11
        | (unsigned __int16)((4 * (unsigned __int8)*(_DWORD *)(v12 + 0x58))
                           | (2 * (unsigned __int8)*(_DWORD *)(v12 + 0x48))
                           | (*((_WORD *)v12 + 10) << 6)),
          (unsigned __int8)*(_DWORD *)(a2 + 0x8),
          (unsigned __int8)*(_DWORD *)(a2 + 0x8));
        v13 = (unsigned __int8)*a2;
        v14 = (unsigned __int8)*(_DWORD *)(a2 + 0x4);
        v15 = off_13B404;
        *(_BYTE *)(696 * v13 + 12 * v14 + dword_13B414 + 452) = BYTE1(a3);
        *((_DWORD *)v12 + 2) = *(_DWORD *)(v15 + 0x10);
        sub_13B8CC(a3 >> 8);
        sub_12CBF4(a3, 1);
      }
    }
    return 0;
  }
  if ( **(__int16 **)off_13B3FC >= 0 )
    return 0;
  sub_12F35C(dword_13B40C, dword_13B408, 109);
  return 0;
}

