#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

string filename;							// 파일 이름

vector<string> filecalls(vector<string> st)
{
	ifstream fp;							// 파일 변수
	string line;							// 파일 읽기 변수
	cout << " 파일 이름 : ";
	cin >> filename;
	fp.open(filename);
	if (fp.is_open())						// Word파일이 있을때
	{
		while (!fp.eof())
		{
			getline(fp, line);
			st.push_back(line);
		}
		cout << " 파일을 정상적으로 읽었습니다." << endl;
		cout << " ----------------------" << endl;
	}
	else									// Word 파일이 없을때
	{
		cout << " 일치하는 파일이 없습니다. 프로그램을 종료합니다." << endl;
		exit(0);
	}
	fp.close();
	return st;
}

void filesave(vector<string> st)
{
	ofstream out(filename);
	if (out.is_open())
	{
		for (int a = 0; a < st.size(); a++)
		{
			out << st[a] << endl;
		}
	}
	cout << " ----------------------" << endl;
	out.close();
}

vector<string> search(vector<string> st)
{
	string search_;						// 검색할 단어
	int count = 0;

	cout << " 검색할 단어 : ";
	cin >> search_;
	cout << " " << search_ << "가 포함된 단어 " << endl;
	cout << " ----------------------" << endl;

	for (int b = 0; b < st.size(); b++)
	{
		if (st[b].find(search_) != string::npos)
		{
			count++;
			cout << " " << count << ".	 " << st[b] << endl;
		}
	}
	if (count == 0)							// 검색 체크
	{
		cout << " 검색결과 : 없음 " << endl;
	}

	cout << " ----------------------" << endl;
	string wo;							// 탐색할 단어
	string change;						// 변환할 단어
	int co = 0;							// 탐색 체크

	cout << " 탐색할 단어 : ";
	cin >> wo;
	cout << " 변환할 단어 : ";
	cin >> change;

	for (int r = 0; r < st.size(); r++)
	{
		if (st[r] == wo)
		{
			co++;
			st[r] = change;

		}
	}
	cout << " ----------------------" << endl;
	if (co == 0)
	{
		cout << " 일치하는 단어가 없습니다. 종료합니다. " << endl;
	}
	else
	{
		cout << " 해당하는 단어는 총" << co << "회 사용되었습니다." << endl;
		cout << " 모든 단어를 변환 완료하였습니다." << endl;
	}
	return st;
}

void main()
{
	vector<string> str;
	str = filecalls(str);			// 불러온 txt파일을 str에 저장
	str = search(str);				// 단어 검색, 변경
	filesave(str);				// 단어 저장
}
