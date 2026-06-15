// sub_12C5FC @ 0x12c5fc, size 152 bytes
int __fastcall sub_12C5FC(int result, int a2)
{
  int *v2; // r5
  _DWORD *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12C694 = 1;
  }
  v2 = (int *)off_12C698;
  v3 = off_12C69C;
  v4 = *((_DWORD *)off_12C69C + 5);
  v5 = *(_DWORD *)off_12C698 + 1;
  *(_DWORD *)off_12C698 = v5;
  if ( v4 )
  {
    if ( *(unsigned __int16 *)(v4 + 4) == result && *(unsigned __int16 *)(v4 + 6) == a2 )
    {
      sub_12D190(v3 + 5);
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        sub_124BFC(v9, *(_DWORD *)(v8 + 8));
        if ( **(__int16 **)off_12C6A8 < 0 && *(_DWORD *)(v8 + 8) - *((_DWORD *)off_12C6AC + 4) < 0 )
          sub_12F32C(dword_12C6B4, dword_12C6B0, 232);
      }
      else
      {
        sub_124CF4(v9);
      }
    }
    else
    {
      result = sub_12C8FC(dword_12C6A4, off_12C6A0, a2 | (result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = sub_12CA88(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(_DWORD *)off_12C694;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

