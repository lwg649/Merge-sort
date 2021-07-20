//归并需要额外的存储空间进行储存
//1:将前一半排序(运用递归的思想来实现)
//2:将后一半排序
//把两半归并到一个新的有序数组，然后在拷贝回原数组，排序完成。

#include<iostream>
using namespace std;

int a[10] = { 13,27,19,2,8,12,2,8,30,89 };
int b[10];

void Mergesort(int a[], int s, int e, int tmp[]);
int main() {
	int size = sizeof(a) / sizeof(int);
	Mergesort(a, 0, size - 1, b);// 数组首地址，   排序的起始地址与终止地址， 用于储存
	for (int i = 0; i < size; i++) {
		cout << a[i] << "，";
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
	//将数组a的局部a[s,m]和a[m+1,e]合并到tep,并保证tep有序；然后再拷贝会a[s,m]
	//归并操作时间复杂度：0（e-m+1),即0(n)
	int pb = 0;
	int p1 = s, p2 = m + 1;//设置数组中指向前一半的指针与后一半的指针
	while (p1<=m&&p2<=e)//循环条件，要归并的数组是否走到头
	{
		if (a[p1] < a[p2]){	tmp[pb++] = a[p1++];}//后加，存放之后再向后面移
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

