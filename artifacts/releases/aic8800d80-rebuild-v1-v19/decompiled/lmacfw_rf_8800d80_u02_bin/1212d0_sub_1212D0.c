// sub_1212D0 @ 0x1212d0, size 118 bytes
int __fastcall sub_1212D0(int a1, int a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r1
  _DWORD *v7; // r4
  int v8; // r0
  _DWORD *v10; // r2
  _BYTE *v11; // r0
  _DWORD *v12; // r3
  _DWORD *v13; // r3

  v5 = rf_setup_dispatch(1040, a4, a3, 4u);
  v6 = *(unsigned __int16 *)(a2 + 4);
  v7 = (_DWORD *)v5;
  if ( *((_BYTE *)off_121348 + 177) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v10 = off_121354;
    *(_DWORD *)off_121350 |= 0x2000000u;
    v11 = off_121358;
    v10[14] |= 0x10u;
    *v11 = 1;
  }
  if ( v6 == 1 )
  {
    v12 = off_121354;
    *((_DWORD *)off_121354 + 18) = *(_DWORD *)a2;
    v12[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v13 = off_121354;
    *((_DWORD *)off_121354 + 19) = *(_DWORD *)a2;
    v13[75] = 128;
  }
LABEL_5:
  v8 = dword_12134C;
  *v7 = 0;
  msg_parse(v8);
  sub_11DE50((int)v7);
  return 0;
}

