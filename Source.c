//////////////////////////////////
//Name: Zero871015
//Date: 5/12/2018
//Todo: SimpleAncestorTree
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int father;		//и
	int myNumber;	//иID
	bool isFap;		//ì格
}People;

int main()
{
	int number;
	int bigFather;
	bool isImmediate = false;
	scanf("%d", &number);
	People *peoples;
	peoples = (People*)malloc(sizeof(People)*number);

	//﹍て攫
	for (int i = 0; i < number; i++)
	{
		peoples[i].father = -1;
		peoples[i].myNumber = i;
	}

	//ミ闽玒
	for (int i = 0; i < number-1; i++)
	{
		int tempFather,tempChild;
		scanf("%d %d", &tempFather, &tempChild);
		peoples[tempChild].father = tempFather;
	}

	//т程ρ
	for (int i = 0; i < number; i++)
	{
		if (peoples[i].father == -1)
		{
			bigFather = i;
			break;
		}
	}

	for (int i = 0; i < number; i++)
	{
		for (int j = i+1; j < number; j++)
		{
			People *p1 = &peoples[i];
			People *p2 = &peoples[j];
			int commonFather = -1;
			int count1 = 0;
			int count2 = 0;
			//砞ì格
			for (int k = 0; k < number; k++)
			{
				peoples[k].isFap = false;
			}
			while (1)
			{
				//т
				if (p1->myNumber == p2->myNumber)
				{
					commonFather = p1->myNumber;
					break;
				}
				//тì格
				else if (p1->isFap&&p1->myNumber!=bigFather)
				{
					commonFather = p1->myNumber;
					break;
				}
				//тì格
				else if (p2->isFap&&p2->myNumber != bigFather)
				{
					commonFather = p2->myNumber;
					break;
				}
				//ミì格
				p1->isFap = true;
				p2->isFap = true;
				//碻菌
				if (p1->myNumber != bigFather)
					p1 = &peoples[p1->father];
				if (p2->myNumber != bigFather)
					p2 = &peoples[p2->father];
			}
			//т程穝璸衡禯瞒
			p1 = &peoples[i];
			p2 = &peoples[j];
			while (p1->myNumber!=commonFather)
			{
				count1++;
				p1 = &peoples[p1->father];
			}
			while (p2->myNumber != commonFather)
			{
				count2++;
				p2 = &peoples[p2->father];
			}
			printf("%d-%d-%d\n", i, j, count1 + count2);
		}
	}

	system("pause");
	return 0;
}