/*
 *           佛曰:  
 *                   写字楼里写字间，写字间里程序员；  
 *                   程序人员写程序，又拿程序换酒钱。  
 *                   酒醒只在网上坐，酒醉还来网下眠；  
 *                   酒醉酒醒日复日，网上网下年复年。  
 *                   但愿老死电脑间，不愿鞠躬老板前；  
 *                   奔驰宝马贵者趣，公交自行程序员。  
 *                   别人笑我忒疯癫，我笑自己命太贱；  
 *                   不见满街漂亮妹，哪个归得程序员？
 * 
 * @Author: your name
 * @Date: 2021-12-07 11:32:55
 * @LastEditTime: 2021-12-07 11:47:04
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \CppStudyPractice\smartprt\smartptr.cpp
 */
#include <iostream>
#include <memory>
using namespace std;

void  main()//smart pointer
{

    unique_ptr<int> p1 (new int(3));

    int * p2 = p1.get();

    //p1.reset();//释放所有权并删除管理对象
    //p1.release();//返回指针并释放所有权
    int a=*p2; //此时访问原对象会出现不确定值

//如果调用release()释放所有权以后，这里需要手动释放空间。若没掉release或者是调用了reset，这里使用free手动释放会出问题  
    //free(p2);
    cout<<a<<endl;

//weak_ptr 配合shared_ptr使用
    shared_ptr<int> p3(new int(6));
    weak_ptr<int> p4(p3);//配合shared_ptr，解决循环引用的问题,不影响shared_ptr的引用计数

    int b=0;
    if(!p4.expired())//检测对象是否被释放
    {
        b =*(p4.lock());
    }
    cout<<b<<endl;

    
}
