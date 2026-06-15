// sub_10327C @ 0x10327c, size 356 bytes
void __noreturn sub_10327C()
{
  unsigned int *v0; // r6
  unsigned int *v1; // r5

  v0 = (unsigned int *)off_1033E0;
  v1 = (unsigned int *)off_1033E4;
  *(_DWORD *)off_1033E0 |= 0x10u;
  *v1 = *v1 & 0xFFFFC0FF | 0x300;
  *v0 &= ~0x200u;
  *v0 = *v0 & 0xFFFE03FF | 0x10000;
  *v1 |= 0x4000u;
  while ( 1 )
    ;
}

