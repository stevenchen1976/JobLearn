#include "QuickSelect.hpp"
using namespace std;


/* 排序算法----快速选择
 *
 * 算法思想:
 * 1. 二分法思想
 * 2. 递归思想
 *
 * 时间复杂度:
 * 最坏的时间复杂度:O(N^2)
 * 平均时间复杂度:O(N)
 *
 * 算法特点:
 * 1.属于快排变形算法,每次只对一半进行递归处理
 * 2.会对原数据进行破坏
 *
 * 思考:
 * 1.需要设置2个哨兵,左边的起始位置为哨兵i,右边的起始位置为哨兵j
 * 2.当基准数选在左边第一个数时,必然是哨兵j先向左移动
 * 3.求第k小的数,基准数所在的位置为i:k<=i:在左半部分进行递归处理;k>i+1,在右半部分进行处理
 *
 * */


int main() {
    TestQuickSelect();         //快速选择---求一组数据中心第k小的数
}
