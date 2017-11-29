#include<iostream>
#include<vector>
using namespace std;
void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
    int b = dimh, x,y;
	if(board[posr][posc] == 'd')
	{
		cout << "CLEAN\n";
		return;
	}
	x=posc;y=posr;
	int fmin=dimh+dimw; string ans;
	int l, r;
	l = board[posr].find_last_of('d', posc);
	r = board[posr].find_first_of('d', posc);
	if(l!=string::npos)
	{
		if(r!=string::npos)
		{
			fmin = min(x-l,r-x);
			if(x-l < r-x)
				ans="LEFT";
			else
				ans="RIGHT";
		}
		else
		{
			fmin = x-l;
			ans="LEFT";
		}
	}
	else if(r!=string::npos)
	{
		ans="RIGHT";
		fmin = r-x;
	}

//	cout << "pre fmin = " << fmin << endl;

	int ulim = max(0, posr-fmin), llim = min(posr+fmin, b-1), xl, xr, rmin=dimw;
//	cout << "UPPER:\n";
	for(int i=posr-1; i>=ulim; i--)
	{
		l = board[i].find_last_of('d', posc),
				r = board[i].find_first_of('d', posc);
//		cout << l << " " << r << "\n";
		if(l == posc)
		{
			ans="UP";
			fmin = posr-i;
			break;
		}
		if(l!=string::npos)
		{
			if(r!=string::npos)
				rmin = min(x-l, r-x);
			else
				rmin = x-l;
		}
		else if(r!=string::npos)
			rmin = r-x;
		if(rmin + posr-i < fmin)
		{
			fmin = rmin + posr - i;
			ans = "UP";
			break;
		}
	}
//	cout << "fmin: "<<fmin<<endl;
	llim = min(posr+fmin, b-1);
//	cout << "LOWER\n";
	for(int j=posr+1; j<=llim; j++)
	{
			l = board[j].find_last_of('d', posc),
					r = board[j].find_first_of('d', posc);
			if(l == posc)
			{
				ans="DOWN";
				fmin = j-posr;
				break;
			}
			if(l!=string::npos)
			{
				if(r!=string::npos)
					rmin = min(x-l, r-x);
				else
					rmin = x-l;
			}
			else if(r!=string::npos)
				rmin = r-x;
			if(rmin + j-posr < fmin)
			{
				fmin = rmin + j - posr;
				ans = "DOWN";
				break;
			}
		}
	cout << ans << endl;
}
int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
