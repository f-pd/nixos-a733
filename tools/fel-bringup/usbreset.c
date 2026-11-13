#include <libusb.h>
#include <stdio.h>
int main(void){ libusb_context*c; libusb_init(&c);
 libusb_device_handle*h=libusb_open_device_with_vid_pid(c,0x1f3a,0xefe8);
 if(!h){puts("no device");return 1;}
 int r=libusb_reset_device(h); printf("reset: %s\n", libusb_error_name(r)); libusb_close(h); libusb_exit(c); return r!=0 && r!=LIBUSB_ERROR_NOT_FOUND; }
