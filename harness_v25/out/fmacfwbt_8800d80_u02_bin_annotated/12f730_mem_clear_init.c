// fwstruct annotate: 12f730_mem_clear_init.c
// mem_clear_init @ 0x12f730, size 16 bytes
// Doc: mem_clear_init [util]: Initialize/zero a 8-byte buffer then return 0
// mem_clear_init [util]: Initialize/zero a 8-byte buffer then return 0
int mem_clear_init()
{
  memset_thunk((int *)dword_12F740, 0, 8u);
  return 0;
}

