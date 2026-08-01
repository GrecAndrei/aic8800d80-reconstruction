// rx_env_list_init @ 0x12c564, size 22 bytes
// Doc: rx_env_list_init [rf]: Configure RF bus access and address/data masking
// rx_env_list_init [rf]: Configure RF bus access and address/data masking
int rx_env_list_init()
{
  int v0; // r4

  v0 = dword_12C57C;
  zero_struct(dword_12C57C);
  return zero_struct(v0 + 8);
}

