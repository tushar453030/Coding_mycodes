    void mergeboth(vector<int> &num,int l,int mid,int r){
        int n1=mid-l+1;
        int n2=r-mid;
        
        int Left[n1],Right[n2];
        for(int i=0;i<n1;i++)
            Left[i]=num[l+i];
        for(int j=0;j<n2;j++)
            Right[j]=num[mid+1+j];
        
        int i,j,k;
        i=0;
        j=0;
        k=l;
        
        while(i<n1 && j<n2){
            if(Left[i]<=Right[j]){
                num[k]=Left[i];
                i++;
            }
            else{
                num[k]=Right[j];
                j++;
            }
            k++;
        }
        
        while(i<n1){
            num[k]=Left[i];
            i++;
            k++;
        }
        while(j<n2){
            num[k]=Right[j];
            j++;
            k++;
        }
    }
    void merge(vector<int> &num,int l,int r){
        if(l<r){
            int mid=(r+l)/2;
            merge(num,l,mid);
            merge(num,mid+1,r);
            mergeboth(num,l,mid,r);
        }
    }
