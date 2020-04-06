#ifndef __BFS1__H__
#define __BFS1__H__

#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <array>

using namespace std;

/*�Թ�����----������������㷨(BFS)
 *
 * ��������:
 * �Թ���n��m�еĵ�Ԫ�����(n��m��С�ڵ���50)��ÿ����Ԫ��Ҫô�ǿյأ�Ҫô���ϰ���ҵ�һ�����Թ������ͨ��ĳ��λ�õ����·����
 * ע��:�ϰ����ǲ����ߵ�
 *
 * ˼��:
 * 1.����arrayģ�����,ʵ�ֹ���
 * */

int a1[51][51]={0}; //�Թ���ͼ
int visit1[51][51]={0}; //��û����·������
int n,m =0; //�Թ�������������
int minStep = 999999; //���·��
int startx,starty=0;//���λ��
int p,q=0;; //�Թ��յ�λ��

//��¼·�� arrayģ��ջ
struct Pos{
    Pos() = default;
    Pos(int posx,int posy):x(posx),y(posy){}
    int x {0};
    int y {0};
};
std::array<Pos,51*51> que={};
int top=0;

/* 1 ��ʾ���ϰ���
 * 0 ��ʾ����ͨ��
 * */
void CreateMap(){
    std::default_random_engine random(time(nullptr));
    std::uniform_int_distribution<int> dis(0,3);
    std::cout<<"�������Թ�������������(�м��Կո���Ϊ�ָ���):";
    std::cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1){
                a1[i][j]=0;//��֤�Թ���㲻�����ϰ���
            }else{
                a1[i][j]=dis(random)/3;//Ϊ����0���ֵĸ��ʴ�Щ
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cout<<a1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void PrintPath(){
}

void BFS1(int x, int y,int step){





//    //�����յ�
//    if(x==p && y==q){
//        if(step<minStep) {
//            minStep = step; //���·��
//            PrintPath();    //�����·
//        }
//        return;
//    }
//
//    //����ÿ�������
//    static int next[4][2]={
//            {0,1},  //����
//            {1,0},  //����
//            {0,-1}, //����
//            {-1,0}  //����
//    };
//    for(int k=0;k<4;k++){
//        int nextx = x+next[k][0];
//        int nexty = y+next[k][1];
//        if(nextx<1 || nextx>n || nexty<1 || nexty>m){ //Խ���ж�
//            continue;
//        }
//        if(a1[nextx][nexty]==0 && visit1[nextx][nexty]==0) { //�����ϰ��ﲢ�Ҳ���·����
//            visit1[nextx][nexty] = 1; //����·����
//            Pos pos{nextx,nexty};   //ѹջ
//            que[top] = pos;
//            top++;
//
//            BFS1(nextx, nexty, step + 1);  //����
//
//            visit1[nextx][nexty] = 0;//��·����ɾ��
//            top--;//��ջ
//        }
//    }
}

int TestBFS1(){
    //����һ����ͼ
    CreateMap();

    auto start = std::chrono::steady_clock::now();

    std::cout<<"�������Թ������x�����λ��y(�м��Կո���Ϊ�ָ���):";
    std::cin>>startx>>starty;
    std::cout<<"�Թ������λ��:("<<startx<<","<<starty<<")"<<std::endl;

    std::cout<<"�������Թ����յ�x���յ�λ��y(�м��Կո���Ϊ�ָ���):";
    std::cin>>p>>q;
    std::cout<<"�Թ����յ�λ��:("<<p<<","<<q<<")"<<std::endl;

    visit1[startx][starty]=1; //������ʶ��·����

    BFS1(startx,starty,0);//��������㷨

    if(minStep == 999999){
        std::cout<<"û�����·��"<<std::endl;
    }else{
        std::cout<<"minStep:"<<minStep<<std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::seconds>(end-start);
    std::cout<<"time:"<<time.count()<<"s"<<std::endl;

    return 0;
}


#endif //__BFS1__H__
