// fwstruct annotate: 10f1c8_log_free_wrapper.c
// log_free_wrapper @ 0x10f1c8, size 12 bytes
// Doc: log_free_wrapper [util]: Wrapper that frees log buffer and returns success
// log_free_wrapper [util]: Wrapper that frees log buffer and returns success
int __fastcall log_free_wrapper(int a1, int a2)
{
  log_free_dispatch_2(a2);
  return 1;
}

