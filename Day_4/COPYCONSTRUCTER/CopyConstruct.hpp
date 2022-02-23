#ifndef _CLOCK_H_
#define _CLOCK_H_

class Clock
{
public:
    Clock(int NewH, int NewM, int NewS);
    Clock(Clock &c); //�������캯����������ӣ�����һ����Զ�����һ���������캯������˼Ӳ��Ӷ�����ֱ��ʹ�á�
    void SetTime(int NewH, int NewM, int NewS);
    void ShowTime();
    ~Clock(); //�������������������Զ�����һ��Ĭ�ϵ���������
private:
    int Hour, Minute, Second;
};


#endif // !_CLOCK_H_
