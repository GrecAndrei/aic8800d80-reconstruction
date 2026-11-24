// hw_config_init @ 0x1005a4, size 50 bytes
// Doc: hw_config_init [rf]: Initialize RF hardware config (peripheral base, RF params)
// hw_config_init [rf]: Initialize RF hardware config (peripheral base, RF params)
int hw_config_init()
{
  int *v0; // r4
  int v1; // r5
  int result; // r0
  __int16 v3; // r2

  v0 = (int *)off_1005DC;
  v1 = sub_1004CC(HIBYTE(*(_DWORD *)off_1005D8) & 3);
  sub_100200(v0, 0, 8u);
  result = dword_1005E0 + 16 * v1;
  v3 = *(_WORD *)(result + 6);
  *(_DWORD *)off_1005E4 = *(unsigned __int16 *)(result + 4);
  *((_BYTE *)v0 + 1) = v3;
  *(_BYTE *)v0 = -1;
  return result;
}

