#include<string.h>
#include<iostream>
class StrPtr
{
	friend class SmartString;
private:
	char *s;
	unsigned int count;
public:
	StrPtr(const char *p)
	{
		s = new char[strlen(p) + 1];
		//strcpy_s(s,strlen(p)+1, p);
		strcpy(s, p);
		count = 1;
	}
	~StrPtr()
	{
		delete[]s;
	}
};

class SmartString
{
public:
	SmartString() :p(NULL)
	{}
	
	SmartString(const char *s)
	{
		p = new StrPtr(s);
	}
	SmartString(const SmartString &str)
	{
		p = str.p;
		++p->count;
	}

	SmartString& operator=(const SmartString &str);
	SmartString& operator=(const char *s);

	bool operator==(const SmartString& str)const;
	bool operator!=(const SmartString& str)const;

	bool operator>(const SmartString& str)const;
	bool operator<(const SmartString& str)const;

	bool operator>=(const SmartString& str)const;
	bool operator<=(const SmartString& str)const;

	char& operator[](int n);//返回第n个字符

	~SmartString()
	{
		destroy();
	}
	void destroy();
	friend std::ostream& operator << (std::ostream& out, const SmartString& str);

	char *getStr()const;//获取原始指针
	unsigned int getCount()const;//获取计数器

private:
	StrPtr *p;
};

inline std::ostream& operator<<(std::ostream& out,SmartString& str)//inline is needed
{
	out << str.getStr();
	return out;
}