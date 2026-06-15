// sub_140B78 @ 0x140b78, size 116 bytes
// Doc: fmac_irq_handler_n0b7c [mac]: FMAC interrupt handler
// fmac_irq_handler_n0b7c [mac]: FMAC interrupt handler
int __fastcall sub_140B78(unsigned __int16 *a1, int a2, int a3)
{
  int result; // r0
  int v6; // r2
  unsigned __int8 *v7; // r0
  char *v8; // r5
  unsigned __int8 v9; // [sp+4h] [bp-34h] BYREF
  char v10; // [sp+5h] [bp-33h] BYREF

  if ( !a3 )
    return 1;
  result = *(unsigned __int8 *)(a3 + 50);
  if ( *(_BYTE *)(a3 + 50)
    || *(unsigned __int16 *)(a3 + 52) == *a1
    && *(unsigned __int16 *)(a3 + 54) == a1[1]
    && *(unsigned __int16 *)(a3 + 56) == a1[2] )
  {
    v6 = *(unsigned __int8 *)(a3 + 58);
    if ( !*(_BYTE *)(a3 + 58) )
      return 1;
    if ( !a2 )
      return 1;
    v9 = *(_BYTE *)(a2 + 1);
    if ( !v9 )
      return 0;
    v7 = &v9;
    v8 = (char *)(&v9 + v9);
    do
    {
      v7[1] = v7[a2 + 2 - (_DWORD)&v9];
      ++v7;
    }
    while ( v7 != (unsigned __int8 *)v8 );
    return v9 == v6 && !sub_143710(a3 + 59, &v10, v6);
  }
  return result;
}

