// fmacfw_version_get @ 0x12ea44, size 6 bytes
// Doc: fmacfw_version_get [util]: Return pointer to firmware version string
// fmacfw_version_get [util]: Return pointer to firmware version string
int fmacfw_version_get()
{
  return *(_DWORD *)off_12EA4C;
}

