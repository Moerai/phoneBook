#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData=0;
phoneData *phoneList[LIST_NUM];

void InputPhoneData(void)
{
	phoneData *pData;

	if(numOfData>=LIST_NUM)
	{
		puts("매모리공간이 부족합니다");
		return;	
	}
	
	fputs("이름 입력 : ",stdout);
	gets(pData->name);
	
	fputs("전화번호 입력 : ",stdout);
	gets(pData->phoneNum);
	
	phoneList[numOfData]=pData;

	numOfData++;
	
	puts("입력이 완료되었습니다");
	getchar();
}
void ShowAllData(void)
{
	int i;
	for(i=0; i<numOfData; i++)
	{
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	puts("출력이 완료되었습니다.");
	getchar();
}
void SearchPhoneData(void)
{
	int i;
	char searchName[NAME_LEN];

	fputs("찾는 이름은? ", stdout);
	gets(searchName);

	for(i=0;i<numOfData; i++)
	{
		if(!strcmp(phoneList[i]->name, searchName))
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			puts("검색이 완료되었습니다.");
			getchar();
			return;
		}
	}

	puts("찾는 이름의 데이터가 존재하지 않습니다.");
	getchar();
}

void DeletePhoneData(void)
{
	int i,j;
	char delName[NAME_LEN];

	fputs("찾는 이름은? ", stdout);
	gets(delName);

	for(i=0; i<numOfData; i++)
	{
		if(!strcmp(phoneList[i]->name, delName))
		{
			free(phoneList[i]);

			for(j=i;j<numOfData-1; j++)
			{
				phoneList[j]=phoneList[j+1];
		}
			numOfData--;
			puts("삭제가 완료되었습니다.");
			getchar();
			return;
		}
	}

	puts("찾는 이름의 데이터가 존재하지 않습니다.");
	getchar();
}
