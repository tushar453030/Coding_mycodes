    public:
    static bool cmp(Item a,Item b){
        double r1=(double) a.value/a.weight;
        double r2=(double) b.value/b.weight;
        return r1>r2;
     }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>> m;
        sort(arr,arr+n,cmp);
        double ans=0.0;
        for(int i=0;i<n && W>0;i++){
            if(W>=arr[i].weight){
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else{
                ans+=arr[i].value*((double) W/arr[i].weight);
                W=0;
                break;
            }
        }
        return ans;
    }
