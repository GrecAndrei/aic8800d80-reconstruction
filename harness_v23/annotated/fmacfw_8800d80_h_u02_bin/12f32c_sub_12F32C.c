// v23 annotated: sub_12F32C @ 0x12f32c
// Original: 12f32c_sub_12F32C.c
// Primary struct: <unclustered>
//
// sub_12F32C @ 0x12f32c, size 36 bytes
int __fastcall sub_12F32C(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_12F354;
  *(_DWORD *)off_12F350 = 0;
  result = sub_12E948(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(_DWORD *)off_12F358 )
    ;
  return result;
}

