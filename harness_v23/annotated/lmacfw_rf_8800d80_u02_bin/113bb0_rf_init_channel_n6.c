// v23 annotated: rf_init_channel_n6 @ 0x113bb0
// Original: 113bb0_rf_init_channel_n6.c
// Primary struct: <unclustered>
//
// rf_init_channel_n6 @ 0x113bb0, size 54 bytes
// Doc: rf_init_channel_n6 [rf]: Initializes RF channel 6 via sub_113a44 helper
// rf_init_channel_n6 [rf]: Initializes RF channel 6 via sub_113a44 helper
int __fastcall rf_init_channel_n6(int a1)
{
  __int16 v2; // r0
  char v3; // r1
  int v4; // r5

  v2 = sub_113A44(6u);
  v3 = v2;
  if ( !(_BYTE)v2 )
  {
    v4 = 1;
LABEL_3:
    host_reg_wait_set(6u, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( (v2 & 0xFF00) == 0 )
  {
    v3 = 8;
    goto LABEL_3;
  }
  return -1;
}

