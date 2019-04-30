
#include <stdio.h>

/**
 * file: include/linux/list.h
 * ͨ�����ݽṹ�е�ĳ����(field����Ա)ָ�룬�õ������ṹ���ָ�롣
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
	((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

typedef struct foo
{
	char c;
	int i;
	float f;
} __attribute__ ((packed)) foo_t;

int main()
{
	foo_t t;
	t.c = 'H';
	t.i = 123;
	t.f = 3.14;
	printf("�ṹ�����: c= %c, i= %d, f= %f\n", t.c, t.i, t.f);
	
	int *pi = &t.i;
	foo_t * pt = list_entry(pi, foo_t, i);
	printf("�ṹ��ָ�����: c= %c, i= %d, f= %f\n", pt->c, pt->i, pt->f);
	
	printf("field offset: %lu\n",(unsigned long)(&((foo_t *)0)->f));
	return 0;
}
