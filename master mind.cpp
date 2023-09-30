#include<stdio.h>
void brain(int x[],int y,int z,int r);
void seprat(int x[],int y);
int mergnumber(int x[],int t);
int checker(int x[],int t);
void maker(int x[],int t,int y);
void jaygashtput(int x[]);
void jaygashtput(int x[])
{
	int i=0,j;
	int wantedarray[4];
	for(j=0;j<4;j++){
			wantedarray[j]=1;
	}
	for(j=1;i<360;j++){
		maker(wantedarray,4,6);
		if(checker(wantedarray,4)==2){
		x[i]=mergnumber(wantedarray,4);
		i++;
		}
	}
}
int mergnumber(int x[],int t){
	int i,sum=0;
	for(i=0;i<t;i++){
		sum=sum+x[i];
		sum=sum*10;
	}
	return sum/10;
}
int checker(int x[],int t){
	int i,j,e=0;
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			if(x[i]==x[j]&&i!=j){
				e=1;
			}
			if(e==1){
		      return 1;
	        }
    }
	}
	if(e==0){
		return 2;
	}
}
void maker(int x[],int t,int y){
	int i,j;
	int bond[100];
	for(i=0;i<t;i++){
		bond[i]=y;
	}
	if(mergnumber(x,t)<mergnumber(bond,t)){
		x[t-1]++;
	for(i=t-1;i>=0;i--){
		if(i>0&&x[i]==y+1){
			x[i]=1;
			x[i-1]++;
		}
	}
    }
}
int main(){
	int motherarray[360];
	int i;
	printf("wlecome to the game\n if you want to start so write 'ok'\n");
	scanf("ok");
	jaygashtput(motherarray);	
	printf("\nguse the number\n");
	int com=0,part=0;
	for(i=0;i<360;i++){
		if(motherarray[i]!=0){
		printf("\n%d\n",motherarray[i]);
		scanf("%d%d",&com,&part);
		if(com==4){
			printf("\n end the game");
			break;
		}
		if(com!=4){
		brain(motherarray,com,part,motherarray[i]);
	    }
	    }
	}
}
void brain(int x[],int y,int z,int r){
	int array1[4],radix[4];
	int f,i,j,base1,base2;
    seprat(radix,r);
	for(i=0;i<360;i++){
	base1=0;
	base2=0;	
	if(x[i]!=0){
	seprat(array1,x[i]);
	for(j=0;j<4;j++){
		if(array1[j]==radix[j]){
			base1++;
		}
	}
		for(j=0;j<4;j++){
			for(f=0;f<4;f++){
				if(array1[f]==radix[j]){
					base2++;
				}
			}
		}
		if(base1!=y||(base2-base1)!=z){
		x[i]=0;
	    }
	}
    }
}
void seprat(int x[],int y){
	int i;
	for(i=0;y!=0;i++){
		x[i]=y%10;
		y=y/10;
	}
}
