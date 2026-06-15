// v23 annotated: rf_level_apply_6d60 @ 0x126d60
// Original: 126d60_rf_level_apply_6d60.c
// Primary struct: <unclustered>
//
// rf_level_apply_6d60 @ 0x126d60, size 52 bytes
// Doc: rf_level_apply_n_60 [rf]: Apply RF level by clearing bits 0x10000 and 0x780000 in control registers
// rf_level_apply_n_60 [rf]: Apply RF level by clearing bits 0x10000 and 0x780000 in control registers
int __fastcall rf_level_apply_6d60(int a1)
{
  void *v1; // r1
  unsigned int *v2; // r2
  int v3; // r3
  int v4; // r0
  unsigned int v5; // r3

  v1 = rf_level_apply_6d94;
  v2 = (unsigned int *)off_126D98;
  v3 = *(_DWORD *)rf_level_apply_6d94;
  if ( a1 )
  {
    *(_DWORD *)rf_level_apply_6d94 = v3 | 0x10000;
    v4 = rf_level_apply_0;
    v5 = *v2 & 0xFF87FFFF | 0x700000;
  }
  else
  {
    *(_DWORD *)rf_level_apply_6d94 = v3 & 0xFFFEFFFF;
    v4 = rf_level_apply_n_38;
    v5 = *v2 & 0xFF87FFFF;
  }
  *v2 = v5;
  return msg_parse(v4, v1, v2, v5);
}

