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
	int father;		//�ڪ�
	int myNumber;	//�ڪ�ID
	bool isFap;		//����
}People;

int main()
{
	int number;
	int bigFather;
	bool isImmediate = false;
	scanf("%d", &number);
	People *peoples;
	peoples = (People*)malloc(sizeof(People)*number);

	//��l�ƾ�
	for (int i = 0; i < number; i++)
	{
		peoples[i].father = -1;
		peoples[i].myNumber = i;
	}

	//�إ߯������Y
	for (int i = 0; i < number-1; i++)
	{
		int tempFather,tempChild;
		scanf("%d %d", &tempFather, &tempChild);
		peoples[tempChild].father = tempFather;
	}

	//���̦ѯ���
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
			//���]����
			for (int k = 0; k < number; k++)
			{
				peoples[k].isFap = false;
			}
			while (1)
			{
				//���ۦP����
				if (p1->myNumber == p2->myNumber)
				{
					commonFather = p1->myNumber;
					break;
				}
				//��쨬��
				else if (p1->isFap&&p1->myNumber!=bigFather)
				{
					commonFather = p1->myNumber;
					break;
				}
				//��쨬��
				else if (p2->isFap&&p2->myNumber != bigFather)
				{
					commonFather = p2->myNumber;
					break;
				}
				//�إߨ���
				p1->isFap = true;
				p2->isFap = true;
				//�`������
				if (p1->myNumber != bigFather)
					p1 = &peoples[p1->father];
				if (p2->myNumber != bigFather)
					p2 = &peoples[p2->father];
			}
			//���̪񯪥���A���s�p��Z��
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