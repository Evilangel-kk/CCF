#include<stdio.h>
typedef long long LL;

int r,y,g;//红绿灯设置 
int n;
int k,t;
LL ans=0;

/*
k=1: 红灯r [0,r)
k=2: 黄灯y [r+g,r+g+y)
k=3: 绿灯g [r,r+g)

以坐标轴来看 
即 |__________|__________|___|
	   红灯       绿灯    黄灯 
*/

int judge(LL tt){ //判断tt时刻该处的红绿灯情况
	if(tt>=0 && tt<r) return 1;	//红灯
	if(tt>=r+g && tt<r+g+y) return 2; //黄灯
	if(tt>=r && tt<r+g) return 3; //绿灯
}

int main(){
	scanf("%d%d%d",&r,&y,&g);
	scanf("%d",&n);
	for(LL i=0;i<n;i++){
		scanf("%d%d",&k,&t);
		if(k==0){	//经过路段
			ans+=t;
		}
		else if(k==1){	//刚开始这里是红灯，判断此时会变成什么灯
			LL tt=r-t;
			tt=(tt+ans)%(r+y+g);
			int flag=judge(tt);
			if(flag==1){	//变成了红灯
				ans+=r-tt;
			}
			else if(flag==2){	//变成了黄灯
				ans+=r+y+g-tt+r;
			}
		}
		else if(k==2){  //刚开始这里是黄灯，判断此时会变成什么灯
			LL tt=r+g+y-t;
			tt=(tt+ans)%(r+y+g);
			int flag=judge(tt);
			if(flag==1){ 	//变成了红灯
				ans+=r-tt;
			}
			else if(flag==2){	//变成了黄灯
				ans+=r+y+g-tt+r;
			}
		}
		else if(k==3){  //刚开始这里是绿灯，判断此时会变成什么灯
			LL tt=r+g-t;
			tt=(tt+ans)%(r+y+g);
			int flag=judge(tt);
			if(flag==1){	//变成了红灯
				ans+=r-tt;
			}
			else if(flag==2){	//变成了黄灯
				ans+=r+y+g-tt+r;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

