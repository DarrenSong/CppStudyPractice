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
 * @Date: 2021-12-02 16:47:07
 * @LastEditTime: 2021-12-03 09:46:11
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \test\SmartPtr\smartptr.cpp
 */

#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int  add(int a,int b)
{
    return a+b;
}
//thread and mutex 
int main()
{
    thread th1;

    th1.join();
    
/*mutex 有四种*/
/*
std::mutex，最基本的 Mutex 类。
    mutex 对象提供了独占所有权的特性——即不支持递归地对 std::mutex 对象上锁
std::recursive_mutex，递归 Mutex 类。
    std::recursive_mutex 允许同一个线程对互斥量多次上锁（即递归上锁），
    来获得对互斥量对象的多层所有权，std::recursive_mutex 释放互斥量时需要调用与该锁层次深度相同次数的 unlock()，
    可理解为 lock() 次数和 unlock() 次数相同，除此之外，std::recursive_mutex 的特性和 std::mutex 大致相同
std::time_mutex，定时 Mutex 类。
    time_mutex 比 std::mutex 多了两个成员函数，try_lock_for()，try_lock_until()。
    try_lock_for 函数接受一个时间范围，表示在这一段时间范围之内线程如果没有获得锁则被阻塞住
    ，如果在此期间其他线程释放了锁，则该线程可以获得对互斥量的锁，如果超时（即在指定时间内还是没有获得锁），则返回 false
    try_lock_until 函数则接受一个时间点作为参数，在指定时间点未到来之前线程如果没有获得锁则被阻塞住，如果在此期间其他线程释放了锁，
    则该线程可以获得对互斥量的锁
std::recursive_timed_mutex，定时递归 Mutex 类。
*/
    std::mutex mtx; 

/*Lock 有两种*/
//lock_guard是一个互斥量包装程序，
//它提供了一种方便的RAII（Resource acquisition is initialization ）风格的机制来在作用域块的持续时间内拥有一个互斥量。
//创建lock_guard对象时，它将尝试获取提供给它的互斥锁的所有权。当控制流离开lock_guard对象的作用域时，lock_guard析构并释放互斥量
/*
1.创建即加锁，作用域结束自动析构并解锁，无需手工解锁
2.不能中途解锁，必须等作用域结束才解锁
3.不能复制
*/
    std::lock_guard<std::mutex> lg(mtx);
//unique_lock是一个通用的互斥量锁定包装器，它允许延迟锁定，限时深度锁定，递归锁定，锁定所有权的转移以及与条件变量一起使用。
//unique_lock 是 lock_guard 的升级加强版，它具有 lock_guard 的所有功能，同时又具有其他很多方法，使用起来更强灵活方便，能够应对更复杂的锁定需要。
//
/*
1.创建时可以不锁定（通过指定第二个参数为std::defer_lock），而在需要时再锁定
2.可以随时加锁解锁
3.作用域规则同 lock_grard，析构时自动释放锁
4.不可复制，可移动
5.条件变量需要该类型的锁作为参数（此时必须使用unique_lock）
*/
    unique_lock <mutex> lock(mtx);

//
    

//    condition_variable cond;

 //   cond.wait(mtx);

 //   cond.notify_one();


}

void  main1()//smart pointer
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
