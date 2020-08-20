
/*   efficient solution is at GFG   time complexity:O(1)   space complexity:O(1)   */

import java.util.*;
class Get_Min_From_Stack
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T>0)
		{
			int q = sc.nextInt();
			GfG g = new GfG();
			while(q>0)
			{
				int qt = sc.nextInt();
				
				if(qt == 1)
				{
					int att = sc.nextInt();
					g.push(att);
					//System.out.println(att);
				}
				else if(qt == 2)
				{
					System.out.print(g.pop()+" ");
				}
				else if(qt == 3)
				{
					System.out.print(g.getMin()+" ");
				}
			
			q--;
			}
			System.out.println();
		T--;
		}
		sc.close();
		
	}
}


/*This is a function problem.You only need to complete the function given below*/
class GfG
{
    int minEle=32767;
    Stack<Integer> s=new Stack<Integer>();
    int arr[]=new int[10000];
    int t=0;
    
    
    /*returns min element from stack*/
    int getMin()
    {
        return minEle;
    }
    
     
    int pop()
    {
	  int temp=s.peek(); t--;	
	   if(temp==minEle)
	   {   minEle=32767;
	      for(int i=0;i<t;i++)  
	        if(arr[i]<minEle)  minEle=arr[i];
	   }
	   s.pop();
	   return temp;
    }
    /*push element x into the stack*/
    void push(int x)
    {
       s.push(x);  arr[t++]=x;
       if(x<minEle)  minEle=x;
    }	
}
