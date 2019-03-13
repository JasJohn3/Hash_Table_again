#pragma once
#ifndef HASH_H
#define HASH_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 5;

/*
 * HashNode Class Declaration
 */
template <typename K, typename V>
class HashNode
{
public:
    V key;
	K value;
	HashNode<K, V>** next;
	HashNode<K,V>(K key, V value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

/*
 * Hash_Table Class Declaration
 */
template <typename K, typename V>
class Hash_Table
{
private:
	HashNode<K,V>** Table;
public:
	Hash_Table()
	{
		Table = new HashNode<K, V>**[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			Table[i] = NULL;
	}
	~Hash_Table()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			HashNode<K, V>** entry = Table[i];
			while (entry != NULL)
			{
				HashNode<K, V>** prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
		delete[] Table;
	}
	/*
	 * Hash Function
	 */
	int HashFunc(int key)
	{
		return key % TABLE_SIZE;
	}

	/*
	 * Insert Element at a key
	 */
	void Insert(K key, V value)
	{
		int Hash_Index = HashFunc(key);
		HashNode<K, V>** prev = NULL;
		HashNode<K, V>** entry = Table[Hash_Index];
		while (entry != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (entry == NULL)
		{
			entry = new HashNode<K, V>(key, value);
			if (prev == NULL)
			{
				Table[Hash_Index] = entry;
			}
			else
			{
				prev->next = entry;
			}
		}
		else
		{
			entry->value = value;
		}
	}
	/*
	 * Remove Element at a key
	 */
	void Remove(int key)
	{
		int hash_val = HashFunc(key);
		HashNode<K, V>** entry = Table[hash_val];
		HashNode<K, V>** prev = NULL;
		if (entry == NULL || entry->key != key)
		{
			std::cout << "No Element found at key " << key << endl;
			return;
		}
		while (entry->next != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (prev != NULL)
		{
			prev->next = entry->next;
		}
		delete entry;
		std::cout << "Element Deleted" << endl;
	}
	/*
	 * Search Element at a key
	 */
	int Search(K key)
	{
		bool flag = false;
		int hash_val = HashFunc(key);
		HashNode<K, V>** entry = Table[hash_val];
		while (entry != NULL)
		{
			if (entry->key == key)
			{
				cout << entry->value << " ";
				flag = true;
			}
			entry = entry->next;
		}
		if (!flag)
			return -1;
	}
};

#endif

