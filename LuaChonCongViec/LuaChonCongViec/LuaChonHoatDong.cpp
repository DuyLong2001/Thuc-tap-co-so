#include<stdio.h>
#include<fstream>
#include<iostream>
using namespace std;

void nhaphoatdong(int &n)
{
	printf("Nhap so luong hoat dong\n");
	scanf_s("%d",&n);
	while (n > 20) {
		printf("Nhap so luong hoat dong be hon 20\n");
		scanf_s("%d", &n);
	}
}
void nhapthoigian(int arr[3][21], int n, int &a, int &b)
{
	for (int i = 0; i < n;i++)
	{
		printf("\nHoat dong %d\n", i + 1);
		printf("Nhap thoi gian bat dau: ");
			scanf_s("%d", &a);
			while (a > 23)
			{
				printf("Thoi gian bat dau phai nho hon 24: ");
				scanf_s("%d", &a);
			}
			printf("Nhap thoi gian ket thuc: ");
			scanf_s("%d", &b);
			while (b > 24)
			{
				printf("Thoi gian ket thuc phai nho hon 25: ");
				scanf_s("%d", &b);
			}
			while (a >= b)
			{
				printf("Thoi gian ket thuc phai lon hon > thoi gian bat dau: ");
				scanf_s("%d", &b);
			}
			arr[0][i] = a;
			arr[1][i] = b;
	}
}

//ham void sap xep 1 dung de xuat ket qua ra file text
void sapxep1(int arr[3][21], int &n, ofstream &File)
{
	printf("(%d,%d)", arr[0][0], arr[1][0]);
	File<<"("<<arr[0][0]<<"," << arr[1][0]<<")"<<endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			if (arr[0][j] > arr[1][i] )
			{
				printf("(%d,%d)", arr[0][j], arr[1][j]);
				File << "(" << arr[0][j] << "," << arr[1][j] << ")"<<endl;
				i = j;
			}
		}
	}
}

//ham void sap xep 2 dung de lay du lieu tu file text
void sapxep2(int arr[3][21], int& n, ifstream& File)
{
	printf("(%d,%d)", arr[0][0], arr[1][0]);
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			if (arr[0][j] > arr[1][i])
			{
				printf("(%d,%d)", arr[0][j], arr[1][j]);
				i = j;
			}
		}
	}
}

//ham main dung de xuat ket qua ra File.text
int main()
{
	int n, a, b;
	int arr[3][21];
	int i, j;
	nhaphoatdong(n);
	nhapthoigian(arr, n, a, b);
	ofstream File("File.txt");
	File << "Ket qua hoat dong\n";
	sapxep1(arr,n,File);
	File.close();
}

//ham main dung de lay du lieu tu File1.text
//int main() {
//	ifstream File1;
//	File1.open("File1.txt");
//	int n, a, b;
//	int arr[3][21];
//	int i, j;
//	File1 >> n;
//	
//	for (i = 0; i < n; i++)
//	{
//		File1 >> a, File1 >> b;
//		cout << "hoat dong thu " << i + 1 << endl;
//		cout << "thoi gian bat dau " << a << endl;
//		cout << "thoi gian ket thuc " << b << endl;
//		arr[0][i] = a;
//		arr[1][i] = b;
//	}
//	sapxep2(arr, n, File1);
// File1.close();
// }
