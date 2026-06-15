// v23 annotated: fmacfw_version_get @ 0x12ea44
// Original: 12ea44_fmacfw_version_get.c
// Primary struct: delay_timer (cluster 0, 24 funcs)
// Fields: us=0x0, ticks=0x4
//
// fmacfw_version_get @ 0x12ea44, size 6 bytes
// Doc: fmacfw_version_get [util]: Return pointer to firmware version string
// fmacfw_version_get [util]: Return pointer to firmware version string
int fmacfw_version_get()
{
  return *(_DWORD *)off_12EA4C;
}

