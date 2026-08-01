// llm_env_init @ 0x11831c, size 56 bytes
// Doc: llm_env_init [mac]: Initialize and register a small lmac control block via memset and log_alloc
// llm_env_init [mac]: Initialize and register a small lmac control block via memset and log_alloc
int llm_env_init()
{
  int v0; // r4

  v0 = dword_118354;
  memset_byte((int *)dword_118354, 0, 0x28u);
  zero_struct(v0);
  zero_struct(v0 + 8);
  zero_struct(v0 + 16);
  zero_struct(v0 + 24);
  return zero_struct(v0 + 32);
}

