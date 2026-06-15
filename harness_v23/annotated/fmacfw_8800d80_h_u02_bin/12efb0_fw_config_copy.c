// v23 annotated: fw_config_copy @ 0x12efb0
// Original: 12efb0_fw_config_copy.c
// Primary struct: <unclustered>
//
// fw_config_copy @ 0x12efb0, size 22 bytes
// Doc: fw_config_copy [util]: Copy firmware config block via 0x42c message
// fw_config_copy [util]: Copy firmware config block via 0x42c message
void __noreturn fw_config_copy()
{
  msg_parse(dword_12EFC8);
  sub_12C5FC(1068, 1);
  sub_12EF88();
}

