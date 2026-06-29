// fw_init_or_status_check @ 0x102bc0, size 38 bytes
// Doc: fw_init_or_status_check [util]: Initialize FW state and poll sign halfword status
// fw_init_or_status_check [util]: Initialize FW state and poll sign halfword status
int  fw_init_or_status_check(int a1, int a2, int a3)
{
  int result; // r0

  result = msg_parse(dword_102BEC, dword_102BE8, a3);
  if ( **(__int16 **)off_102BF0 < 0 )
    return sub_12F46C(dword_102BF8, dword_102BF4, 61);
  return result;
}

