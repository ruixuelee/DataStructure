#ifndef __ARR_H__
#define __ARR_H__

typedef struct arr
{
	int* pBase;
	int length;
	int maxsize;
}Arr,*pArr;

void initArr(pArr, int maxsize);
void destroyArr(pArr);
bool appendArr(pArr,int val);
void traverseArr(pArr);

bool deleteArrByPos(pArr,int pos,int* val);  //��λɾ����ɾ����Ԫ�ش���val��
bool deleteArrByData(pArr, int val, int* pos); //��ֵɾ����ɾ����Ԫ��λ�ô���pos��
bool insertArr(pArr,int pos,int val); //�����Ԫ��Ϊval
bool researchByPos(pArr, int pos, int* data); //��λ����
bool researchByData(pArr, int data,int* pos); //��ֵ����
bool isEmpty(pArr);  //�пղ���
bool isFull(pArr);   //����
void sortArr(pArr);  //����
void inversionArr(pArr);//��������

#endif