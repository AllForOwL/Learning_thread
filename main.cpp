#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <time.h>

std::mutex g_lock;

std::vector<int> vec;
int				 numberElement = 0;

void Multiplication()
{
	//g_lock.lock();

	for (numberElement; numberElement < vec.size(); numberElement++)
	{
		vec[numberElement] *= rand() % 10 + 2;
		//std::this_thread::sleep_for(std::chrono::seconds(rand() % 5));
		std::cout << numberElement << "  " << vec[numberElement] << " id: " << std::this_thread::get_id() << " " << vec.size() << std::endl;
	}

	//g_lock.unlock();
}

int main()
{
	setlocale(LC_ALL, "russian");

	srand((unsigned int)time(0));
	
	int _countTask;
	std::cout << "������ ����� ��������:";
	std::cin >> _countTask;

	switch (_countTask)
	{
		case 1:
		{
				  int _countElement;
				  std::cout << "������ ������� ��������: ";
				  std::cin >> _countElement;

				  int _temp = 0;
				  for (int i = 0; i < _countElement; i++)
				  {
					  _temp = rand() % 100 + 2;
					  vec.push_back(_temp);
				  }

			break;
		}
		case 2:
		{
				  break;
		}
		case 3:
		{
				  break;
		}
	default:
		break;
	}

	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer, mktime(&y2k));


	std::thread t1(Multiplication);
	std::thread t2(Multiplication);
	std::thread t3(Multiplication);
	std::thread t4(Multiplication);
	std::thread t5(Multiplication);
	std::thread t6(Multiplication);
	std::thread t7(Multiplication);
	std::thread t8(Multiplication);
	std::thread t9(Multiplication);
	std::thread t10(Multiplication);
	std::thread t11(Multiplication);
	std::thread t12(Multiplication);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();


	double seconds2;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds2 = difftime(timer, mktime(&y2k));

	std::cout << seconds << " " << seconds2 << " : "<< seconds2 - seconds << std::endl;

	system("pause");
	return 0;
}

/*
	1. ��������� ��������� ������� �������� �������, ���������, �������� �������� ������� �� �����. ����� �������� ������� �������� ���������� N.
	2. ��������� �������������� ������� �������� �������, �������������� ���� ������� �� ���� ����� ��������. ����� ������ �������� ���������� M. (�������: ����� ����������� ��������� �������� �������� 0..(N-1) �� �����, ������� �� ������� ������ �. ��� ������� �������� ������ �� �������� ���������� ��� ������� ������, ���� ������� ������� ������, ���� ������������ � ������ ������, ��� ���������� � ������� ������� �������� �������).
	3. ��������� ����� ����������� �������������� ������� ��� ����� ���������� N (10, 100, 1000, 100 000) � M (2, 3, 4, 5, 10). ���������� ������� � �������� ����. (�������: � ����� ����������� ������ ������ ����� ������� ��� ��������� ������� ������).

*/