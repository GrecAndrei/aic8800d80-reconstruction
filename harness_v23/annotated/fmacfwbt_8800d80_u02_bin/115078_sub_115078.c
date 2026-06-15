// v23 annotated: sub_115078 @ 0x115078
// Original: 115078_sub_115078.c
// Primary struct: <unclustered>
//
// sub_115078 @ 0x115078, size 70 bytes
// Doc: patch_apply_n_46c [patch]: Apply patch: store byte, call indirect via r3 with arg 0xa, then bit-shift result
// patch_apply_n_46c [patch]: Apply patch: store byte, call indirect via r3 with arg 0xa, then bit-shift result
int __fastcall sub_115078(char a1, _BYTE *a2)
{
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0
  char v6; // r2

  v3 = (unsigned int)MEMORY[0x1FC](10) >> (8 * a1);
  v4 = (unsigned __int8)v3 >> 4;
  if ( (v3 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(_BYTE)v3 )
    {
      *a2 = 0;
      return 2;
    }
    v4 = (unsigned __int8)v3;
    result = 1;
  }
  if ( (v4 & 1) != 0 )
    v6 = -1;
  else
    v6 = 1;
  *a2 = (v4 >> 1) * v6;
  return result;
}

