// v23 annotated: sub_101754 @ 0x101754
// Original: 101754_sub_101754.c
// Primary struct: <unclustered>
//
// sub_101754 @ 0x101754, size 390 bytes
// Doc: sub_1201754 [util]: Check signed half-word from shared state and branch on result
// sub_1201754 [util]: Check signed half-word from shared state and branch on result
void __noreturn sub_101754()
{
  if ( **(__int16 **)off_1018DC < 0
    && (unsigned __int8)BYTE2(*(_DWORD *)off_101928) + 10 * (HIBYTE(*(_DWORD *)off_101928) + 2) != 32 )
  {
    sub_12F46C(dword_101930, dword_10192C, 6119);
  }
  panic_loop_06d8();
}

