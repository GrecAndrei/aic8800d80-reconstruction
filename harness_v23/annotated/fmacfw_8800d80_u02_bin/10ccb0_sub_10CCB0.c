// v23 annotated: sub_10CCB0 @ 0x10ccb0
// Original: 10ccb0_sub_10CCB0.c
// Primary struct: <unclustered>
//
// sub_10CCB0 @ 0x10ccb0, size 190 bytes
int __fastcall sub_10CCB0(_WORD *a1)
{
  __int16 **v2; // r7
  int v3; // r0
  __int16 *v4; // r6
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r7
  int *v8; // r3
  int *v9; // r2
  int v10; // r1
  int v11; // t1
  _DWORD *v12; // r1
  __int16 v13; // r3

  v2 = (__int16 **)off_10CD70;
  v3 = message_dispatch_n158((unsigned __int16)a1[5] + 16);
  v4 = *v2;
  v5 = v3;
  if ( **v2 < 0 && !v3 )
  {
    sub_12F46C(dword_10CD88, dword_10CD80, 1358);
    v4 = *v2;
  }
  v6 = (unsigned __int16)a1[5];
  v7 = (unsigned __int16)a1[3];
  *(_WORD *)(v5 + 4) = a1[2];
  *(_WORD *)(v5 + 8) = 13;
  *(_WORD *)(v5 + 10) = v6;
  *(_WORD *)(v5 + 6) = v7;
  *(_DWORD *)v5 = 0;
  v8 = (int *)(a1 + 6);
  if ( v6 )
  {
    v9 = (int *)((char *)a1 + ((v6 - 1) & 0xFFFFFFFC) + 16);
    v10 = v5 + 8;
    do
    {
      v11 = *v8++;
      *(_DWORD *)(v10 + 4) = v11;
      v10 += 4;
    }
    while ( v8 != v9 );
  }
  if ( *v4 < 0 )
  {
    if ( v7 > 0xE )
    {
      sub_12F46C(dword_10CD90, dword_10CD8C, 183);
      sub_12F46C(dword_10CD84, dword_10CD80, 1375);
    }
    else if ( v7 > 0xC )
    {
      sub_12F46C(dword_10CD84, dword_10CD80, 1375);
    }
  }
  if ( **(_BYTE **)off_10CD74 == 3 )
  {
    v12 = off_10CD7C;
    v13 = *((unsigned __int8 *)off_10CD78 + 21);
    *((_BYTE *)off_10CD78 + 21) = v13 + 1;
    a1[4] = v13;
    *v12 = 4;
  }
  return sdio_buffer_prepare_n_4e8(v5 + 12);
}

