// sub_131784 @ 0x131784, size 142 bytes
int __fastcall sub_131784(int a1, unsigned __int8 *a2)
{
  int v3; // r5
  int v4; // r6
  char v5; // r3
  char v7; // r3

  v3 = *(_DWORD *)(dword_131818 + 696 * *a2 + 340);
  if ( **(__int16 **)off_131814 < 0 && !v3 )
    sub_12F46C(dword_131820, dword_13181C, 1031);
  v4 = *((unsigned __int16 *)a2 + 1);
  if ( v4 == 0xFFFF )
  {
    v5 = *(_BYTE *)(v3 + 166);
    *(_WORD *)(v3 + 190) = -1;
    v5 &= 0xCFu;
    *(_BYTE *)(v3 + 166) = v5;
    if ( (v5 & 0x80) == 0 )
      return 0;
    mac_table_lookup(*a2);
    *(_BYTE *)(v3 + 166) &= ~0x80u;
    return 0;
  }
  else
  {
    if ( !key_index_lookup(v3, *((unsigned __int16 *)a2 + 1)) )
      return 0;
    v7 = *(_BYTE *)(v3 + 166);
    *(_WORD *)(v3 + 190) = v4;
    *(_BYTE *)(v3 + 166) = v7 & 0xCF | 0x10;
    return 0;
  }
}

