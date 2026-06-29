// sub_109620 @ 0x109620, size 278 bytes
int  sub_109620(float *a1, float *a2)
{
  float v2; // s15
  float v3; // s14
  float v4; // s13

  v2 = *a1;
  v3 = a1[1];
  if ( *a1 < v3 && *a2 >= a2[1] )
    return 2;
  if ( v2 > v3 && *a2 <= a2[1] )
    return 2;
  v4 = a1[2];
  if ( v2 < v4 && *a2 >= a2[2] )
    return 2;
  if ( v2 > v4 && *a2 <= a2[2] || v3 < v4 && a2[1] >= a2[2] || v3 > v4 && a2[1] <= a2[2] )
    return 2;
  if ( *a2 > 0.0 && a2[1] > 0.0 && a2[2] > 0.0 )
    return 1;
  if ( *a2 >= 0.0 || a2[1] >= 0.0 )
    return 0;
  return a2[2] < 0.0;
}

