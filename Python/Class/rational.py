class Rational:             #定义一个有理数类
    @staticmethod
    def _gcd(m,n):          #定义一个局部使用的方法_gcd()以对分子分母约分
        if n == 0:
            m,n = n,m
        while m != 0:
            m,n = n%m,m
        return n
    
    def __init__(self,num,den=1):
        if not isinstance(num,int) or not isinstance(den,int):#分子分母必须要为整数
            raise TypeError
        if den == 0:         #分母不为0                           
            raise ZeroDivisionError
        sign = 1            #判断正负
        if num < 0:
            num,sign = -num,-sign
        if den < 0:
            den,sign = -den,-sign
        a = Rational._gcd(num,den)#约分，输出最简形式
        self._num = sign * (num//a)
        self._den = den//a
        
    def num(self):#返回有理数的分子
        return self._num
    
    def den(self):#返回有理数的分母
        return self._den
    
    def plus(self,another):#定义有理数加法，通分后相加
        den = self._den * another.den()
        num = self._den * another.num() + self._num * another.den()
        return Rational(num,den)
    
    def minus(self,another):#定义有理数减法，通分后相减
        den = self._den * another.den()
        num = self._num * another.den() - self._den * another.num()  
        return Rational(num,den)
    
    def multiply(self,another):#定义有理数乘法。分子分母对应相乘再约分
        den = self._den * another.den()
        num = self._num * another.num()
        return Rational(num,den)
    
    def divide(self,another):#定义有理数除法
        den = self._den * another.num()
        num = self._num * another.den()
        return Rational(num,den)
    
    def string(self):#将有理数转化为字符串输出
        return str(self._num) + "/" + str(self._den)
    
    def print(self):#对计算后的结果进行打印，整数直接输出，其余输出分数形式
        if self._num % self._den == 0:
            print(int(self._num/self._den))
        else:
            print(self._num,"/",self._den)
    

