// sub_1033C4 @ 0x1033c4, size 356 bytes
void __noreturn sub_1033C4()
{
  unsigned int *v0; // r6
  unsigned int *v1; // r5

  v0 = (unsigned int *)off_103528;
  v1 = (unsigned int *)off_10352C;
  *(uint32_t *)off_103528 |= 0x10u;
  *v1 = *v1 & 0xFFFFC0FF | 0x300;
  *v0 &= ~0x200u;
  *v0 = *v0 & 0xFFFE03FF | 0x10000;
  *v1 |= 0x4000u;
  while ( 1 )
    ;
}

