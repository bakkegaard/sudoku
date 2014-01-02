#include <iostream>
#include <vector>

using namespace std;

int sum=0;

int print(vector< vector <int> >& sudoku){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

bool checkrow(vector < vector < int > > & sudoku, int x){
	vector<bool> numbers(10);
	for(int i=0;i<9;i++){
		int temp= sudoku[x][i];
		if(temp==0) continue;
		else if(numbers[temp]) return false;
		else numbers[temp]=true;
	}
	return true;
}

bool checksq(vector < vector < int > > & sudoku, int x, int y){
	vector<bool> numbers(10);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int temp= sudoku[x+i][y+j];
			if(temp==0) continue;
			else if(numbers[temp]) return false;
			else numbers[temp]=true;
		}
	}
	return true;
}

bool checksqs(vector < vector < int > > & sudoku){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!checksq(sudoku,i*3,j*3)) return false;;
		}
	}
	return true;
}

bool checkcolumn(vector < vector < int > > & sudoku, int y){
	vector<bool> numbers(10);
	for(int i=0;i<9;i++){
		int temp= sudoku[i][y];
		if(temp==0) continue;
		else if(numbers[temp]) return false;
		else numbers[temp]=true;
	}
	return true;
}

bool check(vector < vector <int> > & sudoku, int x, int y){
	if(checkrow(sudoku,x) && checkcolumn(sudoku,y) && checksqs(sudoku)) return true;
	else return false;
}

int countx(int x, int y){
	if(y==8 && x==8) return -1;
	if(y==8) return ++x;
	else return x;
}
int county(int x, int y){
	if(y==8) return 0;
	else return ++y;
}

bool solve(vector< vector < int> > sudoku , int x,int y){
	sum++;
	if(x==-1){
		cout << sum << endl;
		print(sudoku);
		return true;
	}
	if(sudoku[x][y]==0){		
		for(int i=1;i<=9;i++){
			sudoku[x][y]=i;
			if(check(sudoku,x,y)){
				if(solve(sudoku,countx(x,y),county(x,y))) return true;
			}
			if(i==9) return false;
		}
		if(x==8 && y==8){
			print(sudoku);
			return true;
			
		}
	}
	return 	solve(sudoku,countx(x,y),county(x,y));
}

int main(){
	vector< vector <int> > sudoku(9);

	int temp;

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> temp;	
			sudoku[i].push_back(temp);
		}
	}

	if(solve(sudoku,0,0)); 
	else cout << "Wrong!" << endl;

}
