// fwstruct annotate: 12cf5c_sub_12CF5C.c
// sub_12CF5C @ 0x12cf5c, size 278 bytes
_DWORD *__fastcall sub_12CF5C(unsigned int a1, int a2)
{
  __int16 **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  _WORD *v7; // r9
  _DWORD *result; // r0
  int (__fastcall *v9)(_DWORD *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r6

  v2 = (__int16 **)off_12D074;
  v5 = a1 >> 8;
  v6 = (unsigned __int8)a1;
  if ( **(__int16 **)off_12D074 >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a1 > 0xDu )
  {
    sub_12F694(dword_12D09C, dword_12D090, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (_WORD *)(*(_DWORD *)(dword_12D078 + 16 * v6 + 8) + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      sub_12F694(dword_12D0A4, dword_12D0A0, 183);
  }
  else if ( (unsigned __int8)a1 != 13 )
  {
    goto LABEL_16;
  }
  sub_12F694(dword_12D0A8, dword_12D090, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v16 = dword_12D078 + 16 * v6;
  if ( *(unsigned __int16 *)(v16 + 14) > v5 )
  {
    v7 = (_WORD *)(*(_DWORD *)(v16 + 8) + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  sub_12F694(dword_12D098, dword_12D090, 175);
  v7 = (_WORD *)(*(_DWORD *)(v16 + 8) + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    sub_12F694(dword_12D094, dword_12D090, 180);
LABEL_3:
  result = (_DWORD *)sub_12ECB0(dword_12D07C, a1, a2);
  if ( (unsigned __int16)*v7 != a2 )
  {
    v9 = (int (__fastcall *)(_DWORD *, int))dword_12D0AC;
    v10 = dword_12D080;
    v11 = (int *)off_12D084;
    *v7 = a2;
    while ( 1 )
    {
      result = sub_12CC64(v10, v9, a1);
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_12D088;
      v13 = dword_12D08C;
      ++*(_DWORD *)off_12D088;
      sub_12D470(v13);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      sub_12D32C(0x4000000);
    }
  }
  return result;
}

