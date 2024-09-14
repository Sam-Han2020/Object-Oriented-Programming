#include <iostream>
#include <windows.h>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
    //初始化属性
    // this->m_EmpNum=0;
    // this->m_EmpArray=NULL;

    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//读文件
    if(!ifs.is_open())
    {
        // cout<<"文件不存在！"<<endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum=0;
        //初始化数组指针
        this->m_EmpArray=NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty=true;
        ifs.close();
        return;
    }

    //2.文件存在，数据为空
    char ch;
    ifs>>ch;
    if(ifs.eof())//判断文件是否为空
    {
        //文件为空
        // cout<<"文件为空！"<<endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum=0;
        //初始化数组指针
        this->m_EmpArray=NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty=true;
        ifs.close();
        return;
    }
    ifs.close();
    //3.文件存在且记录数据
    int num=this->get_EmpNum();
    cout<<"职工人数为："<<num<<endl;
    this->m_EmpNum=num;
    //开辟空间，将文件中的数据存到数组中
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    this->init_Emp();
    this->m_FileIsEmpty=false;
    
    return;
    //测试代码
    // for(int i=0;i<this->m_EmpNum;++i)
    // {
    //     cout<<"职工编号："<<this->m_EmpArray[i]->m_Id
    //     <<" 姓名："<<this->m_EmpArray[i]->m_Name
    //     <<" 部门编号："<<this->m_EmpArray[i]->m_DeptId<<endl;
    // }
}

//展示菜单
void WorkerManager::Show_Menu()
{
    cout<<"____________________________________________________________________"<<endl;
    cout<<"|欢迎使用智能机器人为达芬奇环保科技株式会社开发的职工管理系统（笑） |"<<endl;
    cout<<"|                       0.退出管理程序                              |"<<endl;
    cout<<"|                       1.增加职工信息                              |"<<endl;
    cout<<"|                       2.显示职工信息                              |"<<endl;
    cout<<"|                       3.删除离职职工                              |"<<endl;
    cout<<"|                       4.修改职工信息                              |"<<endl;
    cout<<"|                       5.查找职工信息                              |"<<endl;
    cout<<"|                       6.按照编号排序                              |"<<endl;
    cout<<"|                       7.清空所有文档                              |"<<endl;
    cout<<"|___________________________________________________________________|"<<endl;
    cout<<endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
    cout<<"欢迎你下次再使用智能机器人为达芬奇环保科技有限公司开发的职工管理系统（笑） "<<endl;
    system("pause");
    cout<<"phi!"<<endl;
    exit(0);//退出程序
}

//添加职工
void WorkerManager::Add_Emp()
{
    cout<<"请输入新引进的韭菜数量："<<endl;
    int addNum=0;
    cin>>addNum;
    if(addNum>0)
    {
        //添加
        //计算添加新空间大小
        int newSize=this->m_EmpNum + addNum;//新空间大小=原来记录人数+新增人数

        //开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        //将原来空间下数据，拷贝到新空间下
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        //批量添加新数据
        for(int i=0;i<addNum;i++)
        {
            int id;//职工编号
            string name;//职工姓名
            int dSelete;//部门选择
            Worker* worker=NULL;
            do{
                cout<<"请输入第 "<<i+1<<" 个新韭菜编号："<<endl;
                cin>>id;
                int sign=0;
                for(int i=0;i<this->m_EmpNum;++i)
                {
                    if(this->m_EmpArray[i]->m_Id==id) sign=1;
                }
                if(sign)
                {
                    cout<<"你在叫啥?(韭菜的编号不能重复)"<<endl;
                    system("pause");
                    system("cls");
                    dSelete=-1;
                    continue;
                }
                cout<<"请输入第 "<<i+1<<" 个新韭菜姓名："<<endl;
                cin>>name;
                cout<<"请选择第"<<i+1<<"个韭菜的岗位："<<endl;
                cout<<"1.普通小职员"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>dSelete;
                switch(dSelete)
                {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    cout<<"你在叫啥?"<<endl;
                    system("pause");
                    system("cls");
                    WorkerManager::Show_Menu();
                    break;
                }

                //将创建的职工职责，保存到数组中
                newSpace[this->m_EmpNum++]=worker;
            }while(dSelete<1 || dSelete>3);
        }
        //释放原有空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray=newSpace;

        //更新新的职工人数
        // this->m_EmpNum=newSize;

        //更新职工不为空的标志
        this->m_FileIsEmpty=false;

        //成功添加后，保存到文件中

        //提示添加成功
        cout<<"恭喜"<<addNum<<"位新韭菜成功加入达芬奇环保科技株式会社（笑）"<<endl;
        
        //保存数据到文件中
        this->save();
    }
    else cout<<"想裁员出门右拐"<<endl;
    //按任意键后，清屏回到上级目录
    system("pause");
    system("cls");
}

//保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//用输出的方式打开文件--写文件

    //将每个人的数据写入到文件中
    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs<<this->m_EmpArray[i]->m_Id<<" "
           <<this->m_EmpArray[i]->m_Name<<" "
           <<this->m_EmpArray[i]->m_DeptId<<endl;
    }

    //关闭文件
    ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//打开文件（读文件）
    int id;
    string name;
    int dId;
    int num=0;
    while(ifs>>id && ifs>>name && ifs>>dId) num++;//统计人数
    return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int index=0;

    while(ifs>>id && ifs>>name && ifs>>dId)
    {
        Worker* worker=NULL;
        switch(dId)
        {
        case 1:
            worker=new Employee(id,name,dId);
            break;
        case 2:
            worker=new Manager(id,name,dId);
            break;
        case 3:
            worker=new Boss(id,name,dId);
            break;
        default:
            break;
        }
        this->m_EmpArray[index++]=worker;
    }

    //关闭文件
    ifs.close();
}

//展示职工信息
void WorkerManager::Show_Emp()
{
    //判断文件是否为空
    if(this->m_FileIsEmpty) cout<<"你的公司居然一个韭菜都没有！"<<endl;
    else
    {
        for(int i=0;i<m_EmpNum;++i)
        {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//判断职工是否存在
//如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::is_Exist(int id)
{
    int index=-1;
    for(int i=0;i<this->m_EmpNum;++i)
    {
        if(this->m_EmpArray[i]->m_Id==id)
        {
            index=i;
            break;//不能漏
        }
    }
    return index;
}

//删除职工
void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty) cout<<"做个人吧，韭菜都被你炒完了！"<<endl;
    else
    {
        //按照职工编号删除
        cout<<"请输入想要用来炒鱿鱼的韭菜"<<endl;
        int id=0;
        cin>>id;
        int index=this->is_Exist(id);
        if(index!=-1)//说明职工存在，并且要删除掉index位置上的员工
        {
            cout<<"韭菜"<<this->m_EmpArray[index]->m_Name<<": 我滴任务完成啦！！！"<<endl;
            //数据前移
            for(int i=index;i<this->m_EmpNum-1;++i)
            {
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            //更新数组中记录人员个数
            this->m_EmpNum--;
            if(this->m_EmpNum==0) this->m_FileIsEmpty=true;
            //数据同步更新到文件中
            this->save();
        }
        else cout<<"可能这茬韭菜已经被炒了"<<endl;
    }
    //按任意键清屏
    system("pause");
    system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty) cout<<"做个人吧，韭菜都被你炒完了！"<<endl;
    else
    {
        cout<<"请输入待修改韭菜的编号："<<endl;
        int id;
        cin>>id;
        int ret=this->is_Exist(id);
        if(ret!=-1)
        {
            //说明查找到编号的职工
            int temp=this->m_EmpArray[ret]->m_DeptId;
            string name=this->m_EmpArray[ret]->m_Name;
            delete this->m_EmpArray[ret];
            int newId=0;
            string newName="";
            int dSelete=0;
            cout<<"查到："<<id<<"号韭菜，请输入新的编号："<<endl;
            cin>>newId;
            cout<<"请输入新的姓名"<<endl;
            cin>>newName;
            Worker *worker=NULL;
            do{
                cout<<"请输入新的岗位"<<endl;
                cout<<"1.普通小职员"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>dSelete;
                switch(dSelete)
                {
                    case 1:
                        worker=new Employee(newId,newName,dSelete);
                        break;
                    case 2:
                        worker=new Manager(newId,newName,dSelete);
                        break;
                    case 3:
                        worker=new Boss(newId,newName,dSelete);
                        break;
                    default:
                        cout<<"你在叫啥?"<<endl;
                        system("pause");
                        system("cls");
                        break;
                }
            }while(dSelete<1 || dSelete>3);
            //更新数据到数组中
            this->m_EmpArray[ret]=worker;          
            if(dSelete>temp &&newName==name) cout<<"恭喜韭菜 "<<name<<" 升官发财，逐步走向人生巅峰！"<<endl;
            else if(dSelete<temp &&newName==name) cout<<"希望韭菜 "<<name<<" 以后表现好一点，多贡献一点剩余价值，别再被降职了！"<<endl;
            else cout<<"恭喜韭菜 "<<name<<" 被其他人所取代了！"<<endl;
            //保存到文件中
            this->save();
        }
        else cout<<"这茬韭菜可能早就被取代了。。。"<<endl;
    }
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty) cout<<"做个人吧，韭菜都被你炒完了，找不到韭菜压榨了！"<<endl;
    else
    {
        int c;
        do{
            cout<<"请输入查找的方式"<<endl;
            cout<<"1.按照韭菜编号查找"<<endl;
            cout<<"2.按照韭菜姓名查找"<<endl;
            cin>>c;
            switch(c)
            {
                case 1 :
                    {
                        int id;
                        cout<<"请输入韭菜的编号："<<endl;
                        cin>>id;
                        int ret=is_Exist(id);
                        if(ret!=-1)
                        {
                            cout<<"查到："<<id<<"号韭菜，信息如下："<<endl;
                            this->m_EmpArray[ret]->showInfo();
                        }
                        else cout<<"可能这个韭菜带着他的小姨子跑路了。。。"<<endl;
                        // system("pause");
                        // system("cls");
                        break;
                    }
                case 2 :
                    {
                        string name;
                        cout<<"请输入韭菜的姓名："<<endl;
                        cin>>name;
                        int sign=1;//默认未找到职工
                        for(int i=0;i<this->m_EmpNum;++i)
                        {
                            if(this->m_EmpArray[i]->m_Name==name)
                            {
                                cout<<"查找成功，信息如下："<<endl;
                                this->m_EmpArray[i]->showInfo();
                                sign=0;
                            }
                        }
                        if(sign) cout<<"可能这个韭菜带着他的小姨子跑路了。。。"<<endl;
                        // system("pause");
                        // system("cls");
                        break;
                    }
                default:
                    cout<<"你在叫啥？再叫一遍！"<<endl;
                    system("pause");
                    system("cls");
                    break;
            }
        }while(c<1 || c>2);
    }
    system("pause");
    system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"做个人吧，韭菜都被你炒完了，找不到韭菜压榨了！"<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        int select=0;
        do
        {
            cout<<"请选择排序方式："<<endl;
            cout<<"1.按职工号进行升序"<<endl;
            cout<<"2.按职工号进行降序"<<endl;
            cin>>select;
            if(select<1 || select>2)
            {
                cout<<"你在叫啥？再叫一遍！"<<endl;
                system("pause");
                system("cls");
            }
        }while(select<1 || select>2);
        for(int k=0;k<m_EmpNum-1;++k)
        {
            int minOrMax=k;
            for(int i=k;i<m_EmpNum;++i)
            {
                
                switch(select)
                {
                case 1:
                    if(i==k || m_EmpArray[i]->m_Id<m_EmpArray[minOrMax]->m_Id) minOrMax=i;
                    break;
                case 2:
                    if(i==k || m_EmpArray[i]->m_Id>m_EmpArray[minOrMax]->m_Id) minOrMax=i;
                    break;
                default:
                    break;
                }
            }
            if(k!=minOrMax)
            {
                Worker *t=m_EmpArray[k];
                m_EmpArray[k]=m_EmpArray[minOrMax];
                m_EmpArray[minOrMax]=t;
            }
        }
        cout<<"韭菜们听话，来排排坐："<<endl;
        this->save();//排序后结果更新到文件中
        this->Show_Emp();
    }
}

//清空文件
void WorkerManager::Clean_File()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"做个人吧，韭菜都被你炒完了！"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"按1炒掉公司里面的所有韭菜,按其他放弃"<<endl;
    int dSelect=0;
    cin>>dSelect;
    if(dSelect!=1)
    {
        cout<<"算你有自知之明"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {
        //清空文件
        ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
        ofs.close();
        if(this->m_EmpArray!=NULL)
        {
            //删除堆区的每个职工对象
            for(int i=0;i<this->m_EmpNum;++i)
            {
                cout<<"韭菜"<<this->m_EmpArray[i]->m_Name<<": 我滴任务完成啦！！！"<<endl;
                Sleep(1000);
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
            //删除堆区数组指针
            delete[] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty=true;
        }
        cout<<"韭菜炒鱿鱼好吃吗？"<<endl;
        system("pause");
        system("cls");
    }
}

WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray!=NULL)
    {
        //删除堆区的每个职工对象
        for(int i=0;i<this->m_EmpNum;++i)
        {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i]=NULL;
        }
        //删除堆区数组指针
        delete[] this->m_EmpArray;
        this->m_EmpArray=NULL;
        this->m_EmpNum=0;
        this->m_FileIsEmpty=true;
    }
}