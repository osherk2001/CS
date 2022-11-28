#include <stdio.h>
int sumDigit(int num);
int checkID(int id);
int sumLongestArithmeticList(int n);
int main() {
	int n, ID;
	printf("enter your number\n");
	scanf_s("%d", &n);
	printf("the sum is %d\n", sumDigit(n));
	scanf_s("%d", &ID);
	checkID(ID);
	scanf_s("%d", &n);
	sumLongestArithmeticList(n);
	return 1;
}
int sumDigit(int num) {
	int sum = 0;
	while (num > 0) {
		sum = sum + (num % 10);
		num = num / 10;
	}
	return sum;
}
int checkID(int id) {
	int num = 0;
	while (id > 0) {
		num = num + (id % 10);
		id = id / 10;
		if ((id % 10) * 2 >= 10) {
			num = num + sumDigit((id % 10) * 2);
			id = id / 10;
		}
		else {
			num = num + ((id % 10) * 2);
			id = id / 10;
		}
	}
	if (num % 10 == 0)
		printf("correct ID number\n");
	else
		printf("not correct id\n");
	return 0;
}
int sumLongestArithmeticList(int n) {
	int leng=0 , nleng = 1, i, num, num2, f,max,nmax=0;
	scanf_s("%d", &num);
	max = num;
	for (i = 2; i <= n; i++) {
		scanf_s("%d", &num2);
		
		if (i == 2) {
			f = num - num2;
		}
		if (num - num2 == f) {
			nleng++;
			max += num2;
			
		}
		else {
			f = num - num2;
			if (nleng > leng) {
				leng = nleng;
				nleng = 1;
				nmax = max;
				max = num2;
			}
		}
		num = num2;
	}
	printf("leng=%d  nleng=%d", max, nmax);
	return 0;
}

