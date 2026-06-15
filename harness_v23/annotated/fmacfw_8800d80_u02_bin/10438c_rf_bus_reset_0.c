// v23 annotated: rf_bus_reset_0 @ 0x10438c
// Original: 10438c_rf_bus_reset_0.c
// Primary struct: <unclustered>
//
// rf_bus_reset_0 @ 0x10438c, size 66 bytes
// Doc: rf_bus_reset [rf]: Resets RF bus state via shifted write
// rf_bus_reset [rf]: Resets RF bus state via shifted write
int __fastcall rf_bus_reset_0(int a1, int a2, _DWORD *a3)
{
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (unsigned __int16)*(_DWORD *)off_1043D0;
  v4 = 0x3FFF;
  if ( v3 == 0x3FFF )
    a3 = (_DWORD *)*a3;
  else
    v4 = v3 + 1;
  if ( v3 != 0x3FFF )
    a3 = (_DWORD *)a3[v4];
  if ( ((unsigned __int8)a3 & 1) != 0 )
  {
    if ( a2 )
      goto LABEL_8;
  }
  else if ( a2 != 1 )
  {
LABEL_8:
    result = v3 + 2 + 2 * a1;
    goto LABEL_9;
  }
  result = v3 + 1 + 2 * a1;
LABEL_9:
  if ( result >= 0x4000 )
    result -= 0x4000;
  return result;
}

