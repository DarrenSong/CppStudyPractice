/*
 *  ┌─────────────────────────────────────────────────────────────┐
 *  │┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐│
 *  ││Esc│!1 │@2 │#3 │$4 │%5 │^6 │&7 │*8 │(9 │)0 │_- │+= │|\ │`~ ││
 *  │├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤│
 *  ││ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{[ │}] │ BS  ││
 *  │├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤│
 *  ││ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  ││
 *  │├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤│
 *  ││ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│Shift │Fn ││
 *  │└─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘│
 *  │      │Fn │ Alt │         Space         │ Alt │Win│   HHKB   │
 *  │      └───┴─────┴───────────────────────┴─────┴───┘          │
 *  └─────────────────────────────────────────────────────────────┘
 * 
 * @Author: your name
 * @Date: 2021-12-13 15:49:49
 * @LastEditTime: 2021-12-16 15:41:58
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \CppStudyPractice\memorymgr\memorytest.cpp
 */

/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 * 
 * @Author: your name
 * @Date: 2021-12-13 15:50:08
 * @LastEditTime: 2021-12-13 15:50:08
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \CppStudyPractice\memorymgr\CMakeLists.txt
 */

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class animal
{
public:
    animal()
    {  
        cout<<"animal constructor"<<endl;
    }
    virtual ~animal()
    {
        cout<<"animal destructor"<<endl;
    }
    string name;
    int act;
};
class dog : public animal
{
public:
    dog()
    {
        cout<<"dog constructor"<<endl;
    }
    ~dog()
    {
        cout<<"dog destructor"<<endl;
    }
    
};

class Person
{
 public:
    	int age;
    	int* high;
    Person()
    {
        high=(int*)malloc(sizeof(int));//申请内存
    }
    #if 1
    Person(Person & pe)
    {
        age=pe.age;
        //浅拷贝,这是默认拷贝构造函数的实现方式
        high = pe.high;        // 指向同一片内存
        //深拷贝,这是我们应该正确的实现方式 
        high= new int(*(pe.high));
    }
    #endif 
    ~Person()
    {
        delete high;    //释放内存
    }
};
class People
{
 public:
    	int age;
    	//int* high;
        shared_ptr<int> high;
    People()
    {
        high.reset(new int(1));//申请内存
    }
    #if 0
    People(People & pe)
    {
        age=pe.age;
        //浅拷贝,这是默认拷贝构造函数的实现方式
       // high = pe.high;        // 指向同一片内存
        //深拷贝,这是我们应该正确的实现方式 
       // high= new int(*(pe.high));
        high=pe.high;
    }
    #endif
    ~People()
    {
        //delete high;    //释放内存
    }
};

class Tube
{
public:
    int ma;

    Tube()
    {
        cout<<"Tube Constructor"<<endl;
    } 
    ~Tube()
    {
        cout<<"Tube Destructor"<<endl;
    }
};
class Acq
{
public:
    int ma;
    Tube te;
    Acq()
    {
        cout<<"Acq Constructor"<<endl;
    } 
    ~Acq()
    {
        cout<<"Acq Destructor"<<endl;
    }
};
int main()
{
    Acq a1;
    cout<<"a1 complete"<<endl;
    Acq a2(a1);
    cout<<"a2 complete"<<endl;

    return 0;
}

int main2()
{
	// animal* am=new dog;
	// delete am;

    People p1;
    
    People p2(p1);
    
    *(p1.high.get())=6;
    
    int a= *(p1.high.get());
    int b= *(p2.high.get());
    cout<<"people1: "<<a<<endl;
    cout<<"people2: "<<b<<endl;


    Person pe1;
    Person pe2(pe1);
    
    return 0;

}
int main1()
{
    int *p =(int *)malloc(sizeof(int));

    int *q =(int *)malloc(sizeof(int));

    p=q;

    free(p);
    free(q);

    return 0;
}
