// rf_param_select_n_e60 @ 0x124e60, size 166 bytes
// Doc: rf_param_select_n_e60 [rf]: Select RF parameter by comparing value against 2 and allocating stack frame
// rf_param_select_n_e60 [rf]: Select RF parameter by comparing value against 2 and allocating stack frame
int __fastcall rf_param_select_n_e60(int a1, int a2)
{
  int *v3; // r5
  int v4; // r3
  unsigned __int8 *v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r3
  int v9; // r5
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int *v13; // r1
  int *v14; // r2
  int v16; // [sp+0h] [bp-14h] BYREF
  int v17; // [sp+4h] [bp-10h] BYREF
  int v18; // [sp+8h] [bp-Ch] BYREF
  _DWORD v19[2]; // [sp+Ch] [bp-8h] BYREF

  if ( a1 <= 2 )
  {
    msg_parse(dword_124F1C);
    return -1;
  }
  else
  {
    v3 = (int *)off_124F08;
    v4 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    v5 = *(unsigned __int8 **)(a2 + 8);
    v6 = v4;
    v7 = parse_int(v5, nullptr, 0xAu);
    v8 = *(_DWORD *)off_124F0C;
    v9 = *v3;
    v10 = *(_DWORD *)off_124F10;
    v11 = *(_DWORD *)off_124F14;
    LOWORD(v16) = *(_DWORD *)off_124F0C;
    BYTE2(v16) = BYTE2(v8);
    LOWORD(v17) = v9;
    BYTE2(v17) = BYTE2(v9);
    LOWORD(v18) = v10;
    BYTE2(v18) = BYTE2(v10);
    LOWORD(v19[0]) = v11;
    BYTE2(v19[0]) = BYTE2(v11);
    if ( v6 )
    {
      if ( v7 )
      {
        sub_102ADC(0);
        v13 = &v18;
      }
      else
      {
        sub_102ADC(1);
        v13 = v19;
      }
      v14 = &v16;
    }
    else
    {
      if ( v7 )
      {
        sub_102B40(0);
        v13 = &v18;
      }
      else
      {
        sub_102B40(1);
        v13 = v19;
      }
      v14 = &v17;
    }
    msg_parse(dword_124F18, v13, v14, v12, v16, v17, v18, v19[0]);
    return 0;
  }
}

