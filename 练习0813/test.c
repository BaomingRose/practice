#if 1


#include<stdio.h>

/*静态局部变量使用static修饰符定义，即使在声明时未赋初值，编译器也会把它初始化为0。
且静态局部变量存储于进程的全局数据区，即使函数返回，它的值也会保持不变。*/
/*其作用域为局部作用域，当定义它的函数结束时，其作用域随之结束*/

/*全局变量定义在函数体外部，在全局数据区分配存储空间，且编译器会自动对其初始化。
普通全局变量对整个工程可见，其他文件可以使用extern外部声明后直接使用。
也就是说其他文件不能再定义一个与其相同名字的变量了（否则编译器会认为它们是同一个变量）。
静态全局变量仅对当前文件可见，其他文件不可访问，其他文件可以定义与其同名的变量，两者互不影响。*/

int fun(int x, int y) {
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}

int main() {
	int j = 4; 
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d,", k);		//8
	k = fun(j, m);
	printf("%d\n", k);		//17
	return 0;
}
#endif
