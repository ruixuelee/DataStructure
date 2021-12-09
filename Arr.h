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

bool deleteArrByPos(pArr,int pos,int* val);  //按位删除，删除的元素存于val中
bool deleteArrByData(pArr, int val, int* pos); //按值删除，删除的元素位置存于pos中
bool insertArr(pArr,int pos,int val); //插入的元素为val
bool researchByPos(pArr, int pos, int* data); //按位查找
bool researchByData(pArr, int data,int* pos); //按值查找
bool isEmpty(pArr);  //判空操作
bool isFull(pArr);   //判满
void sortArr(pArr);  //排序
void inversionArr(pArr);//逆置数组

#endif