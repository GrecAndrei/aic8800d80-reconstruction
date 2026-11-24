// sub_114B44 @ 0x114b44, size 44 bytes
// Doc: patch_apply_n_34d [patch]: Apply patch and return status (1/2/0)
// patch_apply_n_34d [patch]: Apply patch and return status (1/2/0)
int __fastcall sub_114B44(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = MEMORY[0x1FC](15);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (_BYTE)v2 )
      return 1;
    else
      return 2;
  }
}

