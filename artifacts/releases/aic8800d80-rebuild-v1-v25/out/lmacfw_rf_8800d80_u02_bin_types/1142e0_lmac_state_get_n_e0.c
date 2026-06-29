// lmac_state_get_n_e0 @ 0x1142e0, size 42 bytes
// Doc: lmac_state_get_n_e0 [util]: Get LMAC state value from global pointer
// lmac_state_get_n_e0 [util]: Get LMAC state value from global pointer
void lmac_state_get_n_e0()
{
  int *v0; // r4

  v0 = (int *)off_11430C;
  if ( !*(uint32_t *)off_11430C )
    *v0 = sub_114218();
  if ( !*(uint32_t *)off_114310 )
    *(uint32_t *)off_114310 = *v0 + 67092480;
  *(uint32_t *)off_114314 = 1;
}

