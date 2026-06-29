// fwstruct annotate: 135930_sub_135930.c
// sub_135930 @ 0x135930, size 46 bytes
void __fastcall sub_135930(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v14; // r1
  int v15; // r2
  int v16; // r3

  event_queue_push(6154, 6);
  if ( a1 )
  {
    feature_guard_check(256, dword_135960, a1);
    sub_134E04(a1, v14, v15, v16, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
  else
  {
    queue_pending_check();
  }
}

