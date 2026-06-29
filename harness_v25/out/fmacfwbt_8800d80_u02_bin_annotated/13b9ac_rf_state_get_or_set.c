// fwstruct annotate: 13b9ac_rf_state_get_or_set.c
// rf_state_get_or_set @ 0x13b9ac, size 68 bytes
// Doc: rf_state_get_or_set [rf]: Inspect or modify RF state byte at offset 0x106+6 based on value 2
// rf_state_get_or_set [rf]: Inspect or modify RF state byte at offset 0x106+6 based on value 2
int __fastcall rf_state_get_or_set(int a1)
{
  int v1; // r3
  int v2; // r6
  int (__fastcall *v4)(int, int); // r2
  unsigned __int8 v5; // r0

  v1 = *(unsigned __int8 *)(a1 + 262) + a1;
  if ( *(_BYTE *)(v1 + 6) != 2 )
    return 0;
  LOBYTE(v2) = 0;
  do
  {
    *(_BYTE *)(v1 + 6) = 0;
    v4 = *(int (__fastcall **)(int, int))a1;
    *(_WORD *)(a1 + 4) = (*(_WORD *)(a1 + 4) + 1) & 0xFFF;
    v5 = v4(a1, 1);
    v1 = a1 + v5;
    *(_BYTE *)(a1 + 262) = v5;
    v2 = (char)(v2 + 1);
  }
  while ( *(_BYTE *)(v1 + 6) == 2 );
  return v2;
}

