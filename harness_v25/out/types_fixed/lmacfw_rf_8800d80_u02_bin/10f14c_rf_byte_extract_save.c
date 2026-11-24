// rf_byte_extract_save @ 0x10f14c, size 12 bytes
// Doc: rf_byte_extract_save [rf]: Extracts high byte and saves to stack
// rf_byte_extract_save [rf]: Extracts high byte and saves to stack
int rf_byte_extract_save()
{
  return sub_10F064(dword_10F158, 0, 2, 1);
}

