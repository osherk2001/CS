#define _CRT_SECURE_NO_WARNINGS
#define N 3

/*Libraries*/
#include <stdio.h>
#include <math.h>

/*
	Assigned by:
		Student1_Hodaya Triki  324059005
		Student2_Osher Kikirov 322566100
*/

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

/* Declarations of other sub-functions */

int sumDigits(int);
int checkID(int);
int sumLongestArithmeticList(int);
int numberLength(int);
int rotateNumber(int, int);

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : ", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

void Ex1() {
	int id = 0, answer = 0;
	printf("please enter your id: ");
	scanf("%d", &id);
	answer = checkID(id);
	if (answer) {
		printf("Your id is a correct id.\n");
	}
	else {
		printf("Your id is incorrent.\n");
	}

}

void Ex2() {
	int size = 0, answer = 0;
	printf("please enter the arithmetic list size: ");
	scanf("%d", &size);
	answer = sumLongestArithmeticList(size);
	printf("The sum of the longest sequence arithmetic list is: %d.\n", answer);
}

void Ex3() {
	int number = 0, spins = 0, answer = 0;
	printf("please enter the number and the amount of spins: ");
	scanf("%d%d", &number, &spins);
	answer = rotateNumber(number, spins);
	printf("The number %d after %d spins is: %d.\n", number, spins, answer);
}

/* Sub-Function definitions */

int sumDigits(int num) {
	/*Write Code Here!*/
	int sum = 0;
	while (num > 0) {
		sum = sum + (num % 10);
		num = num / 10;
	}
	return sum;
}



int checkID(int id) {
	/*Write Code Here!*/
	int num = 0;
	while (id > 0) {
		num = num + (id % 10);
		id = id / 10;
		if ((id % 10) * 2 >= 10) {
			num = num + sumDigits((id % 10) * 2);
			id = id / 10;
		}
		else {
			num = num + ((id % 10) * 2);
			id = id / 10;
		}
	}
	if (num % 10 == 0)
		return 1;
	else

		return 0;
}


int sumLongestArithmeticList(int n) {
	/*Write Code Here!*/
	int localmax = 0;
	int max = 0;
	int realsum = 0;
	int sum = 0;
	int oldnum = 0;
	int size = 0;
	int realsize = 0;
	int num = 0;
	int d = 0;
	printf("enter a number:\n");
	scanf_s("%d", &oldnum);
	if (n != 1) {
		printf("enter a number:\n");
		scanf_s("%d", &num);
	}
	if (n == 1) {
		return  oldnum;
	}
	else if (n == 2) {
		return num + oldnum;
	}
	else {
		d = oldnum - num;
		sum = oldnum + num;
		size = 2;
		oldnum = num;
		for (int i = 0; i < n - 2; i++) {
			printf("enter a number:\n");
			scanf_s("%d", &num);
			if ((oldnum - num) == d) {
				sum += num;
				size++;
				oldnum = num;
			}
			else {
				if (size > realsize) {
					realsize = size;
					size = 0;
					realsum = sum;
					sum = 0;
				}
				else if (size == realsize) {
					size = 0;
					if (realsum < sum) {
						realsum = sum;
					}
					else {
					}
					sum = 0;
				}
				else {
					sum = 0;
					size = 0;
				}
				d = oldnum - num;
				sum = oldnum + num;
				size = 2;
				oldnum = num;
			}

		}
		return realsum;
	}


	return max;
}


int numberLength(int num) {
	/*Write Code Here!*/

	int counter = 0;
	while (num > 0)
	{
		counter++;
		num /= 10;
	}
	return counter;
}
int rotateNumber(int num, int spins) {
	/*Write Code Here!*/

	int numberLen, b;
	numberLen = numberLength(num);
	b = pow(10, (numberLen - 1));

	if (spins % numberLen == 0)
		spins = numberLen;

	while (spins > 0)
	{

		num = (num % 10 * b) + (num / 10);
		num / 10;
		spins--;

	}
	return num;
}



