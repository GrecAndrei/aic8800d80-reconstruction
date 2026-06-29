// fwstruct annotate: 114a40_sub_114A40.c
// sub_114A40 @ 0x114a40, size 28 bytes
// Doc: sub_1214A40 [util]: Reads and checks a half-word global (likely init/version check)
// sub_1214A40 [util]: Reads and checks a half-word global (likely init/version check)
void __noreturn sub_114A40()
{
  if ( **(__int16 **)off_114A5C < 0 )
    rf_cmd_send_n264(dword_114A64, dword_114A60, 242);
  while ( 1 )
    ;
}

