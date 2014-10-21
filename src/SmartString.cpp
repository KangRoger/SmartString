#include"SmartString.h"


SmartString& SmartString::operator=(const SmartString &str)
{
	if (this == &str)
		return *this;
	destroy();
	p = str.p;
	++p->count;
	return *this;
}
SmartString& SmartString::operator=(const char *s)
{
	destroy();
	p = new StrPtr(s);
	return *this;
}
void SmartString::destroy()
{

	if (p&&--p->count == 0)
	{
		delete p;
		p = NULL;
	}
}
bool SmartString::operator==(const SmartString& str)const
{
	if (p == str.p)
		return true;
	if (strcmp(getStr(), str.getStr())==0)
		return true;
	return false;
}
bool SmartString::operator!=(const SmartString& str)const
{
	if (p == str.p)
		return false;
	if (strcmp(getStr(), str.getStr())==0)
		return false;
	return true;
}
bool SmartString::operator>(const SmartString& str)const
{
	return strcmp(getStr(), str.getStr())>0;
}
bool SmartString::operator<(const SmartString& str)const
{
	return strcmp(getStr(), str.getStr())<0;
}

bool SmartString::operator>=(const SmartString& str)const
{
	return strcmp(getStr(), str.getStr())>=0;
}
bool SmartString::operator<=(const SmartString& str)const
{
	return strcmp(getStr(), str.getStr())<=0;
}

char& SmartString::operator[](int n)
{
	char *s = getStr();
	//没有做安全检查
	return s[n];
}

char* SmartString::getStr()const//获取原始指针
{
	if (!p)
		return 0;
	else
		return p->s;
}
unsigned int SmartString::getCount()const
{
	if (!p)
		return 0;
	else
		return p->count;
}
