#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/mm.h>
#include <linux/bio.h>
#include <linux/fs.h>
#include <linux/fs_struct.h>
#include <linux/buffer_head.h>
#include <linux/blkdev.h>
#include <linux/mpage.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Jay Salzman");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintArray[2] = { -1, -1 };
static int arr_argc = 0;

/*
 *  * module_param(foo, int, 0000)
 *   * The first param is the parameters name
 *    * The second param is it's data type
 *     * The final argument is the permissions bits,
 *      * for exposing parameters in sysfs (if non-zero) at a later stage.
 *       */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

/*
 *  * module_param_array(name, type, num, perm);
 *   * The first param is the parameter's (in this case the array's) name
 *    * The second param is the data type of the elements of the array
 *     * The third argument is a pointer to the variable that will store the number
 *      * of elements of the array initialized by the user at module loading time
 *       * The fourth argument is the permission bits
 *        */
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int __init hello_5_init(void)
{
	
	struct block_device *bdev;
	char *dev_name = "/dev/sda2";
	int nr_vecs ;
	struct file_system_type *fs_type;
	struct bio *bio;
	sector_t first_sector;
	fmode_t mode = FMODE_READ | FMODE_EXCL | FMODE_WRITE;
	gfp_t gfp_flags;
	
	printk(KERN_INFO "Module init ext4");

	fs_type = get_fs_type("ext4");
	if(fs_type != NULL ){
		printk(KERN_INFO "fs_type  found");
	}else{
		printk(KERN_INFO "fs_type not found");
	}

	bdev = blkdev_get_by_path(dev_name, mode, fs_type);
	if (IS_ERR(bdev)){
		printk(KERN_INFO "Fail to get bdev");
	}else{
		printk(KERN_INFO "Get bdev success");
	}
		
	nr_vecs = 1;
	gfp_flags = GFP_KERNEL;
	first_sector = 1;
	bio = bio_alloc(gfp_flags, nr_vecs);
	if(bio != NULL){
		printk(KERN_INFO "alloc bio success");
		bio->bi_bdev = bdev;
		bio->bi_iter.bi_sector = first_sector;
	}
	
	
	return 0;
}

static void __exit hello_5_exit(void)
{
	printk(KERN_INFO "Module exit\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);
