#include <iostream>
#include <algorithm>
#include <vector>

struct Object
{
	int weight;
	bool mark;
};

bool cmp(Object& a, Object& b)
{
	return a.weight < b.weight;
}

int main()
{
	int number_of_items;
	do
	{
		std::cout << "Enter the number of items: ";
		std::cin >> number_of_items;
	} while (number_of_items <= 0);

	std::vector<Object> data(number_of_items);

	for (int i = 0; i < number_of_items; ++i)
	{
		do
		{
			std::cout << "Enter a[" << i << "]: ";
			std::cin >> data[i].weight;
		} while (data[i].weight <= 0);
		data[i].mark = false;
	}

	std::sort(data.begin(), data.end(), cmp);

	int number_of_packages, max_package_weight;
	do
	{
		std::cout << "Enter the number of packages: ";
		std::cin >> number_of_packages;
	} while (number_of_items <= 0);
	do
	{
		std::cout << "Enter the maximum package weight: ";
		std::cin >> max_package_weight;
	} while (max_package_weight <= 0);

	int count(0);

	int right_counter(data.size() - 1);

	bool sorted(true);

	if (data[right_counter].weight > max_package_weight)
		sorted = false;

	if (sorted)
	{
		int weight_of_items(0);
		for (int i = 0; i < number_of_items; ++i)
			weight_of_items += data[i].weight;

		if (weight_of_items > number_of_packages * max_package_weight)
			sorted = false;
	}

	if (sorted)
	{
		bool package_full;
		for (;;)
		{
			package_full = false;

			static int sum = 0;
			static bool all_item_utillizied;

			while (!package_full)
			{
				sum = 0;
				all_item_utillizied = false;
				right_counter = data.size() - 1;

				while (right_counter >= 0)
				{
					if (!data[right_counter].mark && sum + data[right_counter].weight <= max_package_weight)
					{
						sum += data[right_counter].weight;
						data[right_counter].mark = true;
					}
					--right_counter;
				}

				if (sum == 0)
				{
					package_full = true;
					all_item_utillizied = true;
				}
				else
				{
					package_full = true;
					count++;
				}
			}

			if (all_item_utillizied)
				break;
			if (count > number_of_packages)
			{
				sorted = false;
				break;
			}
		}

		if (sorted)
			std::cout << "Minimum number of packages: " << count << '\n';
	}
	else
		std::cout << "There is no way to sort packages.\n";
	return 0;
}