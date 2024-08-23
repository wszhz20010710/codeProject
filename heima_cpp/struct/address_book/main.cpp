#include <iostream>
#include <string>

#define MAX 1000

using namespace std;

struct Person
{
    string name;
    int gender;
    int age;
    string phone_number;
    string address;
};

struct Contact
{
    struct Person persons_array[MAX];
    int contact_size;
};

// functions
void show_menu();
void add_contact(Contact * ptr);
void show_contact(Contact * ptr);
void delete_contact(Contact * ptr);
void search_contact(Contact * ptr);
void modify_contact();
void delete_all();
int is_exist(Contact * ptr, string name);



int main()
{
    Contact ptr;
    ptr.contact_size = 0;

    int choice = 0;
    while (true)
    {
        show_menu();
        cout << "请输入您需要的功能号：";

        cin >> choice;
        switch (choice)
        {
            case 1:
                add_contact(&ptr);
                break;
            case 2:
                show_contact(&ptr);
                break;
            case 3:
                delete_contact(&ptr);
                break;
            case 4:
            search_contact(&ptr);
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout << "！！！欢迎下次使用！！！" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }
    
}

void show_menu()
{
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}

void add_contact(Contact * ptr)
{
    // 通讯录已满则不添加
    if (ptr->contact_size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        // 开始添加
        cout << "现在开始添加。请输入对应数据！" << endl;
        // 姓名
        cout << "请输入姓名：" << endl;
        string name;
        cin >> name;
        ptr->persons_array[ptr->contact_size].name = name;
        
        // 性别
        cout << "请输入性别：" << endl;
        cout << "1————男" << endl;
        cout << "2————女" << endl;
        int gender = 0;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                ptr->persons_array[ptr->contact_size].gender = gender;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！！！" << endl;
            }
        }
        
        // 年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        while (true)
        {
            cin >> age;
            // 超出正常值的年龄判错
            if (age >= 0 && age <= 120)
            {
                ptr->persons_array[ptr->contact_size].age = age;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！！！" << endl;
            }
            
        }
        
        // 号码
        cout << "请输入号码：" << endl;
        string phone_number;
        while (true)
        {
            cin >> phone_number;
            if (phone_number.length() == 11)
            {
                ptr->persons_array[ptr->contact_size].phone_number = phone_number;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！！！" << endl;
            }
        }
        
        
        // 地址
        cout << "请输入地址：" << endl;
        string address;
        cin >> address;
        ptr->persons_array[ptr->contact_size].address = address;
    
        // 更新人数
        ptr->contact_size ++;

        cout << "添加成功！！！" << endl;

        return;
        system("pause");
        
    
    }
    
}

int is_exist(Contact * ptr, string name)
{
    int length = ptr->contact_size;
    for (int i = 0; i < length; i++)
    {
        if (ptr->persons_array[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void show_contact(Contact * ptr)
{
    if (ptr->contact_size == 0)
    {
        cout << "当前记录为空！" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < ptr->contact_size; i++)
        {
            cout << "联系人" << i+1 << endl;
            cout << "姓名：" << ptr->persons_array[i].name << endl;
            cout << "性别：" << (ptr->persons_array[i].gender == 1? "男":"女") << endl;
            cout << "年龄：" << ptr->persons_array[i].age << endl;
            cout << "手机号：" << ptr->persons_array[i].phone_number << endl;
            cout << "住址：" << ptr->persons_array[i].address << endl;
        }
        
    }
    return;
    system("pause");
    system("cls");
}

void delete_contact(Contact * ptr)
{
    cout << "请输入需要删除的联系人姓名：" << endl;
    string name;
    cin >> name;

    int ret = is_exist(ptr, name);

    if (ret == -1)
    {
        cout << "查无此人，请重新输入！" << endl;
        return;
    }
    else
    {
        for (int i = ret; i < ptr->contact_size - 1; i++)
        {
            ptr->persons_array[i] = ptr->persons_array[i+1];
        }
        ptr->contact_size --;
        cout << "删除成功！" << endl;
        return;
    }
    system("pause");
    system("cls");
}

void search_contact(Contact * ptr)
{
    cout << "请输入需要搜索的联系人姓名：" << endl;
    string name;
    cin >> name;
    
    int res = is_exist(ptr, name);

    if (res == -1)
    {
        cout << "查无此人，请重新输入！" << endl;
        return;
    }
    else
    {
        cout << "已找到！信息如下： " << endl;
        cout << "姓名：" << ptr->persons_array[res].name << endl;
        cout << "性别：" << (ptr->persons_array[res].gender == 1? "男":"女") << endl;
        cout << "年龄：" << ptr->persons_array[res].age << endl;
        cout << "手机号：" << ptr->persons_array[res].phone_number << endl;
        cout << "住址：" << ptr->persons_array[res].address << endl;
        return;
    }

    system("pause");
}

