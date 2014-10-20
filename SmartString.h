#include<string.h>
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
		strcpy_s(s,strlen(p)+1, p);
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
	SmartString& operator=(const SmartString &str)
	{
		if (this == &str)
			return *this;
		destroy();
		p = str.p;
		++p->count;
		return *this;
	}
	SmartString& operator=(const char *s)
	{
		destroy();
		p = new StrPtr(s);
		return *this;
	}
	~SmartString()
	{
		destroy();
	}
	inline void destroy()
	{
		
		if (p&&--p->count == 0)
		{
			delete p;
			p = NULL;
		}
	}
	

	char *getStr()
	{
		if (!p)
			return 0;
		else
		return p->s;
	}
	unsigned int getCount()
	{
		if (!p)
			return 0;
		else
		return p->count;
	}
private:
	StrPtr *p;
};