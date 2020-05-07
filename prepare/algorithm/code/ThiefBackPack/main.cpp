#include "ThiefBackPack.hpp"
using namespace std;


/* 动态规划-----背包问题:小偷偷东西
 *
 * 动态规划:
 * 1. 思想:
 * 白话说就是一种解决棘手问题的方法,它将问题分成小问题,并先着手解决这些小问题,最后得到最优解
 *
 * 2. 特点:
 * 1). 动态规划可帮助你在给定约束条件下找到最优解.在背包问题中,你必须在背包容量给定的情况下,偷到价值最高的商品.
 * 2). 在问题可分解为彼此独立且离散的子问题时,就可使用动态规划来解决(很重要)
 *
 * 背包问题:
 * 要高度注意:"背包"可不仅仅是指例子中物理的背包,是指一种约束条件.比如说要在规定时间去旅游,那么这个"背包"就是时间!
 *
 * */

int main() {
    TestThiefBackPack();//NPC问题-----背包问题:小偷偷东西
}