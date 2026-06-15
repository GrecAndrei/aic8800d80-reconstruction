// sub_12686C @ 0x12686c, size 108 bytes
// Doc: sub_122686C [rf]: Reads flag byte from global base, RF state poll
// sub_122686C [rf]: Reads flag byte from global base, RF state poll
int __fastcall sub_12686C(int result)
{
  unsigned __int16 *v1; // r7
  int *v2; // r1
  int v3; // r12
  int v4; // r6
  int v5; // r5
  int v6; // r4
  int v7; // r2
  unsigned int v8; // r3
  unsigned int v9; // t1
  unsigned int v10; // r2
  int v11; // r2

  v1 = (unsigned __int16 *)off_1268D8;
  if ( !*((_BYTE *)off_1268D8 + 36) )
  {
    v2 = (int *)dword_1268DC;
    v3 = dword_1268E8;
    v4 = dword_1268E0;
    v5 = dword_1268E4;
    v6 = dword_1268DC + 128;
    while ( 1 )
    {
      while ( 1 )
      {
        v9 = v2[1];
        ++v2;
        v8 = v9;
        v10 = v9 >> 8;
        if ( ((v9 >> 8) & 0xC) != 0 )
          break;
LABEL_7:
        if ( (int *)v6 == v2 )
          return mmio_set_bit_120090C(0, v1[20]);
      }
      v11 = v10 & 0xF;
      if ( result )
      {
        if ( v11 == 4 )
        {
          v7 = 0x1000000;
        }
        else if ( v11 == 7 )
        {
          v7 = 0;
        }
        else
        {
          v7 = (15 - v11) << 24;
        }
        *v2 = v8 & v5 | v7;
        goto LABEL_7;
      }
      *v2 = v8 & v3 | v4;
      if ( (int *)v6 == v2 )
        return mmio_set_bit_120090C(0, v1[20]);
    }
  }
  return result;
}

