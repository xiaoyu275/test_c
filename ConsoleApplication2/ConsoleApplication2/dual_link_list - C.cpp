
#include <iostream>
#include "linux_list.h"
using namespace std;



void list_demo_1()
{
	struct Node
	{
		struct list_head head;
		int value;
	};
	struct Node l={0};
	struct list_head *list=(struct list_head*)&l;
	struct list_head* slider;
	INIT_LIST_HEAD(&l.head);
cout<<"insert start"<<endl;
	for(int i=0;i<5;i++)
	{
		struct Node *n = (struct Node*)malloc(sizeof(struct Node));
		n->value=i;
		list_add_tail((struct list_head *) n, list);//list_add
	}
	list_for_each(slider, list)
	{
		cout << "value:"<<((struct Node *)slider)->value<<endl;
	}
	cout<<"insert end"<<endl;

cout<<"delect start"<<endl;
	list_for_each(slider, list)
	{
		if(((struct Node *)slider)->value == 3)
			{
				list_del(slider);
				free(slider);
				break;
			}
	}
	list_for_each(slider, list)
	{
		cout << "value:"<<((struct Node *)slider)->value<<endl;
	}
	cout<<"delect end"<<endl;
	//del
}
void list_demo_2()
{
	struct Node
	{
		int value;
		struct list_head head;
	};

		struct Node l={0};
		struct list_head *list=(struct list_head*)&l.head;
		struct list_head* slider;
		INIT_LIST_HEAD(&l.head);
	cout<<"insert2 start"<<endl;
		for(int i=0;i<5;i++)
		{
			struct Node *n = (struct Node*)malloc(sizeof(struct Node));
			n->value=i;
			list_add_tail(&n->head, list);
		}
		list_for_each(slider, list)
		{
			cout << "value:"<<list_entry(slider,struct Node,head)->value<<endl;
		}
		cout<<"insert2 end"<<endl;

	cout<<"delect2 start"<<endl;
		list_for_each(slider, list)
		{
			struct Node* n = list_entry(slider, struct Node, head);
			if(n->value == 3)
				{
					list_del(slider);
					free(n);
					break;
				}
		}
		list_for_each(slider, list)
		{
			cout << "value:" << list_entry(slider, struct Node, head)->value << endl;
		}
		cout<<"delect2 end"<<endl;
		
		
}
int main(int argc, char* argv[])//int main()
{
	list_demo_2();
	std::cin.get();//»ògetchar()system("pause");
	return 0;
}
