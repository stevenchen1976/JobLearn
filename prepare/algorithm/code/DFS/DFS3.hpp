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
 * 1.���������в��Թ�����ʱ�򵱵�ͼ�Ƚϴ�ʱ���Ҳ��Ե���10��10�У�minStep������ʱ���Ǵ���ģ�������ʱ�򻹻�����ѭ����ȥ(�޷�Ѱ���յ�)��
 * ��ʱû���ҳ���ԭ��
 * */



int a3[51][51]={0}; //�Թ���ͼ
int book3[51][51]={0}; //��û����·������
int n,m =0; //�Թ�������������
int minStep = 999999; //���·��
int startx,starty=0;//���λ��
int p,q=0;; //�Թ��յ�λ��

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
                a3[i][j]=0;//��֤�Թ���㲻�����ϰ���
            }else{
                a3[i][j]=dis(random)/3;//Ϊ����0���ֵĸ��ʴ�Щ
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cout<<a3[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void PrintPath(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(book3[i][j]==1){
                if(i==1&&j==1){
                    std::cout<<"("<<i<<","<<j<<")";
                }else{
                    std::cout<<"->("<<i<<","<<j<<")";
                }
            }
        }
    }
    std::cout<<std::endl;
}

void DFS3(int x, int y,int step){
    //�����յ�
    if(x==p && y==q){
        if(step<minStep) {
            minStep = step; //���·��
            PrintPath();    //�����·
        }
        return;
    }

    //����ÿ�������
    static int next[4][2]={
            {0,1},  //����
            {1,0},  //����
            {0,-1}, //����
            {-1,0}  //����
    };
    for(int k=0;k<4;k++){
        int nextx = x+next[k][0];
        int nexty = y+next[k][1];
        if(nextx<1 || nextx>n || nexty<1 || nexty>m){ //Խ���ж�
            continue;
        }
        if(a3[nextx][nexty]==0 && book3[nextx][nexty]==0) { //�����ϰ��ﲢ�Ҳ���·����
            book3[nextx][nexty] = 1; //����·����
            DFS3(nextx, nexty, step + 1);  //����
            book3[nextx][nexty] = 0;//��·����ɾ��
        }
    }
}

int TestDFS3(){
    //����һ����ͼ
    CreateMap();

    auto start = std::chrono::steady_clock::now();

    std::cout<<"�������Թ������x�����λ��y(�м��Կո���Ϊ�ָ���):";
    std::cin>>startx>>starty;
    std::cout<<"�Թ������λ��:("<<startx<<","<<starty<<")"<<std::endl;

    std::cout<<"�������Թ����յ�x���յ�λ��y(�м��Կո���Ϊ�ָ���):";
    std::cin>>p>>q;
    std::cout<<"�Թ����յ�λ��:("<<p<<","<<q<<")"<<std::endl;

    book3[startx][starty]=1; //������ʶ��·����

    DFS3(startx,starty,0);//��������㷨

    if(minStep == 999999){
        std::cout<<"û�����·��"<<std::endl;
    }else{
        std::cout<<"minStep:"<<minStep<<std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"time:"<<time.count()<<"ms"<<std::endl;

    return 0;
}


#endif //__DFS3__H__
