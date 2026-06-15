// v23 annotated: sub_12D380 @ 0x12d380
// Original: 12d380_sub_12D380.c
// Primary struct: delay_timer (cluster 0, 24 funcs)
// Fields: us=0x0, ticks=0x4
//
// sub_12D380 @ 0x12d380, size 70 bytes
int __fastcall sub_12D380(int result, _DWORD *a2, int (__fastcall *a3)(_DWORD *, _DWORD *))
{
  _DWORD *v3; // r4
  _DWORD *v4; // r7
  _DWORD *v7; // r8

  v3 = *(_DWORD **)result;
  v4 = (_DWORD *)result;
  if ( *(_DWORD *)result )
  {
    v7 = nullptr;
    for ( result = a3(a2, v3); !result; result = a3(a2, v3) )
    {
      v7 = v3;
      if ( !*v3 )
      {
        v4[1] = a2;
        *a2 = 0;
        goto LABEL_9;
      }
      v3 = (_DWORD *)*v3;
    }
    *a2 = v3;
    if ( !v7 )
      goto LABEL_7;
LABEL_9:
    *v7 = a2;
  }
  else
  {
    *(_DWORD *)(result + 4) = a2;
    *a2 = 0;
LABEL_7:
    *v4 = a2;
  }
  return result;
}

