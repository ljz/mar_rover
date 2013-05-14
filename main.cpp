//火星车探索模拟  
#include<iostream>
#include<string>
using namespace std;

//判断一个数是否是正整数
int Pos_int(double x) 
{
 	double judge_x;
	judge_x = (int)x;

	if ( judge_x == x && x>0 )
		return 1;
	else
		return 0;
}

//判断方向是否合法
int Judge_direc(char direc)
{
	if( 'N' == direc || 'n' == direc || 'E' == direc || 'e' == direc 
		|| 'S' == direc || 's' == direc ||'W' == direc ||'w' == direc )
		return 1;
	else
		return 0;
}

//判断操作字符串是否合法
int Judge_action(string atc)
{
	for (string::size_type j = 0 ; j != atc.size();++j)
	{
		if(!('m' == atc[j] || 'M' == atc[j] || 'l' == atc[j] 
			|| 'L' == atc[j] || 'r' == atc[j] || 'R' == atc[j]))
		{
			return 0;
		}
	}
	return 1;
}

//探索执行函数
int explore(double max_x,double max_y,double *p_cur_x,double *p_cur_y,char *p_cur_face,string act)
{
	for (string::size_type i = 0 ; i != act.size();++i)
	{
		if('L' == act[i] || 'l' == act[i])//左转
		{
			switch(*p_cur_face)
			{
			case 'N':
				case 'n':
				*p_cur_face = 'W';	break;
			case 'E':
			case 'e':
				*p_cur_face = 'N';  break;
			case 'S':
			case 's':
				*p_cur_face = 'E';  break;
			case 'W':
			case 'w':
				*p_cur_face = 'S';  break;
			default: ;
			}
		}
		else if('M' == act[i] || 'm' == act[i])//前进
		{
			switch(*p_cur_face)
			{
			case 'N':
			case 'n':
				{
					(*p_cur_y)++;
					if ( *p_cur_y>max_y)
					{
						return 0;
					}
					else
						break;
				}
			case 'E':
			case 'e':
				{
					(*p_cur_x) ++;
					if (*p_cur_x>max_x)
					{
						return 0;
					}
					else
						break;
				}
			case 'S':
			case 's':
				{
					(*p_cur_y) --;
					if (*p_cur_y<0)
					{
						return 0;
					}
					else 
						break;
				}
			case 'W':
			case 'w':
				{
					(*p_cur_x) --;
					if (*p_cur_x<0)
					{
						return 0;
					}
					else
						break;
				}
			default: ;
			}
		}
		else if('R' == act[i] || 'r' == act[i])//右转
		{
			switch(*p_cur_face)
			{
			case 'N' :
			case 'n' :
				*p_cur_face = 'E'; 
				break;
			case 'E' :
			case 'e' :
				*p_cur_face = 'S';
				break;
			case 'S' :
			case 's' :
				*p_cur_face = 'W';
				break;
			case  'W' :
			case 'w' :
				*p_cur_face = 'N';
				break;
			default: ;
			}
		}
		else ;
	}
	return 1;
}
int main()
{
	double upper = 0.0,right = 0.0;//高原的右上角坐标
	double ro_x = 0.0,ro_y = 0.0;//火星车的坐标
	char ro_face = 0;//火星车的方向
	string str_act ;//执行步骤
	do{
		cout<<"Please input the upper-right coordinates of the plateau!"
			<<"two Positive integers separated by spaces(eg:3 5):"<<endl;
		cin>>upper>>right;
	}while( !( Pos_int(upper) && Pos_int(right) && 0<upper*right ) );//判断输入的合法性

     do{
        cout<<"Please input the robotic rover's position and face !"
            <<"(Two Positive integers and one char which in{n,N,w,W,e,E,s,S} separated by spaces):"<<endl;
        cin>>ro_x>>ro_y>>ro_face;
      }while( !( Pos_int(ro_x) && Pos_int(ro_y) && Judge_direc(ro_face) && ro_x<right && ro_y<upper) );//判断输入的合法性

	 do{
		cout<<"Please input the letters to tell the rover how to explore the plateau."
		    <<"(One string only Contain {M,m,L,l,R,r})"<<endl;
	    cin>>str_act;
	    }while(!Judge_action(str_act));//判断输入的合法性

    	if(!explore(right,upper,&ro_x,&ro_y,&ro_face,str_act))//开始模拟探索
    	{
	    	cout<<"The rover will go out of the plateau "<<endl;
	    	return 0;
    	}
    	cout<<ro_x<<' '<<ro_y<<' '<<ro_face<<endl;
    
    	return 1;
}
//test git 
