// fwstruct annotate: 102e48_sub_102E48.c
// sub_102E48 @ 0x102e48, size 50 bytes
int __fastcall sub_102E48(int a1)
{
  int *v1; // r2
  int v2; // r3

  if ( a1 )
  {
    v1 = (int *)off_102E80;
    *(_DWORD *)off_102E7C &= ~0x400u;
    v2 = *v1 | 0x8000000;
  }
  else
  {
    v1 = (int *)off_102E7C;
    *(_DWORD *)off_102E80 &= ~0x8000000u;
    v2 = *v1 | 0x400;
  }
  *v1 = v2;
  return rf_init_or_config_helper(a1);
}

