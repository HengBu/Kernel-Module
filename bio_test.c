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
#include <linux/highmem.h>
#include <linux/buffer_head.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Heng Bu");


static void mypage_end_io(struct bio *bio)
{
	struct bio_vec *bv;
	int i;

	printk(KERN_INFO "bio is end");
	bio_for_each_segment_all(bv, bio, i) {
		struct page *page = bv->bv_page;
		page_endio(page, op_is_write(bio_op(bio)), bio->bi_error);
		if(!bio->bi_error){
			printk(KERN_INFO "bio success");
		}
		__free_page(page);
	}

	bio_put(bio);
}

static struct bio *mypage_bio_submit(int op, int op_flags, struct bio *bio)
{
	bio->bi_end_io = mypage_end_io;
	bio_set_op_attrs(bio, op, op_flags);
	//guard_bio_eod(op, bio);
	submit_bio(bio);
	printk(KERN_INFO "submit bio success");
	return NULL;
}


static int __init bio_test_init(void)
{
	
	struct block_device *bdev;
	char *dev_name = "/dev/sda2";
	int nr_vecs ;
	int length;
	struct file_system_type *fs_type;
	struct bio *bio;
	struct page *page;
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

	page = alloc_page(gfp_flags| __GFP_ZERO);
	if (page){
		printk(KERN_INFO "alloc page success");
	}else{
		printk(KERN_INFO "fail to alloc page");
	}

	length = 512;
	if (bio_add_page(bio, page, length, 0) == length) {
		bio = mypage_bio_submit(REQ_OP_READ, 0, bio);	
	}
	
	
	return 0;
}

static void __exit bio_test_exit(void)
{
	printk(KERN_INFO "Module exit\n");
}

module_init(bio_test_init);
module_exit(bio_test_exit);
