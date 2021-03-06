#include<iostream>
#include<vector>

using namespace std;

class PackEnum
{
protected:
	vector<int> m_p; //N个背包的价格
	vector<int> m_w;// N个背包的重量
	int m_c;        //背包的容量
	int m_num;      //物品的件数


public:
	PackEnum();  //构造函数
	PackEnum(vector<int>& p,vector<int>& w,int c,int n):m_p(p),m_w(c),m_c(c),m_num(n){}//构造函数初始化并赋值

	//获取背包内物品的最大值
	int GetBestValue() const{
		int bestValue=0;           //背包最大价值
		int currentValue=0;       //当前背包内物品的价值
		int currentWeight=0;      //当前背包内物品的重量 

		const unsigned int max = 2 << m_num;
		//穷举所有的可能
		for(unsigned int i=0;i<max;++i){
			//清空背包
			currentValue = 0;
			currentWeight = 0;
			//取二进制中的每一位
			unsigned int bit = i;
			int j=0;
			while(bit!=0){
				currentWeight+=m_w[j]*(bit & 1);
				currentValue+=m_p[j]*(bit & 1);
				//如果bit的最低位为1，则bit&1=1，否则为0
				bit >>= 1;
				++j;
			}
			//保存最优解
			if(currentWeight<=m_c && bestValue < currentValue){
				bestValue = currentValue;
			}
		}
		return bestValue;
	}
};


int main03(void){
	int n;
	int c;

	cout << "请输入物品的件数 :" <<endl;
	cin >> n;
	cout << "请输入背包的容量 :"<<endl;
	cin>>c;
	vector<int> w(n);
	vector<int> p(n);

	cout<<"请输入物品的重量 :"<<endl;
	for(int i=0;i<n;++i){
		cin >>w[i];
	cout<<"请输入物品的价值:"<<endl;
	for(int j=0;j<n;j++)
		cin>>p[j];

	PackEnum pack(p,w,c,n);

	int bestValue = pack.GetBestValue();
	cout<<"背包内物品的最大价值为：" <<bestValue<<endl;
	return 0;
	}

}