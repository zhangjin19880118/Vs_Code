#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

template<class Arg1,class Arg2,class Arg3,class Result>
struct third_function
{	// base class for binary functions
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Arg3 third_argument_type;
	typedef Result result_type;
};

template<class Functor>
class Target
{
	typedef typename Functor::first_argument_type first_arg_type;
	typedef typename Functor::second_argument_type second_arg_type;
	typedef typename Functor::third_argument_type third_arg_type;
	typedef typename Functor::result_type ret_type;
public:
	Target(Functor functor, second_arg_type param1, third_arg_type param2) : mFunctor(functor),
		mParam1(param1), mParam2(param2){}
	ret_type operator()(first_arg_type v)
	{
		return mFunctor(v, mParam1, mParam2);
	}
private:
	Functor mFunctor;
	second_arg_type mParam1;
	third_arg_type mParam2;
};

template<class FunctorType, class Param1Type, class Param2Type>
Target<FunctorType> bind3rd(FunctorType functor, Param1Type param1, Param2Type param2)
{
	return Target<FunctorType>(functor, param1, param2);
}

struct Print : third_function<int, int, int, void>
{
	void operator()(int v, int param1, int param2)
	{
		cout << v << " " << param1 << " " << param2 << " " << endl;
	}
};

int main(void)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	for_each(v.begin(), v.end(), bind3rd(Print(), 100, 200));

	system("pause");
	return 0;
}
