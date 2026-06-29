// fwstruct annotate: 128ef8_key_mfp_table_init.c
// key_mfp_table_init @ 0x128ef8, size 28 bytes
// Doc: key_mfp_table_init [ke]: Initialize MFP key table with assertion on hw_key_idx
// key_mfp_table_init [ke]: Initialize MFP key table with assertion on hw_key_idx
int key_mfp_table_init()
{
  _DWORD *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_128F14;
  v1 = memset_thunk((int *)off_128F14, 0, 0x28u);
  result = sub_1420A0(v1);
  v0[4] = off_128F18;
  *((_BYTE *)v0 + 28) = 1;
  return result;
}

