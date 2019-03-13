#include "Hash.h"

int main()
{
	Hash_Table<int,int> hash;
	int key, value;
	int choice;
	while (1)
	{
		std::cout << "\n----------------------" << endl;
		std::cout << "Operations on Hash Table" << endl;
		std::cout << "\n----------------------" << endl;
		std::cout << "1.Insert element into the table" << endl;
		std::cout << "2.Search element from the key" << endl;
		std::cout << "3.Delete element at a key" << endl;
		std::cout << "4.Exit" << endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter element to be inserted: ";
			std::cin >> value;
			std::cout << "Enter key at which element to be inserted: ";
			std::cin >> key;
			hash.Insert(key, value);
			break;
		case 2:
			std::cout << "Enter key of the element to be searched: ";
			std::cin >> key;
			std::cout << "Element at key " << key << " : ";
			if (hash.Search(key) == -1)
			{
				std::cout << "No element found at key " << key << endl;
				continue;
			}
			break;
		case 3:
			std::cout << "Enter key of the element to be deleted: ";
			std::cin >> key;
			hash.Remove(key);
			break;
		case 4:
			exit(1);
		default:
			std::cout << "\nEnter correct option\n";
		}
	}
	return 0;
}