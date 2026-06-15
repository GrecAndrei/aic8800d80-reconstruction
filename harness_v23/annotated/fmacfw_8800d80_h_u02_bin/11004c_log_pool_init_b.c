// v23 annotated: log_pool_init_b @ 0x11004c
// Original: 11004c_log_pool_init_b.c
// Primary struct: <unclustered>
//
// log_pool_init_b @ 0x11004c, size 72 bytes
// Doc: log_pool_init_b [util]: Initialize log pool B using descriptors at 0x187e68/0x182ba0
// log_pool_init_b [util]: Initialize log pool B using descriptors at 0x187e68/0x182ba0
int log_pool_init_b()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = off_1100A0;
  result = sub_12D100(dword_110094);
  if ( *(_WORD *)(*(_DWORD *)v0 + 6) )
  {
    v2 = off_110098;
    v3 = dword_11009C;
    v4 = dword_110094;
    v5 = 0;
    do
    {
      sub_10F9E8(v3, 0x63Cu);
      result = sub_12D108(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

