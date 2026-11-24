// sub_13B39C @ 0x13b39c, size 414 bytes
int __fastcall sub_13B39C(int a1, char *a2, unsigned int a3)
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

  if ( msg_get_value(a3) == 3 )
  {
    v6 = (char *)off_13B540 + 32 * (a3 >> 8);
    if ( *(_DWORD *)(v6 + 0x44) )
    {
      if ( *(_DWORD *)(v6 + 0x44) == 1 )
      {
        if ( *(_DWORD *)(a2 + 0x8) )
        {
          sub_13BA24(a3 >> 8);
          list_push_tail(dword_13B55C, v6);
          sub_12CD34(a3, 0);
        }
        else
        {
          v7 = *(_DWORD *)(v6 + 0x50);
          sub_13C3AC((char *)off_13B540 + 32 * (a3 >> 8));
          *((_DWORD *)v6 + 2) = *((_DWORD *)off_13B544 + 4);
          v8 = *a2;
          v9 = *(_DWORD *)(a2 + 0x4);
          v10 = (_BYTE *)sub_12C92C(5131, 13, 5, 3u);
          *(_DWORD *)(v10 + 0x8) = v7 - 4;
          *v10 = v8;
          *(_DWORD *)(v10 + 0x4) = v9;
          sdio_buffer_prepare_n_4e8((int)v10);
          sub_13BA0C(a3 >> 8);
          sub_12CD34(a3, 1);
        }
      }
      else if ( **(__int16 **)off_13B53C < 0 )
      {
        sub_12F49C(dword_13B54C, dword_13B548, 218);
      }
    }
    else
    {
      v11 = *((unsigned __int8 *)off_13B550 + 371);
      if ( *((_BYTE *)off_13B550 + 371) )
        v11 = *(unsigned __int8 *)(dword_13B558
                                 + 1320
                                 * *(unsigned __int8 *)(dword_13B554 + 696 * *((unsigned __int8 *)off_13B540 + 16) + 34)
                                 + 106) == 0;
      v12 = (char *)off_13B540 + 32 * (a3 >> 8);
      if ( *(_DWORD *)(a2 + 0x8) )
      {
        sub_13B698(
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
        list_push_tail(dword_13B560, v12);
        sub_12CD34(a3, 0);
      }
      else
      {
        sub_13B698(
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
        v15 = off_13B544;
        *(_BYTE *)(696 * v13 + 12 * v14 + dword_13B554 + 452) = BYTE1(a3);
        *((_DWORD *)v12 + 2) = *(_DWORD *)(v15 + 0x10);
        sub_13BA0C(a3 >> 8);
        sub_12CD34(a3, 1);
      }
    }
    return 0;
  }
  if ( **(__int16 **)off_13B53C >= 0 )
    return 0;
  sub_12F49C(dword_13B54C, dword_13B548, 109);
  return 0;
}

