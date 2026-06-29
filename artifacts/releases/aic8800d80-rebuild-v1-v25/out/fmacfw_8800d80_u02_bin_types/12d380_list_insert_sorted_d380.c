// list_insert_sorted_d380 @ 0x12d380, size 70 bytes
// Doc: list_insert_sorted_d380 [util]: Insert node into a sorted linked list by key
// list_insert_sorted_d380 [util]: Insert node into a sorted linked list by key
int  list_insert_sorted_d380(int result, uint32_t *a2, int ( *a3)(uint32_t *, uint32_t *))
{
  uint32_t *v3; // r4
  uint32_t *v4; // r7
  uint32_t *v7; // r8

  v3 = *(uint32_t **)result;
  v4 = (uint32_t *)result;
  if ( *(uint32_t *)result )
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
      v3 = (uint32_t *)*v3;
    }
    *a2 = v3;
    if ( !v7 )
      goto LABEL_7;
LABEL_9:
    *v7 = a2;
  }
  else
  {
    *(uint32_t *)(result + 4) = a2;
    *a2 = 0;
LABEL_7:
    *v4 = a2;
  }
  return result;
}

