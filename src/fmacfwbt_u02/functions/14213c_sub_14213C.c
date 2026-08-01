// mac_init_ring @ 0x14213c, size 38 bytes
// Doc: mac_init_ring [util]: Initialize firmware data structure via memset and setup callback
// mac_init_ring [util]: Initialize firmware data structure via memset and setup callback
int *mac_init_ring()
{
  int *v0; // r4
  int *v1; // r5
  int *result; // r0

  v0 = (int *)dword_142168;
  memset_byte((int *)dword_142164, 0, 3u);
  v1 = v0 + 144;
  do
  {
    result = memset_byte(v0, 0, 0x48u);
    v0[15] = (int)v0;
    v0 += 18;
  }
  while ( v0 != v1 );
  return result;
}

