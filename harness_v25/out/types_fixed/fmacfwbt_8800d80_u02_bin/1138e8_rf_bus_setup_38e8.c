// rf_bus_setup_38e8 @ 0x1138e8, size 16 bytes
// Doc: rf_bus_setup_38e8 [rf]: Initializes RF bus addresses from globals
// rf_bus_setup_38e8 [rf]: Initializes RF bus addresses from globals
BOOL rf_bus_setup_38e8()
{
  return *((unsigned __int8 *)off_1138F8 + 8) == 1;
}

