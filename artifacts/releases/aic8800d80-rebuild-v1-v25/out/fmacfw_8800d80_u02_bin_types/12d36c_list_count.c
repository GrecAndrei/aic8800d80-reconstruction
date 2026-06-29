// list_count @ 0x12d36c, size 20 bytes
// Doc: list_count [util]: Return node count loaded from list head pointer (linked-list length helper)
// list_count [util]: Return node count loaded from list head pointer (linked-list length helper)
int  list_count(uint32_t **a1)
{
  uint32_t *v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    v1 = (uint32_t *)*v1;
    ++result;
  }
  while ( v1 );
  return result;
}

