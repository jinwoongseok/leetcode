//22.9.15
class Solution {
public:
   int maxArea(vector<int>& height) {
       int start = 0;
       int end = height.size()-1;
       int Max =0;
       int multi=0;
       while(end-start!=0){
           int xAxis = end-start;
           int yAxis = min(height[start],height[end]);
           multi = xAxis*yAxis;
           Max = multi > Max ? multi : Max ;
           if(height[start]>height[end]){
               end-=1;
           }else{
               start+=1;
           }
        }
        return Max;
   }//end int maxArea
};
