#include"CGame.h"
int main(){
	char select('Y');
	CJewelry mymaze;
	while (select=='Y')
	{
		mymaze.SwapJew();
		cout << "����������" << endl;
		system("pause");
		system("cls");
		mymaze.Eliminate();
		mymaze.PrintMaze();
		cout << "�½�������" << endl;
		system("pause");
		system("cls");
		mymaze.siftdown();
		mymaze.PrintMaze();
		cout << "��䡣����" << endl;
		system("pause");
		system("cls");
		mymaze.Pad();
		mymaze.PrintMaze();
		cout << "�Ƿ������(Y/N)";
		getchar();
		select = getchar();
	}	
	cout << "�ټ���";
	return 0;
}