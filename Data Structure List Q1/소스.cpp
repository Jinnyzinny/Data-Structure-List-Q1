#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* Link = nullptr;
public:
	Node(int input = 0)
		:data(input)
	{

	}
	Node* getlink()
	{
		return this->Link;
	}
	void setlink(Node* next)
	{
		this->Link = next;
	}
	int getData()
	{
		return this->data;
	}
	void setData(int input)
	{
		data = input;
	}
};

class Linkedlist {
private:
	Node head;
	int cnt;
	Node* getHead()
	{
		return head.getlink();
	}
	Node* getNode(int pos)
	{
		Node* p = &head;
		for (int i = -1; i < pos; i++)
		{
			if (p == nullptr)break;
			p = p->getlink();
		}
		return p;
	}
public:
	Linkedlist() {
		this->cnt = 0;
	}
	bool empty()
	{
		return this->getHead() == nullptr;
	}
	int size()
	{
		return this->cnt;
	}
	void insert(int pos, int data)
	{
		Node* prev = this->getNode(pos - 1);
		if (prev != nullptr)
		{
			Node* p = new Node(data);
			p->setlink(prev->getlink());
			prev->setlink(p);
			this->cnt++;
		}
	}
	void display()
	{
		for (Node* p = getHead(); p != nullptr; p = p->getlink())
		{
			cout << p->getData() << " ";
		}
		cout << endl;
	}
	void sorted_insert(int input)
	{
		if (this->empty() == true)
		{
			insert(0, input);
		}
		else {
			int size = this->size();
			if (getNode(size - 1)->getData() >= input)
			{
				insert(size, input);
			}
			else {
				for (int i = 0; i < size; i++)
				{
					if (getNode(i)->getData() < input)
					{
						insert(i, input);
						break;
					}
				}
			}
		}
	}
};

int main()
{
	int n;
	cin >> n;
	int input;

	Linkedlist list;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		list.sorted_insert(input);
		list.display();
	}


	return 0;
}