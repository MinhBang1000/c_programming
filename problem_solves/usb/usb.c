#include <sys/mount.h>
#include <stdio.h>
#include <errno.h>
int main() {
    const char* src  = "/dev/sda1";
    const char* trgt = "/media/minhbang/minhbang";
    const char* type = "ntfs";
    const unsigned long mntflags = 0;
    const char* opts = "mode=0700,uid=65534";   /* 65534 is the uid of nobody */

    int result = mount(src, trgt, type, mntflags, opts);
    printf("%d\n", result);
    printf("%d\n", errno);

    // printf("%d", mount("/dev/sda1", "/media/minhbang/minhbang", "ext4", MS_SYNCHRONOUS, NULL));
    // if () {
    //     if (errno == EBUSY) {
    //         printf("Mount point busy\n");
    //     } else {
    //         printf("Mount error: %d\n", errno);
    //     }
    // }else {
    //     printf("Mount successful\n");
    // }
    return 0;
}