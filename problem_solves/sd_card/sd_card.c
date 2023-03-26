/*
 *	Description: 
 *		example for SD Card.
 *	
 *		What is shown in this example:
 *		1. How to mount SD Card
 *		2. How to write a file to SD Card
 *		3. How to umount SD Card
 */
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mount.h>
#include <unistd.h>

const char buf[] = "MATRIX SD Card Example\n";

int main(void)
{
	int	ret, fd;
	char	filename[128];

	/*mount SD device*/
	ret = mount("/dev/mmc", "/mnt/mmc", "vfat", MS_SYNCHRONOUS, NULL);
	if (ret == -1) {
		ret = mount("/dev/mmc0", "/mnt/mmc", "vfat", MS_SYNCHRONOUS, NULL);
		if(ret == -1) {
			printf("no device found\r\n");
			return;
		}
		printf("found /dev/mmc0\r\n");
	} else {
		printf("found /dev/mmc\r\n");
	}

	sprintf(filename, "/mnt/mmc/tmpfile");	
	/*create file on SD Card*/
	fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC);
	if (fd == -1) {
		printf("create file failed. errno: %d\r\n", errno);		
	} else {
		/*write file to SD Card*/
		ret = write(fd, buf, sizeof(buf));
		if (ret == -1) {
			printf("write file failed. errno: %d\r\n", errno);
		} else {
			printf("write tmpfile to SD Card ok\r\n");
		}
	}
	close(fd);

	/*umount SD Card*/	
	while (1) {
		ret = umount("/mnt/mmc");
		if (ret != 0) {
			if (errno == EBUSY) { 
				sleep(1);
				continue;
			}	
		}
		printf("umount /mnt/mmc\r\n");
		break;
	}
}