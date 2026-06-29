// fwstruct annotate: 11e3fc_sub_11E3FC.c
// sub_11E3FC @ 0x11e3fc, size 186 bytes
int __fastcall sub_11E3FC(int a1, unsigned int a2)
{
  __int16 **v2; // r4
  unsigned int v4; // r7
  unsigned int v5; // r8
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  char v13; // r5
  int v14; // r3

  v2 = (__int16 **)off_11E4B8;
  v4 = (unsigned __int8)a2;
  v5 = a2 >> 8;
  if ( **(__int16 **)off_11E4B8 >= 0 )
    goto LABEL_2;
  v13 = a2;
  if ( (unsigned __int8)a2 <= 4u )
    goto LABEL_9;
  rf_cmd_send_n264(dword_11E4C8, dword_11E4C0, 267);
  if ( **v2 >= 0 )
  {
LABEL_2:
    v6 = dword_11E4BC;
    v7 = 16 * v4;
    goto LABEL_3;
  }
  if ( v4 <= 5 )
  {
LABEL_9:
    if ( (v13 & 0xFC) == 0 )
      goto LABEL_10;
  }
  else
  {
    rf_cmd_send_n264(dword_11E4D0, dword_11E4CC, 183);
    if ( (v13 & 0xFC) == 0 )
      goto LABEL_16;
  }
  rf_cmd_send_n264(dword_11E4D4, dword_11E4C0, 268);
LABEL_16:
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_11E4BC;
  v14 = dword_11E4BC + 16 * v4;
  v7 = 16 * v4;
  if ( *(unsigned __int16 *)(v14 + 14) <= v5 )
    rf_cmd_send_n264(dword_11E4C4, dword_11E4C0, 269);
LABEL_3:
  v8 = *(_DWORD *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(unsigned __int16 *)(*(_DWORD *)(v9 + 8) + 2 * v5),
        (result = sub_11E184(a1, (int *)v10, *(unsigned __int16 *)(v10 + 4))) == 0) )
  {
    v12 = *(_DWORD *)(v9 + 4);
    if ( v12 )
      return sub_11E184(a1, (int *)v12, *(unsigned __int16 *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

