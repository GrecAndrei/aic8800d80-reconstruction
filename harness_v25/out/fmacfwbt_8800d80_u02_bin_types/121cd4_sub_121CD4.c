// sub_121CD4 @ 0x121cd4, size 86 bytes
int sub_121CD4()
{
  if ( **(__int16 **)off_121D2C < 0 && msg_get_value(0) != 3 )
    sub_12F694(dword_121D40, dword_121D3C, 1785);
  if ( *((uint8_t *)off_121D30 + 31) && *((unsigned __int8 *)off_121D34 + 18) + *((unsigned __int8 *)off_121D34 + 17) <= 1 )
    return rf_bus_mark_n_3b7(0);
  *(uint32_t *)off_121D38 = 48;
  return rf_bus_mark_n_3b7(0);
}

