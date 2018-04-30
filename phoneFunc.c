#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData=0;
phoneData phoneList[LIST_NUM];

void InputPhoneData(void)
{
	phoneData data;

	if(numOfData>LIST_NUM)
	{
		puts("매모리공간이 부족합니다");
		return;	
	}
	
	fputs("이름 입력 : ",stdout);
	gets(data.name);
	
	fputs("전화번호 입력 : ",stdout);
	gets(data.phoneNum);
	
	phoneList[numOfData]=data;

	numOfData++;
	
	puts("입력이 완료되었습니다");
	getchar();
}
void ShowAllData(void)
{
	int i;
	for(i=0; i<numOfData; i++)
	{
		ShowPhoneInfo(phoneList[i]);
	}

	puts("출력이 완료되었습니다.");
	getchar();
}

