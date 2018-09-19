#include"CGame.h"
int main(){
	char select('Y');
	CJewelry mymaze;
	while (select=='Y')
	{
		mymaze.SwapJew();
		cout << "消除。。。" << endl;
		system("pause");
		system("cls");
		mymaze.Eliminate();
		mymaze.PrintMaze();
		cout << "下降。。。" << endl;
		system("pause");
		system("cls");
		mymaze.siftdown();
		mymaze.PrintMaze();
		cout << "填充。。。" << endl;
		system("pause");
		system("cls");
		mymaze.Pad();
		mymaze.PrintMaze();
		cout << "是否继续？(Y/N)";
		getchar();
		select = getchar();
	}	
	cout << "再见！";
	return 0;
}