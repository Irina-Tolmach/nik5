//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//
//typedef long long ll;
//using namespace std;
//
////|a/h b/g|    |?| = a*d/h-b*c/g=(a*d*g -b*c*h)/gh = A;
////| c    d|					() + () + () + (); для 4 и 3 НОК = 12 = 4*3/НОД(4,3)
//
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<pair<ll, ll>>> a(n, vector<pair<ll, ll>>(n));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//		{
//			string s;
//			cin >> s;
//			bool flag = 0;
//			ll n1, n2;
//			for (int k = 0; k < s.size(); ++k)
//			{
//				if (s[k] == '/')
//				{
//					int ch, zn;
//					string s1, s2;
//					s1 = s.substr(0, k);
//					s2 = s.substr(k + 1);
//					flag = 1;
//					n1 = stoi(s1);
//					n2 = stoi(s2);
//					break;
//					
//				}
//			}
//			if (flag)
//			{
//				a[i][j].first = n1;
//				a[i][j].second = n2;
//			}
//			else
//			{
//				a[i][j].first = stoi(s);
//				a[i][j].second = 1;
//			}
//		}
//	}
//	
//	ll mn = 1;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j)
//			mn *= a[i][j].second;
//	}  
//	cout << mn;
//}

// Толмачева Ирина ИВТ-13
// я старалась, правда))))))) (Однако не все получилось(((()
#include <iostream>
#include <fstream>
#include <vector>
#include <locale.h>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
ll nn, koef = 1, krai = 9223372036854775806;
vector<ll> otv, delit;
vector<vector<ll>>itog;
int cnt = 0;


bool count(ll i, vector<ll> alf, vector<ll> word)
{
	ll k = alf[i];
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == k)
			return false;
	}
	return true;
}

void Perestanov0chka(vector<ll> alf, vector<ll> word, int n)
{
	int i;
	if (n == word.size())
	{
		itog.push_back(word);
		return;
	}
	for (i = 0; i < alf.size(); i++)
	{
		if (count(i, alf, word))
		{
			word[n] = alf[i];
			Perestanov0chka(alf, word, n + 1);
		}
	}
}

void Trans(ll** a, ll n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			ll t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
}

//map<ll, ll> mp, mp1;
//void funu(ll a, bool flag) // неудавшаяся оптимизация для Гаусса((((
//{
//	if (flag)
//	{
//		if (a < 0)
//		{
//			KK *= -1;
//			a *= -1;
//		}
//		ll a1 = a;
//		for (ll i = 2; i * i <= a1; i++)
//			while (a % i == 0)
//			{
//				a /= i;
//				if (mp[i] != 1)
//					mp[i] = 1;
//				else
//					mp[i]++;
//			}
//		if (a != 1)
//			mp[a] = 1;
//		return;
//	}
//	else
//	{
//		if (a < 0)
//		{
//			KK *= -1;
//			a *= -1;
//		}
//		ll a1 = a;
//		for (ll i = 2; i * i <= a1; i++)
//			while (a % i == 0)
//			{
//
//				a /= i;
//				if (mp1[i] != 1)
//					mp1[i] = 1;
//				else
//					mp1[i]++;
//			}
//		if (a != 1)
//			mp1[a] = 1;
//		return;
//	}
//}
//bool comp(ll a, ll b)
//{
//	return a > b;
//}
//void Koeff(ll** a, ll n)
//{
//	for (int str = 0; str < n; str++) {
//		vector<ll> del;
//		ll smin = krai;
//		for (ll i = 0; i < n; i++)
//		{
//			if(a[str][i] != 0)
//				smin = min(abs(a[str][i]), smin);
//		}
//		if (smin != krai && smin!=1) {
//			for (ll i = 1; i * i <= smin; i++)
//			{
//				if (smin % i == 0)
//				{
//					del.push_back(i);
//					if (i * i != smin)
//						del.push_back(smin / i);
//				}
//			}
//			sort(del.begin(), del.end(), comp);
//			for (auto it = del.begin(); it != del.end(); it++)
//			{
//				bool flag = true;
//				for (ll i = 0; i < n && flag; i++)
//					if (a[str][i] % (*it) != 0)
//						flag = false;
//				if (flag)
//				{
//					for (ll i = 0; i < n; i++)
//						a[str][i] = a[str][i] / (*it);
//					if ((*it) != 1)
//					{
//						delit.push_back(*it);
//						cout << endl << "выносим общий множитель " << (*it) << " из " << str + 1 << " строки";
//					}
//					break;
//				}
//			}
//		}
//	}
//	return;
//}

pair<ll, ll> FindStrStolb(ll** a, ll n)
{
	pair<ll, ll> p;
	ll cnt0 = 0, cnt1 = 0, cnt1rec = 0, cnt0rec = 0, col = 0, roll = 0;
	for (int i = 0; i < n; i++) {
		cnt1 = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
				cnt1++;
		}
		if (cnt1 > cnt1rec)
		{
			cnt1rec = cnt1; // строчка
			roll = i;
		}
	}
	for (int i = 0; i < n; i++) {
		cnt0 = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j][i] == 0)
				cnt0++;
		}
		if (cnt0 > cnt0rec)
		{
			cnt0rec = cnt0; // столбец
			col = i;
		}
	}
	if (cnt1rec >= cnt0rec)
	{
		p.first = 1; // строка
		p.second = roll;
	}
	else
	{
		p.first = 0; // столбец
		p.second = col;
	}
	return p;
}

ll** Minor(ll** a, ll col, ll roll, ll n)
{
	ll** b;
	b = new ll * [n - 1];
	for (int i = 0; i < n - 1; i++)
		b[i] = new ll[n - 1];
	ll ii = 0, jj = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == roll)
			continue;
		jj = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == col)
				continue;
			b[ii][jj] = a[i][j];
			jj++;

		}
		ii++;
	}
	return b;
}

ll Laplas(ll** a, ll n)
{
	ll d = 0;
	if (n == 1) {
		return a[0][0];
	}
	else if (n == 2) {
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	else
	{
		ll** b, ak;
		b = new ll * [n - 1];
		for (ll i = 0; i < n - 1; i++)
			b[i] = new ll[n - 1];
		pair <ll, ll> p = FindStrStolb(a, n);
		if (p.first == 0)
			Trans(a, n);
		if (n == nn) {
			if (p.first == 1)
				cout << "Разложение определителя по " << p.second + 1 << " строке" << endl;
			else
				cout << "Разложение определителя по " << p.second + 1 << " столбцу" << endl;
		}
		for (ll i = 0; i < n; i++)
		{
			b = Minor(a, i, p.second, n);
			if (n == nn && a[p.second][i] != 0) {
				cout << a[p.second][i];

				for (ll i = 0; i < n - 1; i++)
				{
					cout << endl;
					for (ll j = 0; j < n - 1; j++)
						cout << b[i][j] << " ";
				}
				cout << endl;
			}

			if ((i + p.second) % 2 == 0)
				ak = 1;
			else
				ak = -1;
			if (n == nn) {
				if (Laplas(b, n - 1) >= 0 && a[p.second][i] != 0)
					cout << "=" << ak * a[p.second][i] << "*" << Laplas(b, n - 1) << "=" << ak * a[p.second][i] * Laplas(b, n - 1) << endl << endl;
				else if (a[p.second][i] != 0)
					cout << "=" << ak * a[p.second][i] << "*(" << Laplas(b, n - 1) << ")=" << ak * a[p.second][i] * Laplas(b, n - 1) << endl << endl;
				if (ak * a[p.second][i] * Laplas(b, n - 1) != 0)
					otv.push_back(ak * a[p.second][i] * Laplas(b, n - 1));
			}
			d = d + ak * a[p.second][i] * Laplas(b, n - 1);

		}
	}
	if (n == nn) {
		cout << "Определитель матрицы по рекурсивной формуле:";
		for (int i = 0; i < otv.size(); i++)
		{
			if (i != 0)
				cout << "+";
			if (otv[i] > 0)
				cout << otv[i];
			else
				cout << "(" << otv[i] << ")";
		}
	}
	return d;
}

void Gauss(ll** a, int n)
{
	int h, k, pivot = 0;
	h = 0; k = 0;
	while (h < n) //n
	{
		//Koeff(a, n);
		pivot = h;
		while (pivot < n)
		{
			if (a[pivot][k] == 0)
				pivot++;
			else
			{
				if (pivot != h)
				{
					for (int i = 0; i < n; i++)
					{
						int t = a[pivot][i];
						a[pivot][i] = a[h][i];
						a[h][i] = t;
					}
					koef *= -1;
					cout << endl << "(" << h + 1 << ")" << "<-->" << "(" << pivot + 1 << ")";
					cout << endl;
					for (int i = 0; i < n; i++)
					{
						cout << endl;
						for (int j = 0; j < n; j++) {
							cout << a[i][j] << " ";
						}
					}
					cout << endl;
				}
				break;
			}
		}
		if (pivot == n)
		{
			cout << "Определитель равен 0, по сложившимся обстоятельствам) В ходе метода Гаусса оказалось, что у нас нолик на главной диагонали, как строчки не тасуй((" << endl;
			return;
		}
		pivot = h;
		int cf1, cf2;
		for (int i = h; i < n; i++)
		{
			if (i == pivot)
				continue;
			else
			{
				cf1 = a[pivot][k];
				cf2 = a[i][k];
				koef *= cf1;
				for (int j = k; j < n; j++)
				{
					a[i][j] = a[i][j] * cf1 - a[pivot][j] * cf2;
				}
				cout << endl;
				cout << cf1 << "*" << "(" << i + 1 << ")" << " - " << cf2 << " * " << "(" << pivot + 1 << ")";
			}
		}
		if (h + 1 < n)
		{
			//Koeff(a, n);
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				cout << endl;
				for (int j = 0; j < n; j++) {
					cout << a[i][j] << " ";
				}
			}
			cout << endl;
			//Koeff(a, n);
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				cout << endl;
				for (int j = 0; j < n; j++) {
					cout << a[i][j] << " ";
				}
			}
			cout << endl;
		}

		h++;
		k++;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	ifstream in;
	//in.open(argv[1]);
	in.open("input.txt");
	ll n, ** a, ** b;
	in >> nn;
	n = nn;
	a = new ll * [n];
	b = new ll * [n];
	for (int i = 0; i < n; i++) {
		a[i] = new ll[n];
		b[i] = new ll[n];
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
			b[i][j] = a[i][j];
		}
	}

	//cout << "Определитель матрицы по методу Гаусса:" << endl;
	//for (ll i = 0; i < n; i++)
	//{
	//	for (ll j = 0; j < n; j++)
	//		cout << a[i][j] << " ";
	//	cout << endl;
	//}
	//Gauss(a, n);
	//ll opr = 1;
	//cout << "Определитель матрицы по методу Гаусса:  ";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		if (i == j) {
	//			opr *= a[i][j];
	//			if (i != 0)
	//				cout << "*";
	//			if (a[i][j] < 0)
	//				cout << "(" << a[i][j] << ")";
	//			else
	//				cout << a[i][j];
	//		}
	//	}
	//}
	//cout << "/" << koef;
	//cout << " = " << opr / koef;
	//cout << endl << endl << endl;
	//for (int i = 0; i < nn; i++)
	//	for (int j = 0; j < nn; j++)
	//		a[i][j] = b[i][j];

	//cout << "Определитель по рекурсивной формуле (Лаплас):" << endl;

	//for (ll i = 0; i < n; i++)
	//{
	//	for (ll j = 0; j < n; j++)
	//		cout << a[i][j] << " ";
	//	cout << endl;
	//}
	//cout << endl;
	//for (int i = 0; i < otv.size(); i++)
	//{
	//	if (i != 0)
	//		cout << "+";
	//	if (otv[i] > 0)
	//		cout << otv[i];
	//	else
	//		cout << "(" << otv[i] << ")";
	//}

	//cout << " = " << Laplas(a, n); // Лаплас

	//cout << endl << endl << endl;

	//for (int i = 0; i < nn; i++)
	//	for (int j = 0; j < nn; j++)
	//		a[i][j] = b[i][j];



	vector<ll> alf(nn); // отсюда Начинается Лейбниц
	vector<ll>word(nn, -1);
	vector<ll> Delta;
	for (int i = 0; i < nn; i++)
		alf[i] = i;
	Perestanov0chka(alf, word, 0);
	for (int i = 0; i < itog.size(); i++) {
		ll cnt = 0;
		for (int j = 0; j < itog[i].size(); j++)
		{
			for (int k = j + 1; k < itog[i].size(); k++)
				if (itog[i][k] < itog[i][j])
					cnt++;
		}
		Delta.push_back(cnt);
	}
	cout << "Определитель матрицы по комбинаторной формуле (Лейбниц):" << endl;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	vector<ll> promdet((int)itog.size(), 1);
	ll ii = 0, k = 0;
	for (ii = 0; ii < itog.size(); ii++) {
		k = 0;
		if (ii != 0 && Delta[ii] % 2 == 0)
			cout << " + ";
		if (Delta[ii] % 2 != 0) {
			cout << " - ";
			promdet[ii] = -1;
		}
		for (int i = 0; i < nn; i++, k++)
		{
			if (i != 0)
				cout << "*";
			cout << a[i][itog[ii][k]];
			promdet[ii] *= a[i][itog[ii][k]];
		}

	}
	cout << " = ";
	ll globdet = 0;
	for (int i = 0; i < promdet.size(); i++)
	{
		if (promdet[i] < 0)
			cout << "(" << promdet[i] << ")";
		else
			cout << promdet[i];
		if (i != promdet.size() - 1)
			cout << " + ";
		globdet += promdet[i];
	}
	cout << " = " << globdet;
}