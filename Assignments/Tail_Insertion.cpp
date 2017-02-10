/**
* @ProgramName:
* @Author: Stephen Puthenpurackal
* @Description:
*     This program uses EndCert, FrontSert, PrintSert methods to traverse a
* linked list and add nodes within the front and back of lists.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 2-09-2017
*/



#include <iostream>

struct Node {
	int Data;
	Node *Next;
};

using namespace std;

class List
{
private:
	Node *Head;
	Node *Tail;
public:
	List()

	{
		Head = NULL;
		Tail = NULL;
	}

	void FrontSert(int x)
	{
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (!Head)
		{
			Tail = Temp;
		}

		else
		{
			Temp->Next = Head;
		}

		Head = Temp;

	}



	/**
	* @FunctionName: EndSert
	* @Description:
	*     Allocates new node between tail and null switching pointers around.
	* @Params:
	*    Int
	* @Returns:
	*    void
	*/


	void EndSert(int x)
	{
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;


		if (!Head) {

			Head = Temp;
			Tail = Head;
		}

		else
		{
			Tail->Next = Temp;
			Tail = Temp;


		}

	}


	void PrintList()
	{
		if (!Head)
		{
			cout << "Empty" << endl;
			return;
		}
		else
		{
			Node *Temp = Head;
			while (Temp != NULL)
			{
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
		}
	}

};
int main() {

	List L;


	L.FrontSert(3);
	L.FrontSert(4);
	L.FrontSert(7);
	L.EndSert(4);
	L.EndSert(5);
	L.EndSert(4);
	L.PrintList();

	system("pause");
	return 0;
}
