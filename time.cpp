#include <iomanip>
#include <iostream>

#include "time.hpp"

using namespace std;

void Time::hour(int hour) 
{ 
    if (hour >= 24 || hour < 0)
        cout << "Hatali deger girildi." << endl;
    else {
        m_hour = hour; 
        m_totalsec = m_second + m_minute * 60 + m_hour * 3600; 
    }
}

void Time::minute(int minute) 
{
    if (minute >= 60 || minute < 0)
        cout << "Hatali deger girildi." << endl;
    else {
        m_minute = minute; 
        m_totalsec = m_second + m_minute * 60 + m_hour * 3600;
    }
}

void Time::second(int second) 
{
    if (second >= 60 || second < 0)
        cout << "Hatali deger girildi." << endl;
    else {
        m_second = second; 
        m_totalsec = m_second + m_minute * 60 + m_hour * 3600; 
    }
}

void Time::totalsec(int tsec)
{
    if (tsec < 0 || tsec > 86399)
         cout << "Deger 0 ile 86399 de dahil arasinda girilmeli." << endl;
    else {
        m_totalsec = tsec;
        m_second = m_totalsec % 60;
        m_minute = (m_totalsec % 3600) / 60;
        m_hour = (m_totalsec / 3600) % 24;
    }
}

void Time::disp() const
{
    cout << setfill('0') << setw(2) << hour() << ':'
         << setw(2) << minute() << ':'
         << setw(2) << second() 
         << " (" << m_totalsec << ')' << endl;
}

void Time::addsec(int second)
{
    m_totalsec += second;

    if (m_totalsec >= 24 * 3600)
        m_totalsec %= 24 * 3600;
    else if (m_totalsec < 0)
        m_totalsec = (24 * 3600) + (m_totalsec % (24 * 3600));

    m_second = m_totalsec % 60;
    m_minute = (m_totalsec % 3600) / 60;
    m_hour = (m_totalsec / 3600) % 24;

    // m_second += second;
    // m_minute += m_second / 60;
    // m_hour += m_minute / 60;
    // if (m_second >= 60)
    //     m_second %= 60;
    // if (m_minute >= 60)
    //     m_minute %= 60;
    // if (m_hour >= 24)
    //     m_hour %= 24, m_totalsec = m_second + m_minute * 60 + m_hour * 3600;
    // else
    //     m_totalsec += second;
}

void Time::addmin(int minute)
{
    m_totalsec += minute * 60;

    if (m_totalsec >= 24 * 3600)
        m_totalsec %= 24 * 3600;
    else if (m_totalsec < 0)
        m_totalsec = (24 * 3600) + (m_totalsec % (24 * 3600));

    m_second = m_totalsec % 60;
    m_minute = (m_totalsec % 3600) / 60;
    m_hour = (m_totalsec / 3600) % 24;

    // m_minute += minute;
    // m_hour += m_minute / 60;
    // if (m_minute >= 60)
    //     m_minute %= 60;
    // if (m_hour >= 24)
    //     m_hour %= 24, m_totalsec = m_second + m_minute * 60 + m_hour * 3600;
    // else
    //     m_totalsec += minute * 60;
}

void Time::addhour(int hour)
{
    m_totalsec += hour * 3600;

    if (m_totalsec >= 24 * 3600)
        m_totalsec %= 24 * 3600;
    else if (m_totalsec < 0)
        m_totalsec = (24 * 3600) + (m_totalsec % (24 * 3600));

    m_second = m_totalsec % 60;
    m_minute = (m_totalsec % 3600) / 60;
    m_hour = (m_totalsec / 3600) % 24;

    // m_hour += hour;
    // if (m_hour >= 24)
    //     m_hour %= 24, m_totalsec = m_second + m_minute * 60 + m_hour * 3600;
    // else
    //     m_totalsec += hour * 3600;
}

void Time::addtime(int hour, int minute, int second)
{
    addsec(second);
    addmin(minute);
    addhour(hour);
}

void Time::addtime(const Time &t) 
{
    addsec(t.m_second);
    addmin(t.m_minute);
    addhour(t.m_hour);
}

double Time::totalmin() const
{
    return totalsec() / 60.;
}

double Time::totalhour() const
{
    return totalsec() / 3600.;
}

