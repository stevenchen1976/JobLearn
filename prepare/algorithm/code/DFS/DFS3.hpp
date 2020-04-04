#ifndef __DFS3__H__
#define __DFS3__H__

#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <array>
using namespace std;

/*�Թ�����----������������㷨(DFS)
 *
 * ��������:
 * �Թ���n��m�еĵ�Ԫ�����(n��m��С�ڵ���50)��ÿ����Ԫ��Ҫô�ǿյأ�Ҫô���ϰ���ҵ�һ�����Թ������ͨ��ĳ��λ�õ����·����
 * ע��:�ϰ����ǲ����ߵ�
 *
 * ˼��:
 * 1.���ﲻ��Ҫ������·������Ҫ�����·���������
 * */



int a3[51][51]={0}; //�Թ���ͼ
int book3[51][51]={0}; //��û����·������
struct Pos{
public:
    Pos() = default;
    Pos(int x,int y,int fx,int fy){
        this->x = x;
        this->y = y;
        this->fx = fx;
        this->fy = fy;
    }
public:
    int x {0}; //��ǰλ������
    int y {0}; //��ǰλ������
    int fx {0};//��ǰλ�ø��ڵ�����
    int fy {0};//��ǰλ�ø��ڵ�����
};

/* 1 ��ʾ���ϰ���
 * 0 ��ʾ����ͨ��
 * */
void CreateMap(){
    std::default_random_engine random(time(nullptr));
    std::uniform_int_distribution<int> dis(0,3);
    int n,m=0;
    std::cout<<"�������Թ�������:";
    std::cin>>n;
    std::cout<<"�������Թ�������:";
    std::cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0){
                a3[i][j]=0;//��֤�Թ���㲻�����ϰ���
            }else{
                a3[i][j]=dis(random)/3;//Ϊ����0���ֵĸ��ʴ�Щ
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cout<<a3[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

//������
void DFS(int x,int y,int step){
    //�ж�����
    //�˳�

    //����ÿһ�ֿ���
    //DFS(step+1)

    //�˳�
}

int TestDFS3(){
    //����һ����ͼ
    CreateMap();

    auto start = std::chrono::steady_clock::now();

    Pos startPos;
    std::cout<<"�������Թ������x:";
    std::cin>>startPos.x;
    std::cout<<"�������Թ������y:";
    std::cin>>startPos.y;

    book3[startPos.x][startPos.y]=1; //������ʶ��·����

    DFS(startPos.x,startPos.y,0);//��������㷨

    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"time:"<<time.count()<<"ms"<<std::endl;

    return 0;
}


#endif //__DFS3__H__