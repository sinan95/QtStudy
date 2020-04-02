#ifndef OBSERVER_H
#define OBSERVER_H

/*****************************************************
 * 观察者模式
 * Copyright (C) 2020 sinan Inc.
 *
 * This file is a design pattern.
 *
 * @file     observer.h
 * @brief    观察者模式
 * @author   sinan
 * @date     2020/03/03
 * @license  GNU General Public License (GPL)
 *
 * Remark :
 *
 * ***************************************************/

#include <iostream>
#include <set>

namespace myobserver {

/**
 * @brief The Notify class
 * 消息事件
 * 提供两个参数：
 * Type:事件的类型
 * data:事件的数据
 */
class Notify
{
public:
    /**
     * @brief The Type enum
     * 消息类型
     */
    enum Type {
        None,
        Int,
        Float,
        Double,
        Str,
        User
    };
    Notify(int type);
    Notify(int type, void *data);
    virtual ~Notify();
    /// 消息的类型
    inline int type() const { return t; }
    /// 获取消息的数据
    inline void *data() const { return m_pData; }
protected:
    int  t;
    void *m_pData;
};

/**
 * @brief The Observer class
 * 观察者基类
 * 接收被观察者的事件消息
 * 需要实现虚函数：void receiveNotify()
 */
class Observer
{
public:
    Observer();
    virtual ~Observer();
    /// 接收被观察者消息虚函数
    virtual void receiveNotify(Notify *notify = NULL) = 0;
};

/**
 * @brief The Subject class
 * 被观察者基类
 * 发送事件到观察者中
 */
class Subject
{
public:
    Subject();
    virtual ~Subject();
    /// 注册观察者
    void attachObserver(Observer *obs);
    /// 注销观察者
    void detachObserver(Observer *obs);
    /// 清空观察者
    void clearObserver();
    /// 通知消息到观察者
    void notify(Notify *notify = NULL);
    /// 获取观察者的个数
    int  getObserverCount();
private:
    std::set<Observer *> m_setObs;
};

}

#endif // OBSERVER_H
