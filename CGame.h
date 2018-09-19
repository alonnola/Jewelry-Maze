#ifndef CGAME_H
#define CGAME_H
#include <cstdlib>
#include <time.h>
#include"Queue.h"
#include <iomanip>

struct loc {
	int x;
	int y;
};

class CJewelry
{
public:
	CJewelry();    //初始化
	~CJewelry();
	void PrintMaze();
	void SwapJew();
	int Findneighbor(int i,int j,bool visited[10][10],loc trace[100],int count);
	void Eliminate();
	void Pad();
	void siftdown();
	int value(char);
private:
	char maze[10][10];
};
int CJewelry::value(char a) {
	if (a == '!')return 0;
	else return 1;
}

CJewelry::CJewelry()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10;j++) {
			switch (rand()%5)
			{
			case 0: maze[i][j] = 'R'; break;
			case 1: maze[i][j]= 'Y'; break;
			case 2:maze[i][j] = 'G'; break;
			case 3:maze[i][j] = 'B'; break;
			case 4:maze[i][j] = 'P'; break;
			default:	break;
			}
		}
		system("cls");
		PrintMaze();
	}
}

CJewelry::~CJewelry()
{
	
}
void CJewelry::siftdown() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j<10; j++) {			
			for (int k = 0; k<10-j; k++)
			{	
				if (value(maze[k][i]) >value( maze[k+1][i]))
				{	
					char temc= maze[k][i];
					maze[k][i] = maze[k+1][i];
					maze[k+1][i] = temc;
				}
			}
		}
	}
}
void CJewelry::SwapJew()
{
	int i1, i2, j1, j2; char tem;
	cout << "请输入要交换的个宝石坐标： " << endl;
	cin >> i1 >> j1 >> i2 >> j2;
	tem = maze[i1-1][j1-1];
	maze[i1-1][j1-1] = maze[i2-1][j2-1];
	maze[i2-1][j2-1] = tem;
	system("cls");
	PrintMaze();
}

int CJewelry::Findneighbor(int i, int j ,bool visited[10][10],loc trace[100],int count)
{
	LinkedQueue<loc> q;
	loc tem,tem1;
	tem.x = i; tem.y = j;
	q.EnQueue(tem);
	while (!q.IsEmpty()) {
		q.DeQueue(tem);
		visited[i][j] = true;
		trace[count].x = tem.x;
		trace[count].y = tem.y;		
		count++;
		if (tem.x>0&&visited[tem.x-1][tem.y]==false&&maze[tem.x -1][tem.y] == maze[tem.x][tem.y])			
		{
			visited[tem.x -1][tem.y] = true;
			tem1.x =tem.x-1; tem1.y = tem.y;
			q.EnQueue(tem1);			
		}		
		if (tem.x<9 && visited[tem.x + 1][tem.y] == false && maze[tem.x + 1][tem.y] == maze[tem.x][tem.y])
		{
			visited[tem.x +1][tem.y] = true;
			tem1.x = tem.x +1; tem1.y = tem.y;
			q.EnQueue(tem1);
		}
		if (tem.y>0 && visited[tem.x][tem.y-1] == false && maze[tem.x ][tem.y-1] == maze[tem.x][tem.y])
		{
			visited[tem.x ][tem.y-1] = true;
			tem1.x = tem.x ; tem1.y = tem.y-1;
			q.EnQueue(tem1);
		}
		if (tem.y<9 && visited[tem.x][tem.y+1] == false && maze[tem.x][tem.y+1] == maze[tem.x][tem.y])
		{
			visited[tem.x][tem.y+1] = true;
			tem1.x = tem.x ; tem1.y = tem.y+1;
			q.EnQueue(tem1);
		}
	}
	return count;
}

void CJewelry::Eliminate()
{
	loc  trace[100];
	bool visited[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (visited[i][j] == false) {
				int count = 0;
				int sum = Findneighbor(i, j, visited, trace, count);
				if(sum>=3){
					for (int k = 0; k <sum; k++)
					{ 
						maze[trace[k].x][trace[k].y] = '!';
					}
				}
			}
		}
	}



}

void CJewelry::Pad()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (maze[i][j] == '!')
			{
				switch (rand() % 5)
				{
				case 0: maze[i][j] = 'R'; break;
				case 1: maze[i][j] = 'Y'; break;
				case 2:maze[i][j] = 'G'; break;
				case 3:maze[i][j] = 'B'; break;
				case 4:maze[i][j] = 'P'; break;
				}
			}
		}
	}

}

 void CJewelry::PrintMaze()
{
	 for (int i = 0; i < 10; i++) {
		 for (int j = 0; j < 10; j++) {
			 cout <<setw(4)<< maze[i][j];
		 }
		 cout <<endl<< endl;
	 }
}

#endif // !CGAME_h
