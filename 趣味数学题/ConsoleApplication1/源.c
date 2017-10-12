#if 0
//公鸡5元1只，母鸡3元1只，小鸡1元3只，求100块钱买100只鸡有多少种方法？
//i+j+k=100;
//5i+3j+k/3=100;
//15i+9j+k=300
//14i + 8j = 200;
//7i+4j=100
//j=25-7i/4-->i=4n,j=25-7n,n=0,1,2,3
#endif

#if 0
// 现在有五家共用一口井，
// 甲、乙、丙、丁、戌五家各有一条绳子汲水
// （下面用文字表示每一家的绳子）：
// 甲×2 + 乙 = 井深，
// 乙×3 + 丙 = 井深，
// 丙×4 + 丁 = 井深，
// 丁×5 + 戊 = 井深，
// 戊×6 + 甲 = 井深，
// 求甲、乙、丙、丁、戊各家绳子的长度和井深。
//y=js-2j=js-2(js-6w)=12w-js=12(js-5d)-js=11js-60d=11js-60(js-4b)=240b-49js=240(js-3y)-49js=191js-720y
//721y=191js
//y=191js/721-->js=721n-->y=191n
#endif

void func5()
{
	for (int n = 1; n < 4; ++n)
	{
		int js = 721*n;
		int y = 191*n;
		int j = (js - y) / 2;
		int b = js - 3 * y;
		int d = js - 4 * b;
		int w = js - 5 * d;
		printf("j=%d,y=%d,b=%d,d=%d,w=%d,js=%d\n", j, y, b, d, w, js);
	}
}

void func4()
{
	for (int js = 1;; js++)
	{
		for (int j = 1; j < js; j++)
		{
			int y = js - 2 * j;
			int b = js - 3 * y;
			int d = js - 4 * b;
			int w = js - 5 * d;
			if (y>0 && b > 0 && d > 0 && w > 0 && js == 6 * w + j)
			{
				printf("j=%d,y=%d,b=%d,d=%d,w=%d,js=%d\n", j, y, b, d, w, js);
				return;
			}
		}
	}
}

void func1()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 34; ++j)
		{
			for (int k = 0; k < 100; k+=3)
			{
				if (100 == i + j + k && 100 == 5 * i + 3 * j + k / 3)
					printf("i=%d,j=%d,k=%d\n", i, j, k);
			}
		}
	}
}

void func2()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 34; ++j)
		{
			int k = 100 - i - j;
			if (100 == 5 * i + 3 * j + k / 3&&0==k%3)
				printf("i=%d,j=%d,k=%d\n", i, j, k);
		}
	}
}

void func3()
{
	for (int n = 0; n < 4; ++n)
	{
		int i = 4*n;
		int j = 25 - 7*n;
		int k = 75 +3*n;
		printf("i=%d,j=%d,k=%d\n", i, j, k);
	}
}

int main()
{
	//func1()
	//func2();
	//func3();
	//func4();
	func5();
	return 0;
}
