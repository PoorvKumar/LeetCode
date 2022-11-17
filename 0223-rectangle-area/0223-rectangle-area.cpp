class Solution 
{
private:
    int calcArea(int x1,int y1,int x2,int y2)
    {
        return (x2-x1)*(y2-y1);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int a1=calcArea(ax1,ay1,ax2,ay2);
        int a2=calcArea(bx1,by1,bx2,by2);
        
        if(a1==0 || a2==0)
        {
            if(a1==0)
            {
                return a2;
            }
            return a1;
        }
        
        int ans=a1+a2;
        
        int x=0;
        int y=0;
        
        if(bx1>=ax1 && bx1<=ax2 || ax1>=bx1 && ax1<=bx2)
        {
            if(bx2>=ax1 && bx2<=ax2 && bx1>=ax1 && bx1<=ax2)
            {
                x=bx2-bx1;
            }
            else if(ax2>=bx1 && ax2<=bx2 && ax1>=bx1 && ax1<=bx2)
            {
                x=ax2-ax1;
            }
            else if(bx1>=ax1 && bx1<=ax2)
            {
                x=abs(ax2-bx1);
            }
            else
            {
                x=abs(bx2-ax1);
            }
        }
        
        if(by1>=ay1 && by1<=ay2 || ay1>=by1 && ay1<=by2)
        {
            if(by2>=ay1 && by2<=ay2 && by1>=ay1 && by1<=ay2)
            {
                y=by2-by1;
            }
            else if(ay2>=by1 && ay2<=by2 && ay1>=by1 && ay1<=by2)
            {
                y=ay2-ay1;
            }
            else if(by1>=ay1 && by1<=ay2)
            {
                y=abs(ay2-by1);
            }
            else
            {
                y=abs(by2-ay1);
            }
        }
        
        ans=ans-calcArea(0,0,x,y);
        return ans;
    }
};