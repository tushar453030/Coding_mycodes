class Solution {
public:
    void nearestsmallestleft(vector<int>& heights,vector<int> &left){
        stack<pair<int,int>> st;
        int preindex=-1;
        for(int i=0;i<heights.size();i++){
            if(st.size()==0){
                left.push_back(preindex);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                left.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i]){
                    st.pop();
                }
                
                if(st.size()==0){
                    left.push_back(preindex);
                }
                else{
                    left.push_back(st.top().second);
                }
            }
            
            st.push({heights[i],i});
        }
    }
    void nearestsmallestright(vector<int>& heights,vector<int> &right){
        stack<pair<int,int>> st;
        int preindex=heights.size();
        for(int i=heights.size()-1;i>=0;i--){
            if(st.size()==0){
                right.push_back(preindex);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                right.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i]){
                    st.pop();
                }
                
                if(st.size()==0){
                    right.push_back(preindex);
                }
                else{
                    right.push_back(st.top().second);
                }
            }
            
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        nearestsmallestleft(heights,left);
        nearestsmallestright(heights,right);
        int maxi=0;
        int totalsize=0;
        for(int i=0;i<right.size();i++){
            maxi=right[i]-left[i]-1;
            if(totalsize<maxi*heights[i]){
                totalsize=maxi*heights[i];
            }
        }
        return totalsize;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        int maxarea=0;
        char temp='2';
        
        for(int j=0;j<matrix[0].size();j++){
            v.push_back(int(matrix[0][j])-48);
        }
        int cal=largestRectangleArea(v);
        
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]=v[j]+(int(matrix[i][j])-48);
                }
            }
            cal=max(cal,largestRectangleArea(v));
        }
        return cal;
    }
};
