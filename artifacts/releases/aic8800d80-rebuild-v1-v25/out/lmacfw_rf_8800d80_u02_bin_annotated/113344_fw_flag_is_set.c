// fwstruct annotate: 113344_fw_flag_is_set.c
// fw_flag_is_set @ 0x113344, size 16 bytes
// Doc: fw_flag_is_set [util]: Return 1 if firmware flag byte is 0 or 1, else 0
// fw_flag_is_set [util]: Return 1 if firmware flag byte is 0 or 1, else 0
BOOL fw_flag_is_set()
{
  return *((unsigned __int8 *)off_113354 + 8) == 1;
}

