// sub_103154 @ 0x103154, size 356 bytes
void __noreturn sub_103154()
{
  unsigned int *v0; // r6
  unsigned int *v1; // r5

  v0 = (unsigned int *)off_1032B8;
  v1 = (unsigned int *)off_1032BC;
  *(uint32_t *)off_1032B8 |= 0x10u;
  *v1 = *v1 & 0xFFFFC0FF | 0x300;
  *v0 &= ~0x200u;
  *v0 = *v0 & 0xFFFE03FF | 0x10000;
  *v1 |= 0x4000u;
  while ( 1 )
    ;
}

