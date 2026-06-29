// fwstruct annotate: 114e7c_indirect_call_trampoline.c
// indirect_call_trampoline @ 0x114e7c, size 8 bytes
// Doc: indirect_call_trampoline [util]: Trampoline performing indirect call through 0x1fc vector
// indirect_call_trampoline [util]: Trampoline performing indirect call through 0x1fc vector
int indirect_call_trampoline()
{
  return MEMORY[0x1FC]();
}

