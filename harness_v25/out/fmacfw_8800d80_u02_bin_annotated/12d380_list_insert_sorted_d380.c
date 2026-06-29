// fwstruct annotate: 12d380_list_insert_sorted_d380.c
// list_insert_sorted_d380 @ 0x12d380, size 70 bytes
// Doc: list_insert_sorted_d380 [util]: Insert node into a sorted linked list by key
// list_insert_sorted_d380 [util]: Insert node into a sorted linked list by key
int __fastcall list_insert_sorted_d380(int result, _DWORD *a2, int (__fastcall *a3)(_DWORD *, _DWORD *))
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

