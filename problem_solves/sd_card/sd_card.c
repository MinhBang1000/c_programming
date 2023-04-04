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
	char path[] = "/home/minhbang/Data/c_workspace/c_programming/problem_solves/sd_card/mounted";

	/*mount SD device*/
	ret = mount("/dev/sda", "/mnt/sda", "ext4", MS_SYNCHRONOUS, NULL);
	if (ret == -1) {
		printf("Not found /dev/sda\r\n");
		printf("Error code = %d\n", errno);
	} else {
		printf("Found /dev/sda\r\n");
	}

	// sprintf(filename, "/home/minhbang/Data/c_workspace/c_programming/problem_solves/sd_card/mounted/tmpfile\n");	
	// printf("%s", filename);
	// /*create file on SD Card*/
	// fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC);
	// if (fd == -1) {
	// 	printf("create file failed. errno: %d\r\n", errno);		
	// } else {
	// 	/*write file to SD Card*/
	// 	ret = write(fd, buf, sizeof(buf));
	// 	if (ret == -1) {
	// 		printf("write file failed. errno: %d\r\n", errno);
	// 	} else {
	// 		printf("write tmpfile to SD Card ok\r\n");
	// 	}
	// }
	// close(fd);

	// /*umount SD Card*/	
	// while (1) {
	// 	ret = umount("/mnt/mmc");
	// 	if (ret != 0) {
	// 		if (errno == EBUSY) { 
	// 			sleep(1);
	// 			continue;
	// 		}	
	// 	}
	// 	printf("umount /mnt/mmc\r\n");
	// 	break;
	// }
}