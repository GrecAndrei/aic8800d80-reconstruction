// fwstruct annotate: 11c38c_sub_11C38C.c
// sub_11C38C @ 0x11c38c, size 388 bytes
int __fastcall sub_11C38C(int a1, int a2)
{
  __int16 **v2; // r9
  int v3; // r7
  int v4; // r10
  int v7; // r6
  int v8; // r11
  int v9; // r8
  int v10; // r3
  int v11; // r5
  int v12; // r2
  _BYTE *v13; // r5
  char v15; // r0
  __int16 *v16; // r1
  unsigned int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r1

  v2 = (__int16 **)off_11C53C;
  v3 = dword_11C510;
  v4 = dword_11C538;
  v7 = dword_11C510 + 28 * a2;
  if ( **(__int16 **)off_11C53C < 0 )
  {
    v8 = 8 * a1;
    if ( *(_DWORD *)(dword_11C538 + 224 * a1 + 72) && (rf_cmd_send_n264(dword_11C520, dword_11C51C, 3061), **v2 >= 0) )
    {
      v9 = 8 * a2;
    }
    else
    {
      v9 = 8 * a2;
      if ( *(unsigned __int8 *)(v3 + 28 * a2 + 24) == 255 )
        rf_cmd_send_n264(dword_11C524, dword_11C51C, 3062);
    }
  }
  else
  {
    v8 = 8 * a1;
    v9 = 8 * a2;
  }
  v10 = v3 + 4 * (v9 - a2);
  v11 = v4 + 32 * (v8 - a1);
  v12 = (unsigned __int8)(*(_BYTE *)(v10 + 25) + 1);
  *(_DWORD *)(v11 + 72) = v7;
  *(_BYTE *)(v11 + 85) = 0;
  *(_BYTE *)(v10 + 25) = v12;
  v13 = off_11C514;
  if ( v12 == 1 )
  {
    v15 = *((_BYTE *)off_11C514 + 90);
    *(_BYTE *)(v10 + 16) = 1;
    v16 = *v2;
    v17 = (unsigned __int8)(v15 + 1);
    v13[90] = v17;
    if ( *v16 < 0 && v17 > 2 )
    {
      rf_cmd_send_n264(dword_11C52C, dword_11C51C, 3082);
      v17 = (unsigned __int8)v13[90];
    }
    if ( v17 == 2 )
    {
      sub_11E71C(dword_11C534);
      v19 = dword_11C538;
      v20 = dword_11C538 + 896;
      do
      {
        *(_BYTE *)(v19 + 85) &= ~1u;
        v19 += 224;
      }
      while ( v20 != v19 );
    }
    list_push_tail(dword_11C528);
    if ( (v13[88] & 0xC) != 0 )
    {
      v18 = *((_DWORD *)v13 + 8);
      if ( **v2 < 0 && !v18 )
      {
        rf_cmd_send_n264(dword_11C530, dword_11C51C, 3097);
        v18 = 0;
      }
      *(_DWORD *)(v18 + 8) = v7;
      v12 = *(unsigned __int8 *)(v3 + 4 * (v9 - a2) + 25);
    }
    else
    {
      if ( *((_DWORD *)v13 + 11) )
        *((_DWORD *)v13 + 11) = v7;
      else
        sub_11ADD0(v7);
      v12 = *(unsigned __int8 *)(v3 + 4 * (v9 - a2) + 25);
    }
  }
  sub_11F74C(256, dword_11C518, v12, a2);
  return rf_get_status_byte_n_a24(v7);
}

