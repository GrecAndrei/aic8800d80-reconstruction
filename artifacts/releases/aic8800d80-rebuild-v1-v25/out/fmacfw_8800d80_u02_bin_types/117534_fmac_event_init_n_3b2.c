// fmac_event_init_n_3b2 @ 0x117534, size 48 bytes
// Doc: fmac_event_init_n_3b2 [util]: Initialize fmac event/state object with cleared slot at offset 0x4f8
// fmac_event_init_n_3b2 [util]: Initialize fmac event/state object with cleared slot at offset 0x4f8
int  fmac_event_init_n_3b2(int a1)
{
  int v1; // r4
  int v2; // r5
  int v3; // r0
  int result; // r0
  int v5; // [sp+4h] [bp-8h]

  v1 = a1 + 1272;
  v2 = 0;
  do
  {
    v3 = (unsigned __int8)v2;
    v5 = (unsigned __int8)v2++;
    sub_118940(v3, v1, 0);
    result = sub_118940(v5, v1 - 40, 0);
    v1 += 8;
  }
  while ( v2 != 5 );
  return result;
}

