#include"worker_management.h"

//ϵͳ��ʼҳ��
void show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "**********  8.��ְ����Ϣд���ļ�  **********" << endl;
	cout << "*********  9.���ļ��ж�ȡְ����Ϣ  *********" << endl;
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
		cout << "����������ѡ��Ĺ��ܣ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			//����ְ����Ϣ����
			w.add_information();
			break;
		}
		case 2:
		{
			//��ʾְ����Ϣ����
			w.show_information();
			break;
		}
		case 3:
		{
			//ɾ����ְְ������
			w.delete_information();
			break;
		}
		case 4:
		{
			//�޸�ְ����Ϣ����
			w.revise_information();
			break;
		}
		case 5:
		{
			//����ְ����Ϣ����
			w.search_information();
			break;
		}
		case 6:
		{
			//���ձ��������
			w.sort_information();
			break;
		}
		case 7:
		{
			//��������ĵ�����
			w.clear_information();
			break;
		}
		case 8:
		{
			//��ְ����Ϣд���ļ�
			w.writefile_information();
			break;
		}
		case 9:
		{
			//���ļ��ж�ȡ��Ϣ
			w.readfile_information();
			break;
		}
		case 0:
		{
			//�˳����������
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