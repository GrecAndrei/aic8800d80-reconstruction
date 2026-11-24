// sub_10C444 @ 0x10c444, size 74 bytes
void __fastcall sub_10C444(int a1, int a2)
{
  int *v2; // r2
  unsigned __int16 *v3; // r3
  int *v4; // r5
  unsigned __int16 *v5; // r4
  int v7; // r0
  unsigned __int8 v8; // [sp+20h] [bp+18h]
  unsigned __int8 v9; // [sp+24h] [bp+1Ch]

  v4 = v2;
  v5 = v3;
  sub_101DE8(a1, a2, a2, 0, 0, 0);
  sub_10C1B8(v4, (unsigned int)v5, v8, v9);
  if ( v8 )
  {
    if ( a1 == 1 )
      v7 = 28;
    else
      v7 = 3;
    tx_rate_config(v7, v5);
  }
}
