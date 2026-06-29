// fwstruct annotate: 12d9d0_msg_alloc_and_init_n1e6.c
// msg_alloc_and_init_n1e6 @ 0x12d9d0, size 40 bytes
// Doc: msg_alloc_and_init_n1e6 [ipc]: Allocate and initialize 5-word message structure
// msg_alloc_and_init_n1e6 [ipc]: Allocate and initialize 5-word message structure
unsigned __int8 *__fastcall msg_alloc_and_init_n1e6(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+Eh] [bp-2h] BYREF

  result = sub_12D788(a1, a2, (unsigned __int8 *)dword_12D9F8, 5, &v5);
  if ( result )
  {
    if ( v5 <= 0x17u )
      return nullptr;
    else
      *a3 = v5 - 2;
  }
  return result;
}

