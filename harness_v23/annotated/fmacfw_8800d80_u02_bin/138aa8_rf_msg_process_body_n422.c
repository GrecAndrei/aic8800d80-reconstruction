// v23 annotated: rf_msg_process_body_n422 @ 0x138aa8
// Original: 138aa8_rf_msg_process_body_n422.c
// Primary struct: <unclustered>
//
// rf_msg_process_body_n422 @ 0x138aa8, size 152 bytes
// Doc: rf_msg_process_body_n422 [rf]: RF message handler: set flag, bump counter, invoke callback
// rf_msg_process_body_n422 [rf]: RF message handler: set flag, bump counter, invoke callback
int __fastcall rf_msg_process_body_n422(unsigned __int8 *a1, _DWORD *a2, char *a3, int a4)
{
  char v5; // r2
  int v6; // r4
  char *v7; // r3
  int v10; // r7
  int v12; // r9
  int v13; // r7

  v5 = a3[1];
  v6 = a4;
  if ( a4 )
    v6 = 2;
  if ( (v5 & 0x40) != 0 )
    v6 = (unsigned __int8)(v6 + 8);
  v7 = &a3[v6];
  if ( a3[v6 + 30] != 8 )
    return 0;
  if ( v7[31] != 6 )
    return 0;
  v10 = (unsigned __int8)v7[38];
  if ( v7[38] )
    return 0;
  v12 = (unsigned __int8)v7[39];
  if ( v12 == 1 )
  {
    v13 = ((unsigned __int8)v7[58] << 16)
        | ((unsigned __int8)v7[59] << 24)
        | (unsigned __int8)v7[56]
        | ((unsigned __int8)v7[57] << 8);
    feature_guard_check(128, dword_138B44, v13, *a2);
    if ( v13 == *a2 )
      sub_135AFC(*a1, (int)&a3[v6 + 40], a3);
    return 1;
  }
  else if ( v12 == 2 )
  {
    feature_guard_check(128, dword_138B40);
  }
  return v10;
}

