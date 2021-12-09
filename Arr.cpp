# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include "Arr.h"

void initArr(pArr pArr, int maxsize) {
    pArr->pBase = (int *) malloc(sizeof(int) * maxsize);
    if (pArr->pBase == NULL) {
        printf("����ʧ�ܣ�");
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

//׷��
bool appendArr(pArr pArr, int val) {
    if (isFull(pArr)) {
        return false;
    }
    pArr->pBase[pArr->length] = val;
    pArr->length++;
    return true;
}

//����
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
        return false;  //i+1�����Ǹ��Ƿ�ֵ����pos<1 || pos>pArr->length)

}

void destroyArr(pArr pArr) {   //��free�ṹ��ָ���Ա��ָ��Ķ���
    //��free�ṹ��ָ�뱾��
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
    int val;  //����val,���ڽ�������
    int pos;  //����val,���ڽ�������

    initArr(pArr, 5);  //������󳤶�Ϊ5������

    //׷���ĸ�����
    appendArr(pArr, 1);
    appendArr(pArr, 2);
    appendArr(pArr, 3);
    appendArr(pArr, 4);
    //������ǰ���飬������鳤��
    traverseArr(pArr);  //�����1 2 3 4
    printf("��ǰ���鳤��Ϊ��%d\n", pArr->length);  //���Ϊ4

    //����λɾ������6������Υ��������3����
    if (deleteArrByPos(pArr, 6, &val))
        printf("�ɹ�ɾ����6�����ݣ�������Ϊ��%d\n", val);
    else
        printf("ɾ��ʧ�ܣ�\n");

    if (deleteArrByPos(pArr, 3, &val))
        printf("�ɹ�ɾ����3�����ݣ�������Ϊ��%d\n", val);
    else
        printf("ɾ��ʧ�ܣ�\n");

    //����ֵɾ��������Ϊ8������Υ����������Ϊ2����
    if (deleteArrByData(pArr, 8, &pos))
        printf("����Ϊ8�����ɹ�ɾ����������λ��Ϊ��%d\n", pos);
    else
        printf("ɾ��ʧ�ܣ�\n");

    if (deleteArrByData(pArr, 2, &pos))
        printf("����Ϊ2�����ɹ�ɾ����������λ��Ϊ��%d\n", pos);
    else
        printf("ɾ��ʧ�ܣ�\n");

    //������ǰ����
    traverseArr(pArr);  //�����1 4
    printf("��ǰ���鳤��Ϊ��%d\n", pArr->length);  //���Ϊ2

    //ָ��λ�ò���Ԫ��
    if (insertArr(pArr, 1, 66)) {
        printf("�ɹ��ڵ�һ��λ�ò���66�����������Ϊ��\n");
        traverseArr(pArr);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    if (insertArr(pArr, 6, 666)) {
        printf("�ɹ��ڵ�һ��λ�ò���66�����������Ϊ��\n");
        traverseArr(pArr);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    if (insertArr(pArr, 2, 88)) {
        printf("�ɹ��ڵ�һ��λ�ò���66�����������Ϊ��\n");
        traverseArr(pArr);
    } else {
        printf("����ʧ�ܣ�\n");
    }

    //��������
    printf("����ǰ�����飺\n");
    traverseArr(pArr);
    printf("���ú�����飺\n");
    inversionArr(pArr);
    traverseArr(pArr);

    //����
    //��λ����
    if (researchByPos(pArr, 2, &val))
        printf("�ڶ���λ�õ�Ԫ�ز��ҳɹ�����Ԫ��Ϊ��%d\n", val);
    else
        printf("����ʧ�ܣ�");

    //��ֵ����
    if (researchByData(pArr, 88, &pos)) {
        printf("����Ϊ88��Ԫ�ز��ҳɹ�����Ԫ��λ��Ϊ%d\n", pos);

    } else
        printf("����ʧ�ܣ�");


    //��������
    sortArr(pArr);
    printf("����������Ϊ��");
    traverseArr(pArr);

    //��������
    destroyArr(pArr);
    if (isEmpty(pArr)) {
        printf("�����ѱ�����");
    } else {
        printf("����δ�����٣��������£�");
        printf("%d\n",pArr->length);
        traverseArr(pArr);
    }

    return 0;
}