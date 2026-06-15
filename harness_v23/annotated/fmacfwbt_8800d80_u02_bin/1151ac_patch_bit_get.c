// v23 annotated: patch_bit_get @ 0x1151ac
// Original: 1151ac_patch_bit_get.c
// Primary struct: <unclustered>
//
// patch_bit_get @ 0x1151ac, size 18 bytes
// Doc: patch_bit_get [patch]: Calls helper and extracts single bit (bit 18) from returned flag word
// patch_bit_get [patch]: Calls helper and extracts single bit (bit 18) from returned flag word
unsigned int patch_bit_get()
{
  return ((unsigned int)MEMORY[0x1FC](15) >> 18) & 1;
}

