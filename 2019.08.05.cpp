#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Student
{
public:
	string id;
	char level;
	int place;
	string date;
	int code;
	int score;
public:
	Student() :id(""), level('\0'), place(0), date(""), code(0), score(0){}
	Student(string c) :id(c)
	{
		level = id[0];
		place = stoi(id.substr(1, 3));
		date = id.substr(4, 6);
		code = stoi(id.substr(10, 3));
	}
	friend bool cmpScore(const Student& s1, const Student& s2);
	~Student(){}
}; 
bool cmpScore(const Student& s1, const Student& s2)
{
	if (s1.score > s2.score)
		return true;
	else if (s1.score == s2.score)
		return s1.id < s2.id;
	else
		return false;
}
class myPair
{
private:
	int place;
	int nums;
public:
	myPair() :place(0), nums(0){}
	myPair(int p, int n) :place(p), nums(n){}
	friend bool cmpPair(const myPair& p1, const myPair& p2);
	friend ostream& operator<<(ostream& os, const myPair& mp);
};
bool cmpPair(const myPair& p1, const myPair& p2)
{
	if (p1.nums > p2.nums)
		return true;
	else if (p1.nums == p2.nums)
		return p1.place < p2.place;
	else
		return false;
}
ostream& operator<<(ostream& os, const myPair& mp)
{
	os << mp.place << " " << mp.nums << endl;
	return os;
}
class IQuery
{
public:
	IQuery(){}
	virtual void process(const vector<Student>& students,int casenum) = 0;
	virtual ~IQuery(){}
};

class Query1 :public IQuery
{
private:
	char param;
public:
	Query1(char p) :param(p){}
	void process(const vector<Student>& students, int casenum)
	{
		vector<Student> ans;
		for (size_t i = 0; i < students.size(); ++i)
		{
			if (students[i].level == param)
				ans.push_back(students[i]);
		}
		sort(ans.begin(), ans.end(), cmpScore);
		cout << "Case "<<casenum<<": 1 " << param << endl;
		if (ans.size() == 0)
			cout << "NA" << endl;
		for (size_t i = 0; i < ans.size(); ++i)
			cout << ans[i].id << " " << ans[i].score << endl;
	}
	~Query1(){}
};

class Query2 :public IQuery
{
private:
	int param;
public:
	Query2(int p) :param(p){}
	void process(const vector<Student>& students, int casenum)
	{
		int numbers=0, scores=0;
		for (auto& x : students)
		{
			if (x.place == param)
				++numbers, scores += x.score;
		}
		cout << "Case " << casenum << ": 2 " << param << endl;
		if (numbers == 0)
			cout << "NA" << endl;
		else
			cout << numbers << " " << scores << endl;
	}
	~Query2(){}
};

class Query3 :public IQuery
{
private:
	string param;
public:
	Query3(string p) :param(p){}
	void process(const vector<Student>& students, int casenum)
	{
		int hash[899] = { 0 };
		for (auto& x : students)
		{
			if (x.date == param)
				++hash[x.place - 101];
		}
		vector<myPair> ans;
		for (size_t i = 0; i < 899; ++i)
		{
			if (hash[i] != 0)
				ans.push_back(myPair(i + 101, hash[i]));
		}
		sort(ans.begin(), ans.end(), cmpPair);
		cout << "Case " << casenum << ": 3 " << param << endl;
		if (ans.size() == 0)
			cout << "NA" << endl;
		else
			copy(ans.begin(), ans.end(), ostream_iterator<myPair>(cout));
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	cin.get();
	string studentID;
	int score;
	vector<Student> students(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> studentID >> score;
		cin.get();
		Student temp(studentID);
		temp.score=score;
		students[i] = temp;
	}
	int casenum;
	IQuery* query = nullptr;
	for (int i = 0; i < M; ++i)
	{
		cin >> casenum;
		switch (casenum)
		{
		case 1:
		{
			cin.get();
			char lev;
			cin >> lev;
			cin.get();
			query = new Query1(lev);
			break;
		}
		case 2:
		{
			int plce;
			cin >> plce;
			query = new Query2(plce);
			break;
		}
		case 3:
		{
			string date;
			cin.get();
			cin >> date;
			cin.get();
			query = new Query3(date);
		}
		default:
			break;
		}
		query->process(students, i + 1);
		delete query;
		query = nullptr;
	}
	return 0;
}