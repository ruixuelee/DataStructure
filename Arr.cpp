# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include "Arr.h"

void initArr(pArr pArr, int maxsize) {
    pArr->pBase = (int *) malloc(sizeof(int) * maxsize);
    if (pArr->pBase == NULL) {
        printf("分配失败！");
        exit(-1);
    } else {
        pArr->length = 0;
        pArr->maxsize = maxsize;
    }
}

bool isEmpty(pArr pArr) {
    if (pArr->length == 0)
        return true;
    else
        return false;
}

bool isFull(pArr pArr) {
    if (pArr->length == pArr->maxsize) {
        return true;
    } else
        return false;
}

//追加
bool appendArr(pArr pArr, int val) {
    if (isFull(pArr)) {
        return false;
    }
    pArr->pBase[pArr->length] = val;
    pArr->length++;
    return true;
}

//遍历
void traverseArr(pArr pArr) {
    if (isEmpty(pArr)) {
        return;
    }
    for (int i = 0; i < pArr->length; i++) {
        printf("%d ", pArr->pBase[i]);
    }
    printf("\n");
    return;
}

bool deleteArrByPos(pArr pArr, int pos, int *val) {
    if (isEmpty(pArr))
        return false;

    if (pos < 1 || pos >= pArr->length)
        return false;

    *val = pArr->pBase[pos - 1];
    for (int i = pos; i < pArr->length; i++) {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    pArr->length--;
    return true;
}

bool deleteArrByData(pArr pArr, int val, int *pos) {
    int i = 0;
    if (isEmpty(pArr))
        return false;
    for (i = 0; i < pArr->length; i++) {
        if (pArr->pBase[i] == val) {
            *pos = i + 1;
            break;
        }
    }
    if (deleteArrByPos(pArr, i + 1, &val)) {
        return true;
    } else
        return false;  //i+1可能是个非法值（即pos<1 || pos>pArr->length)

}

void destroyArr(pArr pArr) {   //先free结构体指针成员所指向的对象
    //再free结构体指针本身
    if (pArr == NULL)
        return;

    if (pArr->pBase != NULL) {
        free(pArr->pBase);
        pArr->pBase = NULL;
    }
    free(pArr);
    pArr->length = 0;
    pArr = NULL;
    return;
}

bool insertArr(pArr pArr, int pos, int val) {
    if (isFull(pArr))
        return false;
    for (int i = pArr->length; i >= pos; i--) {
        pArr->pBase[i] = pArr->pBase[i - 1];
    }
    pArr->pBase[pos - 1] = val;
    pArr->length++;
    return true;
}

void inversionArr(pArr pArr) {
    if (isEmpty(pArr))
        return;

    int temp;
    for (int i = 0, j = pArr->length - 1; i < (pArr->length) / 2; i++, j--) {
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = temp;
    }
    return;
}

bool researchByPos(pArr pArr, int pos, int *val) {
    if (isEmpty(pArr))
        return false;
    if (pos < 1 || pos > pArr->length)
        return false;

    *val = pArr->pBase[pos - 1];
    return true;
}

bool researchByData(pArr pArr, int val, int *pos) {
    if (isEmpty(pArr))
        return false;
    for (int i = 0; i < pArr->length; i++) {
        if (pArr->pBase[i] == val) {
            *pos = i + 1;
            break;
        }
    }
    return true;
}

void sortArr(pArr pArr) {
    if (isEmpty(pArr))
        return;

    int temp;
    for (int i = 0; i < pArr->length - 1; i++) {
        for (int j = 0; j < pArr->length - i - 1; j++) {
            if (pArr->pBase[j] > pArr->pBase[j + 1]) {
                temp = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[j + 1];
                pArr->pBase[j + 1] = temp;
            }
        }
    }
    return;
}

int main() {
    Arr arr;
    pArr pArr = &arr;
    int val;  //声明val,用于接受数据
    int pos;  //声明val,用于接受数据

    initArr(pArr, 5);  //创建最大长度为5的数组

    //追加四个数据
    appendArr(pArr, 1);
    appendArr(pArr, 2);
    appendArr(pArr, 3);
    appendArr(pArr, 4);
    //遍历当前数组，输出数组长度
    traverseArr(pArr);  //输出：1 2 3 4
    printf("当前数组长度为：%d\n", pArr->length);  //结果为4

    //【按位删除】第6个数（违法）、第3个数
    if (deleteArrByPos(pArr, 6, &val))
        printf("成功删除第6个数据！该数据为：%d\n", val);
    else
        printf("删除失败！\n");

    if (deleteArrByPos(pArr, 3, &val))
        printf("成功删除第3个数据！该数据为：%d\n", val);
    else
        printf("删除失败！\n");

    //【按值删除】数据为8的数（违法）、数据为2的数
    if (deleteArrByData(pArr, 8, &pos))
        printf("数据为8的数成功删除！该数据位置为：%d\n", pos);
    else
        printf("删除失败！\n");

    if (deleteArrByData(pArr, 2, &pos))
        printf("数据为2的数成功删除！该数据位置为：%d\n", pos);
    else
        printf("删除失败！\n");

    //遍历当前数组
    traverseArr(pArr);  //输出：1 4
    printf("当前数组长度为：%d\n", pArr->length);  //结果为2

    //指定位置插入元素
    if (insertArr(pArr, 1, 66)) {
        printf("成功在第一个位置插入66！插入后数组为：\n");
        traverseArr(pArr);
    } else {
        printf("插入失败！\n");
    }

    if (insertArr(pArr, 6, 666)) {
        printf("成功在第一个位置插入66！插入后数组为：\n");
        traverseArr(pArr);
    } else {
        printf("插入失败！\n");
    }

    if (insertArr(pArr, 2, 88)) {
        printf("成功在第一个位置插入66！插入后数组为：\n");
        traverseArr(pArr);
    } else {
        printf("插入失败！\n");
    }

    //逆置数组
    printf("逆置前的数组：\n");
    traverseArr(pArr);
    printf("逆置后的数组：\n");
    inversionArr(pArr);
    traverseArr(pArr);

    //查找
    //按位查找
    if (researchByPos(pArr, 2, &val))
        printf("第二个位置的元素查找成功！该元素为：%d\n", val);
    else
        printf("查找失败！");

    //按值查找
    if (researchByData(pArr, 88, &pos)) {
        printf("数据为88的元素查找成功！该元素位置为%d\n", pos);

    } else
        printf("查找失败！");


    //数组排序
    sortArr(pArr);
    printf("排序后的数组为：");
    traverseArr(pArr);

    //销毁数组
    destroyArr(pArr);
    if (isEmpty(pArr)) {
        printf("数组已被销毁");
    } else {
        printf("数组未被销毁，数组如下：");
        printf("%d\n",pArr->length);
        traverseArr(pArr);
    }

    return 0;
}