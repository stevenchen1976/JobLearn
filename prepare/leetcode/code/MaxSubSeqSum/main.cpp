#include "MaxSubSeqSum.hpp"
using namespace std;


/* 最大子序列和
 *
 * 相关概念
 * 联机算法:
 * 如果数据在磁盘上或通过互联网传送,那么它就可以被顺序读入,在主存中不必存储数组的任何部分.不仅如此,在任意时刻,算法都能对它已经读
 * 入的数据给出子序列问题的正确答案(其他算法不具有这个特性).具有这种特性的算法叫作联机算法(on-line algorithm).
 * 仅需要常量空间并以线性时间运行的联机算法几乎是完美的算法.
 *
 * 解决方法:
 * 1. 暴力枚举
 * 2. 分治思想(递归)
 * 3. 联机算法(最优)
 *
 * 时间复杂度:
 * 1. 暴力枚举:O(N^2)
 * 2. 分治思想(递归)::O(NlogN)
 * 3. 联机算法:查看main2.cpp
 *
 * 算法特点:
 *
 * 思考:
 *
 * */


int main() {
    TestEnum();//暴力枚举
    TestRe();//分治思想
}
