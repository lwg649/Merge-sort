//�鲢��Ҫ����Ĵ洢�ռ���д���
//1:��ǰһ������(���õݹ��˼����ʵ��)
//2:����һ������
//������鲢��һ���µ��������飬Ȼ���ڿ�����ԭ���飬������ɡ�

#include<iostream>
using namespace std;

int a[10] = { 13,27,19,2,8,12,2,8,30,89 };
int b[10];

void Mergesort(int a[], int s, int e, int tmp[]);
int main() {
	int size = sizeof(a) / sizeof(int);
	Mergesort(a, 0, size - 1, b);// �����׵�ַ��   �������ʼ��ַ����ֹ��ַ�� ���ڴ���
	for (int i = 0; i < size; i++) {
		cout << a[i] << "��";
		cout << endl;
		return 0;
	}
}
void Mergesort(int a[], int s, int e, int tmp[]) {
	if (s < e) {
		int m = s + (e - s) / 2;
		Mergesort(a, s, m, tmp);
		Mergesort(a, m + 1, e, tmp);
		Merge(a, s, m, e, tmp);
	}
}
void Merge(int a[], int s, int m, int e, int tmp[]) {
	//������a�ľֲ�a[s,m]��a[m+1,e]�ϲ���tep,����֤tep����Ȼ���ٿ�����a[s,m]
	//�鲢����ʱ�临�Ӷȣ�0��e-m+1),��0(n)
	int pb = 0;
	int p1 = s, p2 = m + 1;//����������ָ��ǰһ���ָ�����һ���ָ��
	while (p1<=m&&p2<=e)//ѭ��������Ҫ�鲢�������Ƿ��ߵ�ͷ
	{
		if (a[p1] < a[p2]){	tmp[pb++] = a[p1++];}//��ӣ����֮�����������
		else{ tmp[pb++] = a[p2++];}
	}
	while (p1 <= m)
		tmp[pb++] = a[p1++];
	while (p2 <= e)
		tmp[pb++] = a[p2++];
	for (int i = 0; i < e-s+1; i++)
	{
		a[s + i] = tmp[i];
	}
}

