#ifndef TIME__
#define TIME__

class Time {
public:
    // constructors
    constexpr Time() : m_hour(0), m_minute(0), m_second(0), m_totalsec(0)
    {}
    constexpr Time(int hour, int minute, int second) : 
    m_hour(hour), m_minute(minute), m_second(second), 
    m_totalsec(second + minute * 60 + hour * 3600)
    {
        if (m_totalsec >= 24 * 3600)
            m_totalsec %= 24 * 3600;
        else if (m_totalsec < 0)
            m_totalsec = (24 * 3600) + (m_totalsec % (24 * 3600));
        
        m_second = m_totalsec % 60;
        m_minute = (m_totalsec % 3600) / 60;
        m_hour = (m_totalsec / 3600) % 24;
    }

    // getters
    constexpr int hour() const { return m_hour; }
    constexpr int minute() const { return m_minute; } 
    constexpr int second() const { return m_second; }
    constexpr int totalsec() const { return m_totalsec; }

    // setters
    void hour(int hour); 
    void minute(int minute);
    void second(int second);
    void totalsec(int tsec);

    // utilites
    void disp() const;
    void addsec(int second);
    void addmin(int minute);
    void addhour(int hour);
    void addtime(int hour, int minute, int second);
    void addtime(const Time &t);
    constexpr int comp(const Time &r) const
    {
        if (m_totalsec == r.m_totalsec)
            return 0;

        return m_totalsec - r.m_totalsec; 
    }
    constexpr int comp(int hour, int minute, int second) const
    {
        Time temp_t(hour, minute, second);

        return comp(temp_t);
    }
    
    double totalmin() const;
    double totalhour() const;

private:
    int m_hour;
    int m_minute;
    int m_second;
    int m_totalsec;
};

#endif

