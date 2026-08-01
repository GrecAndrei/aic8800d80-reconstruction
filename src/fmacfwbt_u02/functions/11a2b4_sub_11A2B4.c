// llc_tx_process @ 0x11a2b4, size 72 bytes
int llc_tx_process()
{
  int v0; // r4
  int *v1; // r7
  int v2; // r6
  int v3; // r9
  int result; // r0
  int v5; // t1
  int v6; // r5
  int v7; // r8

  v0 = dword_11A2FC;
  v1 = (int *)dword_11A300;
  v2 = dword_11A304;
  v3 = dword_11A2FC + 48;
  do
  {
    result = zero_struct(v0);
    v5 = *v1++;
    if ( v5 > 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        result = check_abort_flag(v0);
        ++v7;
        v6 += 360;
      }
      while ( v7 < *(v1 - 1) );
    }
    v0 += 8;
    v2 += 4;
  }
  while ( v0 != v3 );
  return result;
}

