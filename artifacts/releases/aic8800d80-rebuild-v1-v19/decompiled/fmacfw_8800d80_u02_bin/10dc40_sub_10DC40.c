// sub_10DC40 @ 0x10dc40, size 90 bytes
// Doc: sub_120DC40 [mmio]: Reads status register block at 0x40505000
// sub_120DC40 [mmio]: Reads status register block at 0x40505000
void sub_10DC40()
{
  _DWORD *v0; // r4
  unsigned int v1; // r3
  signed int v2; // r3
  int v3; // r6
  int v4; // r0
  unsigned int v5; // r2
  void (__fastcall *v6)(int); // r1

  v0 = off_10DC9C;
  v1 = *((_DWORD *)off_10DC9C + 8);
  if ( v1 )
  {
    v2 = 31 - __clz(v1);
    if ( v2 <= 7 )
    {
      v3 = dword_10DCA0;
      do
      {
        v0[9] = 1 << v2;
        __isb(0xFu);
        v6 = *(void (__fastcall **)(int))(v3 + 4 * v2);
        if ( v6 )
        {
          if ( ((v0[4] >> v2) & 1) != 0 )
            v4 = 2;
          else
            v4 = ((v0[5] >> v2) & 1) == 0;
          v6(v4 | (v2 << 16));
        }
        v5 = v0[8];
        v2 = 31 - __clz(v5);
      }
      while ( v5 && v2 <= 7 );
    }
  }
}

