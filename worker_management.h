#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;

//定义职工类
class employee
{
public:
	int num;//职工编号
	string name;//职工姓名
	int deploy_num;//部门编号

	virtual void output_post() = 0;//输出职工岗位信息
	virtual void out_responsibility() = 0;//输出职责信息
	virtual void show_information() = 0;//输出职工信息

	void get_information(int n, string& na, int de) //添加职工信息
	{
		num = n;
		name = na;
		deploy_num = de;
	}
};

//定义普通职工类
class normal :public employee
{
	virtual void output_post()
	{
		cout << "职工岗位：普通员工" << endl;
	}
	virtual void out_responsibility()
	{
		cout << "职责：完成经理交给的任务" << endl;
	}
	virtual void show_information()
	{
		cout << "职工编号：" << num << endl;
		cout << "职工姓名：" << name << endl;
		output_post();
		out_responsibility();
	}
};

//定义经理类
class manager :public employee
{
	virtual void output_post()
	{
		cout << "职工岗位：经理" << endl;
	}
	virtual void out_responsibility()
	{
		cout << "职责：完成老板交给的任务，并下发任务给员工" << endl;
	}
	virtual void show_information()
	{
		cout << "职工编号：" << num << endl;
		cout << "职工姓名：" << name << endl;
		output_post();
		out_responsibility();
	}
};

//定义老板类
class boss :public employee
{
	virtual void output_post()
	{
		cout << "职工岗位：老板" << endl;
	}
	virtual void out_responsibility()
	{
		cout << "职责：管理公司所有事务" << endl;
	}
	virtual void show_information()
	{
		cout << "职工编号：" << num << endl;
		cout << "职工姓名：" << name << endl;
		output_post();
		out_responsibility();
	}
};

//定义职工管理系统
class worker_management
{
private:
	vector<employee*> worker_list;
public:
	//析构函数
	~worker_management()
	{
		for (int i = 0; i < worker_list.size(); i++)
		{
			delete worker_list[i];
		}
	}

	//退出系统函数
	void exit_system()
	{
		cout << "退出职工管理系统" << endl;
		system("pause");
		exit(0);
	}

	//使用者输入信息到系统
	void add_information()
	{
		int num;
		string name;
		int de_num;
		cout << "请输入需要添加的职工信息" << endl;
		cout << "请输入职工编号：";
		cin >> num;
		cout << "请输入职工姓名：" << endl;
		cin >> name;
		cout << "请输入部门编号（1—普通员工，2—经理，3—老板）：" << endl;
		cin >> de_num;
		switch (de_num)
		{
		case 1:
		{
			employee* e1=new normal;
			e1->get_information(num, name, de_num);
			worker_list.push_back(e1);
			break;
		}
		case 2:
		{
			employee* e2 = new manager;
			e2->get_information(num, name, de_num);
			worker_list.push_back(e2);
			break;
		}
		case 3:
		{
			employee* e3 = new boss;
			e3->get_information(num, name, de_num);
			worker_list.push_back(e3);
			break;
		}
		default:
			break;
		}
	}

	//从文件中读取信息到系统
	void readfile_information()
	{
		ifstream ifa;
		ifa.open("worker_information.txt", ios::in);
		if (!ifa)//检查文件是否存在
		{
			cerr << "文件不存在！" << endl;
			ifa.close();
			return;
		}
		if (ifa.peek() == std::ifstream::traits_type::eof())//检查文件是否为空
		{
			cout << "文件为空！" << endl;
			ifa.close();
			return;
		}
		//文件不为空，则开始读取数据
		int n;
		string na;
		int de_nu;
		while (ifa >> n>> na >> de_nu)
		{
			switch (de_nu)
			{
			case 1:
			{
				employee* e1 = new normal;
				e1->get_information(n, na, de_nu);
				worker_list.push_back(e1);
				break;
			}
			case 2:
			{
				employee* e2 = new manager;
				e2->get_information(n, na, de_nu);
				worker_list.push_back(e2);
				break;
			}
			case 3:
			{
				employee* e3 = new boss;
				e3->get_information(n, na, de_nu);
				worker_list.push_back(e3);
				break;
			}
			default:
				break;
			}
		}
		
	}

	//将系统中信息写入文件中
	void writefile_information()
	{
		ofstream ofa;
		ofa.open("worker_information.txt", ios::out);
		if (!ofa)
		{
			cerr << "打开文件失败！" << endl;
		}

		for (vector<employee*>::iterator it = worker_list.begin(); it != worker_list.end(); ++it)
		{
			ofa << (*it)->num << " " << (*it)->name << " " << (*it)->deploy_num << endl;
		}
		ofa.close();
	}

	//显示职工信息
	void show_information()
	{
		for (int i = 0; i < worker_list.size(); i++)
		{
			worker_list[i]->show_information();
		}
	}

	//删除离职职工，按照编号删除指定的职工
	void delete_information()
	{
		int n_temp;
		cout << "请输入要删除的职工编号：" << endl;
		cin >> n_temp;
		if (!cin) {
			// 处理输入错误
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
			cout << "输入错误，请输入有效的职工编号。" << endl;
			return;
		}

		auto it = std::find_if(worker_list.begin(), worker_list.end(), [n_temp](const auto& worker_ptr) {
			return worker_ptr->num == n_temp;
		});

		if (it == worker_list.end()) {
			cout << "系统中不存在该职工编号" << endl;
		}
		else {
			delete* it; // 删除指针指向的对象
			*it = nullptr; // 可选：将已删除对象的指针设置为nullptr
			worker_list.erase(it); // 从vector中移除指针
		}
	}

	//修改职工信息，按照编号修改职工个人信息
	void revise_information()
	{
		int n_temp;
		cout << "请输入要修改的职工编号：" << endl;
		cin >> n_temp;
		if (!cin) {
			// 处理输入错误
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
			cout << "输入错误，请输入有效的职工编号。" << endl;
			return;
		}
		auto it = std::find_if(worker_list.begin(), worker_list.end(), [n_temp](const auto& worker_ptr) {
			return worker_ptr->num == n_temp;
		});

		if (it == worker_list.end()) {
			cout << "系统中不存在该职工编号" << endl;
		}
		else
		{
			cout << "当前该职工的信息如下：" << endl;
			(*it)->show_information();
			cout << "——————————" << endl;
			cout << "需要修改姓名吗？（1——是，0——否）" << endl;
			int j;
			cin >> j;
			if (j == 1)
			{
				string name_temp;
				cout << "请输入修改后的姓名：" << endl;
				cin >> name_temp;
				(*it)->name = name_temp;
			}
			cout << "需要修改部门编号吗？需要则输入对应部门编号（1，2和3），否则输入0" << endl;
			cin >> j;
			if (j == 1 && j != (*it)->deploy_num)
			{
				employee* e = new normal;
				e->get_information((*it)->num, (*it)->name, j);
				delete* it;
				*it = e;
			}
			if (j == 2 && j != (*it)->deploy_num)
			{
				employee* e = new manager;
				e->get_information((*it)->num, (*it)->name, j);
				delete* it;
				*it = e;
			}
			if (j == 3 && j != (*it)->deploy_num)
			{
				employee* e = new boss;
				e->get_information((*it)->num, (*it)->name, j);
				delete* it;
				*it = e;
			}
			cout << "——————————" << endl;
			cout << "修改后的对应信息如下：" << endl;
			(*it)->show_information();
		}

	}

	//查找职工信息，按照编号或姓名进行查找
	void search_information()
	{
		int n_temp;
		cout << "请输入要查找的职工编号：" << endl;
		cin >> n_temp;
		if (!cin) {
			// 处理输入错误
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
			cout << "输入错误，请输入有效的职工编号。" << endl;
			return;
		}
		auto it = std::find_if(worker_list.begin(), worker_list.end(), [n_temp](const auto& worker_ptr) {
			return worker_ptr->num == n_temp;
		});

		if (it == worker_list.end()) {
			cout << "系统中不存在该职工编号" << endl;
		}
		else
		{
			cout << "查找到的职工编号信息如下：" << endl;
			(*it)->show_information();
		}
	}

	//按照职工的编号进行排序，排序规则由用户指定
	void sort_information()
	{
		cout << "按照职工编号从小到大输入1，从大到小输入0：" << endl;
		int i;
		cin >> i;
		if (i == 1)
		{
			sort(worker_list.begin(), worker_list.end(), [](const employee* a, const employee* b) 
			{
				return a->num < b->num; // 按职工编号升序排序
			});
			cout << "从小到大排序后的信息如下：" << endl;
			for (const auto& e : worker_list)
				e->show_information();
		}
		if (i == 0)
		{
			sort(worker_list.begin(), worker_list.end(), [](const employee* a, const employee* b)
			{
				return a->num > b->num; // 按职工编号降序排序
			});
			cout << "从大到小排序后的信息如下：" << endl;
			for (const auto& e : worker_list)
				e->show_information();
		}
	}

	//清空文件中记录的所有职工信息
	void clear_information()
	{
		ofstream ofb;
		ofb.open("worker_information.txt", ios::trunc);
		if (!ofb)
		{
			cerr << "无法打开文件！" << endl;
			return;
		}
		ofb.close();
		return;
	}
};