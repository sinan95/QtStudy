#include "observer.h"
namespace myobserver {

//////////////////////////@class Notify///////////////////////////////
Notify::Notify(int type) :
    t(type)
{}

Notify::Notify(int type, void *data) :
    t(type),
    m_pData(data)
{}

Notify::~Notify()
{}

//////////////////////////@class Observer///////////////////////////////
Observer::Observer()
{}

Observer::~Observer()
{}

//////////////////////////@class Subject///////////////////////////////
Subject::Subject()
{}

Subject::~Subject()
{
    m_setObs.clear();
}

void Subject::attachObserver(Observer *obs)
{
    if (obs) {
        m_setObs.insert(obs);
    }
}

void Subject::detachObserver(Observer *obs)
{
    m_setObs.erase(obs);
}

void Subject::clearObserver()
{
    m_setObs.clear();
}

void Subject::notify(Notify *notify)
{
    std::set<Observer *>::iterator it = m_setObs.begin();
    for (; it != m_setObs.end(); it++) {
        if (*it) {
            (*it)->receiveNotify(notify);
        }
    }
}

int  Subject::getObserverCount()
{
    return m_setObs.size();
}

}
