#include"worker_management.h"

//系统初始页面
void show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "**********  8.将职工信息写入文件  **********" << endl;
	cout << "*********  9.从文件中读取职工信息  *********" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

int main()
{
	worker_management w;
	int select;
	while (true)
	{
		show_menu();
		cout << "请输入你想选择的功能：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			//增加职工信息功能
			w.add_information();
			break;
		}
		case 2:
		{
			//显示职工信息功能
			w.show_information();
			break;
		}
		case 3:
		{
			//删除离职职工功能
			w.delete_information();
			break;
		}
		case 4:
		{
			//修改职工信息功能
			w.revise_information();
			break;
		}
		case 5:
		{
			//查找职工信息功能
			w.search_information();
			break;
		}
		case 6:
		{
			//按照编号排序功能
			w.sort_information();
			break;
		}
		case 7:
		{
			//清空所有文档功能
			w.clear_information();
			break;
		}
		case 8:
		{
			//将职工信息写入文件
			w.writefile_information();
			break;
		}
		case 9:
		{
			//从文件中读取信息
			w.readfile_information();
			break;
		}
		case 0:
		{
			//退出管理程序功能
			w.exit_system();
			break;
		}
		default:
			break;
		}
		if (select == 0)
		{
			system("pause");
			break;
		}
	}
	return 0;
}