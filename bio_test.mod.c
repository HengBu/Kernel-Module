#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x588eb51a, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x3e9a2f0f, __VMLINUX_SYMBOL_STR(submit_bio) },
	{ 0xaa0944ba, __VMLINUX_SYMBOL_STR(bio_add_page) },
	{ 0x5e126480, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x8dc1a6f6, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0x5f636e1, __VMLINUX_SYMBOL_STR(fs_bio_set) },
	{ 0x5f38cf03, __VMLINUX_SYMBOL_STR(blkdev_get_by_path) },
	{ 0xc1f54d2d, __VMLINUX_SYMBOL_STR(get_fs_type) },
	{ 0xb4e36761, __VMLINUX_SYMBOL_STR(bio_put) },
	{ 0x39d0d4fc, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0x7b79f1b6, __VMLINUX_SYMBOL_STR(page_endio) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

