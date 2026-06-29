// rf_channel_seq_init_ae40 @ 0x12ae40, size 48 bytes
// Doc: rf_channel_seq_init_ae40 [rf]: Sequential init calls with args 0..3 to sub
// rf_channel_seq_init_ae40 [rf]: Sequential init calls with args 0..3 to sub
int *rf_channel_seq_init_ae40()
{
  int *result; // r0
  uint8_t *v1; // r3
  int v2; // r1

  fmac_table_lookup(0);
  fmac_table_lookup(1);
  fmac_table_lookup(2);
  result = fmac_table_lookup(3);
  v1 = (uint8_t *)dword_12AE70;
  v2 = dword_12AE70 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (uint8_t *)v2 );
  return result;
}

