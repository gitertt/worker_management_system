#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;

//����ְ����
class employee
{
public:
	int num;//ְ�����
	string name;//ְ������
	int deploy_num;//���ű��

	virtual void output_post() = 0;//���ְ����λ��Ϣ
	virtual void out_responsibility() = 0;//���ְ����Ϣ
	virtual void show_information() = 0;//���ְ����Ϣ

	void get_information(int n, string& na, int de) //���ְ����Ϣ
	{
		num = n;
		name = na;
		deploy_num = de;
	}
};

//������ְͨ����
class normal :public employee
{
	virtual void output_post()
	{
		cout << "ְ����λ����ͨԱ��" << endl;
	}
	virtual void out_responsibility()
	{
		cout << "ְ����ɾ�����������" << endl;
	}
	virtual void show_information()
	{
		cout << "ְ����ţ�" << num << endl;
		cout << "ְ��������" << name << endl;
		output_post();
		out_responsibility();
	}
};

//���徭����
class manager :public employee
{
	virtual void output_post()
	{
		cout << "ְ����λ������" << endl;
	}
	virtual void out_responsibility()
	{
		cout << "ְ������ϰ彻�������񣬲��·������Ա��" << endl;
	}
	virtual void show_information()
	{
		cout << "ְ����ţ�" << num << endl;
		cout << "ְ��������" << name << endl;
		output_post();
		out_responsibility();
	}
};

//�����ϰ���
class boss :public employee
{
	virtual void output_post()
	{
		cout << "ְ����λ���ϰ�" << endl;
	}
	virtual void out_responsibility()
	{
		cout << "ְ�𣺹���˾��������" << endl;
	}
	virtual void show_information()
	{
		cout << "ְ����ţ�" << num << endl;
		cout << "ְ��������" << name << endl;
		output_post();
		out_responsibility();
	}
};

//����ְ������ϵͳ
class worker_management
{
private:
	vector<employee*> worker_list;
public:
	//��������
	~worker_management()
	{
		for (int i = 0; i < worker_list.size(); i++)
		{
			delete worker_list[i];
		}
	}

	//�˳�ϵͳ����
	void exit_system()
	{
		cout << "�˳�ְ������ϵͳ" << endl;
		system("pause");
		exit(0);
	}

	//ʹ����������Ϣ��ϵͳ
	void add_information()
	{
		int num;
		string name;
		int de_num;
		cout << "��������Ҫ��ӵ�ְ����Ϣ" << endl;
		cout << "������ְ����ţ�";
		cin >> num;
		cout << "������ְ��������" << endl;
		cin >> name;
		cout << "�����벿�ű�ţ�1����ͨԱ����2������3���ϰ壩��" << endl;
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

	//���ļ��ж�ȡ��Ϣ��ϵͳ
	void readfile_information()
	{
		ifstream ifa;
		ifa.open("worker_information.txt", ios::in);
		if (!ifa)//����ļ��Ƿ����
		{
			cerr << "�ļ������ڣ�" << endl;
			ifa.close();
			return;
		}
		if (ifa.peek() == std::ifstream::traits_type::eof())//����ļ��Ƿ�Ϊ��
		{
			cout << "�ļ�Ϊ�գ�" << endl;
			ifa.close();
			return;
		}
		//�ļ���Ϊ�գ���ʼ��ȡ����
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

	//��ϵͳ����Ϣд���ļ���
	void writefile_information()
	{
		ofstream ofa;
		ofa.open("worker_information.txt", ios::out);
		if (!ofa)
		{
			cerr << "���ļ�ʧ�ܣ�" << endl;
		}

		for (vector<employee*>::iterator it = worker_list.begin(); it != worker_list.end(); ++it)
		{
			ofa << (*it)->num << " " << (*it)->name << " " << (*it)->deploy_num << endl;
		}
		ofa.close();
	}

	//��ʾְ����Ϣ
	void show_information()
	{
		for (int i = 0; i < worker_list.size(); i++)
		{
			worker_list[i]->show_information();
		}
	}

	//ɾ����ְְ�������ձ��ɾ��ָ����ְ��
	void delete_information()
	{
		int n_temp;
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		cin >> n_temp;
		if (!cin) {
			// �����������
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ�������
			cout << "���������������Ч��ְ����š�" << endl;
			return;
		}

		auto it = std::find_if(worker_list.begin(), worker_list.end(), [n_temp](const auto& worker_ptr) {
			return worker_ptr->num == n_temp;
		});

		if (it == worker_list.end()) {
			cout << "ϵͳ�в����ڸ�ְ�����" << endl;
		}
		else {
			delete* it; // ɾ��ָ��ָ��Ķ���
			*it = nullptr; // ��ѡ������ɾ�������ָ������Ϊnullptr
			worker_list.erase(it); // ��vector���Ƴ�ָ��
		}
	}

	//�޸�ְ����Ϣ�����ձ���޸�ְ��������Ϣ
	void revise_information()
	{
		int n_temp;
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		cin >> n_temp;
		if (!cin) {
			// �����������
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ�������
			cout << "���������������Ч��ְ����š�" << endl;
			return;
		}
		auto it = std::find_if(worker_list.begin(), worker_list.end(), [n_temp](const auto& worker_ptr) {
			return worker_ptr->num == n_temp;
		});

		if (it == worker_list.end()) {
			cout << "ϵͳ�в����ڸ�ְ�����" << endl;
		}
		else
		{
			cout << "��ǰ��ְ������Ϣ���£�" << endl;
			(*it)->show_information();
			cout << "��������������������" << endl;
			cout << "��Ҫ�޸������𣿣�1�����ǣ�0������" << endl;
			int j;
			cin >> j;
			if (j == 1)
			{
				string name_temp;
				cout << "�������޸ĺ��������" << endl;
				cin >> name_temp;
				(*it)->name = name_temp;
			}
			cout << "��Ҫ�޸Ĳ��ű������Ҫ�������Ӧ���ű�ţ�1��2��3������������0" << endl;
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
			cout << "��������������������" << endl;
			cout << "�޸ĺ�Ķ�Ӧ��Ϣ���£�" << endl;
			(*it)->show_information();
		}

	}

	//����ְ����Ϣ�����ձ�Ż��������в���
	void search_information()
	{
		int n_temp;
		cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
		cin >> n_temp;
		if (!cin) {
			// �����������
			cin.clear(); // ��������־
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ�������
			cout << "���������������Ч��ְ����š�" << endl;
			return;
		}
		auto it = std::find_if(worker_list.begin(), worker_list.end(), [n_temp](const auto& worker_ptr) {
			return worker_ptr->num == n_temp;
		});

		if (it == worker_list.end()) {
			cout << "ϵͳ�в����ڸ�ְ�����" << endl;
		}
		else
		{
			cout << "���ҵ���ְ�������Ϣ���£�" << endl;
			(*it)->show_information();
		}
	}

	//����ְ���ı�Ž�����������������û�ָ��
	void sort_information()
	{
		cout << "����ְ����Ŵ�С��������1���Ӵ�С����0��" << endl;
		int i;
		cin >> i;
		if (i == 1)
		{
			sort(worker_list.begin(), worker_list.end(), [](const employee* a, const employee* b) 
			{
				return a->num < b->num; // ��ְ�������������
			});
			cout << "��С������������Ϣ���£�" << endl;
			for (const auto& e : worker_list)
				e->show_information();
		}
		if (i == 0)
		{
			sort(worker_list.begin(), worker_list.end(), [](const employee* a, const employee* b)
			{
				return a->num > b->num; // ��ְ����Ž�������
			});
			cout << "�Ӵ�С��������Ϣ���£�" << endl;
			for (const auto& e : worker_list)
				e->show_information();
		}
	}

	//����ļ��м�¼������ְ����Ϣ
	void clear_information()
	{
		ofstream ofb;
		ofb.open("worker_information.txt", ios::trunc);
		if (!ofb)
		{
			cerr << "�޷����ļ���" << endl;
			return;
		}
		ofb.close();
		return;
	}
};