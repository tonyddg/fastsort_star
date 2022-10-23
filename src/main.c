#include "stdio.h"
#include "sort.h"

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int sort_fast(int* beg, int* end)
{
    int gap = end - beg;

    if(gap <= 1)
    {
        
    }
    else if(gap == 2)
    {
        if(*(end - 1) < *beg)
        {
            swap((end - 1), beg);
        }
    }
    else
    {
        swap(beg + gap / 2, beg);

        // l ָ�����δ��֤
        int* l = beg + 1;
        // r ָ���������֤
        int* r = end;
        int k = *beg;

        while(r > l)
        {
            if(*l > k)
            {
                r--;
                swap(l, r);
            }
            else
            {
                l++;
            }
        }

        //���ض�С�� k, �Ҳ�ض����� k
        //��� k �����ٴ�����
        //���ҷ�ֹ �ظ����ֵ��µ�����ѭ�� bug
        
        // printf("************************\n");
        // printf("k=%d ; l=%d\n", k, l - beg);
        // print_array(beg, end, "�� %d ������ : %d\n");
        // printf("************************\n");
        
        swap(beg, l - 1);

        sort_fast(beg, l - 1);
        sort_fast(l, end);             
    }
    
    return gap;
}

void input_array(int* beg, int* end, const char* hint)
{
    int count = 0;
    for(beg; beg < end; beg++)
    {
        count++;
        if(hint)printf(hint, count);
        //�������
        if(!scanf("%d", beg))
        {
            beg--;
            count--;
            //��ջ�����
            scanf("%*[^\n]%*c");
        }
        printf("\n");
    }
}

void print_array(int* beg, int* end, const char* hint)
{
    int count = 0;
    for(beg; beg < end; beg++)
    {
        count++;
        if(hint)printf(hint, count, *beg);
    }
}

#define SORT_SIZE 10

int a[SORT_SIZE] = {0};

int main()
{
    input_array(a, a + SORT_SIZE, "����� %d ���� : ");
    sort_fast(a, a + SORT_SIZE);
    print_array(a, a + SORT_SIZE, "�� %d ������ : %d\n");
    printf("star NB\n");
    
    return 0;
}