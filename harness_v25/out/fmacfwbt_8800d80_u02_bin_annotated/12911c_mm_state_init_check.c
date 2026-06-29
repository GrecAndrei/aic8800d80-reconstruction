// fwstruct annotate: 12911c_mm_state_init_check.c
// mm_state_init_check @ 0x12911c, size 28 bytes
// Doc: mm_state_init_check [mac]: Initialize MM state and assert MM_IDLE transition
// mm_state_init_check [mac]: Initialize MM state and assert MM_IDLE transition
int mm_state_init_check()
{
  _DWORD *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_129138;
  v1 = memset_thunk((int *)off_129138, 0, 0x28u);
  result = sub_14213C(v1);
  v0[4] = dword_12913C;
  *((_BYTE *)v0 + 28) = 1;
  return result;
}

