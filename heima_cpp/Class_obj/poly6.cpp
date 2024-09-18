#include <iostream>
#include <string>
using namespace std;

// 多态案例3——电脑组装
class CPU
{
public:
    virtual void Calculate() = 0;
};

class GPU
{
public:
    virtual void Display() = 0;
};

class DRAM
{
public:
    virtual void Write() = 0;
};

class SSD
{
public:
    virtual void Storage() = 0;
};

class PowerSource
{
public:
    virtual void Enpower() = 0;
};

// 具体型号
class Intel_12400f : public CPU
{
public:
    virtual void Calculate()
    {
        cout << "Intel_12400f开始计算了！" << endl;
    }
};

class Nvidia_4060ti : public GPU
{
public:
    virtual void Display()
    {
        cout << "Nvidia_4060ti开始显示了！" << endl;
    }
};

class DDR4 : public DRAM
{
public:
    virtual void Write()
    {
        cout << "DDR4开始写入了！" << endl;
    }
};

class PC005 : public SSD
{
public:
    virtual void Storage()
    {
        cout << "硬盘开始存储了！" << endl;
    }
};

class GM750 : public PowerSource
{
public:
    virtual void Enpower()
    {
        cout << "电源开始供电了！" << endl;
    }
};


class Computer
{
public:
    Computer(CPU * cpu, GPU * gpu, DRAM * dram, SSD * ssd, PowerSource  * power)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_dram = dram;
        m_ssd = ssd;
        m_power = power;
    }

    void work()
    {
        m_cpu->Calculate();
        m_gpu->Display();
        m_dram->Write();
        m_ssd->Storage();
        m_power->Enpower();
    }

    // 释放电脑零件
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        else if (m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu = NULL;
        }
        else if (m_dram != NULL)
        {
            delete m_dram;
            m_dram = NULL;
        }
        else if (m_ssd != NULL)
        {
            delete m_ssd;
            m_ssd = NULL;
        }
        else if (m_power != NULL)
        {
            delete m_power;
            m_power = NULL;
        }
        
        
        
        
    }

private:
    CPU * m_cpu;
    GPU * m_gpu;
    DRAM * m_dram;
    SSD * m_ssd;
    PowerSource * m_power;
};

void test01()
{
    // first computer's components
    CPU * cpu = new Intel_12400f;
    GPU * gpu = new Nvidia_4060ti;
    DRAM * dram = new DDR4;
    SSD * ssd = new PC005;
    PowerSource * ps = new GM750;

    // first computer
    Computer * computer1 = new Computer(cpu, gpu, dram, ssd, ps);
    computer1->work();
    delete computer1;

}

int main()
{
    test01();

    system("pause");
    return 0;
}