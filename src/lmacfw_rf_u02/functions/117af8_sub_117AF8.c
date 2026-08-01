// init_table_185d40 @ 0x117af8, size 74 bytes
int init_table_185d40()
{
  int v0; // r5
  int v1; // r7
  int i; // r6
  int v3; // r4
  int v4; // r0
  int result; // r0

  v0 = dword_117B48;
  v1 = dword_117B44;
  list_init(dword_117B44);
  for ( i = 0; i != 76; i += 19 )
  {
    mutex_acquire_if_ready(v0 - 88);
    check_kernel_state(v1);
    v3 = v0 - 32;
    do
    {
      list_init(v3);
      v4 = v3 + 32;
      v3 += 8;
      result = list_init(v4);
    }
    while ( v3 != v0 );
    v0 = v3 + 152;
  }
  return result;
}

