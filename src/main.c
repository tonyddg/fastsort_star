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

        // l 指向的数未验证
        int* l = beg + 1;
        // r 指向的数已验证
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

        //左侧必定小于 k, 右侧必定大于 k
        //因此 k 不必再次排序
        //并且防止 重复数字导致的无限循环 bug
        
        // printf("************************\n");
        // printf("k=%d ; l=%d\n", k, l - beg);
        // print_array(beg, end, "第 %d 个数是 : %d\n");
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
        //输入错误
        if(!scanf("%d", beg))
        {
            beg--;
            count--;
            //清空缓冲区
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
    input_array(a, a + SORT_SIZE, "输入第 %d 个数 : ");
    sort_fast(a, a + SORT_SIZE);
    print_array(a, a + SORT_SIZE, "第 %d 个数是 : %d\n");
    printf("star NB\n");
    
    return 0;
}