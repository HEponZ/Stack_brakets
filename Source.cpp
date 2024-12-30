#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	stack<char> stack;
	string buf;
	char buf_char, open_braket;

	cout << "������� ������: ";
	getline(cin, buf, ';');

	for (size_t i{ 0 }; i < buf.size(); i++)
	{
		//��������� � ���������� �����_������ ���� ���� �� ������
		buf_char = buf[i];
		//�������� - �������� �� ������� ������ ����������� �������
		if (buf_char == '[' || buf_char == '{' || buf_char == '(')
		{
			//���� �������� �� ���������� ��� � ����
			stack.push(buf_char);
		}
		//���� ���, �� ��������� - �������� �� ���� ������ ����������� �������
		else if (buf_char == ']' || buf_char == '}' || buf_char == ')')
		{
			//������� �� �������� ������ ������ ����, 
			// ���� ����������� ����� - ( �� ����������� ����� - )
			if (buf_char == ']')
			{
				open_braket = '[';
			}
			else if (buf_char == '}')
			{
				open_braket = '{';
			}
			else if (buf_char == ')')
			{
				open_braket = '(';
			}
			//�������� ���� �� ���� ��� ��������� ������ �� �������� �����������
			if (stack.empty() || stack.top()!= open_braket)
			{
				cout << "������ �� �������\n";
				return 0;
			}
			//���� � ������ ���� � ����, ������� ��������� ����������� ������
			stack.pop();
		}
	}
	//���� � ����� �� �������� �� ����� ������, ��� ������, ���� �������� ���� ����
	//����������� ������, ������ � ��� ��� ����
	cout << "��� ������!\n";

	return 0;
}