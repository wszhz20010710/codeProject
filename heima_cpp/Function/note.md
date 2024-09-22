***
函数的默认参数

1.如果某个位置已有默认参数，那么从这个位置往后，从左到右都必须有默认值
2.如果函数声明有默认参数，函数实现就不能有默认参数
***
函数的占位参数

第二个参数只用来占位置

    void func(int a, int)

占位参数可以有默认参数
***
函数重载

函数名可以相同，提高复用性

条件：同一个作用域下，函数名称相同，参数类型、个数、顺序至少有一个不同，函数的返回值不能作为函数重载的条件

注意事项
1.引用作为重载的条件
2.函数重载碰到默认参数，会出现二义性，报错，尽量避免这种情况