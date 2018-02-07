#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static LIST_HEAD(birthday_list);

struct birthday{
	int day;
	int month;
	int year;
	int name;
	struct list_head list;
}

struct birthday *person;
person = kmalloc(sizeof(*person), GFP KERNEL);
person->day = 2;
person->month= 8;
person->year = 1995;
INIT_LIST_HEAD(&person->list);
list_add_tail(&person->list, &birthday list);

/* This function is called when the module is loaded. */
int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n");

	//Traversing the linked list
	struct birthday *ptr;

	list_for_each_entry(ptr, &birthday list, list) {
		/* on each iteration ptr points */
		/* to the next birthday struct */
	}

	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");

	//Removing elements from the linked list
	list_for_each_entry_safe(ptr,next,&birthday list,list) {
		/* on each iteration ptr points */
		/* to the next birthday struct */
		list_del(&ptr->list);
		kfree(ptr);
	}
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");




