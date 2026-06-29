// fwstruct annotate: 100688_hw_config_init_0688.c
// hw_config_init_0688 @ 0x100688, size 50 bytes
// Doc: hw_config_init_0688 [util]: Initialize hardware configuration
// hw_config_init_0688 [util]: Initialize hardware configuration
int hw_config_init_0688()
{
  int *v0; // r4
  int inited; // r5
  int result; // r0
  __int16 v3; // r2

  v0 = (int *)off_1006C0;
  inited = fw_init_setup(HIBYTE(*(_DWORD *)off_1006BC) & 3);
  memset_thunk(v0, 0, 8u);
  result = dword_1006C4 + 16 * inited;
  v3 = *(_WORD *)(result + 6);
  *(_DWORD *)off_1006C8 = *(unsigned __int16 *)(result + 4);
  *((_BYTE *)v0 + 1) = v3;
  *(_BYTE *)v0 = -1;
  return result;
}

