// sub_127F8C @ 0x127f8c, size 48 bytes
int __fastcall sub_127F8C(__int64 a1, int a2, int a3)
{
  if ( a3 || a2 )
  {
    LODWORD(a1) = sub_127FBC(a1);
  }
  else if ( a1 )
  {
    LODWORD(a1) = -1;
  }
  return a1;
}

