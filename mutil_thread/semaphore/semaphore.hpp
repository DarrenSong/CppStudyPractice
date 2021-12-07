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
 * @Date: 2021-12-07 11:16:49
 * @LastEditTime: 2021-12-07 11:18:11
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \CppStudyPractice\mutil_thread\semaphore.hpp
 */
#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class semaphore
{
public:
    semaphore(int value = 1) :count(value) {}

    void wait()
    {
        unique_lock<mutex> lck(mtk);
        if (--count < 0)//资源不足挂起线程
            cv.wait(lck);
    }

    void signal()
    {
        unique_lock<mutex> lck(mtk);
        if (++count <= 0)//有线程挂起，唤醒一个
            cv.notify_one();
    }

private:
    int count;
    mutex mtk;
    condition_variable cv;
};

#endif 
