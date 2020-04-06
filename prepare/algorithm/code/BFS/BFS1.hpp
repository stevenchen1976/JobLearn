#ifndef __BFS1__H__
#define __BFS1__H__

#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <array>
#include <stack>

using namespace std;

/*�Թ�����----������������㷨(BFS)
 *
 * ��������:
 * �Թ���n��m�еĵ�Ԫ�����(n��m��С�ڵ���50)��ÿ����Ԫ��Ҫô�ǿյأ�Ҫô���ϰ���ҵ�һ�����Թ������ͨ��ĳ��λ�õ����·����
 * ע��:�ϰ����ǲ����ߵ�
 *
 * ˼��:
 * 1.����arrayģ�����,ʵ�ֹ���,Ҳ����ֱ����std::queue
 * 2.ͬ�����Թ�����,���ѵ�ʱ�临�Ӷ�Ҫ������С�ܶ�
 * 3.�������������ʱ�临�Ӷ�Ϊ O(V+E)��VΪ���������EΪ�ߵ�������
 * ���һ�����ж��㶼����ͨ��ͼ��E �϶�Ҫ���� V-1������ʱ�临�Ӷȿ��Լ�дΪ O(V)
 * 4.�ռ临�Ӷ�ΪO(V),VΪ�������
 * */

int a1[51][51]={0}; //�Թ���ͼ
int visit1[51][51]={0}; //��û����·������
int n,m =0; //�Թ�������������
int startx,starty=0;//���λ��
int p,q=0;; //�Թ��յ�λ��

//��¼·�� arrayģ�����
struct Pos{
    Pos() = default;
    Pos(int posx,int posy,int step,int findex):x(posx),y(posy),s(step),f(findex){}
    int x {0};
    int y {0};
    int s {0};//����
    int f {0};//���ڵ��ڶ����е�����
};
std::array<Pos,51*51> que={};
//Pos que[51*51]={};
int head =0;//����ͷ
int tail =0;//����β

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
    //�õ����и��ڵ��index
    std::stack<int> stack;
    stack.push(tail-1);

    int index = tail-1;
    while(que[index].f!=0){
        stack.push(que[index].f);
        index = que[index].f;
    }

    //���·��
    int first = 1;
    while (!stack.empty()){
        index=stack.top();
        stack.pop();
        if(first==1){
            std::cout<<"("<<que[index].x<<","<<que[index].y<<")";
        }else{
            std::cout<<"->("<<que[index].x<<","<<que[index].y<<")";
        }
        first++;
    }
    std::cout<<std::endl;
}

void BFS1(){
    int flag=0; //��ʾ��ľ���ҵ�

    //���г�ʼ��
    head = tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].s = 0;
    que[tail].f = 0;
    tail++;

    visit1[startx][starty]=1; //������ʶ��·����

    //����
    while(head<tail){//��ʾ���в�Ϊ��
        //ö����Χ4��
        static int next[4][2]={
                {0,1},  //����
                {1,0},  //����
                {0,-1}, //����
                {-1,0}  //����
        };
        for(int k=0;k<4;k++){
            int tx = que[head].x + next[k][0];
            int ty = que[head].y + next[k][1];

            if(tx<1 || tx>n || ty<1 || ty>m){//�߽�
                continue;
            }

            if(a1[tx][ty]==0 && visit1[tx][ty]==0){//�����ϰ��ﲢ�Ҳ���·����
                visit1[tx][ty]=1; //����ֻ��һ��
                //�������
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].s = que[head].s+1;//���ڵ㲽����1
                que[tail].f = head;
                tail++;
            }

            if(tx==p && ty==q){//�ҵ�Ŀ���
                flag=1;
                break;
            }
        }

        if(flag==1){
            break;
        }

        head++;//��������
    }

    if(flag==1){
        std::cout<<"�ҵ���Ŀ���:step="<<que[tail-1].s<<std::endl;//tail��ʱ�ڶ�β����һ��λ��
        PrintPath();
    } else{
        std::cout<<"û���ҵ�Ŀ���"<<std::endl;
    }
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

    BFS1(); //����

    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::seconds>(end-start);
    std::cout<<"time:"<<time.count()<<"s"<<std::endl;

    return 0;
}


#endif //__BFS1__H__
