// v23 annotated: rf_get_status_byte_n_a24 @ 0x11c324
// Original: 11c324_rf_get_status_byte_n_a24.c
// Primary struct: <unclustered>
//
// rf_get_status_byte_n_a24 @ 0x11c324, size 96 bytes
// Doc: rf_get_status_byte_n_a24 [rf]: Reads a single status byte at offset 0x19 from a structure
// rf_get_status_byte_n_a24 [rf]: Reads a single status byte at offset 0x19 from a structure
int __fastcall rf_get_status_byte_n_a24(int result)
{
  int v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r2

  if ( *(_BYTE *)(result + 25) )
  {
    v1 = 0;
    v2 = dword_11C384;
    while ( 1 )
    {
      v3 = *(_DWORD *)(v2 + 72);
      v2 += 224;
      if ( v3 == result )
        break;
      if ( ++v1 == 4 )
      {
        v4 = 15;
        goto LABEL_6;
      }
    }
    v4 = *(char *)(dword_11C384 + 224 * v1 + 97);
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = off_11C388;
    *(_BYTE *)(result + 12) = v4;
    if ( v5[10] == result )
      return sub_11D9F8(v4);
  }
  else
  {
    v6 = off_11C388;
    *(_BYTE *)(result + 12) = 15;
    if ( v6[10] == result )
      return sub_11D9F8(15);
  }
  return result;
}

