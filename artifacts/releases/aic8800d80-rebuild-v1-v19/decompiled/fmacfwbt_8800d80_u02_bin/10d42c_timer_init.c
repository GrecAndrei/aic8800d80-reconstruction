// timer_init @ 0x10d42c, size 68 bytes
// Doc: timer_init [util]: Initialize firmware timer subsystem
// timer_init [util]: Initialize firmware timer subsystem
int timer_init()
{
  unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  _DWORD *v3; // r3

  v0 = (unsigned int *)off_10D470;
  v1 = *(_DWORD *)off_10D470;
  if ( (*(_DWORD *)off_10D470 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((_DWORD *)off_10D470 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(_DWORD *)off_10D470 = v1 | 0x4040;
  v3 = off_10D478;
  *(_DWORD *)(*((_DWORD *)off_10D474 + 2) + 148) = dword_10D47C;
  *v3 = 0x200000;
  return result;
}

